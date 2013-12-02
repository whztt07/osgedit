#include <reflection/reflectionregistry.h>
#include <osg/VertexProgram>
#include <stdexcept>

/**
 * Reflector of class osg::VertexProgram
 */
class RefosgVertexProgram: public ClassReflection {
public:
	RefosgVertexProgram();
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
	osg::ref_ptr<osg::VertexProgram> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_vertexProgram","_userData","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgVertexProgram::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgVertexProgram::_table_names;

std::string RefosgVertexProgram::_class_name("osg::VertexProgram");

std::string RefosgVertexProgram::_class_description(" VertexProgram - encapsulates the OpenGL ARB vertex program state.     ");

std::string RefosgVertexProgram::_osg_version("1.2");


/**********************************************************/
RefosgVertexProgram::RefosgVertexProgram() {
}

/**********************************************************/
void RefosgVertexProgram::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::VertexProgram*>(obj);
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
void RefosgVertexProgram::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgVertexProgram::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgVertexProgram::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgVertexProgram::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgVertexProgram::getProperty(const std::string &name) {
	if (name == "_vertexProgram") {
		// Setter overloaded, must specify one type
		typedef void (osg::VertexProgram::*setVertexProgramFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::VertexProgram>("_vertexProgram", _object.get(), &osg::VertexProgram::getVertexProgram, (setVertexProgramFN)&osg::VertexProgram::setVertexProgram);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::VertexProgram::getUserData, &osg::VertexProgram::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::VertexProgram::getName, (setNameFN)&osg::VertexProgram::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::VertexProgram::getUpdateCallback, &osg::VertexProgram::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::VertexProgram::getDataVariance, &osg::VertexProgram::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::VertexProgram::getEventCallback, &osg::VertexProgram::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgVertexProgram::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgVertexProgram::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgVertexProgram::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgVertexProgram::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgVertexProgram::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::VertexProgram, RefosgVertexProgram> _registerRefosgVertexProgram;
