#include <gtkmm/stock.h>
#include <gui/layout/controls/controlfactory.h>
#include "textareacontrol.h"

TextAreaControl::TextAreaControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_textView = Gtk::manage(new Gtk::TextView);
    _updateButton = Gtk::manage(new Gtk::Button(Gtk::Stock::REFRESH));
	_updateButton->signal_activate().connect(sigc::mem_fun(*this, &TextAreaControl::on_activate_text));
	_updateButton->signal_clicked().connect(sigc::mem_fun(*this, &TextAreaControl::on_activate_text));
    _scrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
	_scrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
    _scrolledWindow->add(*_textView);
}

unsigned TextAreaControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 2, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_scrolledWindow, 0, 2, row+1, row+2, Gtk::EXPAND|Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
	table->attach(*_updateButton, 0, 1, row+2, row+3, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+3;
}

void TextAreaControl::apply(StringProperty *prop) {
	_target = prop;
    refresh();
}

void TextAreaControl::on_activate_text() {
	if (_target.valid()) {
		std::string text = _textView->get_buffer()->get_text();
		_target->set(text);
	}
}


void TextAreaControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void TextAreaControl::refresh() {
    if (!_target.valid()) return;
	_textView->get_buffer()->set_text(_target->get());
}

REGISTER_CONTROL(TextAreaControl);
