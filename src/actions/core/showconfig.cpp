#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/main.h>

class ActionShowConfig: public Action {
public:
	bool run() {
		osgedit::OSGEdit::showConfiguration();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionShowConfig, Gtk::Stock::PREFERENCES, "", "Show the preferences editor");
