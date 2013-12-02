#include <reflection/reflectionregistry.h>
#include <osgShadow/ShadowTechnique>
#include <stdexcept>

/**
 * Reflector of class osgShadow::ShadowTechnique
 */
class RefosgShadowShadowTechnique: public ClassReflection {
public:
	RefosgShadowShadowTechnique();
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
	osg::ref_ptr<osgShadow::ShadowTechnique> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowShadowTechnique::_names(_propnames, _propnames+3);

ClassReflection::PropertyNames RefosgShadowShadowTechnique::_table_names;

std::string RefosgShadowShadowTechnique::_class_name("osgShadow::ShadowTechnique");

std::string RefosgShadowShadowTechnique::_class_description(" ShadowedScene provides a mechansim for decorating a scene that the needs to have shadows cast upon it.     ");

std::string RefosgShadowShadowTechnique::_osg_version("1.2");


/**********************************************************/
RefosgShadowShadowTechnique::RefosgShadowShadowTechnique() {
}

/**********************************************************/
void RefosgShadowShadowTechnique::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::ShadowTechnique*>(obj);
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
void RefosgShadowShadowTechnique::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowShadowTechnique::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowShadowTechnique::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowShadowTechnique::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowShadowTechnique::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::ShadowTechnique::getDataVariance, &osgShadow::ShadowTechnique::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::ShadowTechnique::getName, (setNameFN)&osgShadow::ShadowTechnique::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::ShadowTechnique::getUserData, &osgShadow::ShadowTechnique::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowTechnique::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowTechnique::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowShadowTechnique::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowTechnique::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowTechnique::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::ShadowTechnique, RefosgShadowShadowTechnique> _registerRefosgShadowShadowTechnique;
