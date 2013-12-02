#include <reflection/reflectionregistry.h>
#include <osg/TexEnv>
#include <stdexcept>

/**
 * Reflector of class osg::TexEnv
 */
class RefosgTexEnv: public ClassReflection {
public:
	RefosgTexEnv();
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
	osg::ref_ptr<osg::TexEnv> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_mode","_updateCallback","_color","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgTexEnv::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgTexEnv::_table_names;

std::string RefosgTexEnv::_class_name("osg::TexEnv");

std::string RefosgTexEnv::_class_description(" TexEnv encapsulates the OpenGL glTexEnv (texture environment) state.     ");

std::string RefosgTexEnv::_osg_version("1.2");


/**********************************************************/
RefosgTexEnv::RefosgTexEnv() {
}

/**********************************************************/
void RefosgTexEnv::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TexEnv*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_texenv_mode: public Enum<osg::TexEnv::Mode> {
public:
	Enum_osg_texenv_mode() {
		add("DECAL", osg::TexEnv::DECAL);
		add("MODULATE", osg::TexEnv::MODULATE);
		add("BLEND", osg::TexEnv::BLEND);
		add("REPLACE", osg::TexEnv::REPLACE);
		add("ADD", osg::TexEnv::ADD);
	}
} osg_texenv_mode;

using namespace osg;

/**********************************************************/
void RefosgTexEnv::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTexEnv::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTexEnv::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTexEnv::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexEnv::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TexEnv::getUserData, &osg::TexEnv::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::TexEnv::Mode (osg::TexEnv::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::TexEnv::*setModeFN)(osg::TexEnv::Mode) ;
		return new GetterSetterEnumProperty<osg::TexEnv::Mode, osg::TexEnv>("_mode", _object.get(), (getModeFN)&osg::TexEnv::getMode, (setModeFN)&osg::TexEnv::setMode, osg_texenv_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TexEnv::getDataVariance, &osg::TexEnv::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::TexEnv::getUpdateCallback, &osg::TexEnv::setUpdateCallback);
	}
	if (name == "_color") {
		// Getter overloaded, must specify one type
		typedef Vec4 & (osg::TexEnv::*getColorFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::TexEnv::*setColorFN)(const Vec4 &) ;
		return new GetterSetterProperty<osg::Vec4, osg::TexEnv>("_color", _object.get(), (getColorFN)&osg::TexEnv::getColor, (setColorFN)&osg::TexEnv::setColor);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TexEnv::getName, (setNameFN)&osg::TexEnv::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::TexEnv::getEventCallback, &osg::TexEnv::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexEnv::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexEnv::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexEnv::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexEnv::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexEnv::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TexEnv, RefosgTexEnv> _registerRefosgTexEnv;
