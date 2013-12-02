#include <reflection/reflectionregistry.h>
#include <osg/TexGen>
#include <stdexcept>

/**
 * Reflector of class osg::TexGen
 */
class RefosgTexGen: public ClassReflection {
public:
	RefosgTexGen();
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
	osg::ref_ptr<osg::TexGen> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_mode","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgTexGen::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgTexGen::_table_names;

std::string RefosgTexGen::_class_name("osg::TexGen");

std::string RefosgTexGen::_class_description(" TexGen encapsulates the OpenGL glTexGen (texture coordinate generation) state.     ");

std::string RefosgTexGen::_osg_version("1.2");


/**********************************************************/
RefosgTexGen::RefosgTexGen() {
}

/**********************************************************/
void RefosgTexGen::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TexGen*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_texgen_mode: public Enum<osg::TexGen::Mode> {
public:
	Enum_osg_texgen_mode() {
		add("OBJECT_LINEAR", osg::TexGen::OBJECT_LINEAR);
		add("EYE_LINEAR", osg::TexGen::EYE_LINEAR);
		add("SPHERE_MAP", osg::TexGen::SPHERE_MAP);
		add("NORMAL_MAP", osg::TexGen::NORMAL_MAP);
		add("REFLECTION_MAP", osg::TexGen::REFLECTION_MAP);
	}
} osg_texgen_mode;

using namespace osg;

/**********************************************************/
void RefosgTexGen::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTexGen::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTexGen::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTexGen::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexGen::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TexGen::getUserData, &osg::TexGen::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::TexGen::Mode (osg::TexGen::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::TexGen::*setModeFN)(osg::TexGen::Mode) ;
		return new GetterSetterEnumProperty<osg::TexGen::Mode, osg::TexGen>("_mode", _object.get(), (getModeFN)&osg::TexGen::getMode, (setModeFN)&osg::TexGen::setMode, osg_texgen_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TexGen::getDataVariance, &osg::TexGen::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::TexGen::getUpdateCallback, &osg::TexGen::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TexGen::getName, (setNameFN)&osg::TexGen::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::TexGen::getEventCallback, &osg::TexGen::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexGen::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexGen::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexGen::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexGen::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexGen::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TexGen, RefosgTexGen> _registerRefosgTexGen;
