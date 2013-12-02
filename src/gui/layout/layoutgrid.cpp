#include "layoutgrid.h"

LayoutGrid::LayoutGrid() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_tree = Gtk::manage(new Gtk::TreeView);
    Gtk::TreeModelColumn<Glib::ustring> rowTitles;
	_columns.add(rowTitles);
    _tree->append_column("rows", rowTitles);
}

void LayoutGrid::addColumnControl(int column, const std::string &title, LayoutGridControl *control) {
    _controls[column] = control;
	_columns.add(*control->getColumn());
	_tree->insert_column_with_data_func(-1, title, *control->getCellRenderer(),
										sigc::mem_fun(*control, &LayoutGridControl::updateRenderer));
}

void LayoutGrid::connect(ClassReflection *cref, const std::string &tableProperty) {
	_label->set_text(tableProperty);
	_store = Gtk::ListStore::create(_columns);
	_tree->set_model(_store);
	unsigned nCols = cref->getNumTablePropertyColumns(tableProperty);
	unsigned nRows = cref->getNumTablePropertyRows(tableProperty);

	// Fill row titles
    ClassReflection::PropertyNames rowNames = cref->getTablePropertyRowTitles(tableProperty);
	for (unsigned nrow =0 ; nrow < nRows; nrow++) {
		Gtk::TreeModel::Row subrow = *_store->append();
		subrow.set_value(0, rowNames[nrow]);
	}

    // Fill everything else
	for (unsigned ncol = 0; ncol < nCols; ncol++) {
		ControlMap::iterator iter = _controls.find(ncol);
		if (iter != _controls.end()) {
			osg::ref_ptr<LayoutGridControl> control = iter->second;
			control->configure(_store, cref, tableProperty, ncol);
		}
	}
}

unsigned LayoutGrid::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 2, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_tree, 0, 2, row+1, row+2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+2;
}

void LayoutGrid::refresh() {
    // Fill everything else
	ControlMap::iterator iter = _controls.begin();
	for (; iter != _controls.end(); iter++) {
		osg::ref_ptr<LayoutGridControl> control = iter->second;
		control->refresh();
	}
}
