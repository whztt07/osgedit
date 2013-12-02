#include <reflection/reflectionregistry.h>
#include <osgParticle/FluidProgram>
#include <stdexcept>

/**
 * Reflector of class osgParticle::FluidProgram
 */
class RefosgParticleFluidProgram: public ClassReflection {
public:
	RefosgParticleFluidProgram();
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
	osg::ref_ptr<osgParticle::FluidProgram> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_wind","_resetTime","_initialBound","_userData","_startTime","_nodeMask","_lifeTime","_currentTime","_cullingActive","_acceleration","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleFluidProgram::_names(_propnames, _propnames+13);

ClassReflection::PropertyNames RefosgParticleFluidProgram::_table_names;

std::string RefosgParticleFluidProgram::_class_name("osgParticle::FluidProgram");

std::string RefosgParticleFluidProgram::_class_description(" A program class for performing operations on particles using a sequence of operators. To use a FluidProgram you have to create some Operator objects and add them to the program. All operators will be applied to each particle in the same order they've been added to the program.     ");

std::string RefosgParticleFluidProgram::_osg_version("1.2");


/**********************************************************/
RefosgParticleFluidProgram::RefosgParticleFluidProgram() {
}

/**********************************************************/
void RefosgParticleFluidProgram::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::FluidProgram*>(obj);
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
using namespace osg;

/**********************************************************/
void RefosgParticleFluidProgram::addChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(cobj);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleFluidProgram::removeChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(0);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleFluidProgram::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getUpdateCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getEventCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getCullCallback();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleFluidProgram::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleFluidProgram::getProperty(const std::string &name) {
	if (name == "_wind") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgParticle::FluidProgram::*getWindFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgParticle::FluidProgram::*setWindFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::FluidProgram>("_wind", _object.get(), (getWindFN)&osgParticle::FluidProgram::getWind, (setWindFN)&osgParticle::FluidProgram::setWind);
	}
	if (name == "_resetTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_resetTime", _object.get(), &osgParticle::FluidProgram::getResetTime, &osgParticle::FluidProgram::setResetTime);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgParticle::FluidProgram::getInitialBound, &osgParticle::FluidProgram::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::FluidProgram::getUserData, &osgParticle::FluidProgram::setUserData);
	}
	if (name == "_startTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_startTime", _object.get(), &osgParticle::FluidProgram::getStartTime, &osgParticle::FluidProgram::setStartTime);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgParticle::FluidProgram::getNodeMask, &osgParticle::FluidProgram::setNodeMask);
	}
	if (name == "_lifeTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_lifeTime", _object.get(), &osgParticle::FluidProgram::getLifeTime, &osgParticle::FluidProgram::setLifeTime);
	}
	if (name == "_currentTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_currentTime", _object.get(), &osgParticle::FluidProgram::getCurrentTime, &osgParticle::FluidProgram::setCurrentTime);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::FluidProgram::getName, (setNameFN)&osgParticle::FluidProgram::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgParticle::FluidProgram::getCullingActive, &osgParticle::FluidProgram::setCullingActive);
	}
	if (name == "_acceleration") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgParticle::FluidProgram::*getAccelerationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgParticle::FluidProgram::*setAccelerationFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::FluidProgram>("_acceleration", _object.get(), (getAccelerationFN)&osgParticle::FluidProgram::getAcceleration, (setAccelerationFN)&osgParticle::FluidProgram::setAcceleration);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::FluidProgram::getDataVariance, &osgParticle::FluidProgram::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgParticle::FluidProgram::getDescriptions, (setDescriptionsFN)&osgParticle::FluidProgram::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleFluidProgram::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleFluidProgram::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleFluidProgram::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleFluidProgram::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleFluidProgram::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::FluidProgram, RefosgParticleFluidProgram> _registerRefosgParticleFluidProgram;
