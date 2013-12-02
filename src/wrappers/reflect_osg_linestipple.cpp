#include <reflection/reflectionregistry.h>
#include <osg/LineStipple>
#include <stdexcept>

/**
 * Reflector of class osg::LineStipple
 */
class RefosgLineStipple: public ClassReflection {
public:
	RefosgLineStipple();
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
	osg::ref_ptr<osg::LineStipple> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_pattern","_userData","_factor","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgLineStipple::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgLineStipple::_table_names;

std::string RefosgLineStipple::_class_name("osg::LineStipple");

std::string RefosgLineStipple::_class_description("     ");

std::string RefosgLineStipple::_osg_version("1.2");


/**********************************************************/
RefosgLineStipple::RefosgLineStipple() {
}

/**********************************************************/
void RefosgLineStipple::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::LineStipple*>(obj);
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
void RefosgLineStipple::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgLineStipple::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgLineStipple::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgLineStipple::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLineStipple::getProperty(const std::string &name) {
	if (name == "_pattern") {
		// Getter overloaded, must specify one type
		typedef GLushort (osg::LineStipple::*getPatternFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LineStipple::*setPatternFN)(GLushort) ;
		return new GetterSetterProperty<GLushort, osg::LineStipple>("_pattern", _object.get(), (getPatternFN)&osg::LineStipple::getPattern, (setPatternFN)&osg::LineStipple::setPattern);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::LineStipple::getUserData, &osg::LineStipple::setUserData);
	}
	if (name == "_factor") {
		// Getter overloaded, must specify one type
		typedef GLint (osg::LineStipple::*getFactorFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LineStipple::*setFactorFN)(GLint) ;
		return new GetterSetterProperty<GLint, osg::LineStipple>("_factor", _object.get(), (getFactorFN)&osg::LineStipple::getFactor, (setFactorFN)&osg::LineStipple::setFactor);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::LineStipple::getDataVariance, &osg::LineStipple::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::LineStipple::getUpdateCallback, &osg::LineStipple::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::LineStipple::getName, (setNameFN)&osg::LineStipple::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::LineStipple::getEventCallback, &osg::LineStipple::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgLineStipple::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgLineStipple::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLineStipple::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLineStipple::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLineStipple::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::LineStipple, RefosgLineStipple> _registerRefosgLineStipple;
