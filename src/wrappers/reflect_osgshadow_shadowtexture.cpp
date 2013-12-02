#include <reflection/reflectionregistry.h>
#include <osgShadow/ShadowTexture>
#include <stdexcept>

/**
 * Reflector of class osgShadow::ShadowTexture
 */
class RefosgShadowShadowTexture: public ClassReflection {
public:
	RefosgShadowShadowTexture();
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
	osg::ref_ptr<osgShadow::ShadowTexture> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_textureUnit","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowShadowTexture::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgShadowShadowTexture::_table_names;

std::string RefosgShadowShadowTexture::_class_name("osgShadow::ShadowTexture");

std::string RefosgShadowShadowTexture::_class_description(" ShadowedTexture provides an implementation of shadow textures.     ");

std::string RefosgShadowShadowTexture::_osg_version("1.2");


/**********************************************************/
RefosgShadowShadowTexture::RefosgShadowShadowTexture() {
}

/**********************************************************/
void RefosgShadowShadowTexture::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::ShadowTexture*>(obj);
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
void RefosgShadowShadowTexture::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowShadowTexture::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowShadowTexture::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowShadowTexture::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowShadowTexture::getProperty(const std::string &name) {
	if (name == "_textureUnit") {
		return new GetterSetterProperty<unsigned int, osgShadow::ShadowTexture>("_textureUnit", _object.get(), &osgShadow::ShadowTexture::getTextureUnit, &osgShadow::ShadowTexture::setTextureUnit);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::ShadowTexture::getDataVariance, &osgShadow::ShadowTexture::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::ShadowTexture::getName, (setNameFN)&osgShadow::ShadowTexture::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::ShadowTexture::getUserData, &osgShadow::ShadowTexture::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowTexture::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowTexture::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowShadowTexture::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowTexture::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowTexture::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::ShadowTexture, RefosgShadowShadowTexture> _registerRefosgShadowShadowTexture;
