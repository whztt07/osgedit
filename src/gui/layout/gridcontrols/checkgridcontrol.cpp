#include "checkgridcontrol.h"

CheckGridControl::CheckGridControl() {
	_renderer.property_activatable() = true;
	_renderer.signal_toggled().connect(sigc::mem_fun(*this, &CheckGridControl::on_toggled));
}

void CheckGridControl::fillViewModel() {
    unsigned nRows = _cref->getNumTablePropertyRows(_tableProperty);
	Gtk::ListStore::Children rows = _viewModel->children();
	for (unsigned nrow =0 ; nrow < nRows; nrow++) {
        Gtk::TreeModel::Row subrow = rows[nrow];
		BoolProperty *prop =
			dynamic_cast<BoolProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		if (prop) {
			subrow[_column] = prop->get();
		} else {
            subrow[_column] = false;
		}
	}
}

void CheckGridControl::on_toggled(const Glib::ustring& path_string) {
	int nrow = strtol(path_string.c_str(), (char**)NULL, 10);
	Gtk::TreeModel::iterator iter = path2iter(path_string);
	if (iter) {
		Gtk::TreeModel::Row row = *iter;
		BoolProperty *prop = dynamic_cast<BoolProperty*>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		if (prop) {
			bool value = !prop->get();
			prop->set(value);
			row[_column] = value;
		}
	}
}

void CheckGridControl::updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator & iter) {
    Gtk::TreeModel::Row row = *iter;
	_renderer.set_active(row[_column]);
}
