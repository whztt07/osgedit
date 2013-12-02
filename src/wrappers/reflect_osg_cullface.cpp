#include <reflection/reflectionregistry.h>
#include <osg/CullFace>
#include <stdexcept>

/**
 * Reflector of class osg::CullFace
 */
class RefosgCullFace: public ClassReflection {
public:
	RefosgCullFace();
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
	osg::ref_ptr<osg::CullFace> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_mode","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgCullFace::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgCullFace::_table_names;

std::string RefosgCullFace::_class_name("osg::CullFace");

std::string RefosgCullFace::_class_description(" Class to globally enable/disable OpenGL's polygon culling mode.     ");

std::string RefosgCullFace::_osg_version("1.2");


/**********************************************************/
RefosgCullFace::RefosgCullFace() {
}

/**********************************************************/
void RefosgCullFace::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::CullFace*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_cullface_mode: public Enum<osg::CullFace::Mode> {
public:
	Enum_osg_cullface_mode() {
		add("FRONT", osg::CullFace::FRONT);
		add("BACK", osg::CullFace::BACK);
		add("FRONT_AND_BACK", osg::CullFace::FRONT_AND_BACK);
	}
} osg_cullface_mode;

using namespace osg;

/**********************************************************/
void RefosgCullFace::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgCullFace::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgCullFace::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgCullFace::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgCullFace::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::CullFace::getUserData, &osg::CullFace::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::CullFace::Mode (osg::CullFace::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::CullFace::*setModeFN)(osg::CullFace::Mode) ;
		return new GetterSetterEnumProperty<osg::CullFace::Mode, osg::CullFace>("_mode", _object.get(), (getModeFN)&osg::CullFace::getMode, (setModeFN)&osg::CullFace::setMode, osg_cullface_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::CullFace::getDataVariance, &osg::CullFace::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::CullFace::getUpdateCallback, &osg::CullFace::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::CullFace::getName, (setNameFN)&osg::CullFace::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::CullFace::getEventCallback, &osg::CullFace::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCullFace::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCullFace::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCullFace::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCullFace::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCullFace::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::CullFace, RefosgCullFace> _registerRefosgCullFace;
