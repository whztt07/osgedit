#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/main.h>

class ActionUndo: public Action {
public:
	bool run() {
		osgedit::OSGEdit::undo();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionUndo, Gtk::Stock::UNDO, "", "Un-do the last command");
