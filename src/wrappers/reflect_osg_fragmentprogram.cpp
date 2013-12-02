#include <reflection/reflectionregistry.h>
#include <osg/FragmentProgram>
#include <stdexcept>

/**
 * Reflector of class osg::FragmentProgram
 */
class RefosgFragmentProgram: public ClassReflection {
public:
	RefosgFragmentProgram();
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
	osg::ref_ptr<osg::FragmentProgram> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_fragmentProgram","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgFragmentProgram::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgFragmentProgram::_table_names;

std::string RefosgFragmentProgram::_class_name("osg::FragmentProgram");

std::string RefosgFragmentProgram::_class_description(" FragmentProgram - encapsulates the OpenGL ARB fragment program state.     ");

std::string RefosgFragmentProgram::_osg_version("1.2");


/**********************************************************/
RefosgFragmentProgram::RefosgFragmentProgram() {
}

/**********************************************************/
void RefosgFragmentProgram::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::FragmentProgram*>(obj);
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
void RefosgFragmentProgram::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgFragmentProgram::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgFragmentProgram::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgFragmentProgram::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgFragmentProgram::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::FragmentProgram::getUserData, &osg::FragmentProgram::setUserData);
	}
	if (name == "_fragmentProgram") {
		// Setter overloaded, must specify one type
		typedef void (osg::FragmentProgram::*setFragmentProgramFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::FragmentProgram>("_fragmentProgram", _object.get(), &osg::FragmentProgram::getFragmentProgram, (setFragmentProgramFN)&osg::FragmentProgram::setFragmentProgram);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::FragmentProgram::getDataVariance, &osg::FragmentProgram::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::FragmentProgram::getUpdateCallback, &osg::FragmentProgram::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::FragmentProgram::getName, (setNameFN)&osg::FragmentProgram::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::FragmentProgram::getEventCallback, &osg::FragmentProgram::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgFragmentProgram::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgFragmentProgram::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgFragmentProgram::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFragmentProgram::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFragmentProgram::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::FragmentProgram, RefosgFragmentProgram> _registerRefosgFragmentProgram;
