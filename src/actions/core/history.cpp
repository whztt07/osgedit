#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/main.h>

class ActionHistory: public Action {
public:
	bool run() {
		osgedit::OSGEdit::showHistory();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionHistory, Gtk::Stock::INDEX, "_History", "Show the execution history");
