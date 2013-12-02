#include <reflection/reflectionregistry.h>
#include <osgParticle/RandomRateCounter>
#include <stdexcept>

/**
 * Reflector of class osgParticle::RandomRateCounter
 */
class RefosgParticleRandomRateCounter: public ClassReflection {
public:
	RefosgParticleRandomRateCounter();
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
	osg::ref_ptr<osgParticle::RandomRateCounter> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rate_range","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleRandomRateCounter::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgParticleRandomRateCounter::_table_names;

std::string RefosgParticleRandomRateCounter::_class_name("osgParticle::RandomRateCounter");

std::string RefosgParticleRandomRateCounter::_class_description("     ");

std::string RefosgParticleRandomRateCounter::_osg_version("1.2");


/**********************************************************/
RefosgParticleRandomRateCounter::RefosgParticleRandomRateCounter() {
}

/**********************************************************/
void RefosgParticleRandomRateCounter::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::RandomRateCounter*>(obj);
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
void RefosgParticleRandomRateCounter::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleRandomRateCounter::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleRandomRateCounter::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleRandomRateCounter::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleRandomRateCounter::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::RandomRateCounter::getName, (setNameFN)&osgParticle::RandomRateCounter::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::RandomRateCounter::getDataVariance, &osgParticle::RandomRateCounter::setDataVariance, osg_object_datavariance);
	}
	if (name == "_rate_range") {
		// Setter overloaded, must specify one type
		typedef void (osgParticle::VariableRateCounter::*setRateRangeFN)(const rangef &) ;
		return new GetterSetterProperty<rangef, osgParticle::VariableRateCounter>("_rate_range", _object.get(), &osgParticle::RandomRateCounter::getRateRange, (setRateRangeFN)&osgParticle::RandomRateCounter::setRateRange);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::RandomRateCounter::getUserData, &osgParticle::RandomRateCounter::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleRandomRateCounter::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleRandomRateCounter::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleRandomRateCounter::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleRandomRateCounter::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleRandomRateCounter::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::RandomRateCounter, RefosgParticleRandomRateCounter> _registerRefosgParticleRandomRateCounter;
