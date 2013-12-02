#ifndef __ENUM_CONTROL_H__
#define __ENUM_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/comboboxtext.h>
#include <gui/layout/controls/layoutcontrol.h>

/**
 * Enum Control, supports enumeration properties only
 */
class EnumControl: public LayoutControl,
	public Visitor< EnumProperty > {
public:
	EnumControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(EnumProperty *prop);

	void on_changed();

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::ComboBoxText *_combo;
	osg::ref_ptr<EnumProperty> _target;
	sigc::connection _changedConnection;
};

#endif//__ENUM_CONTROL_H__
