#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/main.h>

class ActionShowLog: public Action {
public:
	bool run() {
		osgedit::OSGEdit::showLog();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionShowLog, Gtk::Stock::INFO, "_Log", "Show the messages log");
