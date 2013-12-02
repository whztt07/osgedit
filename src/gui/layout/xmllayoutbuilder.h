#ifndef __XML_LAYOUT_BUILDER_H__
#define __XML_LAYOUT_BUILDER_H__

#include <reflection/classreflection.h>
#include "layout.h"
#include <common/visitor.h>
#include <osg/Vec4f>
#include <osg/Matrixd>
#include <osgText/String>
#include <libxml++/libxml++.h>

#include "export.h"

typedef TemplateProperty< std::string > StringProperty;
typedef TemplateProperty< osgText::String > osgStringProperty;
typedef TemplateProperty< bool > BoolProperty;
typedef TemplateProperty< int > IntProperty;
typedef TemplateProperty< float > FloatProperty;
typedef TemplateProperty< double > DoubleProperty;
typedef TemplateProperty< osg::Vec4f > ColorProperty;
typedef TemplateProperty< osg::Vec3d > Vec3dProperty;
typedef TemplateProperty< osg::Matrixd > MatrixdProperty;


class LAY_EXPORT XmlLayoutBuilder: public BaseVisitor,
	public Visitor< StringProperty >,
	public Visitor< osgStringProperty >,
	public Visitor< BoolProperty >,
	public Visitor< IntProperty >,
	public Visitor< FloatProperty >,
	public Visitor< DoubleProperty >,
	public Visitor< ColorProperty >,
	public Visitor< EnumProperty >,
	public Visitor< Vec3dProperty >,
	public Visitor< MatrixdProperty > {
public:
	XmlLayoutBuilder();

	void apply(ClassReflection *cref);

	void apply(StringProperty *prop);
	void apply(osgStringProperty *prop);
	void apply(BoolProperty *prop);
	void apply(IntProperty *prop);
	void apply(FloatProperty *prop);
	void apply(DoubleProperty *prop);
	void apply(ColorProperty *prop);
	void apply(EnumProperty *prop);
	void apply(Vec3dProperty *prop);
	void apply(MatrixdProperty *prop);

	Layout *getLayout() { return _layout.get(); }
protected:
    void addControl(const std::string &controlName, PropertyReflection *prop);
	void process(xmlpp::Element *node);
private:
	osg::ref_ptr<Layout> _layout; ///< Generated Layout
};

#endif//__XML_LAYOUT_BUILDER_H__
