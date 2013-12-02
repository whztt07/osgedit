#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include "destructiveaction.h"

class ActionNew: public DestructiveAction {
public:
	bool runDestructive() {
		osgedit::OSGEdit::newScene();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionNew, Gtk::Stock::NEW, "", "Start a new scene");
