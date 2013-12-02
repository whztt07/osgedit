#include <reflection/reflectionregistry.h>
#include <osgShadow/ShadowVolume>
#include <stdexcept>

/**
 * Reflector of class osgShadow::ShadowVolume
 */
class RefosgShadowShadowVolume: public ClassReflection {
public:
	RefosgShadowShadowVolume();
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
	osg::ref_ptr<osgShadow::ShadowVolume> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_drawMode","_dynamicShadowVolumes","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowShadowVolume::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgShadowShadowVolume::_table_names;

std::string RefosgShadowShadowVolume::_class_name("osgShadow::ShadowVolume");

std::string RefosgShadowShadowVolume::_class_description(" ShadowedTexture provides an implementation of shadow textures.     ");

std::string RefosgShadowShadowVolume::_osg_version("1.2");


/**********************************************************/
RefosgShadowShadowVolume::RefosgShadowShadowVolume() {
}

/**********************************************************/
void RefosgShadowShadowVolume::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::ShadowVolume*>(obj);
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
void RefosgShadowShadowVolume::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowShadowVolume::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowShadowVolume::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowShadowVolume::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowShadowVolume::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::ShadowVolume::getName, (setNameFN)&osgShadow::ShadowVolume::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::ShadowVolume::getDataVariance, &osgShadow::ShadowVolume::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawMode") {
		return new GetterSetterProperty<osgShadow::ShadowVolumeGeometry::DrawMode, osgShadow::ShadowVolume>("_drawMode", _object.get(), &osgShadow::ShadowVolume::getDrawMode, &osgShadow::ShadowVolume::setDrawMode);
	}
	if (name == "_dynamicShadowVolumes") {
		return new GetterSetterProperty<bool, osgShadow::ShadowVolume>("_dynamicShadowVolumes", _object.get(), &osgShadow::ShadowVolume::getDynamicShadowVolumes, &osgShadow::ShadowVolume::setDynamicShadowVolumes);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::ShadowVolume::getUserData, &osgShadow::ShadowVolume::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowVolume::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowVolume::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowShadowVolume::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowVolume::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowVolume::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::ShadowVolume, RefosgShadowShadowVolume> _registerRefosgShadowShadowVolume;
