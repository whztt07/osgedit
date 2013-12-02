#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>

#include <gtkmm/main.h>

class ActionCopy: public Action {
public:
	bool run() {
		osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
		if (selection->getNumItems() == 0) {
			Gtk::MessageDialog dialog("Select something to copy.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else if (selection->getNumItems() == 1) {
			osgedit::OSGEdit::setClipboardContents(selection->getItem(0).back().get());
            return true;
		} else {
			Gtk::MessageDialog dialog("You can only copy one item.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		}
	}
};

REGISTER_ACTION_FULL(ActionCopy, Gtk::Stock::COPY, "", "Copy the selected item into the clipboard");
