#include <reflection/reflectionregistry.h>
#include <osg/Program>
#include <stdexcept>

/**
 * Reflector of class osg::Program
 */
class RefosgProgram: public ClassReflection {
public:
	RefosgProgram();
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
	osg::ref_ptr<osg::Program> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_updateCallback","_eventCallback","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgProgram::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgProgram::_table_names;

std::string RefosgProgram::_class_name("osg::Program");

std::string RefosgProgram::_class_description(" osg::Program is an application-level abstraction of an OpenGL glProgram. It is an osg::StateAttribute that, when applied, will activate a glProgram for subsequent rendering. osg::Shaders containing the actual shader source code are attached to a Program, which will then manage the compilation, linking, and activation of the GLSL program. osg::Program will automatically manage per-context instancing of the OpenGL glPrograms, if that is necessary for a particular display configuration.     ");

std::string RefosgProgram::_osg_version("1.2");


/**********************************************************/
RefosgProgram::RefosgProgram() {
}

/**********************************************************/
void RefosgProgram::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Program*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osg;

/**********************************************************/
void RefosgProgram::addChild(osg::Object *child) {
	{Shader *cobj = dynamic_cast<Shader *>(child);
	if (cobj != 0) {
		_object->addShader(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgProgram::removeChild(osg::Object *child) {
	{Shader *cobj = dynamic_cast<Shader *>(child);
	if (cobj != 0) {
		_object->removeShader(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgProgram::getChildObject(unsigned i) {
	if (i < _object->getNumShaders()) {
		return _object->getShader(i);
	} else {
		i -= _object->getNumShaders();
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgProgram::getNumChildren() {
	unsigned cnt = 0;
	cnt+= _object->getNumShaders();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgProgram::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Program::getName, (setNameFN)&osg::Program::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Program::getUpdateCallback, &osg::Program::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Program::getDataVariance, &osg::Program::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Program::getEventCallback, &osg::Program::setEventCallback);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Program::getUserData, &osg::Program::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgProgram::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgProgram::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgProgram::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgProgram::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgProgram::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Program, RefosgProgram> _registerRefosgProgram;
