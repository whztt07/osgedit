#ifndef __OSGEDIT_MAIN_WINDOW_H__
#define __OSGEDIT_MAIN_WINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/box.h>
#include <gtkmm/paned.h>
#include <gtkmm/scrolledwindow.h>
#include "objecttree.h"
#include "export.h"

class GUI_EXPORT MainWindow: public Gtk::Window {
public:
    static MainWindow *instance();

	void setSceneRoot(osg::Node *root);

	void setTitleFileName(const std::string &filename);

	ObjectTree &getTree() { return _tree; }
protected:
    bool on_delete_event(GdkEventAny* event);
private:
	MainWindow();
    void createMenuBarActions();
	Gtk::VBox _vBoxMain;
	Gtk::VBox _vBoxPanels;
	Gtk::HPaned _hPaned;
	Gtk::VPaned _vPanedPanels;
	Glib::RefPtr<Gtk::ActionGroup> _actions;
	ObjectTree _tree;
	Gtk::ScrolledWindow _treeScroll;
};

#endif//__OSGEDIT_MAIN_WINDOW_H__
