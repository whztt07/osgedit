#include <reflection/reflectionregistry.h>
#include <osg/TexEnvFilter>
#include <stdexcept>

/**
 * Reflector of class osg::TexEnvFilter
 */
class RefosgTexEnvFilter: public ClassReflection {
public:
	RefosgTexEnvFilter();
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
	osg::ref_ptr<osg::TexEnvFilter> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_lodBias","_userData","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgTexEnvFilter::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgTexEnvFilter::_table_names;

std::string RefosgTexEnvFilter::_class_name("osg::TexEnvFilter");

std::string RefosgTexEnvFilter::_class_description(" TexEnvFilter - encapsulates the OpenGL glTexEnv (GL_TEXTURE_FILTER_CONTROL) state.     ");

std::string RefosgTexEnvFilter::_osg_version("1.2");


/**********************************************************/
RefosgTexEnvFilter::RefosgTexEnvFilter() {
}

/**********************************************************/
void RefosgTexEnvFilter::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TexEnvFilter*>(obj);
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
void RefosgTexEnvFilter::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTexEnvFilter::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTexEnvFilter::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTexEnvFilter::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexEnvFilter::getProperty(const std::string &name) {
	if (name == "_lodBias") {
		return new GetterSetterProperty<float, osg::TexEnvFilter>("_lodBias", _object.get(), &osg::TexEnvFilter::getLodBias, &osg::TexEnvFilter::setLodBias);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TexEnvFilter::getUserData, &osg::TexEnvFilter::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TexEnvFilter::getDataVariance, &osg::TexEnvFilter::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::TexEnvFilter::getUpdateCallback, &osg::TexEnvFilter::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TexEnvFilter::getName, (setNameFN)&osg::TexEnvFilter::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::TexEnvFilter::getEventCallback, &osg::TexEnvFilter::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexEnvFilter::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexEnvFilter::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexEnvFilter::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexEnvFilter::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexEnvFilter::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TexEnvFilter, RefosgTexEnvFilter> _registerRefosgTexEnvFilter;
