#include <reflection/reflectionregistry.h>
#include <osgParticle/BoxPlacer>
#include <stdexcept>

/**
 * Reflector of class osgParticle::BoxPlacer
 */
class RefosgParticleBoxPlacer: public ClassReflection {
public:
	RefosgParticleBoxPlacer();
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
	osg::ref_ptr<osgParticle::BoxPlacer> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_z_range","_userData","center_","_x_range","_y_range","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleBoxPlacer::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgParticleBoxPlacer::_table_names;

std::string RefosgParticleBoxPlacer::_class_name("osgParticle::BoxPlacer");

std::string RefosgParticleBoxPlacer::_class_description(" A sector-shaped particle placer. This placer sets the initial position of incoming particle by choosing a random position within a circular sector; this sector is defined by three parameters: a center point, which is inherited directly from osgParticle::CenteredPlacer, a range of values for radius, and a range of values for the central angle (sometimes called phi).     ");

std::string RefosgParticleBoxPlacer::_osg_version("1.2");


/**********************************************************/
RefosgParticleBoxPlacer::RefosgParticleBoxPlacer() {
}

/**********************************************************/
void RefosgParticleBoxPlacer::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::BoxPlacer*>(obj);
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
void RefosgParticleBoxPlacer::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleBoxPlacer::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleBoxPlacer::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleBoxPlacer::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleBoxPlacer::getProperty(const std::string &name) {
	if (name == "_z_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::BoxPlacer::*setZRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::BoxPlacer>("_z_range", _object.get(), &osgParticle::BoxPlacer::getZRange, (setZRangeFN)&osgParticle::BoxPlacer::setZRange);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::BoxPlacer::getUserData, &osgParticle::BoxPlacer::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::BoxPlacer::getName, (setNameFN)&osgParticle::BoxPlacer::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::BoxPlacer::getDataVariance, &osgParticle::BoxPlacer::setDataVariance, osg_object_datavariance);
	}
	if (name == "center_") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::CenteredPlacer::*setCenterFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::CenteredPlacer>("center_", _object.get(), &osgParticle::BoxPlacer::getCenter, (setCenterFN)&osgParticle::BoxPlacer::setCenter);
	}
	if (name == "_x_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::BoxPlacer::*setXRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::BoxPlacer>("_x_range", _object.get(), &osgParticle::BoxPlacer::getXRange, (setXRangeFN)&osgParticle::BoxPlacer::setXRange);
	}
	if (name == "_y_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::BoxPlacer::*setYRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::BoxPlacer>("_y_range", _object.get(), &osgParticle::BoxPlacer::getYRange, (setYRangeFN)&osgParticle::BoxPlacer::setYRange);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleBoxPlacer::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleBoxPlacer::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleBoxPlacer::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleBoxPlacer::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleBoxPlacer::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::BoxPlacer, RefosgParticleBoxPlacer> _registerRefosgParticleBoxPlacer;
