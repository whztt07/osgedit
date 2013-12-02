#include <reflection/reflectionregistry.h>
#include <osgParticle/ModularProgram>
#include <stdexcept>

/**
 * Reflector of class osgParticle::ModularProgram
 */
class RefosgParticleModularProgram: public ClassReflection {
public:
	RefosgParticleModularProgram();
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
	osg::ref_ptr<osgParticle::ModularProgram> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_resetTime","_initialBound","_userData","_startTime","_nodeMask","_lifeTime","_currentTime","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleModularProgram::_names(_propnames, _propnames+11);

ClassReflection::PropertyNames RefosgParticleModularProgram::_table_names;

std::string RefosgParticleModularProgram::_class_name("osgParticle::ModularProgram");

std::string RefosgParticleModularProgram::_class_description(" A program class for performing operations on particles using a sequence of operators. To use a ModularProgram you have to create some Operator objects and add them to the program. All operators will be applied to each particle in the same order they've been added to the program.     ");

std::string RefosgParticleModularProgram::_osg_version("1.2");


/**********************************************************/
RefosgParticleModularProgram::RefosgParticleModularProgram() {
}

/**********************************************************/
void RefosgParticleModularProgram::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::ModularProgram*>(obj);
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
void RefosgParticleModularProgram::addChild(osg::Object *child) {
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
void RefosgParticleModularProgram::removeChild(osg::Object *child) {
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
osg::Object *RefosgParticleModularProgram::getChildObject(unsigned i) {
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
unsigned RefosgParticleModularProgram::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleModularProgram::getProperty(const std::string &name) {
	if (name == "_resetTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_resetTime", _object.get(), &osgParticle::ModularProgram::getResetTime, &osgParticle::ModularProgram::setResetTime);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgParticle::ModularProgram::getInitialBound, &osgParticle::ModularProgram::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::ModularProgram::getUserData, &osgParticle::ModularProgram::setUserData);
	}
	if (name == "_startTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_startTime", _object.get(), &osgParticle::ModularProgram::getStartTime, &osgParticle::ModularProgram::setStartTime);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgParticle::ModularProgram::getNodeMask, &osgParticle::ModularProgram::setNodeMask);
	}
	if (name == "_lifeTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_lifeTime", _object.get(), &osgParticle::ModularProgram::getLifeTime, &osgParticle::ModularProgram::setLifeTime);
	}
	if (name == "_currentTime") {
		return new GetterSetterProperty<double, osgParticle::ParticleProcessor>("_currentTime", _object.get(), &osgParticle::ModularProgram::getCurrentTime, &osgParticle::ModularProgram::setCurrentTime);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::ModularProgram::getDataVariance, &osgParticle::ModularProgram::setDataVariance, osg_object_datavariance);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgParticle::ModularProgram::getCullingActive, &osgParticle::ModularProgram::setCullingActive);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::ModularProgram::getName, (setNameFN)&osgParticle::ModularProgram::setName);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgParticle::ModularProgram::getDescriptions, (setDescriptionsFN)&osgParticle::ModularProgram::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleModularProgram::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleModularProgram::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleModularProgram::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleModularProgram::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleModularProgram::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::ModularProgram, RefosgParticleModularProgram> _registerRefosgParticleModularProgram;
