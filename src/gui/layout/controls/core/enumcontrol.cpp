#include <gui/layout/controls/controlfactory.h>
#include "enumcontrol.h"

EnumControl::EnumControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_combo = Gtk::manage(new Gtk::ComboBoxText);
	_changedConnection = _combo->signal_changed().connect(sigc::mem_fun(*this, &EnumControl::on_changed));

}

unsigned EnumControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 1, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_combo, 1, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+1;
}

void EnumControl::apply(EnumProperty *prop) {
    _target = prop;
    refresh();
}

void EnumControl::on_changed() {
	if (_target.valid()) {
		std::string text = _combo->get_active_text();
		if (text != _target->get()) {
		    _target->set(text);
		}
	}
}


void EnumControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void EnumControl::refresh() {
	if (!_target.valid()) {
		return;
	}
        _changedConnection.block();
	_combo->clear_items();
	std::vector<std::string> items = _target->getEnumItems();
	for (unsigned i=0;i<items.size();i++) {
		_combo->append_text(items[i]);
	}
	_combo->set_active_text(_target->get());
        _changedConnection.unblock();
}


REGISTER_CONTROL(EnumControl);
