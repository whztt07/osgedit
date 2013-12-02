#include <reflection/reflectionregistry.h>
#include <osg/PolygonOffset>
#include <stdexcept>

/**
 * Reflector of class osg::PolygonOffset
 */
class RefosgPolygonOffset: public ClassReflection {
public:
	RefosgPolygonOffset();
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
	osg::ref_ptr<osg::PolygonOffset> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_units","_factor","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgPolygonOffset::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgPolygonOffset::_table_names;

std::string RefosgPolygonOffset::_class_name("osg::PolygonOffset");

std::string RefosgPolygonOffset::_class_description(" PolygonOffset - encapsulates the OpenGL glPolygonOffset state.     ");

std::string RefosgPolygonOffset::_osg_version("1.2");


/**********************************************************/
RefosgPolygonOffset::RefosgPolygonOffset() {
}

/**********************************************************/
void RefosgPolygonOffset::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::PolygonOffset*>(obj);
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
void RefosgPolygonOffset::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgPolygonOffset::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgPolygonOffset::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgPolygonOffset::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgPolygonOffset::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::PolygonOffset::getUserData, &osg::PolygonOffset::setUserData);
	}
	if (name == "_units") {
		// Getter overloaded, must specify one type
		typedef float (osg::PolygonOffset::*getUnitsFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PolygonOffset::*setUnitsFN)(float) ;
		return new GetterSetterProperty<float, osg::PolygonOffset>("_units", _object.get(), (getUnitsFN)&osg::PolygonOffset::getUnits, (setUnitsFN)&osg::PolygonOffset::setUnits);
	}
	if (name == "_factor") {
		// Getter overloaded, must specify one type
		typedef float (osg::PolygonOffset::*getFactorFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PolygonOffset::*setFactorFN)(float) ;
		return new GetterSetterProperty<float, osg::PolygonOffset>("_factor", _object.get(), (getFactorFN)&osg::PolygonOffset::getFactor, (setFactorFN)&osg::PolygonOffset::setFactor);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::PolygonOffset::getName, (setNameFN)&osg::PolygonOffset::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::PolygonOffset::getUpdateCallback, &osg::PolygonOffset::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::PolygonOffset::getDataVariance, &osg::PolygonOffset::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::PolygonOffset::getEventCallback, &osg::PolygonOffset::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgPolygonOffset::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgPolygonOffset::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgPolygonOffset::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPolygonOffset::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPolygonOffset::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::PolygonOffset, RefosgPolygonOffset> _registerRefosgPolygonOffset;
