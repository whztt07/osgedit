#include <reflection/reflectionregistry.h>
#include <osgSim/LightPointSystem>
#include <stdexcept>

/**
 * Reflector of class osgSim::LightPointSystem
 */
class RefosgSimLightPointSystem: public ClassReflection {
public:
	RefosgSimLightPointSystem();
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
	osg::ref_ptr<osgSim::LightPointSystem> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_intensity","_animationState","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgSimLightPointSystem::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgSimLightPointSystem::_table_names;

std::string RefosgSimLightPointSystem::_class_name("osgSim::LightPointSystem");

std::string RefosgSimLightPointSystem::_class_description("     ");

std::string RefosgSimLightPointSystem::_osg_version("1.2");


/**********************************************************/
RefosgSimLightPointSystem::RefosgSimLightPointSystem() {
}

/**********************************************************/
void RefosgSimLightPointSystem::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::LightPointSystem*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osgsim_lightpointsystem_animationstate: public Enum<osgSim::LightPointSystem::AnimationState> {
public:
	Enum_osgsim_lightpointsystem_animationstate() {
		add("ANIMATION_ON", osgSim::LightPointSystem::ANIMATION_ON);
		add("ANIMATION_OFF", osgSim::LightPointSystem::ANIMATION_OFF);
		add("ANIMATION_RANDOM", osgSim::LightPointSystem::ANIMATION_RANDOM);
	}
} osgsim_lightpointsystem_animationstate;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimLightPointSystem::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgSimLightPointSystem::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgSimLightPointSystem::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgSimLightPointSystem::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimLightPointSystem::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::LightPointSystem::getName, (setNameFN)&osgSim::LightPointSystem::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::LightPointSystem::getDataVariance, &osgSim::LightPointSystem::setDataVariance, osg_object_datavariance);
	}
	if (name == "_intensity") {
		// Getter overloaded, must specify one type
		typedef float (osgSim::LightPointSystem::*getIntensityFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::LightPointSystem::*setIntensityFN)(float) ;
		return new GetterSetterProperty<float, osgSim::LightPointSystem>("_intensity", _object.get(), (getIntensityFN)&osgSim::LightPointSystem::getIntensity, (setIntensityFN)&osgSim::LightPointSystem::setIntensity);
	}
	if (name == "_animationState") {
		return new GetterSetterEnumProperty<osgSim::LightPointSystem::AnimationState, osgSim::LightPointSystem>("_animationState", _object.get(), &osgSim::LightPointSystem::getAnimationState, &osgSim::LightPointSystem::setAnimationState, osgsim_lightpointsystem_animationstate);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::LightPointSystem::getUserData, &osgSim::LightPointSystem::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimLightPointSystem::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimLightPointSystem::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimLightPointSystem::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimLightPointSystem::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimLightPointSystem::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::LightPointSystem, RefosgSimLightPointSystem> _registerRefosgSimLightPointSystem;
