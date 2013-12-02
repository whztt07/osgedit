#include <reflection/reflectionregistry.h>
#include <osg/Fog>
#include <stdexcept>

/**
 * Reflector of class osg::Fog
 */
class RefosgFog: public ClassReflection {
public:
	RefosgFog();
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
	osg::ref_ptr<osg::Fog> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_fogCoordinateSource","_density","_mode","_end","_updateCallback","_color","_start","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgFog::_names(_propnames, _propnames+11);

ClassReflection::PropertyNames RefosgFog::_table_names;

std::string RefosgFog::_class_name("osg::Fog");

std::string RefosgFog::_class_description(" Fog - encapsulates OpenGL fog state.     ");

std::string RefosgFog::_osg_version("1.2");


/**********************************************************/
RefosgFog::RefosgFog() {
}

/**********************************************************/
void RefosgFog::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Fog*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_fog_mode: public Enum<osg::Fog::Mode> {
public:
	Enum_osg_fog_mode() {
		add("LINEAR", osg::Fog::LINEAR);
		add("EXP", osg::Fog::EXP);
		add("EXP2", osg::Fog::EXP2);
	}
} osg_fog_mode;

using namespace osg;

/**********************************************************/
void RefosgFog::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgFog::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgFog::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgFog::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgFog::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Fog::getUserData, &osg::Fog::setUserData);
	}
	if (name == "_fogCoordinateSource") {
		return new GetterSetterProperty<GLint, osg::Fog>("_fogCoordinateSource", _object.get(), &osg::Fog::getFogCoordinateSource, &osg::Fog::setFogCoordinateSource);
	}
	if (name == "_density") {
		// Getter overloaded, must specify one type
		typedef float (osg::Fog::*getDensityFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Fog::*setDensityFN)(float) ;
		return new GetterSetterProperty<float, osg::Fog>("_density", _object.get(), (getDensityFN)&osg::Fog::getDensity, (setDensityFN)&osg::Fog::setDensity);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Fog::getName, (setNameFN)&osg::Fog::setName);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::Fog::Mode (osg::Fog::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Fog::*setModeFN)(osg::Fog::Mode) ;
		return new GetterSetterEnumProperty<osg::Fog::Mode, osg::Fog>("_mode", _object.get(), (getModeFN)&osg::Fog::getMode, (setModeFN)&osg::Fog::setMode, osg_fog_mode);
	}
	if (name == "_end") {
		// Getter overloaded, must specify one type
		typedef float (osg::Fog::*getEndFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Fog::*setEndFN)(float) ;
		return new GetterSetterProperty<float, osg::Fog>("_end", _object.get(), (getEndFN)&osg::Fog::getEnd, (setEndFN)&osg::Fog::setEnd);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Fog::getDataVariance, &osg::Fog::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Fog::getUpdateCallback, &osg::Fog::setUpdateCallback);
	}
	if (name == "_color") {
		// Getter overloaded, must specify one type
		typedef const Vec4 & (osg::Fog::*getColorFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Fog::*setColorFN)(const Vec4 &) ;
		return new GetterSetterProperty<Vec4, osg::Fog>("_color", _object.get(), (getColorFN)&osg::Fog::getColor, (setColorFN)&osg::Fog::setColor);
	}
	if (name == "_start") {
		// Getter overloaded, must specify one type
		typedef float (osg::Fog::*getStartFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Fog::*setStartFN)(float) ;
		return new GetterSetterProperty<float, osg::Fog>("_start", _object.get(), (getStartFN)&osg::Fog::getStart, (setStartFN)&osg::Fog::setStart);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Fog::getEventCallback, &osg::Fog::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgFog::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgFog::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgFog::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFog::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFog::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Fog, RefosgFog> _registerRefosgFog;
