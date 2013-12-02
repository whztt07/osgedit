#include "logwindow.h"
#include <gtkmm/stock.h>

LogWindow::LogWindow(): _buttonBox(Gtk::BUTTONBOX_END), _clear(Gtk::Stock::CLEAR), _close(Gtk::Stock::CLOSE) {
    set_title("OSGEdit Log");
    set_size_request(400,300);
	add(_vBox);
    _vBox.pack_start(_textView, true, true);
    _vBox.pack_start(_buttonBox, false, true, 5);

    _buttonBox.pack_start(_clear, false, false);
    _buttonBox.pack_start(_close, false, false);
    _buttonBox.set_child_ipadding_x(5);
    _buttonBox.set_spacing(5);

	_textView.set_wrap_mode(Gtk::WRAP_WORD);
	_textView.set_pixels_below_lines(5);
	_textView.set_editable(false);
	_textView.set_cursor_visible(false);

	Glib::RefPtr<Gtk::TextTag> tag = _textView.get_buffer()->create_tag("info");
	tag = _textView.get_buffer()->create_tag("warning");
    tag->property_foreground() = "blue";
	tag->property_style() = Pango::STYLE_ITALIC;
    tag = _textView.get_buffer()->create_tag("error");
    tag->property_foreground() = "red";
	tag->property_weight() = Pango::WEIGHT_BOLD;

	_clear.signal_clicked().connect(sigc::mem_fun(*this, &LogWindow::on_clear));
	_close.signal_clicked().connect(sigc::mem_fun(*this, &LogWindow::hide));

	_vBox.show_all();
}

LogWindow *LogWindow::instance() {
	static LogWindow *_instance = new LogWindow;
    return _instance;
}

void LogWindow::log(const std::string &msg, Log::Level level) {
	Gtk::TextIter iter = _textView.get_buffer()->end();
	switch (level) {
	case Log::INFO:
		_textView.get_buffer()->insert_with_tag(iter, "INFO: "+msg+"\n", "info");
        break;
	case Log::WARNING:
		_textView.get_buffer()->insert_with_tag(iter, "WARNING: "+msg+"\n", "warning");
        break;
	case Log::ERROR:
		_textView.get_buffer()->insert_with_tag(iter, "ERROR: "+msg+"\n", "error");
        break;
	}
}

void LogWindow::on_clear() {
    _textView.get_buffer()->erase(_textView.get_buffer()->begin(),_textView.get_buffer()->end());
}
