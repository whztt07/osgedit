#include <reflection/reflectionregistry.h>
#include <osg/PointSprite>
#include <stdexcept>

/**
 * Reflector of class osg::PointSprite
 */
class RefosgPointSprite: public ClassReflection {
public:
	RefosgPointSprite();
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
	osg::ref_ptr<osg::PointSprite> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_coordOriginMode","_userData","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgPointSprite::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgPointSprite::_table_names;

std::string RefosgPointSprite::_class_name("osg::PointSprite");

std::string RefosgPointSprite::_class_description(" PointSprite base class which encapsulates enabling of point sprites .     ");

std::string RefosgPointSprite::_osg_version("1.2");


/**********************************************************/
RefosgPointSprite::RefosgPointSprite() {
}

/**********************************************************/
void RefosgPointSprite::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::PointSprite*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_pointsprite_coordoriginmode: public Enum<osg::PointSprite::CoordOriginMode> {
public:
	Enum_osg_pointsprite_coordoriginmode() {
		add("UPPER_LEFT", osg::PointSprite::UPPER_LEFT);
		add("LOWER_LEFT", osg::PointSprite::LOWER_LEFT);
	}
} osg_pointsprite_coordoriginmode;

using namespace osg;

/**********************************************************/
void RefosgPointSprite::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgPointSprite::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgPointSprite::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgPointSprite::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgPointSprite::getProperty(const std::string &name) {
	if (name == "_coordOriginMode") {
		return new GetterSetterEnumProperty<osg::PointSprite::CoordOriginMode, osg::PointSprite>("_coordOriginMode", _object.get(), &osg::PointSprite::getCoordOriginMode, &osg::PointSprite::setCoordOriginMode, osg_pointsprite_coordoriginmode);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::PointSprite::getUserData, &osg::PointSprite::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::PointSprite::getDataVariance, &osg::PointSprite::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::PointSprite::getUpdateCallback, &osg::PointSprite::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::PointSprite::getName, (setNameFN)&osg::PointSprite::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::PointSprite::getEventCallback, &osg::PointSprite::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgPointSprite::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgPointSprite::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgPointSprite::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPointSprite::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPointSprite::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::PointSprite, RefosgPointSprite> _registerRefosgPointSprite;
