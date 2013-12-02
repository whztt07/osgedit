#ifndef __VEC3D_CONTROL_H__
#define __VEC3D_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/frame.h>
#include <osg/Vec3d>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<osg::Vec3d> Vec3dProperty;

/**
 * Vec3d Control, supports Vec3d properties only
 */
class Vec3dControl: public LayoutControl,
	public Visitor< Vec3dProperty > {
public:
	Vec3dControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(Vec3dProperty *prop);

	void on_set_value(int i);

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_mainLabel;
	Gtk::Label *_labels[3];
	Gtk::SpinButton *_spins[3];
	Gtk::Frame *_frame;
	osg::ref_ptr<Vec3dProperty> _target;
};

#endif//__VEC3D_CONTROL_H__
