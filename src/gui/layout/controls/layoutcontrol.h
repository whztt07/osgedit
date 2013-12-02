#ifndef __LAYOUT_CONTROL_H__
#define __LAYOUT_CONTROL_H__

#include <osg/Referenced>
#include <osg/ref_ptr>
#include <string>
#include <reflection/propertyreflection.h>
#include <osg/Vec4f>
#include <osg/Matrix>
#include <gtkmm/table.h>
#include <common/visitor.h>

/**
 * Layout control abstract superclass.
 *
 * In your subclasses you will need to inherit from the visitor interfaces
 * that you will support. For example:
 *
 * class TextControl: public LayoutControl, public Visitor< TemplateProperty<std::string> > {
 *   void apply(TemplateProperty<std::string> *prop);
 * }
 *
 */
class LayoutControl: public osg::Referenced, public BaseVisitor {
public:
	typedef std::vector< osg::ref_ptr< LayoutControl > > Vector;

	/**
	 * The property being edited may not have a user-friendly name.
	 * This is why we allow to provide a label instead
     */
	virtual void setLabel(const std::string &label) = 0;

	/**
	 * Puts the control in the layout table.
	 * @param table The GTK table
	 * @param row The next free row in the table
     * @return The next row after the render (may have used several rows)
     */
	virtual unsigned render(Gtk::Table *table, unsigned row) = 0;

	/**
	 * Re-read current reflection data
     */
	virtual void refresh() = 0;

	/**
	 * Receives a parameter for this control represented as string and
	 * parses it to use its value. Usefull for giving properties in the
	 * Layout XML file.
     */
	virtual void parseParameter(const std::string &property,const std::string &value) {}
};

#endif//__LAYOUT_CONTROL_H__
