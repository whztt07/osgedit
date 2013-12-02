#include <gtksourceviewmm/sourcelanguagesmanager.h>
#include <gtkmm/stock.h>
#include <gui/layout/controls/controlfactory.h>
#include "sourcecodecontrol.h"
#include <common/log.h>

SourceCodeControl::SourceCodeControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_textView = Gtk::manage(new gtksourceview::SourceView);
    _textView->set_show_line_numbers(true);
	_textView->set_auto_indent(true);
    _textView->get_source_buffer()->set_highlight(true);

	_updateButton = Gtk::manage(new Gtk::Button(Gtk::Stock::EXECUTE));
	_updateButton->signal_activate().connect(sigc::mem_fun(*this, &SourceCodeControl::on_activate_text));
	_updateButton->signal_clicked().connect(sigc::mem_fun(*this, &SourceCodeControl::on_activate_text));
    _scrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
	_scrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
    _scrolledWindow->add(*_textView);
}

unsigned SourceCodeControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 2, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_scrolledWindow, 0, 2, row+1, row+2, Gtk::EXPAND|Gtk::FILL, Gtk::EXPAND|Gtk::FILL, 0, 0);
	table->attach(*_updateButton, 0, 1, row+2, row+3, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+3;
}

void SourceCodeControl::apply(StringProperty *prop) {
	_target = prop;
    refresh();
}

void SourceCodeControl::on_activate_text() {
	if (_target.valid()) {
		std::string text = _textView->get_buffer()->get_text();
		_target->set(text);
	}
}


void SourceCodeControl::setLabel(const std::string &label) {
	_label->set_text(label);
}

void SourceCodeControl::refresh() {
	if (!_target.valid()) return;
	_textView->get_buffer()->set_text(_target->get());
}

void SourceCodeControl::parseParameter(const std::string &property,const std::string &value) {
	if (property == "language") {
		Glib::RefPtr<gtksourceview::SourceLanguagesManager> language_manager =
			gtksourceview::SourceLanguagesManager::create();
		Glib::RefPtr<gtksourceview::SourceLanguage> lang = language_manager->get_language_from_mime_type (value);
		if (lang) {
			_textView->get_source_buffer()->set_language(lang);
		} else {
			std::vector<Glib::RefPtr<gtksourceview::SourceLanguage> > langs;
			langs = language_manager->get_available_languages ();
			std::vector<Glib::RefPtr<gtksourceview::SourceLanguage> >::iterator iter;
			std::string available = "\n";
			for (iter = langs.begin(); iter != langs.end (); ++iter) {
				if (*iter) {
					std::vector< Glib::ustring > mimes = (*iter)->get_mime_types();
					available += " - language: '" + (*iter)->get_name() + "', mimes: ";
					for (unsigned i=0; i < mimes.size();i++) {
						available += mimes[i] + " ";
					}
                    available+="\n";
				} else {
					available+= " - language: null\n";
				}
			}
			LOG("No language for MIME type '"+value+"', available types:"+available, Log::WARNING);
		}
	}
}

REGISTER_CONTROL(SourceCodeControl);
