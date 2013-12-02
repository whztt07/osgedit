#include <reflection/reflectionregistry.h>
#include <osg/Uniform>
#include <stdexcept>

/**
 * Reflector of class osg::Uniform
 */
class RefosgUniform: public ClassReflection {
public:
	RefosgUniform();
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
	osg::ref_ptr<osg::Uniform> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_type","_userData","_updateCallback","_numElements","_modifiedCount","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgUniform::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgUniform::_table_names;

std::string RefosgUniform::_class_name("osg::Uniform");

std::string RefosgUniform::_class_description(" Uniform encapsulates glUniform values     ");

std::string RefosgUniform::_osg_version("1.2");


/**********************************************************/
RefosgUniform::RefosgUniform() {
}

/**********************************************************/
void RefosgUniform::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Uniform*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_uniform_type: public Enum<osg::Uniform::Type> {
public:
	Enum_osg_uniform_type() {
		add("FLOAT", osg::Uniform::FLOAT);
		add("FLOAT_VEC2", osg::Uniform::FLOAT_VEC2);
		add("FLOAT_VEC3", osg::Uniform::FLOAT_VEC3);
		add("FLOAT_VEC4", osg::Uniform::FLOAT_VEC4);
		add("INT", osg::Uniform::INT);
		add("INT_VEC2", osg::Uniform::INT_VEC2);
		add("INT_VEC3", osg::Uniform::INT_VEC3);
		add("INT_VEC4", osg::Uniform::INT_VEC4);
		add("BOOL", osg::Uniform::BOOL);
		add("BOOL_VEC2", osg::Uniform::BOOL_VEC2);
		add("BOOL_VEC3", osg::Uniform::BOOL_VEC3);
		add("BOOL_VEC4", osg::Uniform::BOOL_VEC4);
		add("FLOAT_MAT2", osg::Uniform::FLOAT_MAT2);
		add("FLOAT_MAT3", osg::Uniform::FLOAT_MAT3);
		add("FLOAT_MAT4", osg::Uniform::FLOAT_MAT4);
		add("SAMPLER_1D", osg::Uniform::SAMPLER_1D);
		add("SAMPLER_2D", osg::Uniform::SAMPLER_2D);
		add("SAMPLER_3D", osg::Uniform::SAMPLER_3D);
		add("SAMPLER_CUBE", osg::Uniform::SAMPLER_CUBE);
		add("SAMPLER_1D_SHADOW", osg::Uniform::SAMPLER_1D_SHADOW);
		add("SAMPLER_2D_SHADOW", osg::Uniform::SAMPLER_2D_SHADOW);
		add("SAMPLER_1D_ARRAY", osg::Uniform::SAMPLER_1D_ARRAY);
		add("SAMPLER_2D_ARRAY", osg::Uniform::SAMPLER_2D_ARRAY);
		add("SAMPLER_1D_ARRAY_SHADOW", osg::Uniform::SAMPLER_1D_ARRAY_SHADOW);
		add("SAMPLER_2D_ARRAY_SHADOW", osg::Uniform::SAMPLER_2D_ARRAY_SHADOW);
		add("UNDEFINED", osg::Uniform::UNDEFINED);
	}
} osg_uniform_type;

using namespace osg;

/**********************************************************/
void RefosgUniform::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgUniform::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgUniform::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgUniform::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgUniform::getProperty(const std::string &name) {
	if (name == "_type") {
		// Getter overloaded, must specify one type
		typedef osg::Uniform::Type (osg::Uniform::*getTypeFN)() const;
		// Setter overloaded, must specify one type
		typedef bool (osg::Uniform::*setTypeFN)(osg::Uniform::Type) ;
		return new GetterSetterEnumProperty<osg::Uniform::Type, osg::Uniform>("_type", _object.get(), (getTypeFN)&osg::Uniform::getType, (setTypeFN)&osg::Uniform::setType, osg_uniform_type);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Uniform::getUserData, &osg::Uniform::setUserData);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Uniform::Callback * (osg::Uniform::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Uniform::Callback*, osg::Uniform>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Uniform::getUpdateCallback, &osg::Uniform::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Uniform::getDataVariance, &osg::Uniform::setDataVariance, osg_object_datavariance);
	}
	if (name == "_numElements") {
		return new GetterSetterProperty<unsigned int, osg::Uniform>("_numElements", _object.get(), &osg::Uniform::getNumElements, &osg::Uniform::setNumElements);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::Uniform>("_modifiedCount", _object.get(), &osg::Uniform::getModifiedCount, &osg::Uniform::setModifiedCount);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Uniform::getName, (setNameFN)&osg::Uniform::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Uniform::Callback * (osg::Uniform::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Uniform::Callback*, osg::Uniform>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Uniform::getEventCallback, &osg::Uniform::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgUniform::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgUniform::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgUniform::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgUniform::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgUniform::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Uniform, RefosgUniform> _registerRefosgUniform;
