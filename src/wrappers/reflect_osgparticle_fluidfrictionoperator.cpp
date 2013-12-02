#include <reflection/reflectionregistry.h>
#include <osgParticle/FluidFrictionOperator>
#include <stdexcept>

/**
 * Reflector of class osgParticle::FluidFrictionOperator
 */
class RefosgParticleFluidFrictionOperator: public ClassReflection {
public:
	RefosgParticleFluidFrictionOperator();
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
	osg::ref_ptr<osgParticle::FluidFrictionOperator> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_wind","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleFluidFrictionOperator::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgParticleFluidFrictionOperator::_table_names;

std::string RefosgParticleFluidFrictionOperator::_class_name("osgParticle::FluidFrictionOperator");

std::string RefosgParticleFluidFrictionOperator::_class_description(" An operator that simulates the friction of a fluid. By using this operator you can let the particles move in a fluid of a given density and viscosity. There are two functions to quickly setup the parameters for pure water and air. You can decide whether to compute the forces using the particle's physical radius or another value, by calling the setOverrideRadius() method.     ");

std::string RefosgParticleFluidFrictionOperator::_osg_version("1.2");


/**********************************************************/
RefosgParticleFluidFrictionOperator::RefosgParticleFluidFrictionOperator() {
}

/**********************************************************/
void RefosgParticleFluidFrictionOperator::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::FluidFrictionOperator*>(obj);
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
void RefosgParticleFluidFrictionOperator::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleFluidFrictionOperator::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleFluidFrictionOperator::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleFluidFrictionOperator::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleFluidFrictionOperator::getProperty(const std::string &name) {
	if (name == "_wind") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgParticle::FluidFrictionOperator::*getWindFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgParticle::FluidFrictionOperator::*setWindFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::FluidFrictionOperator>("_wind", _object.get(), (getWindFN)&osgParticle::FluidFrictionOperator::getWind, (setWindFN)&osgParticle::FluidFrictionOperator::setWind);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::FluidFrictionOperator::getName, (setNameFN)&osgParticle::FluidFrictionOperator::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::FluidFrictionOperator::getDataVariance, &osgParticle::FluidFrictionOperator::setDataVariance, osg_object_datavariance);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::FluidFrictionOperator::getUserData, &osgParticle::FluidFrictionOperator::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleFluidFrictionOperator::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleFluidFrictionOperator::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleFluidFrictionOperator::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleFluidFrictionOperator::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleFluidFrictionOperator::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::FluidFrictionOperator, RefosgParticleFluidFrictionOperator> _registerRefosgParticleFluidFrictionOperator;
