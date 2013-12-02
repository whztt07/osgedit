#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/main.h>

class ActionRedo: public Action {
public:
	bool run() {
		osgedit::OSGEdit::redo();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionRedo, Gtk::Stock::REDO, "", "Re-do the last undone command");
