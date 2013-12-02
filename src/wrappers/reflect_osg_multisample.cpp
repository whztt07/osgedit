#include <reflection/reflectionregistry.h>
#include <osg/Multisample>
#include <stdexcept>

/**
 * Reflector of class osg::Multisample
 */
class RefosgMultisample: public ClassReflection {
public:
	RefosgMultisample();
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
	osg::ref_ptr<osg::Multisample> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_invert","_userData","_coverage","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgMultisample::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgMultisample::_table_names;

std::string RefosgMultisample::_class_name("osg::Multisample");

std::string RefosgMultisample::_class_description(" Multisample - encapsulates the OpenGL Multisample state.     ");

std::string RefosgMultisample::_osg_version("1.2");


/**********************************************************/
RefosgMultisample::RefosgMultisample() {
}

/**********************************************************/
void RefosgMultisample::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Multisample*>(obj);
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
void RefosgMultisample::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgMultisample::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgMultisample::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgMultisample::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgMultisample::getProperty(const std::string &name) {
	if (name == "_invert") {
		// Getter overloaded, must specify one type
		typedef bool (osg::Multisample::*getInvertFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Multisample::*setInvertFN)(bool) ;
		return new GetterSetterProperty<bool, osg::Multisample>("_invert", _object.get(), (getInvertFN)&osg::Multisample::getInvert, (setInvertFN)&osg::Multisample::setInvert);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Multisample::getUserData, &osg::Multisample::setUserData);
	}
	if (name == "_coverage") {
		// Getter overloaded, must specify one type
		typedef float (osg::Multisample::*getCoverageFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Multisample::*setCoverageFN)(float) ;
		return new GetterSetterProperty<float, osg::Multisample>("_coverage", _object.get(), (getCoverageFN)&osg::Multisample::getCoverage, (setCoverageFN)&osg::Multisample::setCoverage);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Multisample::getDataVariance, &osg::Multisample::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Multisample::getUpdateCallback, &osg::Multisample::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Multisample::getName, (setNameFN)&osg::Multisample::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Multisample::getEventCallback, &osg::Multisample::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgMultisample::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgMultisample::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgMultisample::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgMultisample::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgMultisample::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Multisample, RefosgMultisample> _registerRefosgMultisample;
