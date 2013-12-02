#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

#include <gtkmm/main.h>

class ActionProperties: public Action {
public:
	bool run() {
		osgedit::OSGEdit::showSceneProperties();
        return true;
	}
};

REGISTER_ACTION_FULL(ActionProperties, Gtk::Stock::PROPERTIES, "_Properties", "File properties");
