#include <gui/layout/controls/controlfactory.h>
#include <gtkmm/adjustment.h>
#include "numericcontrol.h"

NumericControl::NumericControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	Gtk::Adjustment * adj = Gtk::manage(new Gtk::Adjustment(0, G_MININT32, G_MAXINT32, 1, 10, 10));
	_spin = Gtk::manage(new class Gtk::SpinButton(*adj, 1, 2));
	_spin->set_flags(Gtk::CAN_FOCUS);
	_spin->set_update_policy(Gtk::UPDATE_ALWAYS);
	_spin->set_numeric(true);
	_spin->set_wrap(false);
	_spin->signal_value_changed().connect(sigc::mem_fun(*this, &NumericControl::on_value_changed));
}

unsigned NumericControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 1, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_spin, 1, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+1;
}

void NumericControl::apply(IntProperty *prop) {
	_intTarget = prop;
	_floatTarget = 0;
    _doubleTarget = 0;
	_spin->set_value(prop->get());
    _spin->set_digits(0);
}

void NumericControl::apply(FloatProperty *prop) {
	_intTarget = 0;
    _floatTarget = prop;
	_doubleTarget = 0;
    _spin->set_value(prop->get());
    _spin->set_digits(2);
}

void NumericControl::apply(DoubleProperty *prop) {
	_intTarget = 0;
	_floatTarget = 0;
    _doubleTarget = prop;
    _spin->set_value(prop->get());
    _spin->set_digits(4);
}

void NumericControl::on_value_changed() {
	if (_intTarget.valid()) {
		int val = (int)_spin->get_value();
        if (val != _intTarget->get()) _intTarget->set(val);
	} else if (_floatTarget.valid()) {
		float val = (float)_spin->get_value();
		if (val != _floatTarget->get()) _floatTarget->set(val);
	} else if (_doubleTarget.valid()) {
		double val = _spin->get_value();
        if (val != _doubleTarget->get()) _doubleTarget->set(val);
	}
}


void NumericControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void NumericControl::refresh() {
	if (_intTarget.valid()) {
		_spin->set_value(_intTarget->get());
	} else if (_floatTarget.valid()) {
		_spin->set_value(_floatTarget->get());
	} else if (_doubleTarget.valid()) {
		_spin->set_value(_doubleTarget->get());
	}
}


REGISTER_CONTROL(NumericControl);
