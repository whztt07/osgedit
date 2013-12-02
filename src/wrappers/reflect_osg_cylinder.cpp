#include <reflection/reflectionregistry.h>
#include <osg/Shape>
#include <stdexcept>

/**
 * Reflector of class osg::Cylinder
 */
class RefosgCylinder: public ClassReflection {
public:
	RefosgCylinder();
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
	osg::ref_ptr<osg::Cylinder> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rotation","_userData","_height","_center","_radius","_dataVariance"};
ClassReflection::PropertyNames RefosgCylinder::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgCylinder::_table_names;

std::string RefosgCylinder::_class_name("osg::Cylinder");

std::string RefosgCylinder::_class_description("     ");

std::string RefosgCylinder::_osg_version("1.2");


/**********************************************************/
RefosgCylinder::RefosgCylinder() {
}

/**********************************************************/
void RefosgCylinder::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Cylinder*>(obj);
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
void RefosgCylinder::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgCylinder::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgCylinder::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgCylinder::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgCylinder::getProperty(const std::string &name) {
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::Cylinder::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cylinder::*setRotationFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::Cylinder>("_rotation", _object.get(), (getRotationFN)&osg::Cylinder::getRotation, (setRotationFN)&osg::Cylinder::setRotation);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Cylinder::getUserData, &osg::Cylinder::setUserData);
	}
	if (name == "_height") {
		// Getter overloaded, must specify one type
		typedef float (osg::Cylinder::*getHeightFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cylinder::*setHeightFN)(float) ;
		return new GetterSetterProperty<float, osg::Cylinder>("_height", _object.get(), (getHeightFN)&osg::Cylinder::getHeight, (setHeightFN)&osg::Cylinder::setHeight);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Cylinder::getName, (setNameFN)&osg::Cylinder::setName);
	}
	if (name == "_center") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Cylinder::*getCenterFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cylinder::*setCenterFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Cylinder>("_center", _object.get(), (getCenterFN)&osg::Cylinder::getCenter, (setCenterFN)&osg::Cylinder::setCenter);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Cylinder::getDataVariance, &osg::Cylinder::setDataVariance, osg_object_datavariance);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::Cylinder::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cylinder::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::Cylinder>("_radius", _object.get(), (getRadiusFN)&osg::Cylinder::getRadius, (setRadiusFN)&osg::Cylinder::setRadius);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCylinder::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCylinder::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCylinder::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCylinder::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCylinder::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Cylinder, RefosgCylinder> _registerRefosgCylinder;
