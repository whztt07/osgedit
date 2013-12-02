#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>

#include <gtkmm/main.h>

#include <command/commanddelete.h>
#include <command/metacommand.h>

/// We will use a command to allow undo/redo
class ActionDelete: public Action {
public:
	Command* genCommand(osgedit::Selection::ObjectPath &path) {
		int len = path.size();
		if (len > 1) {
			ClassReflection *parent = path[len-2].get();
			ClassReflection *child = path[len-1].get();
			return new CommandDelete(parent, child);
		} else {
			Gtk::MessageDialog dialog("You can not remove the root node.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
		}
        return NULL;
	}

	bool run() {
		osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
		if (selection->getNumItems() == 0) {
			Gtk::MessageDialog dialog("Select something to delete it.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else if (selection->getNumItems() == 1) {
			osgedit::Selection::ObjectPath &path = selection->getItem(0);
			osg::ref_ptr<Command> command = genCommand(path);
			if (command.valid()) {
				command->execute();
                return true;
			} else {
                return false;
			}
		} else {
			osg::ref_ptr<MetaCommand> metaCmd = new MetaCommand("Remove selection");
			for (unsigned i = 0; i < selection->getNumItems(); i++) {
				osgedit::Selection::ObjectPath &path = selection->getItem(i);
                osg::ref_ptr<Command> command = genCommand(path);
				if (command.valid()) {
					metaCmd->addSubCommand(command.get());
				}
			}
			metaCmd->execute();
            return true;
		}
	}
};

REGISTER_ACTION_FULL(ActionDelete, Gtk::Stock::DELETE, "", "Delete the selected item");
