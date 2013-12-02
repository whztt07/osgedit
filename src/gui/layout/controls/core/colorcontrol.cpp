#include <gui/layout/controls/controlfactory.h>
#include "colorcontrol.h"

ColorControl::ColorControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);

	_color = Gtk::manage(new Gtk::ColorButton);
	_color->set_use_alpha(true);
	_color->signal_color_set().connect(sigc::mem_fun(*this, &ColorControl::on_color_set));
}

unsigned ColorControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 1, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_color, 1, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
    return row+1;
}

void ColorControl::apply(ColorProperty *prop) {
    _target = prop;
    refresh();
}

void ColorControl::on_color_set(){
	if (_target.valid()) {
		Gdk::Color rgb = _color->get_color();
		guint16 alpha = _color->get_alpha();
		osg::Vec4 osgcolor(rgb.get_red_p(), rgb.get_green_p(), rgb.get_blue_p(), alpha/65536.0);
        _target->set(osgcolor);
	}
}


void ColorControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void ColorControl::refresh() {
    if (!_target.valid()) return;
	Gdk::Color gdkcolor;
	osg::Vec4 osgcolor = _target->get();
	gdkcolor.set_rgb_p(osgcolor[0], osgcolor[1], osgcolor[2]);
	_color->set_color(gdkcolor);
	_color->set_alpha((guint16)(osgcolor[3]*65535));
}

REGISTER_CONTROL(ColorControl);
