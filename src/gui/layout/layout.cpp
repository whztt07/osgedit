#include <command/commandhistory.h>
#include "layout.h"
#include <set>


Layout::Layout() {
	_noteBook = Gtk::manage(new Gtk::Notebook());
	_noteBook->set_show_tabs(false);
}

Layout::~Layout() {}

void Layout::addControl(const std::string &property, LayoutControl *control) {
	_controls[property] = control;
    getActiveGroup()->addControl(control);
}

void Layout::addGrid(const std::string &tableProperty, LayoutGrid *grid) {
	_grids[tableProperty] = grid;
	getActiveGroup()->addGrid(grid);
}

void Layout::connect(ClassReflection *reflection) {
	std::set<std::string> _handledProps;
	ControlMap::iterator iter = _controls.begin();
	for (; iter != _controls.end(); iter++) {
		std::string controlPropName = iter->first;
		osg::ref_ptr<LayoutControl> control = iter->second;
		try {
			PropertyReflection *prop = reflection->getProperty(controlPropName);
            // Visitor pattern to connect the control to the property
			prop->accept(*control);
            _handledProps.insert(prop->getName());
		} catch (ClassReflection::PropertyNotFoundException&) {}
	}

	ClassReflection::PropertyNames names = reflection->getPropertyNames();
	ClassReflection::PropertyNames tableNames = reflection->getTablePropertyNames();
	ClassReflection::PropertyNames::iterator piter = names.begin();

	GridMap::iterator giter = _grids.begin();
	for (; giter != _grids.end(); giter++) {
		std::string tableProperty = giter->first;
		osg::ref_ptr<LayoutGrid> grid = giter->second;
        grid->connect(reflection, tableProperty);
	}
	_connection = CommandHistory::instance()->signal_command.connect( sigc::mem_fun(this, &Layout::refresh) );
}

void Layout::refresh() {
	ControlMap::iterator iter = _controls.begin();
	for (; iter != _controls.end(); iter++) {
		osg::ref_ptr<LayoutControl> control = iter->second;
        control->refresh();
	}

	GridMap::iterator giter = _grids.begin();
	for (; giter != _grids.end(); giter++) {
		osg::ref_ptr<LayoutGrid> grid = giter->second;
        grid->refresh();
	}
}

bool Layout::hasEmptyGrids() const {
	GridMap::const_iterator giter = _grids.begin();
	for (; giter != _grids.end(); giter++) {
		osg::ref_ptr<LayoutGrid> grid = giter->second;
        if (grid->getNumControls() == 0) return true;
	}
    return false;
}

void Layout::disconnect() {
    _connection.disconnect();
}



Layout::Group::Group(const std::string &name): _nextRow(0) {
	_table = Gtk::manage(new Gtk::Table(1, 2, false));
	_table->set_row_spacings(2);
	_table->set_col_spacings(2);
    _table->set_border_width(4);

	_frame = Gtk::manage(new Gtk::Frame());
	_frame->add(*_table);
	_frame->set_shadow_type(Gtk::SHADOW_NONE);

	if (name != "") {
		Gtk::Label *label = Gtk::manage(new class Gtk::Label("<b>"+name+"</b>"));
        label->set_use_markup(true);
		label->set_justify(Gtk::JUSTIFY_LEFT);
		_frame->set_label_widget(*label);
        _frame->set_label_align (0.0, 0.5);
	}
}

void Layout::Group::addControl(LayoutControl *control) {
    _nextRow = control->render(_table, _nextRow);
}

void Layout::Group::addGrid(LayoutGrid *grid) {
    _nextRow = grid->render(_table, _nextRow);
}

void Layout::Group::addSubGroup(Group *subgroup) {
	_table->attach(*subgroup->getWidget(), 0, 2, _nextRow, _nextRow+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	_nextRow++;
}

/**
 * Begins a new group of controls, inside the parent one
 */
void Layout::beginGroup(const std::string &name) {
	Group *group = new Group(name);
    getActiveGroup()->addSubGroup(group);
	_groupStack.push(group);
}

/**
 * Ends a group of controls, returning to the parent one
 */
void Layout::endGroup() {
    _groupStack.pop();
}

void Layout::beginTab(const std::string &name) {
	Group *master = new Group();
    while (!_groupStack.empty()) _groupStack.pop();
	_groupStack.push(master);
	_noteBook->append_page(*master->getWidget(), name);
	_noteBook->set_show_tabs(true);
}

Layout::Group *Layout::getActiveGroup() {
	if (_groupStack.empty()) {
		Group *master = new Group();
		_groupStack.push(master);
		_noteBook->append_page(*master->getWidget());
	}
    return _groupStack.top().get();
}
