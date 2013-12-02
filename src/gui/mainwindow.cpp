#include <gtkmm/uimanager.h>
#include <actions/actionfactory.h>
#include "osgviewport.h"
#include "reflectioneditor.h"
#include "control3dmanager.h"
#include "mainwindow.h"

#define INTERFACE_FILE DATA_DIR"/osgedit.ui"

MainWindow::MainWindow() {
    set_size_request(800,600);
    setTitleFileName("");
	_actions = Gtk::ActionGroup::create();
    createMenuBarActions();


	Glib::RefPtr<Gtk::UIManager> uiManager = Gtk::UIManager::create();
	uiManager->insert_action_group(_actions);
	uiManager->insert_action_group(ActionFactory::instance()->getActions());
	add_accel_group(uiManager->get_accel_group());

    uiManager->add_ui_from_file(INTERFACE_FILE);

	Gtk::Widget *menubar = uiManager->get_widget("/MenuBar");
	Gtk::Widget *toolbar = uiManager->get_widget("/ToolBar");

	_vBoxMain.pack_start(*menubar, Gtk::PACK_SHRINK);
	_vBoxMain.pack_start(*toolbar, Gtk::PACK_SHRINK);
	_vBoxMain.pack_start(_hPaned, true, true);

	_hPaned.add1(*OSGViewport::instance());

	_hPaned.add2(_vBoxPanels);

	_treeScroll.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
    _treeScroll.add(_tree);

    _vPanedPanels.add1(_treeScroll);
    _vPanedPanels.add2(*ReflectionEditor::instance());

	_vBoxPanels.pack_start(_vPanedPanels, true, true);
	_vBoxPanels.pack_start(*Control3DManager::instance(), false, true);

    add(_vBoxMain);

	show_all();
}

MainWindow *MainWindow::instance() {
	static MainWindow *_instance = new MainWindow;
    return _instance;
}


void MainWindow::createMenuBarActions() {
	_actions->add( Gtk::Action::create("FileMenu", "File") );
	_actions->add( Gtk::Action::create("EditMenu", "Edit") );
	_actions->add( Gtk::Action::create("ViewMenu", "View") );
	_actions->add( Gtk::Action::create("AddMenu", "Add") );
	_actions->add( Gtk::Action::create("GroupMenu", "Group") );
	_actions->add( Gtk::Action::create("GeodeMenu", "Geode") );
	_actions->add( Gtk::Action::create("DrawableMenu", "Drawable") );
	_actions->add( Gtk::Action::create("ShapeMenu", "Shape") );
	_actions->add( Gtk::Action::create("StateAttributeMenu", "StateAttribute") );
	_actions->add( Gtk::Action::create("StateAttributeNormalMenu", "Normal") );
	_actions->add( Gtk::Action::create("StateAttributeTextureMenu", "Texture") );
}

void MainWindow::setSceneRoot(osg::Node *root) {
	_tree.setRoot(root);
	OSGViewport::instance()->setSceneRoot(root);
}

void MainWindow::setTitleFileName(const std::string &filename) {
	std::string filepart = filename;
	if (filename == "") {
        filepart = "Empty scene";
	}
    set_title("OSGEdit - "+filepart);
}

bool MainWindow::on_delete_event(GdkEventAny* event) {
	ActionFactory::instance()->run("ActionExit");
	return true;
}
