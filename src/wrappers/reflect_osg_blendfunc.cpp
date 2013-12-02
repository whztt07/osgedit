#include <reflection/reflectionregistry.h>
#include <osg/BlendFunc>
#include <stdexcept>

/**
 * Reflector of class osg::BlendFunc
 */
class RefosgBlendFunc: public ClassReflection {
public:
	RefosgBlendFunc();
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
	osg::ref_ptr<osg::BlendFunc> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_source_factor","_userData","_destination_factor","_updateCallback","_source_factor_alpha","_destination_factor_alpha","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgBlendFunc::_names(_propnames, _propnames+9);

ClassReflection::PropertyNames RefosgBlendFunc::_table_names;

std::string RefosgBlendFunc::_class_name("osg::BlendFunc");

std::string RefosgBlendFunc::_class_description(" Encapsulates OpenGL blend/transparency state.     ");

std::string RefosgBlendFunc::_osg_version("1.2");


/**********************************************************/
RefosgBlendFunc::RefosgBlendFunc() {
}

/**********************************************************/
void RefosgBlendFunc::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::BlendFunc*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_glenum_destination_factor_alpha: public Enum<GLenum> {
public:
	Enum_glenum_destination_factor_alpha() {
		add("GL_ZERO", GL_ZERO);
		add("GL_ONE", GL_ONE);
		add("GL_SRC_COLOR", GL_SRC_COLOR);
		add("GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR);
		add("GL_DST_COLOR", GL_DST_COLOR);
		add("GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR);
		add("GL_SRC_ALPHA", GL_SRC_ALPHA);
		add("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
		add("GL_DST_ALPHA", GL_DST_ALPHA);
		add("GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA);
		add("GL_CONSTANT_COLOR", GL_CONSTANT_COLOR);
		add("GL_ONE_MINUS_CONSTANT_COLOR", GL_ONE_MINUS_CONSTANT_COLOR);
		add("GL_CONSTANT_ALPHA", GL_CONSTANT_ALPHA);
		add("GL_ONE_MINUS_CONSTANT_ALPHA", GL_ONE_MINUS_CONSTANT_ALPHA);
	}
} glenum_destination_factor_alpha;
static class Enum_glenum_destination_factor: public Enum<GLenum> {
public:
	Enum_glenum_destination_factor() {
		add("GL_ZERO", GL_ZERO);
		add("GL_ONE", GL_ONE);
		add("GL_SRC_COLOR", GL_SRC_COLOR);
		add("GL_ONE_MINUS_SRC_COLOR", GL_ONE_MINUS_SRC_COLOR);
		add("GL_DST_COLOR", GL_DST_COLOR);
		add("GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR);
		add("GL_SRC_ALPHA", GL_SRC_ALPHA);
		add("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
		add("GL_DST_ALPHA", GL_DST_ALPHA);
		add("GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA);
		add("GL_CONSTANT_COLOR", GL_CONSTANT_COLOR);
		add("GL_ONE_MINUS_CONSTANT_COLOR", GL_ONE_MINUS_CONSTANT_COLOR);
		add("GL_CONSTANT_ALPHA", GL_CONSTANT_ALPHA);
		add("GL_ONE_MINUS_CONSTANT_ALPHA", GL_ONE_MINUS_CONSTANT_ALPHA);
	}
} glenum_destination_factor;
static class Enum_glenum_source_factor_alpha: public Enum<GLenum> {
public:
	Enum_glenum_source_factor_alpha() {
		add("GL_ZERO", GL_ZERO);
		add("GL_ONE", GL_ONE);
		add("GL_DST_COLOR", GL_DST_COLOR);
		add("GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR);
		add("GL_SRC_ALPHA", GL_SRC_ALPHA);
		add("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
		add("GL_DST_ALPHA", GL_DST_ALPHA);
		add("GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA);
		add("GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE);
	}
} glenum_source_factor_alpha;
static class Enum_glenum_source_factor: public Enum<GLenum> {
public:
	Enum_glenum_source_factor() {
		add("GL_ZERO", GL_ZERO);
		add("GL_ONE", GL_ONE);
		add("GL_DST_COLOR", GL_DST_COLOR);
		add("GL_ONE_MINUS_DST_COLOR", GL_ONE_MINUS_DST_COLOR);
		add("GL_SRC_ALPHA", GL_SRC_ALPHA);
		add("GL_ONE_MINUS_SRC_ALPHA", GL_ONE_MINUS_SRC_ALPHA);
		add("GL_DST_ALPHA", GL_DST_ALPHA);
		add("GL_ONE_MINUS_DST_ALPHA", GL_ONE_MINUS_DST_ALPHA);
		add("GL_SRC_ALPHA_SATURATE", GL_SRC_ALPHA_SATURATE);
	}
} glenum_source_factor;

using namespace osg;

/**********************************************************/
void RefosgBlendFunc::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgBlendFunc::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgBlendFunc::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgBlendFunc::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgBlendFunc::getProperty(const std::string &name) {
	if (name == "_source_factor") {
		return new GetterSetterEnumProperty<GLenum, osg::BlendFunc>("_source_factor", _object.get(), &osg::BlendFunc::getSourceRGB, &osg::BlendFunc::setSourceRGB, glenum_source_factor);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::BlendFunc::getUserData, &osg::BlendFunc::setUserData);
	}
	if (name == "_destination_factor") {
		return new GetterSetterEnumProperty<GLenum, osg::BlendFunc>("_destination_factor", _object.get(), &osg::BlendFunc::getDestinationRGB, &osg::BlendFunc::setDestinationRGB, glenum_destination_factor);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::BlendFunc::getDataVariance, &osg::BlendFunc::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::BlendFunc::getUpdateCallback, &osg::BlendFunc::setUpdateCallback);
	}
	if (name == "_source_factor_alpha") {
		return new GetterSetterEnumProperty<GLenum, osg::BlendFunc>("_source_factor_alpha", _object.get(), &osg::BlendFunc::getSourceAlpha, &osg::BlendFunc::setSourceAlpha, glenum_source_factor_alpha);
	}
	if (name == "_destination_factor_alpha") {
		return new GetterSetterEnumProperty<GLenum, osg::BlendFunc>("_destination_factor_alpha", _object.get(), &osg::BlendFunc::getDestinationAlpha, &osg::BlendFunc::setDestinationAlpha, glenum_destination_factor_alpha);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::BlendFunc::getName, (setNameFN)&osg::BlendFunc::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::BlendFunc::getEventCallback, &osg::BlendFunc::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgBlendFunc::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgBlendFunc::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgBlendFunc::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBlendFunc::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBlendFunc::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::BlendFunc, RefosgBlendFunc> _registerRefosgBlendFunc;
