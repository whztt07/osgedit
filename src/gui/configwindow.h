#ifndef __CONFIG_WINDOW_H__
#define __CONFIG_WINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/viewport.h>
#include <gtkmm/scrolledwindow.h>
#include "export.h"
/**
 * Configuration editor
 */
class GUI_EXPORT ConfigWindow: public Gtk::Window {
public:
    static ConfigWindow *instance();
private:
    ConfigWindow();
	Gtk::VBox _vBox;
	Gtk::HButtonBox _buttonBox;
	Gtk::Button _close;
	Gtk::ScrolledWindow _scroll;

	Gtk::Adjustment _hAdj;
	Gtk::Adjustment _vAdj;
	Gtk::Viewport _viewPort;
};

#endif//__CONFIG_WINDOW_H__
