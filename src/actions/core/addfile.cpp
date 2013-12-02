#include <actions/action.h>
#include <actions/actionfactory.h>
#include <sdk/osgedit.h>
#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/filechooserdialog.h>

#include <osgDB/ReadFile>

#include <command/commandadd.h>
#include <command/metacommand.h>

class ActionAddFile: public Action {
public:
	bool run() {
		osgedit::Selection *selection = osgedit::OSGEdit::getSelection();
		if (selection->getNumItems() == 0) {
			Gtk::MessageDialog dialog("You have to select some node to add children into.", false, Gtk::MESSAGE_WARNING);
			dialog.run();
            return false;
		} else {

			Gtk::FileChooserDialog chooser("Select a scene file", Gtk::FILE_CHOOSER_ACTION_OPEN);
			chooser.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
			chooser.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

			Gtk::FileFilter filter_osg;
			filter_osg.set_name("OSG files");
			filter_osg.add_pattern("*.osg");
			chooser.add_filter(filter_osg);

			Gtk::FileFilter filter_any;
			filter_any.set_name("Any files");
			filter_any.add_pattern("*");
			chooser.add_filter(filter_any);

			int result = chooser.run();
			if (result == Gtk::RESPONSE_OK) {
				std::string fileName = chooser.get_filename();

				char *previous=setlocale(LC_ALL,NULL);
				setlocale(LC_ALL,"C");
				osg::Node *node = osgDB::readNodeFile(fileName);
				setlocale(LC_ALL,previous);

				ClassReflection *child = osgedit::OSGEdit::reflect(node);
				osgedit::OSGEdit::autoName(child);
				osg::ref_ptr<MetaCommand> metaCmd = new MetaCommand("Add "+child->getName()+" to selected");
				for (unsigned i = 0; i < selection->getNumItems(); i++) {
					osgedit::Selection::ObjectPath &path = selection->getItem(i);
					ClassReflection *parent = path.back().get();
					metaCmd->addSubCommand(new CommandAdd(parent, child));
				}
				try {
					metaCmd->execute();
                    return true;
				} catch (std::exception &e) {
					Gtk::MessageDialog dialog("You can not add " + child->getType() + " inside the selection. Cancelling.", false, Gtk::MESSAGE_WARNING);
					dialog.run();
					try {
						metaCmd->undo();
					} catch (std::exception &e) {
						// IGNORE. We have just warned in the execute :)
					}
                    return false;
				}
			}
		}
	}
};

REGISTER_ACTION_FULL(ActionAddFile, Gtk::Stock::ADD, "Add _from file", "Open a scene file");
