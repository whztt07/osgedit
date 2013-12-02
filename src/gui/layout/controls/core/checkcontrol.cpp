#include <gui/layout/controls/controlfactory.h>
#include "checkcontrol.h"

CheckControl::CheckControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_check = Gtk::manage(new Gtk::CheckButton());
	_check->signal_toggled().connect(sigc::mem_fun(*this, &CheckControl::on_check_toggled));
}

unsigned CheckControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 1, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_check, 1, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+1;
}

void CheckControl::apply(BoolProperty *prop) {
    _target = prop;
    refresh();
}

void CheckControl::on_check_toggled() {
	if (_target.valid()) {
		bool v = _check->get_active();
        if (v != _target->get()) _target->set(v);
	}
}

void CheckControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void CheckControl::refresh() {
    if (!_target.valid()) return;
    _check->set_active(_target->get());
}

REGISTER_CONTROL(CheckControl);
