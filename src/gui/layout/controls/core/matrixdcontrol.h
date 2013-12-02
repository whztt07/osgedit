#ifndef __MATRIXD_CONTROL_H__
#define __MATRIXD_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/table.h>
#include <osg/Matrixd>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<osg::Matrixd> MatrixdProperty;

/**
 * Matrixd Control, supports Matrixd properties only
 */
class MatrixdControl: public LayoutControl,
	public Visitor< MatrixdProperty > {
public:
	MatrixdControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(MatrixdProperty *prop);

	void on_set_value(Gtk::SpinButton *spin, unsigned x, unsigned y);

	void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::SpinButton *_spins[16];
	Gtk::Table *_table;
	osg::ref_ptr<MatrixdProperty> _target;
};

#endif//__MATRIXD_CONTROL_H__
