#include <reflection/reflectionregistry.h>
#include <osg/Shape>
#include <stdexcept>

/**
 * Reflector of class osg::Cone
 */
class RefosgCone: public ClassReflection {
public:
	RefosgCone();
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
	osg::ref_ptr<osg::Cone> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rotation","_userData","_height","_center","_radius","_dataVariance"};
ClassReflection::PropertyNames RefosgCone::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgCone::_table_names;

std::string RefosgCone::_class_name("osg::Cone");

std::string RefosgCone::_class_description("     ");

std::string RefosgCone::_osg_version("1.2");


/**********************************************************/
RefosgCone::RefosgCone() {
}

/**********************************************************/
void RefosgCone::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Cone*>(obj);
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
void RefosgCone::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgCone::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgCone::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgCone::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgCone::getProperty(const std::string &name) {
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::Cone::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cone::*setRotationFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::Cone>("_rotation", _object.get(), (getRotationFN)&osg::Cone::getRotation, (setRotationFN)&osg::Cone::setRotation);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Cone::getUserData, &osg::Cone::setUserData);
	}
	if (name == "_height") {
		// Getter overloaded, must specify one type
		typedef float (osg::Cone::*getHeightFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cone::*setHeightFN)(float) ;
		return new GetterSetterProperty<float, osg::Cone>("_height", _object.get(), (getHeightFN)&osg::Cone::getHeight, (setHeightFN)&osg::Cone::setHeight);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Cone::getDataVariance, &osg::Cone::setDataVariance, osg_object_datavariance);
	}
	if (name == "_center") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Cone::*getCenterFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cone::*setCenterFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Cone>("_center", _object.get(), (getCenterFN)&osg::Cone::getCenter, (setCenterFN)&osg::Cone::setCenter);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Cone::getName, (setNameFN)&osg::Cone::setName);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::Cone::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Cone::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::Cone>("_radius", _object.get(), (getRadiusFN)&osg::Cone::getRadius, (setRadiusFN)&osg::Cone::setRadius);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCone::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCone::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCone::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCone::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCone::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Cone, RefosgCone> _registerRefosgCone;
