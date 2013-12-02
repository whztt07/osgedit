#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>

template <class MyTool>
class ActionUseTool: public Action {
public:
	bool run() {
		osgedit::OSGEdit::setActiveTool(new MyTool);
        return true;
	}
};

#define SUPPORT_TOOL(ATool, Stock, Label, Tooltip) \
	typedef ActionUseTool<ATool> Action##ATool; \
	REGISTER_ACTION_FULL(Action##ATool, Stock, Label, Tooltip)

#include <tools/toolpick.h>

SUPPORT_TOOL(ToolPick, Gtk::StockID("gtk-color-picker"), "_Pick", "Pick an object from the viewport");
