#ifndef __TEXT_AREA_CONTROL_H__
#define __TEXT_AREA_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/textview.h>
#include <gtkmm/button.h>
#include <gtkmm/scrolledwindow.h>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<std::string> StringProperty;

/**
 * Text Control, supports std::string properties only
 */
class TextAreaControl: public LayoutControl,
	public Visitor< StringProperty > {
public:
	TextAreaControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(StringProperty *prop);

	void on_activate_text();

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::TextView *_textView;
	Gtk::Button *_updateButton;
	Gtk::ScrolledWindow *_scrolledWindow;
	osg::ref_ptr<StringProperty> _target;
};

#endif//__TEXT_AREA_CONTROL_H__
