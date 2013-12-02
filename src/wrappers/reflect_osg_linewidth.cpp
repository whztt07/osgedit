#include <reflection/reflectionregistry.h>
#include <osg/LineWidth>
#include <stdexcept>

/**
 * Reflector of class osg::LineWidth
 */
class RefosgLineWidth: public ClassReflection {
public:
	RefosgLineWidth();
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
	osg::ref_ptr<osg::LineWidth> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_width","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgLineWidth::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgLineWidth::_table_names;

std::string RefosgLineWidth::_class_name("osg::LineWidth");

std::string RefosgLineWidth::_class_description(" LineWidth - encapsulates the OpenGL glLineWidth for setting the width of lines in pixels.     ");

std::string RefosgLineWidth::_osg_version("1.2");


/**********************************************************/
RefosgLineWidth::RefosgLineWidth() {
}

/**********************************************************/
void RefosgLineWidth::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::LineWidth*>(obj);
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
void RefosgLineWidth::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgLineWidth::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgLineWidth::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgLineWidth::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLineWidth::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::LineWidth::getUserData, &osg::LineWidth::setUserData);
	}
	if (name == "_width") {
		// Getter overloaded, must specify one type
		typedef float (osg::LineWidth::*getWidthFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LineWidth::*setWidthFN)(float) ;
		return new GetterSetterProperty<float, osg::LineWidth>("_width", _object.get(), (getWidthFN)&osg::LineWidth::getWidth, (setWidthFN)&osg::LineWidth::setWidth);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::LineWidth::getDataVariance, &osg::LineWidth::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::LineWidth::getUpdateCallback, &osg::LineWidth::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::LineWidth::getName, (setNameFN)&osg::LineWidth::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::LineWidth::getEventCallback, &osg::LineWidth::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgLineWidth::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgLineWidth::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLineWidth::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLineWidth::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLineWidth::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::LineWidth, RefosgLineWidth> _registerRefosgLineWidth;
