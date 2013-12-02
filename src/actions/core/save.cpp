#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/filechooserdialog.h>

class ActionSaveGeneric: public Action {
public:
	virtual std::string getFileName() = 0;

	bool run() {
		std::string fileName = getFileName();

		if (fileName == "") {
			Gtk::FileChooserDialog chooser("Select a scene file", Gtk::FILE_CHOOSER_ACTION_SAVE);
			chooser.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
			chooser.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);
            chooser.set_do_overwrite_confirmation(true);

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
				fileName = chooser.get_filename();
				osgedit::OSGEdit::saveSceneFile(fileName);
                return true;
			} else {
                return false;
			}
		} else {
			osgedit::OSGEdit::saveSceneFile(fileName);
            return true;
		}
	}
};

class ActionSave: public ActionSaveGeneric {
public:
	virtual std::string getFileName() {
		return osgedit::OSGEdit::getSceneFileName();
	}
};

class ActionSaveAs: public ActionSaveGeneric {
public:
	virtual std::string getFileName() {
        return "";
	}
};

REGISTER_ACTION_FULL(ActionSave, Gtk::Stock::SAVE, "", "Save the scene");
REGISTER_ACTION_FULL(ActionSaveAs, Gtk::Stock::SAVE_AS, "", "Save the scene with a different name");
