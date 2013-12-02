#include <reflection/reflectionregistry.h>
#include <osg/DrawPixels>
#include <stdexcept>

/**
 * Reflector of class osg::DrawPixels
 */
class RefosgDrawPixels: public ClassReflection {
public:
	RefosgDrawPixels();
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
	osg::ref_ptr<osg::DrawPixels> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_supportsDisplayList","_useDisplayList","_initialBound","_userData","_cullCallback","_drawCallback","_updateCallback","_useVertexBufferObjects","_useSubImage","_eventCallback","_position","_dataVariance"};
ClassReflection::PropertyNames RefosgDrawPixels::_names(_propnames, _propnames+13);

ClassReflection::PropertyNames RefosgDrawPixels::_table_names;

std::string RefosgDrawPixels::_class_name("osg::DrawPixels");

std::string RefosgDrawPixels::_class_description(" DrawPixels is an osg::Drawable subclass which encapsulates the drawing of images using glDrawPixels.     ");

std::string RefosgDrawPixels::_osg_version("1.2");


/**********************************************************/
RefosgDrawPixels::RefosgDrawPixels() {
}

/**********************************************************/
void RefosgDrawPixels::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::DrawPixels*>(obj);
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
void RefosgDrawPixels::addChild(osg::Object *child) {
	{osg::Image *cobj = dynamic_cast<osg::Image *>(child);
	if (cobj != 0) {
		_object->setImage(cobj);
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
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgDrawPixels::removeChild(osg::Object *child) {
	{osg::Image *cobj = dynamic_cast<osg::Image *>(child);
	if (cobj != 0) {
		_object->setImage(0);
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
osg::Object *RefosgDrawPixels::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getImage();
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
unsigned RefosgDrawPixels::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgDrawPixels::getProperty(const std::string &name) {
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osg::DrawPixels::getSupportsDisplayList, &osg::DrawPixels::setSupportsDisplayList);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osg::DrawPixels::getUseDisplayList, &osg::DrawPixels::setUseDisplayList);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osg::DrawPixels::getInitialBound, &osg::DrawPixels::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::DrawPixels::getUserData, &osg::DrawPixels::setUserData);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osg::DrawPixels::getCullCallback, &osg::DrawPixels::setCullCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::DrawPixels::getDataVariance, &osg::DrawPixels::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osg::DrawPixels::getDrawCallback, &osg::DrawPixels::setDrawCallback);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::DrawPixels::getUpdateCallback, &osg::DrawPixels::setUpdateCallback);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useVertexBufferObjects", _object.get(), &osg::DrawPixels::getUseVertexBufferObjects, &osg::DrawPixels::setUseVertexBufferObjects);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::DrawPixels::getName, (setNameFN)&osg::DrawPixels::setName);
	}
	if (name == "_useSubImage") {
		return new GetterSetterProperty<bool, osg::DrawPixels>("_useSubImage", _object.get(), &osg::DrawPixels::getUseSubImage, &osg::DrawPixels::setUseSubImage);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::DrawPixels::getEventCallback, &osg::DrawPixels::setEventCallback);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef osg::Vec3 & (osg::DrawPixels::*getPositionFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::DrawPixels::*setPositionFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::DrawPixels>("_position", _object.get(), (getPositionFN)&osg::DrawPixels::getPosition, (setPositionFN)&osg::DrawPixels::setPosition);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawPixels::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawPixels::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgDrawPixels::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawPixels::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawPixels::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::DrawPixels, RefosgDrawPixels> _registerRefosgDrawPixels;
