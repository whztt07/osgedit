#include <reflection/reflectionregistry.h>
#include <osgParticle/SegmentPlacer>
#include <stdexcept>

/**
 * Reflector of class osgParticle::SegmentPlacer
 */
class RefosgParticleSegmentPlacer: public ClassReflection {
public:
	RefosgParticleSegmentPlacer();
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
	osg::ref_ptr<osgParticle::SegmentPlacer> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_vertexB","_vertexA","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleSegmentPlacer::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgParticleSegmentPlacer::_table_names;

std::string RefosgParticleSegmentPlacer::_class_name("osgParticle::SegmentPlacer");

std::string RefosgParticleSegmentPlacer::_class_description(" A segment-shaped particle placer. To use this placer you have to define a segment, by setting its two vertices (A and B); when an emitter requests a SegmentPlacer to place a particle, the position is chosen randomly within that segment.     ");

std::string RefosgParticleSegmentPlacer::_osg_version("1.2");


/**********************************************************/
RefosgParticleSegmentPlacer::RefosgParticleSegmentPlacer() {
}

/**********************************************************/
void RefosgParticleSegmentPlacer::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::SegmentPlacer*>(obj);
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
void RefosgParticleSegmentPlacer::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleSegmentPlacer::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleSegmentPlacer::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleSegmentPlacer::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleSegmentPlacer::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::SegmentPlacer::getDataVariance, &osgParticle::SegmentPlacer::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::SegmentPlacer::getName, (setNameFN)&osgParticle::SegmentPlacer::setName);
	}
	if (name == "_vertexB") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::SegmentPlacer::*setVertexBFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::SegmentPlacer>("_vertexB", _object.get(), &osgParticle::SegmentPlacer::getVertexB, (setVertexBFN)&osgParticle::SegmentPlacer::setVertexB);
	}
	if (name == "_vertexA") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::SegmentPlacer::*setVertexAFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::SegmentPlacer>("_vertexA", _object.get(), &osgParticle::SegmentPlacer::getVertexA, (setVertexAFN)&osgParticle::SegmentPlacer::setVertexA);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::SegmentPlacer::getUserData, &osgParticle::SegmentPlacer::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleSegmentPlacer::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleSegmentPlacer::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleSegmentPlacer::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleSegmentPlacer::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleSegmentPlacer::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::SegmentPlacer, RefosgParticleSegmentPlacer> _registerRefosgParticleSegmentPlacer;
