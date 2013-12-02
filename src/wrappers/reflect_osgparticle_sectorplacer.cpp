#include <reflection/reflectionregistry.h>
#include <osgParticle/SectorPlacer>
#include <stdexcept>

/**
 * Reflector of class osgParticle::SectorPlacer
 */
class RefosgParticleSectorPlacer: public ClassReflection {
public:
	RefosgParticleSectorPlacer();
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
	osg::ref_ptr<osgParticle::SectorPlacer> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_phi_range","center_","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleSectorPlacer::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgParticleSectorPlacer::_table_names;

std::string RefosgParticleSectorPlacer::_class_name("osgParticle::SectorPlacer");

std::string RefosgParticleSectorPlacer::_class_description(" A sector-shaped particle placer. This placer sets the initial position of incoming particle by choosing a random position within a circular sector; this sector is defined by three parameters: a center point, which is inherited directly from osgParticle::CenteredPlacer, a range of values for radius, and a range of values for the central angle (sometimes called phi).     ");

std::string RefosgParticleSectorPlacer::_osg_version("1.2");


/**********************************************************/
RefosgParticleSectorPlacer::RefosgParticleSectorPlacer() {
}

/**********************************************************/
void RefosgParticleSectorPlacer::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::SectorPlacer*>(obj);
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
void RefosgParticleSectorPlacer::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleSectorPlacer::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleSectorPlacer::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleSectorPlacer::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleSectorPlacer::getProperty(const std::string &name) {
	if (name == "_phi_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::SectorPlacer::*setPhiRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::SectorPlacer>("_phi_range", _object.get(), &osgParticle::SectorPlacer::getPhiRange, (setPhiRangeFN)&osgParticle::SectorPlacer::setPhiRange);
	}
	if (name == "center_") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::CenteredPlacer::*setCenterFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::CenteredPlacer>("center_", _object.get(), &osgParticle::SectorPlacer::getCenter, (setCenterFN)&osgParticle::SectorPlacer::setCenter);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::SectorPlacer::getDataVariance, &osgParticle::SectorPlacer::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::SectorPlacer::getName, (setNameFN)&osgParticle::SectorPlacer::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::SectorPlacer::getUserData, &osgParticle::SectorPlacer::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleSectorPlacer::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleSectorPlacer::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleSectorPlacer::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleSectorPlacer::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleSectorPlacer::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::SectorPlacer, RefosgParticleSectorPlacer> _registerRefosgParticleSectorPlacer;
