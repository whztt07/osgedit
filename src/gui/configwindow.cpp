#include <common/config.h>
#include <gui/layout/layoutcache.h>
#include <gtkmm/stock.h>
#include "configwindow.h"

ConfigWindow::ConfigWindow():
	_buttonBox(Gtk::BUTTONBOX_END),
	_close(Gtk::Stock::CLOSE),
	_hAdj(0,0,0),
	_vAdj(0,0,0),
	_viewPort(_hAdj, _vAdj)
{
    set_title("OSGEdit configuration");
    set_size_request(300,300);
    set_border_width(5);
	add(_vBox);
	_vBox.pack_start(_scroll, true, true);
	_vBox.pack_start(_buttonBox, false, true);
    _buttonBox.pack_start(_close);
	_scroll.add(_viewPort);
	_scroll.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	osg::ref_ptr<Layout> layout = LayoutCache::instance()->get(osgedit::Config::instance());
	_viewPort.add(*layout->getWidget());
    _viewPort.set_border_width(4);
	_viewPort.set_shadow_type(Gtk::SHADOW_NONE);

	_vBox.show_all();
	_close.signal_clicked().connect(sigc::mem_fun(*this, &ConfigWindow::hide));
}

ConfigWindow *ConfigWindow::instance() {
    static ConfigWindow *_instance = new ConfigWindow;
    return _instance;
}
