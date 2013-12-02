#include <reflection/reflectionregistry.h>
#include <osgParticle/ModularEmitter>
#include <stdexcept>

/**
 * Reflector of class osgParticle::ModularEmitter
 */
class RefosgParticleModularEmitter: public ClassReflection {
public:
	RefosgParticleModularEmitter();
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
	osg::ref_ptr<osgParticle::ModularEmitter> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_resetTime","_initialBound","_userData","_startTime","_nodeMask","_lifeTime","_currentTime","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleModularEmitter::_names(_propnames, _propnames+11);

ClassReflection::PropertyNames RefosgParticleModularEmitter::_table_names;

std::string RefosgParticleModularEmitter::_class_name("osgParticle::ModularEmitter");

std::string RefosgParticleModularEmitter::_class_description(" An emitter class that holds three objects to control the creation of particles. These objects are a counter, a placer and a shooter. The counter controls the number of particles to be emitted at each frame; the placer must initialize the particle's position vector, while the shooter initializes its velocity vector. You can use the predefined counter/placer/shooter classes, or you can create your own.     ");

std::string RefosgParticleModularEmitter::_osg_version("1.2");


/**********************************************************/
RefosgParticleModularEmitter::RefosgParticleModularEmitter() {
}

/**********************************************************/
void RefosgParticleModularEmitter::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::ModularEmitter*>(obj);
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
void RefosgParticleModularEmitter::addChild(osg::Object *child) {
	{Counter *cobj = dynamic_cast<Counter *>(child);
	if (cobj != 0) {
		_object->setCounter(cobj);
		return;
	}}
	{Shooter *cobj = dynamic_cast<Shooter *>(child);
	if (cobj != 0) {
		_object->setShooter(cobj);
		return;
	}}
	{Placer *cobj = dynamic_cast<Placer *>(child);
	if (cobj != 0) {
		_object->setPlacer(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
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
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleModularEmitter::removeChild(osg::Object *child) {
	{Counter *cobj = dynamic_cast<Counter *>(child);
	if (cobj != 0) {
		_object->setCounter(0);
		return;
	}}
	{Shooter *cobj = dynamic_cast<Shooter *>(child);
	if (cobj != 0) {
		_object->setShooter(0);
		return;
	}}
	{Placer *cobj = dynamic_cast<Placer *>(child);
	if (cobj != 0) {
		_object->setPlacer(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
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
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleModularEmitter::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getCounter();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getShooter();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getPlacer();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getUpdateCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getCullCallback();
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
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleModularEmitter::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleModularEmitter::getProperty(const std::string &name) {
	if (name == "_resetTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_resetTime", _object.get(), &osgParticle::ModularEmitter::getResetTime, &osgParticle::ModularEmitter::setResetTime);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgParticle::ModularEmitter::getInitialBound, &osgParticle::ModularEmitter::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::ModularEmitter::getUserData, &osgParticle::ModularEmitter::setUserData);
	}
	if (name == "_startTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_startTime", _object.get(), &osgParticle::ModularEmitter::getStartTime, &osgParticle::ModularEmitter::setStartTime);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgParticle::ModularEmitter::getNodeMask, &osgParticle::ModularEmitter::setNodeMask);
	}
	if (name == "_lifeTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_lifeTime", _object.get(), &osgParticle::ModularEmitter::getLifeTime, &osgParticle::ModularEmitter::setLifeTime);
	}
	if (name == "_currentTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_currentTime", _object.get(), &osgParticle::ModularEmitter::getCurrentTime, &osgParticle::ModularEmitter::setCurrentTime);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::ModularEmitter::getName, (setNameFN)&osgParticle::ModularEmitter::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgParticle::ModularEmitter::getCullingActive, &osgParticle::ModularEmitter::setCullingActive);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::ModularEmitter::getDataVariance, &osgParticle::ModularEmitter::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgParticle::ModularEmitter::getDescriptions, (setDescriptionsFN)&osgParticle::ModularEmitter::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleModularEmitter::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleModularEmitter::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleModularEmitter::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleModularEmitter::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleModularEmitter::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::ModularEmitter, RefosgParticleModularEmitter> _registerRefosgParticleModularEmitter;
