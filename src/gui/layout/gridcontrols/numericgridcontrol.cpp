#include "numericgridcontrol.h"
#include <sstream>
#include <locale>

NumericGridControl::NumericGridControl(Mode mode): _mode(mode) {
    _renderer.property_editable() = true;
	_renderer.signal_edited().connect(sigc::mem_fun(*this, &NumericGridControl::on_edited));
}

void NumericGridControl::fillViewModel() {
    unsigned nRows = _cref->getNumTablePropertyRows(_tableProperty);
	Gtk::ListStore::Children rows = _viewModel->children();
	for (unsigned nrow =0 ; nrow < nRows; nrow++) {
        Gtk::TreeModel::Row subrow = rows[nrow];
		IntProperty *intProp =
			dynamic_cast<IntProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		FloatProperty *floatProp =
			dynamic_cast<FloatProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		DoubleProperty *doubleProp =
			dynamic_cast<DoubleProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		if (intProp) {
            subrow[_intColumn] = intProp->get();

		} else if (floatProp) {
            subrow[_floatColumn] = floatProp->get();

		} else if (doubleProp) {
            subrow[_doubleColumn] = doubleProp->get();
		}
	}
}

void NumericGridControl::on_edited(const Glib::ustring& path_string, const Glib::ustring& cell_text) {
	std::string text = cell_text;

	int nrow = strtol(path_string.c_str(), (char**)NULL, 10);
	Gtk::TreeModel::iterator iter = path2iter(path_string);
	if (iter) {
		Gtk::TreeModel::Row row = *iter;
		IntProperty *intProp =
			dynamic_cast<IntProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		FloatProperty *floatProp =
			dynamic_cast<FloatProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		DoubleProperty *doubleProp =
			dynamic_cast<DoubleProperty *>(_cref->getTableProperty(_tableProperty, nrow, _modelColumn));
		if (intProp) {
            int val = strtol(text.c_str(), (char**)NULL, 10);
			intProp->set(val);
            row[_intColumn] = val;

		} else if (floatProp) {
			float val = (float)strtod(text.c_str(), (char**)NULL);
			floatProp->set(val);
            row[_floatColumn] = val;

		} else if (intProp) {
            double val = strtod(text.c_str(), (char**)NULL);
			doubleProp->set(val);
            row[_doubleColumn] = val;
		}
	}
}
void NumericGridControl::updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator & iter) {
	Gtk::TreeModel::Row row = *iter;
	std::ostringstream stream;
	std::locale mylocale("");
    stream.imbue(mylocale);
	switch(_mode) {
	case INT:
		stream << row[_intColumn];
		break;
	case FLOAT:
		stream << row[_floatColumn];
		break;
	case DOUBLE:
		stream << row[_doubleColumn];
        break;
	}
    _renderer.property_text() = stream.str();
}
