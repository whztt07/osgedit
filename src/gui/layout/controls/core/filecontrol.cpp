#include <osgDB/FileUtils>
#include <gui/layout/controls/controlfactory.h>
#include "filecontrol.h"

FileControl::FileControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);
	_fileChooser = Gtk::manage(new Gtk::FileChooserButton("File"));
	_fileChooser->signal_file_activated().connect(sigc::mem_fun(*this, &FileControl::on_selection_changed));
}

unsigned FileControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 1, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_fileChooser, 1, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+1;
}

void FileControl::apply(StringProperty *prop) {
	_target = prop;
    refresh();
}

void FileControl::on_selection_changed() {
	if (_target.valid()) {
		std::string text = _fileChooser->get_filename();
		if (text != _target->get()) {
			_target->set(text);
		}
	}
}


void FileControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void FileControl::refresh() {
    if (!_target.valid()) return;
    std::string resolved = osgDB::findDataFile(_target->get());
	_fileChooser->set_filename(resolved);
}


REGISTER_CONTROL(FileControl);
