#include <gtkmm/cellrendererpixbuf.h>
#include <gtkmm/messagedialog.h>
#include <reflection/reflectioncache.h>
#include <reflection/hierarchymanager.h>
#include <command/commandhistory.h>
#include <common/selection.h>
#include "objecttree.h"
#include "reflectioneditor.h"
#include "control3dmanager.h"
#include <command/commandadd.h>
#include <command/commanddelete.h>
#include <command/metacommand.h>

#define DEFAULT_ICON "default.png"

Glib::RefPtr<Gdk::Pixbuf> type2pixbuf(const std::string &className) {
	std::string image = "";
	for (unsigned i=0;i<className.size();i++) {
		if (className[i] == ':') {
            image+="_";
			i++;
		} else if (className[i] >= 'A' && className[i] <='Z' ) {
            image+=className[i]+'a'-'A';
		} else {
            image+=className[i];
		}
	}
    image+=".png";
	try {
		return Gdk::Pixbuf::create_from_file(std::string(ICON_DIR) + "/" + image);
	} catch (Glib::FileError &e) {
		try {
			return Gdk::Pixbuf::create_from_file(std::string(ICON_DIR) + "/" + DEFAULT_ICON);
		} catch (Glib::FileError &e) {
			return Glib::RefPtr<Gdk::Pixbuf>();
		}
	}
}

ObjectTree::ObjectTree() {
    set_size_request(100,200);
	_model = OsgTreeModel::create();
	set_model(_model);



	//append_column_editable("Name", _model->_columns.m_col_name);
	// add icons
	Gtk::TreeViewColumn *column = Gtk::manage(new Gtk::TreeViewColumn("Name"));
    column->pack_start(_model->_columns.m_col_pixbuf, false);
    column->pack_start(_model->_columns.m_col_name, true);
	column->set_spacing(5);
	std::vector<Gtk::CellRenderer*> renderers = column->get_cell_renderers();
	Gtk::CellRendererText *renderer = dynamic_cast<Gtk::CellRendererText *>(renderers[1]);
    renderer->property_editable() = true;
    renderer->signal_edited().connect(sigc::mem_fun(*this, &ObjectTree::on_signal_edited));
	append_column(*column);

	this->get_selection()->signal_changed().connect(sigc::mem_fun(*this, &ObjectTree::on_selection_changed));
	this->get_selection()->set_mode(Gtk::SELECTION_MULTIPLE);
    this->set_reorderable(true);

    // Capture do/undo events
	CommandHistory::instance()->signal_command.connect( sigc::mem_fun(this, &ObjectTree::refresh) );

    // Capture add/remove children
	HierarchyManager::instance()->signal_add_child.connect( sigc::mem_fun(this, &ObjectTree::on_add_child) );
	HierarchyManager::instance()->signal_del_child.connect( sigc::mem_fun(this, &ObjectTree::on_del_child) );
}

ObjectTree::~ObjectTree() {
}

void ObjectTree::on_signal_edited(const Glib::ustring &pathstr, const Glib::ustring& value) {
	Gtk::TreePath path(pathstr);
	Gtk::TreeModel::iterator iter = _model->get_iter(path);
	Gtk::TreeModel::Row row = *iter;
    row[_model->_columns.m_col_name] = value;
}

void ObjectTree::setRoot(osg::Object *obj) {
    _model->clear();
	ClassReflection* cref = ReflectionCache::instance()->reflect(obj);
	Gtk::TreeModel::Row row = *(_model->append());
	row[_model->_columns.m_col_name] = cref->getName();
	row[_model->_columns.m_col_reflection] = cref;
	row[_model->_columns.m_col_pixbuf] = type2pixbuf(cref->getType());
	recurseChildren(cref, row);
}

void ObjectTree::recurseChildren(ClassReflection *cref, Gtk::TreeModel::Row &row) {
	unsigned nchild = cref->getNumChildren();
	for (unsigned i=0; i < nchild; i++) {
		ClassReflection* childref = cref->getChild(i);
		// May be a null pointer
		if (childref != NULL) {
			Gtk::TreeModel::Row subrow = *(_model->append(row.children()));
			subrow[_model->_columns.m_col_name] = childref->getName();
			subrow[_model->_columns.m_col_reflection] = childref;
			subrow[_model->_columns.m_col_pixbuf] = type2pixbuf(childref->getType());
			recurseChildren(childref, subrow);
		}
	}
}

void ObjectTree::on_selection_changed() {
	std::vector<Gtk::TreeModel::Path> paths = get_selection()->get_selected_rows();
	if (paths.size() == 1) {
		Gtk::TreeModel::iterator iter = _model->get_iter(paths[0]);
		osg::ref_ptr<ClassReflection> cref = iter->get_value(_model->_columns.m_col_reflection);
		ReflectionEditor::instance()->edit(cref.get());
		Control3DManager::instance()->connect(cref.get());
	}

	osgedit::Selection *selection = osgedit::Selection::instance();
	selection->clear();

	for (unsigned i=0; i < paths.size(); i++) {
		osgedit::Selection::ObjectPath selpath;

		do {
			Gtk::TreeModel::iterator iter = _model->get_iter(paths[i]);
			osg::ref_ptr<ClassReflection> cref = iter->get_value(_model->_columns.m_col_reflection);
			selpath.insert(selpath.begin(), cref);
		} while (paths[i].up() && paths[i].get_depth() > 0);
        selection->addItem(selpath);
	}
}

void ObjectTree::refresh() {
	_model->foreach(sigc::mem_fun(*this, &ObjectTree::refreshForEach));
}

bool ObjectTree::refreshForEach(const Gtk::TreeModel::Path&, const Gtk::TreeModel::iterator& iter) {
    Gtk::TreeModel::Row row = *iter;
    osg::ref_ptr<ClassReflection> cref = row[_model->_columns.m_col_reflection];
    row[_model->_columns.m_col_name] = cref->getName();
    return false;
}

bool ObjectTree::addForEach(const Gtk::TreeModel::Path&, const Gtk::TreeModel::iterator& iter,ClassReflection *parent, ClassReflection *child) {
    Gtk::TreeModel::Row row = *iter;
    osg::ref_ptr<ClassReflection> cref = row[_model->_columns.m_col_reflection];
	if (cref->getObject() == parent->getObject()) {
		Gtk::TreeModel::Row subrow = *(_model->append(row.children()));
		subrow[_model->_columns.m_col_name] = child->getName();
		subrow[_model->_columns.m_col_reflection] = child;
		subrow[_model->_columns.m_col_pixbuf] = type2pixbuf(child->getType());
        // Child may have subobjects also
		recurseChildren(child, subrow);
	}
    return false;
}

void ObjectTree::on_add_child(ClassReflection *parent, ClassReflection *child) {
	_model->foreach(sigc::bind<ClassReflection *,ClassReflection *>(sigc::mem_fun(*this, &ObjectTree::addForEach), parent, child));
}

bool ObjectTree::findAndDelete(Gtk::TreeModel::iterator &iter, Gtk::TreeModel::iterator &piter, ClassReflection *parent, ClassReflection *child) {
	if (!iter) return false;
	Gtk::TreeModel::Row row = *iter;
	osg::ref_ptr<ClassReflection> cref = row[_model->_columns.m_col_reflection];
	if (cref->getObject() == child->getObject()) {
		Gtk::TreeModel::Row parentrow = *piter;
		osg::ref_ptr<ClassReflection> parentref = parentrow[_model->_columns.m_col_reflection];
		if (parentref->getObject() == parent->getObject()) {
			iter = _model->erase(iter);
            return true;
		}
	}
	Gtk::TreeModel::iterator childiter = row->children().begin();
	while (childiter) {
		if (! findAndDelete(childiter, iter, parent, child) ) {
            childiter++;
		}
	}
    return false;
}

void ObjectTree::on_del_child(ClassReflection *parent, ClassReflection *child) {
	Gtk::TreeModel::iterator iter = _model->children().begin();
    findAndDelete(iter, iter, parent, child);
}

bool ObjectTree::selectForEach(const Gtk::TreeModel::Path&, const Gtk::TreeModel::iterator& iter, ClassReflection *target) {
    Gtk::TreeModel::Row row = *iter;
    osg::ref_ptr<ClassReflection> cref = row[_model->_columns.m_col_reflection];
	if (cref->getObject() == target->getObject()) {
        get_selection()->select(iter);
	}
    return false;
}

void ObjectTree::select(ClassReflection *target, bool additive) {
	if (!additive) {
        get_selection()->unselect_all();
	}
	_model->foreach(sigc::bind<ClassReflection *>(sigc::mem_fun(*this, &ObjectTree::selectForEach), target));
}

bool ObjectTree::OsgTreeModel::row_draggable_vfunc(const Gtk::TreeModel::Path& path) const {
    return Gtk::TreeStore::row_draggable_vfunc(path);
}

bool ObjectTree::OsgTreeModel::row_drop_possible_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) const {
	bool allowed = Gtk::TreeStore::row_drop_possible_vfunc(dest, selection_data);
	if (allowed) {
        Gtk::TreeModel::Path dest_parent = dest;
		// We disallow moving to toplevel
		dest_parent.up();
        Gtk::TreeModel::Path dest_parent2 = dest_parent;
		bool has_parent = dest_parent2.up();
		if ( !has_parent ) return false;
		else return true;
	} else {
        return false;
	}
}

bool ObjectTree::OsgTreeModel::drag_data_received_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) {
	Gtk::TreeModel::Path dest_parent = dest;
	dest_parent.up();
	iterator iter_dest = get_iter(dest_parent);
	Row dst_row = *iter_dest;

	Gtk::TreeModel::Path src_path;
    Glib::RefPtr<Gtk::TreeModel> refThis = Glib::RefPtr<Gtk::TreeModel>(this);
	Gtk::TreeModel::Path::get_from_selection_data(selection_data, refThis, src_path);
	Gtk::TreeModel::Path src_parent_path = src_path;
    src_parent_path.up();
	iterator iter_src = get_iter(src_path);
    Row src_row = *iter_src;
	iterator iter_src_parent = get_iter(src_parent_path);
    Row src_row_parent = *iter_src_parent;

	osg::ref_ptr<ClassReflection> source_cref = src_row[_columns.m_col_reflection];
	osg::ref_ptr<ClassReflection> source_parent_cref = src_row_parent[_columns.m_col_reflection];
	osg::ref_ptr<ClassReflection> target_cref = dst_row[_columns.m_col_reflection];

	try {
		osg::ref_ptr<MetaCommand> mcmd = new MetaCommand();
        mcmd->addSubCommand(new CommandAdd(target_cref.get(), source_cref.get()));
		mcmd->addSubCommand(new CommandDelete(source_parent_cref.get(), source_cref.get()));
        mcmd->execute();
        return false;
	} catch (ClassReflection::InvalidTypeException &e) {
		Gtk::MessageDialog dialog("You can not add " + source_cref->getType() + " inside a " + target_cref->getType() + ". Cancelling.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
		return false;
	} catch (CommandAdd::NodeLoopException &e) {
		Gtk::MessageDialog dialog("You can not make loops in the graph.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
		return false;
	} catch (CommandAdd::DuplicatedChildException &e) {
		Gtk::MessageDialog dialog("You can not add the same child twice.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
		return false;
	}
}

ObjectTree::OsgTreeModel::OsgTreeModel() {
	set_column_types(_columns);
}

Glib::RefPtr<ObjectTree::OsgTreeModel> ObjectTree::OsgTreeModel::create()
{
	return Glib::RefPtr<ObjectTree::OsgTreeModel>( new OsgTreeModel() );
}

void ObjectTree::OsgTreeModel::on_row_changed (const TreeModel::Path& path, const TreeModel::iterator& iter) {
	Row row = *iter;
	osg::ref_ptr<ClassReflection> cref = row[_columns.m_col_reflection];
	if (cref.valid()) {
		typedef const std::string & (osg::Object::*getNameFN)() const;
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		TemplateProperty<std::string> *prop = new GetterSetterProperty<std::string, osg::Object>("_name", cref->getObject(), (getNameFN)&osg::Object::getName, (setNameFN)&osg::Object::setName);
		Glib::ustring uname = row[_columns.m_col_name];
		std::string name = uname;
        if (prop->get() != name) prop->set(name);
	}
}
