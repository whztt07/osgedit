#include <reflection/reflectionregistry.h>
#include <osg/ShapeDrawable>
#include <stdexcept>

/**
 * Reflector of class osg::ShapeDrawable
 */
class RefosgShapeDrawable: public ClassReflection {
public:
	RefosgShapeDrawable();
	virtual osg::Object *getObject() { return _object.get(); }
	virtual void setObject(osg::Object *obj);
	virtual const std::string &getType() const { return _class_name; }
	virtual const std::string &getOSGVersion() const { return _osg_version; }
	virtual const std::string &getDescription() const { return _class_description; }
	virtual unsigned getNumProperties() const { return _names.size(); }
	virtual const PropertyNames &getPropertyNames() { return _names; }
	virtual void addChild(osg::Object *child);
	virtual void removeChild(osg::Object *child);
	virtual unsigned getNumChildren();
	virtual osg::Object *getChildObject(unsigned i);
	virtual PropertyReflection *getProperty(const std::string &name);
	virtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col);
	virtual unsigned getNumTablePropertyColumns(const std::string &name);
	virtual unsigned getNumTablePropertyRows(const std::string &name);
	virtual const PropertyNames &getTablePropertyNames() { return _table_names; }
	virtual const PropertyNames getTablePropertyColumnTitles(const std::string &name);
	virtual const PropertyNames getTablePropertyRowTitles(const std::string &name);
private:
	osg::ref_ptr<osg::ShapeDrawable> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_supportsDisplayList","_useDisplayList","_initialBound","_userData","_useVertexBufferObjects","_drawCallback","_updateCallback","_color","_cullCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgShapeDrawable::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgShapeDrawable::_table_names;

std::string RefosgShapeDrawable::_class_name("osg::ShapeDrawable");

std::string RefosgShapeDrawable::_class_description(" Allow the use of Shapes as Drawables, so that they can be rendered with reduced effort. The implementation of ShapeDrawable is not geared to efficiency; it's better to think of it as a convenience to render Shapes easily (perhaps for test or debugging purposes) than as the right way to render basic shapes in some efficiency-critical section of code. TodoShapeDrawable currently doesn't render InfinitePlanes.     ");

std::string RefosgShapeDrawable::_osg_version("1.2");


/**********************************************************/
RefosgShapeDrawable::RefosgShapeDrawable() {
}

/**********************************************************/
void RefosgShapeDrawable::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::ShapeDrawable*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osg;

/**********************************************************/
void RefosgShapeDrawable::addChild(osg::Object *child) {
	{TessellationHints *cobj = dynamic_cast<TessellationHints *>(child);
	if (cobj != 0) {
		_object->setTessellationHints(cobj);
		return;
	}}
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(cobj);
		_object->dirtyDisplayList();
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShapeDrawable::removeChild(osg::Object *child) {
	{TessellationHints *cobj = dynamic_cast<TessellationHints *>(child);
	if (cobj != 0) {
		_object->setTessellationHints(0);
		return;
	}}
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShapeDrawable::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getTessellationHints();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getShape();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShapeDrawable::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShapeDrawable::getProperty(const std::string &name) {
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osg::ShapeDrawable::getSupportsDisplayList, &osg::ShapeDrawable::setSupportsDisplayList);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osg::ShapeDrawable::getUseDisplayList, &osg::ShapeDrawable::setUseDisplayList);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osg::ShapeDrawable::getInitialBound, &osg::ShapeDrawable::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::ShapeDrawable::getUserData, &osg::ShapeDrawable::setUserData);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useVertexBufferObjects", _object.get(), &osg::ShapeDrawable::getUseVertexBufferObjects, &osg::ShapeDrawable::setUseVertexBufferObjects);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::ShapeDrawable::getDataVariance, &osg::ShapeDrawable::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osg::ShapeDrawable::getDrawCallback, &osg::ShapeDrawable::setDrawCallback);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::ShapeDrawable::getUpdateCallback, &osg::ShapeDrawable::setUpdateCallback);
	}
	if (name == "_color") {
		// Getter overloaded, must specify one type
		typedef const Vec4 & (osg::ShapeDrawable::*getColorFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::ShapeDrawable::*setColorFN)(const Vec4 &) ;
		return new GetterSetterProperty<Vec4, osg::ShapeDrawable>("_color", _object.get(), (getColorFN)&osg::ShapeDrawable::getColor, (setColorFN)&osg::ShapeDrawable::setColor);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osg::ShapeDrawable::getCullCallback, &osg::ShapeDrawable::setCullCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::ShapeDrawable::getName, (setNameFN)&osg::ShapeDrawable::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::ShapeDrawable::getEventCallback, &osg::ShapeDrawable::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShapeDrawable::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShapeDrawable::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShapeDrawable::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShapeDrawable::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShapeDrawable::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::ShapeDrawable, RefosgShapeDrawable> _registerRefosgShapeDrawable;
