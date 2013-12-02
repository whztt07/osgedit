#include <reflection/reflectionregistry.h>
#include <osgShadow/SoftShadowMap>
#include <stdexcept>

/**
 * Reflector of class osgShadow::SoftShadowMap
 */
class RefosgShadowSoftShadowMap: public ClassReflection {
public:
	RefosgShadowSoftShadowMap();
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
	osg::ref_ptr<osgShadow::SoftShadowMap> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_bias","_userData","_textureSize","_ambientBias","_softnesswidth","_textureUnit","_jitteringscale","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowSoftShadowMap::_names(_propnames, _propnames+9);

ClassReflection::PropertyNames RefosgShadowSoftShadowMap::_table_names;

std::string RefosgShadowSoftShadowMap::_class_name("osgShadow::SoftShadowMap");

std::string RefosgShadowSoftShadowMap::_class_description(" SoftShadowMap provides an implementation of soft shadows with shadow maps.     ");

std::string RefosgShadowSoftShadowMap::_osg_version("1.2");


/**********************************************************/
RefosgShadowSoftShadowMap::RefosgShadowSoftShadowMap() {
}

/**********************************************************/
void RefosgShadowSoftShadowMap::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::SoftShadowMap*>(obj);
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
void RefosgShadowSoftShadowMap::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowSoftShadowMap::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowSoftShadowMap::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowSoftShadowMap::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowSoftShadowMap::getProperty(const std::string &name) {
	if (name == "_bias") {
		// Getter overloaded, must specify one type
		typedef float (osgShadow::SoftShadowMap::*getBiasFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgShadow::SoftShadowMap::*setBiasFN)(float) ;
		return new GetterSetterProperty<float, osgShadow::SoftShadowMap>("_bias", _object.get(), (getBiasFN)&osgShadow::SoftShadowMap::getBias, (setBiasFN)&osgShadow::SoftShadowMap::setBias);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::SoftShadowMap::getUserData, &osgShadow::SoftShadowMap::setUserData);
	}
	if (name == "_textureSize") {
		// Setter overloaded, must specify one type
		typedef void (osgShadow::SoftShadowMap::*setTextureSizeFN)(const osg::Vec2s &) ;
		return new GetterSetterProperty<osg::Vec2s, osgShadow::SoftShadowMap>("_textureSize", _object.get(), &osgShadow::SoftShadowMap::getTextureSize, (setTextureSizeFN)&osgShadow::SoftShadowMap::setTextureSize);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::SoftShadowMap::getDataVariance, &osgShadow::SoftShadowMap::setDataVariance, osg_object_datavariance);
	}
	if (name == "_ambientBias") {
		return new GetterSetterProperty<osg::Vec2, osgShadow::SoftShadowMap>("_ambientBias", _object.get(), &osgShadow::SoftShadowMap::getAmbientBias, &osgShadow::SoftShadowMap::setAmbientBias);
	}
	if (name == "_softnesswidth") {
		return new GetterSetterProperty<float, osgShadow::SoftShadowMap>("_softnesswidth", _object.get(), &osgShadow::SoftShadowMap::getSoftnessWidth, &osgShadow::SoftShadowMap::setSoftnessWidth);
	}
	if (name == "_textureUnit") {
		return new GetterSetterProperty<unsigned int, osgShadow::SoftShadowMap>("_textureUnit", _object.get(), &osgShadow::SoftShadowMap::getTextureUnit, &osgShadow::SoftShadowMap::setTextureUnit);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::SoftShadowMap::getName, (setNameFN)&osgShadow::SoftShadowMap::setName);
	}
	if (name == "_jitteringscale") {
		return new GetterSetterProperty<float, osgShadow::SoftShadowMap>("_jitteringscale", _object.get(), &osgShadow::SoftShadowMap::getJitteringScale, &osgShadow::SoftShadowMap::setJitteringScale);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowSoftShadowMap::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowSoftShadowMap::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowSoftShadowMap::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowSoftShadowMap::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowSoftShadowMap::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::SoftShadowMap, RefosgShadowSoftShadowMap> _registerRefosgShadowSoftShadowMap;
