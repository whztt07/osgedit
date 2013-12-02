#include <reflection/reflectionregistry.h>
#include <osg/Hint>
#include <stdexcept>

/**
 * Reflector of class osg::Hint
 */
class RefosgHint: public ClassReflection {
public:
	RefosgHint();
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
	osg::ref_ptr<osg::Hint> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_mode","_updateCallback","_target","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgHint::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgHint::_table_names;

std::string RefosgHint::_class_name("osg::Hint");

std::string RefosgHint::_class_description("     ");

std::string RefosgHint::_osg_version("1.2");


/**********************************************************/
RefosgHint::RefosgHint() {
}

/**********************************************************/
void RefosgHint::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Hint*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_glenum_mode: public Enum<GLenum> {
public:
	Enum_glenum_mode() {
	}
} glenum_mode;
static class Enum_glenum_target: public Enum<GLenum> {
public:
	Enum_glenum_target() {
	}
} glenum_target;

using namespace osg;

/**********************************************************/
void RefosgHint::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgHint::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgHint::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgHint::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgHint::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Hint::getUserData, &osg::Hint::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::Hint::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Hint::*setModeFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::Hint>("_mode", _object.get(), (getModeFN)&osg::Hint::getMode, (setModeFN)&osg::Hint::setMode, glenum_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Hint::getDataVariance, &osg::Hint::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Hint::getUpdateCallback, &osg::Hint::setUpdateCallback);
	}
	if (name == "_target") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::Hint::*getTargetFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Hint::*setTargetFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::Hint>("_target", _object.get(), (getTargetFN)&osg::Hint::getTarget, (setTargetFN)&osg::Hint::setTarget, glenum_target);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Hint::getName, (setNameFN)&osg::Hint::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Hint::getEventCallback, &osg::Hint::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgHint::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgHint::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgHint::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgHint::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgHint::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Hint, RefosgHint> _registerRefosgHint;
