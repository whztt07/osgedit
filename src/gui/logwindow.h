#ifndef __LOG_WINDOW_H__
#define __LOG_WINDOW_H__

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/textview.h>
#include <common/log.h>
#include "export.h"

/**
 * Window that displays the log messages
 */
class GUI_EXPORT LogWindow: public Gtk::Window, public Log::Impl {
public:
	static LogWindow *instance();

	void log(const std::string &msg, Log::Level level);
protected:
    LogWindow();

    void on_clear();
private:
	Gtk::TextView _textView;
	Gtk::VBox _vBox;
	Gtk::HButtonBox _buttonBox;
	Gtk::Button _clear;
	Gtk::Button _close;
};

#endif
