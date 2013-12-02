#include <gui/layout/controls/controlfactory.h>
#include "textcontrol.h"

TextControl::TextControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_entry = Gtk::manage(new Gtk::Entry);
	_entry->signal_activate().connect(sigc::mem_fun(*this, &TextControl::on_activate_text));
}

unsigned TextControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 1, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_entry, 1, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+1;
}

void TextControl::apply(StringProperty *prop) {
    _target = prop;
    refresh();
}

void TextControl::apply(osgStringProperty *prop) {
    _targetOSG = prop;
    refresh();
}

void TextControl::on_activate_text() {
	if (_target.valid()) {
		std::string text = _entry->get_text();
		_target->set(text);
	} else if (_targetOSG.valid()) {
		osgText::String text = std::string(_entry->get_text());
		_targetOSG->set(text);
	}
}


void TextControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void TextControl::refresh() {
	if (_target.valid()) {
		_entry->set_text(_target->get());
	} else if (_targetOSG.valid()) {
		_entry->set_text(_targetOSG->get().createUTF8EncodedString());
	}
}


REGISTER_CONTROL(TextControl);
