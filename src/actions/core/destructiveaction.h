#ifndef __DESTRUCTIVE_ACTION_H__
#define __DESTRUCTIVE_ACTION_H__

#include <actions/action.h>
#include <gtkmm/messagedialog.h>

/**
 * A destructive action is one that destroys the scene data and can't be
 * undone. If you derive your action class from this one and implement
 * the runDestructive() instead of run(), you will gain a confirmation
 * dialog allowing the user to cancel, save the scene, or risk.
 */
class DestructiveAction: public Action {
public:
	bool run() {
		if (osgedit::OSGEdit::sceneModified()) {
			Gtk::MessageDialog dialog("The current scene has been modified, do you want to save it first?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_NONE);
			dialog.add_button("Do not save", Gtk::RESPONSE_OK);
			dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
			dialog.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_YES);
			int result = dialog.run();
			if (result == Gtk::RESPONSE_CANCEL) {
                return false;
			} else if (result == Gtk::RESPONSE_YES) {
				if (ActionFactory::instance()->run("ActionSave") == false) {
                    return false;
				}
			}
		}
		return runDestructive();
	}

	/**
	 * Method that performs the actual destructive operation
     */
	virtual bool runDestructive() = 0;
};

#endif//__DESTRUCTIVE_ACTION_H__
