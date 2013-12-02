#ifndef __STATS_WINDOW_H__
#define __STATS_WINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/table.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include "export.h"
#include <osg/Node>

#define NUM_STATS 5

/**
 * Window displaying all the statistics
 */
class GUI_EXPORT StatsWindow: public Gtk::Window {
public:
	StatsWindow(osg::Node *node);

    void on_delete_event();
private:
	Gtk::Table _table;
	Gtk::Label _statHeader;
	Gtk::Label _uniqueHeader;
	Gtk::Label _instancedHeader;

	Gtk::Label _statLabels[NUM_STATS];
	Gtk::Label _uniqueStats[NUM_STATS];
	Gtk::Label _instancedStats[NUM_STATS];
	Gtk::VBox _vBox;
	Gtk::HButtonBox _buttonBox;
	Gtk::Button _close;
};

#endif//__STATS_WINDOW_H__
