#include "textgridcontrol.h"

TextGridControl::TextGridControl() {
    _renderer.property_editable() = true;
	_renderer.signal_edited().connect(sigc::mem_fun(*this, &TextGridControl::on_edited));
}

void TextGridControl::fillViewModel() {
    unsigned nRows = _cref->getNumTablePropertyRows(_tableProperty);
	Gtk::ListStore::Children rows = _viewModel->children();
	for (unsigned nrow =0 ; nrow < nRows; nrow++) {
        Gtk::TreeModel::Row subrow = rows[nrow];
		StringProperty *prop =
			dynamic_cast<StringProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		if (prop) {
            subrow[_column] = prop->get();
		} else {
            subrow[_column] = "unsupported";
		}
	}
}

void TextGridControl::on_edited(const Glib::ustring& path_string, const Glib::ustring& cell_text) {
	std::string text = cell_text;

	int nrow = strtol(path_string.c_str(), (char**)NULL, 10);
	Gtk::TreeModel::iterator iter = path2iter(path_string);
	if (iter) {
		Gtk::TreeModel::Row row = *iter;
		StringProperty *prop = dynamic_cast<StringProperty*>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		if (prop) {
			prop->set(text);
            row[_column] = text;
		}
	}
}

void TextGridControl::updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator & iter) {
    Gtk::TreeModel::Row row = *iter;
	_renderer.property_text() = row[_column];
}
