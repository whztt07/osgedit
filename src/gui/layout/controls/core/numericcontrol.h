#ifndef __NUMERIC_CONTROL_H__
#define __NUMERIC_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/spinbutton.h>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<int> IntProperty;
typedef TemplateProperty<float> FloatProperty;
typedef TemplateProperty<double> DoubleProperty;

/**
 * Numeric Control, supports int, float and double properties
 */
class NumericControl: public LayoutControl,
	public Visitor< IntProperty >,
	public Visitor< FloatProperty >,
	public Visitor< DoubleProperty > {
public:
	NumericControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(IntProperty *prop);
	void apply(FloatProperty *prop);
	void apply(DoubleProperty *prop);

	void on_value_changed();

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::SpinButton *_spin;
	osg::ref_ptr<IntProperty> _intTarget;
	osg::ref_ptr<FloatProperty> _floatTarget;
	osg::ref_ptr<DoubleProperty> _doubleTarget;
};

#endif//__NUMERIC_CONTROL_H__
