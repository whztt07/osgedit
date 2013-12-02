#include <reflection/reflectionregistry.h>
#include <osg/FrontFace>
#include <stdexcept>

/**
 * Reflector of class osg::FrontFace
 */
class RefosgFrontFace: public ClassReflection {
public:
	RefosgFrontFace();
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
	osg::ref_ptr<osg::FrontFace> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_mode","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgFrontFace::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgFrontFace::_table_names;

std::string RefosgFrontFace::_class_name("osg::FrontFace");

std::string RefosgFrontFace::_class_description(" Class to specify the orientation of front-facing polygons.     ");

std::string RefosgFrontFace::_osg_version("1.2");


/**********************************************************/
RefosgFrontFace::RefosgFrontFace() {
}

/**********************************************************/
void RefosgFrontFace::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::FrontFace*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_frontface_mode: public Enum<osg::FrontFace::Mode> {
public:
	Enum_osg_frontface_mode() {
		add("CLOCKWISE", osg::FrontFace::CLOCKWISE);
		add("COUNTER_CLOCKWISE", osg::FrontFace::COUNTER_CLOCKWISE);
	}
} osg_frontface_mode;

using namespace osg;

/**********************************************************/
void RefosgFrontFace::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgFrontFace::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgFrontFace::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgFrontFace::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgFrontFace::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::FrontFace::getUserData, &osg::FrontFace::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::FrontFace::Mode (osg::FrontFace::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::FrontFace::*setModeFN)(osg::FrontFace::Mode) ;
		return new GetterSetterEnumProperty<osg::FrontFace::Mode, osg::FrontFace>("_mode", _object.get(), (getModeFN)&osg::FrontFace::getMode, (setModeFN)&osg::FrontFace::setMode, osg_frontface_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::FrontFace::getDataVariance, &osg::FrontFace::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::FrontFace::getUpdateCallback, &osg::FrontFace::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::FrontFace::getName, (setNameFN)&osg::FrontFace::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::FrontFace::getEventCallback, &osg::FrontFace::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgFrontFace::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgFrontFace::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgFrontFace::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFrontFace::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFrontFace::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::FrontFace, RefosgFrontFace> _registerRefosgFrontFace;
