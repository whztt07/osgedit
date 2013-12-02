#include <reflection/reflectionregistry.h>
#include <osg/NodeCallback>
#include <stdexcept>

/**
 * Reflector of class osg::NodeCallback
 */
class RefosgNodeCallback: public ClassReflection {
public:
	RefosgNodeCallback();
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
	osg::ref_ptr<osg::NodeCallback> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_nestedCallback","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgNodeCallback::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgNodeCallback::_table_names;

std::string RefosgNodeCallback::_class_name("osg::NodeCallback");

std::string RefosgNodeCallback::_class_description("     ");

std::string RefosgNodeCallback::_osg_version("1.2");


/**********************************************************/
RefosgNodeCallback::RefosgNodeCallback() {
}

/**********************************************************/
void RefosgNodeCallback::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::NodeCallback*>(obj);
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
void RefosgNodeCallback::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgNodeCallback::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgNodeCallback::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgNodeCallback::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgNodeCallback::getProperty(const std::string &name) {
	if (name == "_nestedCallback") {
		// Getter overloaded, must specify one type
		typedef NodeCallback * (osg::NodeCallback::*getNestedCallbackFN)() ;
		return new GetterSetterProperty<NodeCallback*, osg::NodeCallback>("_nestedCallback", _object.get(), (getNestedCallbackFN)&osg::NodeCallback::getNestedCallback, &osg::NodeCallback::setNestedCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::NodeCallback::getName, (setNameFN)&osg::NodeCallback::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::NodeCallback::getDataVariance, &osg::NodeCallback::setDataVariance, osg_object_datavariance);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::NodeCallback::getUserData, &osg::NodeCallback::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgNodeCallback::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgNodeCallback::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgNodeCallback::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgNodeCallback::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgNodeCallback::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::NodeCallback, RefosgNodeCallback> _registerRefosgNodeCallback;
