#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/filechooserdialog.h>

#include "destructiveaction.h"

class ActionOpen: public DestructiveAction {
public:
	bool runDestructive() {
		Gtk::FileChooserDialog chooser("Select a scene file", Gtk::FILE_CHOOSER_ACTION_OPEN);
		chooser.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
		chooser.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

		Gtk::FileFilter filter_osg;
		filter_osg.set_name("OSG files");
		filter_osg.add_pattern("*.osg");
		chooser.add_filter(filter_osg);

		Gtk::FileFilter filter_any;
		filter_any.set_name("Any files");
		filter_any.add_pattern("*");
		chooser.add_filter(filter_any);

		int result = chooser.run();
		if (result == Gtk::RESPONSE_OK) {
			std::string fileName = chooser.get_filename();
			osgedit::OSGEdit::loadSceneFile(fileName);
            return true;
		} else {
            return false;
		}
	}
};

REGISTER_ACTION_FULL(ActionOpen, Gtk::Stock::OPEN, "", "Open a scene file");
