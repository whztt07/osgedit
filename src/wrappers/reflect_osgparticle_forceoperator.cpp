#include <reflection/reflectionregistry.h>
#include <osgParticle/ForceOperator>
#include <stdexcept>

/**
 * Reflector of class osgParticle::ForceOperator
 */
class RefosgParticleForceOperator: public ClassReflection {
public:
	RefosgParticleForceOperator();
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
	osg::ref_ptr<osgParticle::ForceOperator> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_force","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleForceOperator::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgParticleForceOperator::_table_names;

std::string RefosgParticleForceOperator::_class_name("osgParticle::ForceOperator");

std::string RefosgParticleForceOperator::_class_description(" An operator that applies a constant force to the particles. Remember that if the mass of particles is expressed in kg and the lengths are expressed in meters, then the force should be expressed in Newtons.     ");

std::string RefosgParticleForceOperator::_osg_version("1.2");


/**********************************************************/
RefosgParticleForceOperator::RefosgParticleForceOperator() {
}

/**********************************************************/
void RefosgParticleForceOperator::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::ForceOperator*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgParticle;

/**********************************************************/
void RefosgParticleForceOperator::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleForceOperator::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleForceOperator::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleForceOperator::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleForceOperator::getProperty(const std::string &name) {
	if (name == "_force") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgParticle::ForceOperator::*getForceFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgParticle::ForceOperator::*setForceFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::ForceOperator>("_force", _object.get(), (getForceFN)&osgParticle::ForceOperator::getForce, (setForceFN)&osgParticle::ForceOperator::setForce);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::ForceOperator::getDataVariance, &osgParticle::ForceOperator::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::ForceOperator::getName, (setNameFN)&osgParticle::ForceOperator::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::ForceOperator::getUserData, &osgParticle::ForceOperator::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleForceOperator::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleForceOperator::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleForceOperator::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleForceOperator::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleForceOperator::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::ForceOperator, RefosgParticleForceOperator> _registerRefosgParticleForceOperator;
