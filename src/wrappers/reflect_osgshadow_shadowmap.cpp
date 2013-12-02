#include <reflection/reflectionregistry.h>
#include <osgShadow/ShadowMap>
#include <stdexcept>

/**
 * Reflector of class osgShadow::ShadowMap
 */
class RefosgShadowShadowMap: public ClassReflection {
public:
	RefosgShadowShadowMap();
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
	osg::ref_ptr<osgShadow::ShadowMap> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_ambientBias","_textureSize","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowShadowMap::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgShadowShadowMap::_table_names;

std::string RefosgShadowShadowMap::_class_name("osgShadow::ShadowMap");

std::string RefosgShadowShadowMap::_class_description(" ShadowedTexture provides an implementation of shadow textures.     ");

std::string RefosgShadowShadowMap::_osg_version("1.2");


/**********************************************************/
RefosgShadowShadowMap::RefosgShadowShadowMap() {
}

/**********************************************************/
void RefosgShadowShadowMap::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::ShadowMap*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgShadow;
using namespace osg;

/**********************************************************/
void RefosgShadowShadowMap::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowShadowMap::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowShadowMap::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowShadowMap::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowShadowMap::getProperty(const std::string &name) {
	if (name == "_ambientBias") {
		return new GetterSetterProperty<osg::Vec2, osgShadow::ShadowMap>("_ambientBias", _object.get(), &osgShadow::ShadowMap::getAmbientBias, &osgShadow::ShadowMap::setAmbientBias);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::ShadowMap::getDataVariance, &osgShadow::ShadowMap::setDataVariance, osg_object_datavariance);
	}
	if (name == "_textureSize") {
		return new GetterSetterProperty<osg::Vec2s, osgShadow::ShadowMap>("_textureSize", _object.get(), &osgShadow::ShadowMap::getTextureSize, &osgShadow::ShadowMap::setTextureSize);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::ShadowMap::getName, (setNameFN)&osgShadow::ShadowMap::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::ShadowMap::getUserData, &osgShadow::ShadowMap::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowMap::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowMap::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowShadowMap::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowMap::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowMap::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::ShadowMap, RefosgShadowShadowMap> _registerRefosgShadowShadowMap;
