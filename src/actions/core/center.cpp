#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>

#include <osg/Node>

#include <iostream>

class ActionCenter: public Action {
public:
	bool run() {
		osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
		if (selection->getNumItems() == 0) {
			Gtk::MessageDialog dialog("Select something to center on", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else {
			osg::BoundingSphere bs;
			for (unsigned i = 0; i < selection->getNumItems(); i++) {
				osgedit::Selection::ObjectPath &path = selection->getItem(i);
				osgedit::Selection::ObjectPath::reverse_iterator iter;
				for (iter = path.rbegin(); iter != path.rend(); iter++) {
					ClassReflection *cref = iter->get();
					osg::Node *node = dynamic_cast<osg::Node*>(cref->getObject());
					if (node != NULL) {
                        bs.expandBy(node->getBound());
						break;
					}
				}
			}
			osgedit::OSGEdit::centerCamera(bs);
            return true;
		}
	}
};

REGISTER_ACTION_FULL(ActionCenter, Gtk::Stock::FULLSCREEN, "_Center selection", "Center the selected items on the camera");
