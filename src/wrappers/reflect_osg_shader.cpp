#include <reflection/reflectionregistry.h>
#include <osg/Shader>
#include <stdexcept>

/**
 * Reflector of class osg::Shader
 */
class RefosgShader: public ClassReflection {
public:
	RefosgShader();
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
	osg::ref_ptr<osg::Shader> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_type","_shaderSource","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgShader::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgShader::_table_names;

std::string RefosgShader::_class_name("osg::Shader");

std::string RefosgShader::_class_description(" osg::Shader is an application-level abstraction of an OpenGL glShader. It is a container to load the shader source code text and manage its compilation. An osg::Shader may be attached to more than one osg::Program. Shader will automatically manage per-context instancing of the internal objects, if that is necessary for a particular display configuration.     ");

std::string RefosgShader::_osg_version("1.2");


/**********************************************************/
RefosgShader::RefosgShader() {
}

/**********************************************************/
void RefosgShader::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Shader*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_shader_type: public Enum<osg::Shader::Type> {
public:
	Enum_osg_shader_type() {
		add("VERTEX", osg::Shader::VERTEX);
		add("FRAGMENT", osg::Shader::FRAGMENT);
		add("UNDEFINED", osg::Shader::UNDEFINED);
	}
} osg_shader_type;

using namespace osg;

/**********************************************************/
void RefosgShader::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShader::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShader::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShader::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShader::getProperty(const std::string &name) {
	if (name == "_type") {
		// Getter overloaded, must specify one type
		typedef osg::Shader::Type (osg::Shader::*getTypeFN)() const;
		// Setter overloaded, must specify one type
		typedef bool (osg::Shader::*setTypeFN)(osg::Shader::Type) ;
		return new GetterSetterEnumProperty<osg::Shader::Type, osg::Shader>("_type", _object.get(), (getTypeFN)&osg::Shader::getType, (setTypeFN)&osg::Shader::setType, osg_shader_type);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Shader::getDataVariance, &osg::Shader::setDataVariance, osg_object_datavariance);
	}
	if (name == "_shaderSource") {
		return new GetterSetterProperty<std::string, osg::Shader>("_shaderSource", _object.get(), &osg::Shader::getShaderSource, &osg::Shader::setShaderSource);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Shader::getName, (setNameFN)&osg::Shader::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Shader::getUserData, &osg::Shader::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShader::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShader::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShader::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShader::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShader::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Shader, RefosgShader> _registerRefosgShader;
