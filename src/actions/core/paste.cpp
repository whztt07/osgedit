#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>
#include <osg/Group>

#include <command/commandadd.h>
#include <command/metacommand.h>

class ActionPaste: public Action {
public:
	bool run() {
		osg::ref_ptr<ClassReflection> child = osgedit::OSGEdit::getClipboardContents();
		if (!child.valid()) {
			Gtk::MessageDialog dialog("The clipboard is empty. Copy something first.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else {
			osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
			if (selection->getNumItems() == 0) {
				Gtk::MessageDialog dialog("You have to select some node to paste into.", false, Gtk::MESSAGE_WARNING);
				dialog.run();
			} else {
				osg::ref_ptr<MetaCommand> metaCmd = new MetaCommand("Paste "+child->getName()+" to selected");
				for (unsigned i = 0; i < selection->getNumItems(); i++) {
					osgedit::Selection::ObjectPath &path = selection->getItem(i);
					ClassReflection *parent = path.back().get();
					metaCmd->addSubCommand(new CommandAdd(parent, child.get()));
				}
				try {
					metaCmd->execute();
                    return true;
				} catch (CommandAdd::NodeLoopException &e) {
					Gtk::MessageDialog dialog("Pasting there would cause a loop in the tree. Cancelling.", false, Gtk::MESSAGE_WARNING);
					dialog.run();
					try {
						metaCmd->undo();
					} catch (std::exception &e) {
						// IGNORE. We have just warned in the execute :)
					}
    			} catch (CommandAdd::DuplicatedChildException &e) {
					Gtk::MessageDialog dialog("You can not add the same child twice.", false, Gtk::MESSAGE_WARNING);
					dialog.run();
				} catch (std::exception &e) {
					Gtk::MessageDialog dialog("You can not paste " + child->getType() + " inside the selection. Cancelling.", false, Gtk::MESSAGE_WARNING);
					dialog.run();
					try {
						metaCmd->undo();
					} catch (std::exception &e) {
						// IGNORE. We have just warned in the execute :)
					}
				}
                return false;
			}
		}
	}
};

REGISTER_ACTION_FULL(ActionPaste, Gtk::Stock::PASTE, "", "Paste the clipboard contents into selected items");
