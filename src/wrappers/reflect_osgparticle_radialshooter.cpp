#include <reflection/reflectionregistry.h>
#include <osgParticle/RadialShooter>
#include <stdexcept>

/**
 * Reflector of class osgParticle::RadialShooter
 */
class RefosgParticleRadialShooter: public ClassReflection {
public:
	RefosgParticleRadialShooter();
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
	osg::ref_ptr<osgParticle::RadialShooter> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rot_speed_range","_userData","_phi_range","_theta_range","_speed_range","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleRadialShooter::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgParticleRadialShooter::_table_names;

std::string RefosgParticleRadialShooter::_class_name("osgParticle::RadialShooter");

std::string RefosgParticleRadialShooter::_class_description(" A shooter class that shoots particles radially. This shooter computes the velocity vector of incoming particles by choosing a random direction and a random speed. Both direction and speed are chosen within specified ranges. The direction is defined by two angles: theta, which is the angle between the velocity vector and the Z axis, and phi, which is the angle between the X axis and the velocity vector projected onto the X-Y plane.     ");

std::string RefosgParticleRadialShooter::_osg_version("1.2");


/**********************************************************/
RefosgParticleRadialShooter::RefosgParticleRadialShooter() {
}

/**********************************************************/
void RefosgParticleRadialShooter::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::RadialShooter*>(obj);
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
void RefosgParticleRadialShooter::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleRadialShooter::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleRadialShooter::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleRadialShooter::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleRadialShooter::getProperty(const std::string &name) {
	if (name == "_rot_speed_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::RadialShooter::*setInitialRotationalSpeedRangeFN)(const rangev3 &) ;
		return new GetterSetterProperty<rangev3, osgParticle::RadialShooter>("_rot_speed_range", _object.get(), &osgParticle::RadialShooter::getInitialRotationalSpeedRange, (setInitialRotationalSpeedRangeFN)&osgParticle::RadialShooter::setInitialRotationalSpeedRange);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::RadialShooter::getUserData, &osgParticle::RadialShooter::setUserData);
	}
	if (name == "_phi_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::RadialShooter::*setPhiRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::RadialShooter>("_phi_range", _object.get(), &osgParticle::RadialShooter::getPhiRange, (setPhiRangeFN)&osgParticle::RadialShooter::setPhiRange);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::RadialShooter::getName, (setNameFN)&osgParticle::RadialShooter::setName);
	}
	if (name == "_theta_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::RadialShooter::*setThetaRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::RadialShooter>("_theta_range", _object.get(), &osgParticle::RadialShooter::getThetaRange, (setThetaRangeFN)&osgParticle::RadialShooter::setThetaRange);
	}
	if (name == "_speed_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::RadialShooter::*setInitialSpeedRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::RadialShooter>("_speed_range", _object.get(), &osgParticle::RadialShooter::getInitialSpeedRange, (setInitialSpeedRangeFN)&osgParticle::RadialShooter::setInitialSpeedRange);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::RadialShooter::getDataVariance, &osgParticle::RadialShooter::setDataVariance, osg_object_datavariance);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleRadialShooter::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleRadialShooter::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleRadialShooter::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleRadialShooter::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleRadialShooter::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::RadialShooter, RefosgParticleRadialShooter> _registerRefosgParticleRadialShooter;
