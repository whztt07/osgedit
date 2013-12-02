#include <reflection/reflectionregistry.h>
#include <osg/ClipPlane>
#include <stdexcept>

/**
 * Reflector of class osg::ClipPlane
 */
class RefosgClipPlane: public ClassReflection {
public:
	RefosgClipPlane();
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
	osg::ref_ptr<osg::ClipPlane> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_clipPlane","_userData","_updateCallback","_clipPlaneNum","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgClipPlane::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgClipPlane::_table_names;

std::string RefosgClipPlane::_class_name("osg::ClipPlane");

std::string RefosgClipPlane::_class_description(" Encapsulates OpenGL glClipPlane().     ");

std::string RefosgClipPlane::_osg_version("1.2");


/**********************************************************/
RefosgClipPlane::RefosgClipPlane() {
}

/**********************************************************/
void RefosgClipPlane::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::ClipPlane*>(obj);
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
void RefosgClipPlane::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgClipPlane::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgClipPlane::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgClipPlane::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgClipPlane::getProperty(const std::string &name) {
	if (name == "_clipPlane") {
		// Setter overloaded, must specify one type
		typedef void (osg::ClipPlane::*setClipPlaneFN)(const Vec4d &) ;
		return new GetterSetterProperty<Vec4d, osg::ClipPlane>("_clipPlane", _object.get(), &osg::ClipPlane::getClipPlane, (setClipPlaneFN)&osg::ClipPlane::setClipPlane);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::ClipPlane::getUserData, &osg::ClipPlane::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::ClipPlane::getDataVariance, &osg::ClipPlane::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::ClipPlane::getUpdateCallback, &osg::ClipPlane::setUpdateCallback);
	}
	if (name == "_clipPlaneNum") {
		return new GetterSetterProperty<unsigned int, osg::ClipPlane>("_clipPlaneNum", _object.get(), &osg::ClipPlane::getClipPlaneNum, &osg::ClipPlane::setClipPlaneNum);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::ClipPlane::getName, (setNameFN)&osg::ClipPlane::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::ClipPlane::getEventCallback, &osg::ClipPlane::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgClipPlane::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgClipPlane::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgClipPlane::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgClipPlane::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgClipPlane::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::ClipPlane, RefosgClipPlane> _registerRefosgClipPlane;
