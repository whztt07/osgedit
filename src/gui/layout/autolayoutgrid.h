#ifndef __AUTO_LAYOUT_GRID_H__
#define __AUTO_LAYOUT_GRID_H__

#include <reflection/classreflection.h>
#include <common/visitor.h>
#include <osg/Vec4f>
#include "layoutgrid.h"
#include "export.h"

typedef TemplateProperty< std::string > StringProperty;
typedef TemplateProperty< bool > BoolProperty;
typedef TemplateProperty< int > IntProperty;
typedef TemplateProperty< float > FloatProperty;
typedef TemplateProperty< double > DoubleProperty;
typedef TemplateProperty< osg::Vec4f > ColorProperty;


/**
 * Automatic layout generator
 */
class LAY_EXPORT AutoLayoutGrid: public BaseVisitor,
	public Visitor< StringProperty >,
	public Visitor< BoolProperty >,
	public Visitor< IntProperty >,
	public Visitor< FloatProperty >,
	public Visitor< DoubleProperty >,
	public Visitor< ColorProperty >,
	public Visitor< EnumProperty >
{

public:
	AutoLayoutGrid(){}

	void apply(ClassReflection *cref, const std::string &tableProperty);

	void apply(StringProperty *prop);
	void apply(BoolProperty *prop);
	void apply(IntProperty *prop);
	void apply(FloatProperty *prop);
	void apply(DoubleProperty *prop);
	void apply(ColorProperty *prop);
	void apply(EnumProperty *prop);

	LayoutGrid *getGrid() { return _grid.get(); }
private:
	osg::ref_ptr<LayoutGrid> _grid; ///< Generated grid
	unsigned _lastColumn; ///< Last visited column
	std::string _lastName; ///< Last visited column name
};

#endif//__AUTO_LAYOUT_GRID_H__
