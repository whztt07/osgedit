#ifndef __COLOR_CONTROL_H__
#define __COLOR_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/colorbutton.h>
#include <osg/Vec4>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<osg::Vec4> ColorProperty;

/**
 * Color Control, supports osg::Vec4 properties only
 */
class ColorControl: public LayoutControl,
	public Visitor< ColorProperty > {
public:
	ColorControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(ColorProperty *prop);

	void on_color_set();

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::ColorButton *_color;
	osg::ref_ptr<ColorProperty> _target;
};

#endif//__COLOR_CONTROL_H__
