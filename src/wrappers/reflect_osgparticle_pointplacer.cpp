#include <reflection/reflectionregistry.h>
#include <osgParticle/PointPlacer>
#include <stdexcept>

/**
 * Reflector of class osgParticle::PointPlacer
 */
class RefosgParticlePointPlacer: public ClassReflection {
public:
	RefosgParticlePointPlacer();
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
	osg::ref_ptr<osgParticle::PointPlacer> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","center_","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticlePointPlacer::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgParticlePointPlacer::_table_names;

std::string RefosgParticlePointPlacer::_class_name("osgParticle::PointPlacer");

std::string RefosgParticlePointPlacer::_class_description(" A point-shaped particle placer. This placer class uses the center point defined in its base class CenteredPlacer to place there all incoming particles.     ");

std::string RefosgParticlePointPlacer::_osg_version("1.2");


/**********************************************************/
RefosgParticlePointPlacer::RefosgParticlePointPlacer() {
}

/**********************************************************/
void RefosgParticlePointPlacer::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::PointPlacer*>(obj);
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
void RefosgParticlePointPlacer::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticlePointPlacer::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticlePointPlacer::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticlePointPlacer::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticlePointPlacer::getProperty(const std::string &name) {
	if (name == "center_") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::CenteredPlacer::*setCenterFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::CenteredPlacer>("center_", _object.get(), &osgParticle::PointPlacer::getCenter, (setCenterFN)&osgParticle::PointPlacer::setCenter);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::PointPlacer::getDataVariance, &osgParticle::PointPlacer::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::PointPlacer::getName, (setNameFN)&osgParticle::PointPlacer::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::PointPlacer::getUserData, &osgParticle::PointPlacer::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticlePointPlacer::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticlePointPlacer::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticlePointPlacer::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticlePointPlacer::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticlePointPlacer::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::PointPlacer, RefosgParticlePointPlacer> _registerRefosgParticlePointPlacer;
