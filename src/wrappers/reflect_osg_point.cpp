#include <reflection/reflectionregistry.h>
#include <osg/Point>
#include <stdexcept>

/**
 * Reflector of class osg::Point
 */
class RefosgPoint: public ClassReflection {
public:
	RefosgPoint();
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
	osg::ref_ptr<osg::Point> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_distanceAttenuation","_userData","_updateCallback","_maxSize","_size","_fadeThresholdSize","_minSize","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgPoint::_names(_propnames, _propnames+10);

ClassReflection::PropertyNames RefosgPoint::_table_names;

std::string RefosgPoint::_class_name("osg::Point");

std::string RefosgPoint::_class_description(" Point - encapsulates the OpenGL point smoothing and size state.     ");

std::string RefosgPoint::_osg_version("1.2");


/**********************************************************/
RefosgPoint::RefosgPoint() {
}

/**********************************************************/
void RefosgPoint::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Point*>(obj);
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
void RefosgPoint::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgPoint::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgPoint::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgPoint::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgPoint::getProperty(const std::string &name) {
	if (name == "_distanceAttenuation") {
		return new GetterSetterProperty<Vec3, osg::Point>("_distanceAttenuation", _object.get(), &osg::Point::getDistanceAttenuation, &osg::Point::setDistanceAttenuation);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Point::getUserData, &osg::Point::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Point::getName, (setNameFN)&osg::Point::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Point::getDataVariance, &osg::Point::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Point::getUpdateCallback, &osg::Point::setUpdateCallback);
	}
	if (name == "_maxSize") {
		return new GetterSetterProperty<float, osg::Point>("_maxSize", _object.get(), &osg::Point::getMaxSize, &osg::Point::setMaxSize);
	}
	if (name == "_size") {
		// Getter overloaded, must specify one type
		typedef float (osg::Point::*getSizeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Point::*setSizeFN)(float) ;
		return new GetterSetterProperty<float, osg::Point>("_size", _object.get(), (getSizeFN)&osg::Point::getSize, (setSizeFN)&osg::Point::setSize);
	}
	if (name == "_fadeThresholdSize") {
		return new GetterSetterProperty<float, osg::Point>("_fadeThresholdSize", _object.get(), &osg::Point::getFadeThresholdSize, &osg::Point::setFadeThresholdSize);
	}
	if (name == "_minSize") {
		return new GetterSetterProperty<float, osg::Point>("_minSize", _object.get(), &osg::Point::getMinSize, &osg::Point::setMinSize);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Point::getEventCallback, &osg::Point::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgPoint::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgPoint::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgPoint::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPoint::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPoint::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Point, RefosgPoint> _registerRefosgPoint;
