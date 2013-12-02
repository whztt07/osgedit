#include <gui/controls3d/control3dfactory.h>
#include <common/log.h>
#include "control3dmanager.h"
#include "osgviewport.h"
#include <common/selection.h>

#define POSITION_CONTROL_3D "PositionControl3D"
#define ROTATION_CONTROL_3D "RotationControl3D"
#define SCALE_CONTROL_3D "ScaleControl3D"

static std::string prettyName(std::string name) {
	std::string output = "";
    bool first = true;
	for (unsigned i=0; i<name.size(); i++) {
		if (name[i] == '_') {
			continue;

		} else if (name[i] >= 'A' && name[i] <= 'Z') {
            output = output + " " + name[i];

		} else if (first) {
            char c = name[i] + 'A' - 'a';
			output = output + c;
            first = false;
		} else {
            output = output + name[i];
		}
	}
    return output;
}

Control3DManager::Control3DManager() {
	_label.set_text("<b>3D Controls</b>");
	_label.set_use_markup(true);
    set_label_widget(_label);
	set_border_width(3);

    _treeView.set_headers_visible(false);
	_treeModel = Gtk::ListStore::create(_columns);
	_treeView.set_model(_treeModel);
	add(_treeView);
	_treeView.append_column("Control", _columns.col_name);
	_treeView.append_column_editable("Visible", _columns.col_visible);
	show_all();
	_treeModel->signal_row_changed().connect(sigc::mem_fun(*this, &Control3DManager::on_row_changed));
	osgedit::Selection::instance()->signal_changed.connect(sigc::mem_fun(*this, &Control3DManager::on_selection_changed));
}

Control3DManager *Control3DManager::instance() {
	static Control3DManager *_instance = new Control3DManager;
    return _instance;
}

void Control3DManager::on_selection_changed() {
	osgedit::Selection *selection = osgedit::Selection::instance();
	if (selection->getNumItems() > 0) {
		osg::NodePath np;
		osgedit::Selection::ObjectPath &op = selection->getItem(0);
		// We must skip last one because it contains the local transform
		for (unsigned i=0; i < op.size()-1; i++) {
			osg::Node *node = dynamic_cast<osg::Node*>(op[i]->getObject());
			if (node != 0) {
				np.push_back(node);
			}
		}
		setLocalToWorld(osg::computeLocalToWorld(np));
	}
}


void Control3DManager::connect(ClassReflection *cref) {
	ClassReflection::PropertyNames names = cref->getPropertyNames();
	ClassReflection::PropertyNames::iterator iter = names.begin();
	_treeModel->clear();
    OSGViewport::instance()->clearControls3D();
	for (; iter != names.end(); iter++) {
			std::string name = *iter;
			PropertyReflection *prop = cref->getProperty(name);
            prop->accept(*this);
	}
}

void Control3DManager::apply(Vec3dProperty *prop) {
	if (prop->getName() != "_scale") {
		addControl(prop, POSITION_CONTROL_3D);
	} else {
		addControl(prop, SCALE_CONTROL_3D);
	}
}

void Control3DManager::apply(Vec4fProperty *prop) {
	if (prop->getName() == "_position") {
		addControl(prop, POSITION_CONTROL_3D);
	}
}

void Control3DManager::apply(MatrixdProperty *prop) {
    addControl(prop, POSITION_CONTROL_3D, prop->getName()+"(pos)");
    addControl(prop, ROTATION_CONTROL_3D, prop->getName()+"(rot)");
    addControl(prop, SCALE_CONTROL_3D, prop->getName()+"(siz)");
}

void Control3DManager::apply(QuatProperty *prop) {
    addControl(prop, ROTATION_CONTROL_3D);
}

void Control3DManager::addControl(PropertyReflection *prop, const std::string &controlName, const std::string &label) {
	try {
		Control3D *control = FIND_CONTROL_3D(controlName);
		prop->accept(*control);
		Gtk::TreeModel::Row row = *(_treeModel->append());
		if (label == "") row[_columns.col_name] = prettyName(prop->getName());
		else row[_columns.col_name] = label;
		row[_columns.col_visible] = true;
		row[_columns.col_control] = control;
	} catch (UnknownClassException &e) {
		LOG("Unknown 3D control: "+controlName, Log::ERROR);
	}
}

void Control3DManager::setLocalToWorld(const osg::Matrix &localToWorld) {
	Gtk::TreeIter iter = _treeModel->children().begin();
	while (iter) {
		Gtk::TreeModel::Row row = *iter;
		osg::ref_ptr<Control3D> control = row[_columns.col_control];
        control->setLocalToWorld(localToWorld);
		iter++;
	}
}

void Control3DManager::on_row_changed (const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& iter) {
	Gtk::TreeModel::Row row = *iter;
	osg::ref_ptr<Control3D> control = row[_columns.col_control];
	if (control.valid()) {
		bool visible = row[_columns.col_visible];
		if (visible) {
			OSGViewport::instance()->addControl3D(control.get());
		} else {
			OSGViewport::instance()->removeControl3D(control.get());
		}
	}
}


