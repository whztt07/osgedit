#include <reflection/reflectionregistry.h>
#include <osg/ClampColor>
#include <stdexcept>

/**
 * Reflector of class osg::ClampColor
 */
class RefosgClampColor: public ClassReflection {
public:
	RefosgClampColor();
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
	osg::ref_ptr<osg::ClampColor> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_updateCallback","_clampVertexColor","_clampFragmentColor","_clampReadColor","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgClampColor::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgClampColor::_table_names;

std::string RefosgClampColor::_class_name("osg::ClampColor");

std::string RefosgClampColor::_class_description(" Encapsulates OpenGL ClampColor state.     ");

std::string RefosgClampColor::_osg_version("1.2");


/**********************************************************/
RefosgClampColor::RefosgClampColor() {
}

/**********************************************************/
void RefosgClampColor::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::ClampColor*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_glenum_clampFragmentColor: public Enum<GLenum> {
public:
	Enum_glenum_clampFragmentColor() {
	}
} glenum_clampFragmentColor;
static class Enum_glenum_clampReadColor: public Enum<GLenum> {
public:
	Enum_glenum_clampReadColor() {
	}
} glenum_clampReadColor;
static class Enum_glenum_clampVertexColor: public Enum<GLenum> {
public:
	Enum_glenum_clampVertexColor() {
	}
} glenum_clampVertexColor;

using namespace osg;

/**********************************************************/
void RefosgClampColor::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgClampColor::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgClampColor::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgClampColor::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgClampColor::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::ClampColor::getUserData, &osg::ClampColor::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::ClampColor::getDataVariance, &osg::ClampColor::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::ClampColor::getUpdateCallback, &osg::ClampColor::setUpdateCallback);
	}
	if (name == "_clampVertexColor") {
		return new GetterSetterEnumProperty<GLenum, osg::ClampColor>("_clampVertexColor", _object.get(), &osg::ClampColor::getClampVertexColor, &osg::ClampColor::setClampVertexColor, glenum_clampVertexColor);
	}
	if (name == "_clampFragmentColor") {
		return new GetterSetterEnumProperty<GLenum, osg::ClampColor>("_clampFragmentColor", _object.get(), &osg::ClampColor::getClampFragmentColor, &osg::ClampColor::setClampFragmentColor, glenum_clampFragmentColor);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::ClampColor::getName, (setNameFN)&osg::ClampColor::setName);
	}
	if (name == "_clampReadColor") {
		return new GetterSetterEnumProperty<GLenum, osg::ClampColor>("_clampReadColor", _object.get(), &osg::ClampColor::getClampReadColor, &osg::ClampColor::setClampReadColor, glenum_clampReadColor);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::ClampColor::getEventCallback, &osg::ClampColor::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgClampColor::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgClampColor::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgClampColor::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgClampColor::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgClampColor::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::ClampColor, RefosgClampColor> _registerRefosgClampColor;
