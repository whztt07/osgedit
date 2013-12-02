#ifndef __CHECK_CONTROL_H__
#define __CHECK_CONTROL_H__

#include <gtkmm/checkbutton.h>
#include <gtkmm/label.h>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<bool> BoolProperty;

/**
 * Check Control, supports bool properties only and renders a check button
 */
class CheckControl: public LayoutControl,
	public Visitor< BoolProperty > {
public:
	CheckControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(BoolProperty *prop);

	void on_check_toggled();

	void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::CheckButton *_check;
	osg::ref_ptr<BoolProperty> _target;
};

#endif//__CHECK_CONTROL_H__
