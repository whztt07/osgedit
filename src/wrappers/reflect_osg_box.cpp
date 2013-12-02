#include <reflection/reflectionregistry.h>
#include <osg/Shape>
#include <stdexcept>

/**
 * Reflector of class osg::Box
 */
class RefosgBox: public ClassReflection {
public:
	RefosgBox();
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
	osg::ref_ptr<osg::Box> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rotation","_userData","_center","_halfLengths","_dataVariance"};
ClassReflection::PropertyNames RefosgBox::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgBox::_table_names;

std::string RefosgBox::_class_name("osg::Box");

std::string RefosgBox::_class_description("     ");

std::string RefosgBox::_osg_version("1.2");


/**********************************************************/
RefosgBox::RefosgBox() {
}

/**********************************************************/
void RefosgBox::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Box*>(obj);
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
void RefosgBox::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgBox::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgBox::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgBox::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgBox::getProperty(const std::string &name) {
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::Box::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Box::*setRotationFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::Box>("_rotation", _object.get(), (getRotationFN)&osg::Box::getRotation, (setRotationFN)&osg::Box::setRotation);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Box::getUserData, &osg::Box::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Box::getDataVariance, &osg::Box::setDataVariance, osg_object_datavariance);
	}
	if (name == "_center") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Box::*getCenterFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Box::*setCenterFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Box>("_center", _object.get(), (getCenterFN)&osg::Box::getCenter, (setCenterFN)&osg::Box::setCenter);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Box::getName, (setNameFN)&osg::Box::setName);
	}
	if (name == "_halfLengths") {
		return new GetterSetterProperty<Vec3, osg::Box>("_halfLengths", _object.get(), &osg::Box::getHalfLengths, &osg::Box::setHalfLengths);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgBox::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgBox::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgBox::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBox::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBox::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Box, RefosgBox> _registerRefosgBox;
