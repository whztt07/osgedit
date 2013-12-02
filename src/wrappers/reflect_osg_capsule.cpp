#include <reflection/reflectionregistry.h>
#include <osg/Shape>
#include <stdexcept>

/**
 * Reflector of class osg::Capsule
 */
class RefosgCapsule: public ClassReflection {
public:
	RefosgCapsule();
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
	osg::ref_ptr<osg::Capsule> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rotation","_userData","_height","_center","_radius","_dataVariance"};
ClassReflection::PropertyNames RefosgCapsule::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgCapsule::_table_names;

std::string RefosgCapsule::_class_name("osg::Capsule");

std::string RefosgCapsule::_class_description("     ");

std::string RefosgCapsule::_osg_version("1.2");


/**********************************************************/
RefosgCapsule::RefosgCapsule() {
}

/**********************************************************/
void RefosgCapsule::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Capsule*>(obj);
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
void RefosgCapsule::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgCapsule::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgCapsule::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgCapsule::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgCapsule::getProperty(const std::string &name) {
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::Capsule::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Capsule::*setRotationFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::Capsule>("_rotation", _object.get(), (getRotationFN)&osg::Capsule::getRotation, (setRotationFN)&osg::Capsule::setRotation);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Capsule::getUserData, &osg::Capsule::setUserData);
	}
	if (name == "_height") {
		// Getter overloaded, must specify one type
		typedef float (osg::Capsule::*getHeightFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Capsule::*setHeightFN)(float) ;
		return new GetterSetterProperty<float, osg::Capsule>("_height", _object.get(), (getHeightFN)&osg::Capsule::getHeight, (setHeightFN)&osg::Capsule::setHeight);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Capsule::getDataVariance, &osg::Capsule::setDataVariance, osg_object_datavariance);
	}
	if (name == "_center") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Capsule::*getCenterFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Capsule::*setCenterFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Capsule>("_center", _object.get(), (getCenterFN)&osg::Capsule::getCenter, (setCenterFN)&osg::Capsule::setCenter);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Capsule::getName, (setNameFN)&osg::Capsule::setName);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::Capsule::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Capsule::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::Capsule>("_radius", _object.get(), (getRadiusFN)&osg::Capsule::getRadius, (setRadiusFN)&osg::Capsule::setRadius);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCapsule::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCapsule::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCapsule::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCapsule::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCapsule::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Capsule, RefosgCapsule> _registerRefosgCapsule;
