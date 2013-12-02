#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>
#include <command/commanddelete.h>

#include <gtkmm/main.h>

class ActionCut: public Action {
public:
	Command* genCommand(osgedit::Selection::ObjectPath &path) {
		int len = path.size();
		if (len > 1) {
			ClassReflection *parent = path[len-2].get();
			ClassReflection *child = path[len-1].get();
			return new CommandDelete(parent, child);
		} else {
			Gtk::MessageDialog dialog("You can not cut the root node.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
		}
        return NULL;
	}
	bool run() {
		osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
		if (selection->getNumItems() == 0) {
			Gtk::MessageDialog dialog("Select something to cut.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else if (selection->getNumItems() == 1) {
			osgedit::Selection::ObjectPath &path = selection->getItem(0);
			osg::ref_ptr<Command> command = genCommand(path);
			if (command.valid()) {
				osgedit::OSGEdit::setClipboardContents(path.back().get());
				command->execute();
                return true;
			} else {
                return false;
			}
		} else {
			Gtk::MessageDialog dialog("You can only cut one item.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		}
	}
};

REGISTER_ACTION_FULL(ActionCut, Gtk::Stock::CUT, "", "Cut the selected item and put it into the clipboard");
