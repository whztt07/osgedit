#include <reflection/reflectionregistry.h>
#include <osg/AlphaFunc>
#include <stdexcept>

/**
 * Reflector of class osg::AlphaFunc
 */
class RefosgAlphaFunc: public ClassReflection {
public:
	RefosgAlphaFunc();
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
	osg::ref_ptr<osg::AlphaFunc> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_updateCallback","_referenceValue","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgAlphaFunc::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgAlphaFunc::_table_names;

std::string RefosgAlphaFunc::_class_name("osg::AlphaFunc");

std::string RefosgAlphaFunc::_class_description(" Encapsulates OpenGL glAlphaFunc.     ");

std::string RefosgAlphaFunc::_osg_version("1.2");


/**********************************************************/
RefosgAlphaFunc::RefosgAlphaFunc() {
}

/**********************************************************/
void RefosgAlphaFunc::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::AlphaFunc*>(obj);
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
void RefosgAlphaFunc::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgAlphaFunc::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgAlphaFunc::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgAlphaFunc::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgAlphaFunc::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::AlphaFunc::getUserData, &osg::AlphaFunc::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::AlphaFunc::getName, (setNameFN)&osg::AlphaFunc::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::AlphaFunc::getUpdateCallback, &osg::AlphaFunc::setUpdateCallback);
	}
	if (name == "_referenceValue") {
		return new GetterSetterProperty<float, osg::AlphaFunc>("_referenceValue", _object.get(), &osg::AlphaFunc::getReferenceValue, &osg::AlphaFunc::setReferenceValue);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::AlphaFunc::getDataVariance, &osg::AlphaFunc::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::AlphaFunc::getEventCallback, &osg::AlphaFunc::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgAlphaFunc::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgAlphaFunc::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgAlphaFunc::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgAlphaFunc::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgAlphaFunc::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::AlphaFunc, RefosgAlphaFunc> _registerRefosgAlphaFunc;
