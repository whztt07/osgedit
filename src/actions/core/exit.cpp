#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include "destructiveaction.h"

class ActionExit: public DestructiveAction {
public:
	bool runDestructive() {
		osgedit::OSGEdit::quit();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionExit, Gtk::Stock::QUIT, "", "Exit from OSGEdit");
