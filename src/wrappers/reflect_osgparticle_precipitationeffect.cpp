#include <reflection/reflectionregistry.h>
#include <osgParticle/PrecipitationEffect>
#include <stdexcept>

/**
 * Reflector of class osgParticle::PrecipitationEffect
 */
class RefosgParticlePrecipitationEffect: public ClassReflection {
public:
	RefosgParticlePrecipitationEffect();
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
	osg::ref_ptr<osgParticle::PrecipitationEffect> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_useFarLineSegments","_wind","_initialBound","_particleSize","_nodeMask","_userData","_particleSpeed","_cullingActive","_cellSize","_nearTransition","_farTransition","_particleColor","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgParticlePrecipitationEffect::_names(_propnames, _propnames+15);

ClassReflection::PropertyNames RefosgParticlePrecipitationEffect::_table_names;

std::string RefosgParticlePrecipitationEffect::_class_name("osgParticle::PrecipitationEffect");

std::string RefosgParticlePrecipitationEffect::_class_description("     ");

std::string RefosgParticlePrecipitationEffect::_osg_version("1.2");


/**********************************************************/
RefosgParticlePrecipitationEffect::RefosgParticlePrecipitationEffect() {
}

/**********************************************************/
void RefosgParticlePrecipitationEffect::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::PrecipitationEffect*>(obj);
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
void RefosgParticlePrecipitationEffect::addChild(osg::Object *child) {
	{osg::Fog *cobj = dynamic_cast<osg::Fog *>(child);
	if (cobj != 0) {
		_object->setFog(cobj);
		return;
	}}
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
void RefosgParticlePrecipitationEffect::removeChild(osg::Object *child) {
	{osg::Fog *cobj = dynamic_cast<osg::Fog *>(child);
	if (cobj != 0) {
		_object->setFog(0);
		return;
	}}
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
osg::Object *RefosgParticlePrecipitationEffect::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getFog();
	} else {
		i -= 1;
	}
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
unsigned RefosgParticlePrecipitationEffect::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticlePrecipitationEffect::getProperty(const std::string &name) {
	if (name == "_useFarLineSegments") {
		return new GetterSetterProperty<bool, osgParticle::PrecipitationEffect>("_useFarLineSegments", _object.get(), &osgParticle::PrecipitationEffect::getUseFarLineSegments, &osgParticle::PrecipitationEffect::setUseFarLineSegments);
	}
	if (name == "_wind") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgParticle::PrecipitationEffect::*getWindFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgParticle::PrecipitationEffect::*setWindFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgParticle::PrecipitationEffect>("_wind", _object.get(), (getWindFN)&osgParticle::PrecipitationEffect::getWind, (setWindFN)&osgParticle::PrecipitationEffect::setWind);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgParticle::PrecipitationEffect::getInitialBound, &osgParticle::PrecipitationEffect::setInitialBound);
	}
	if (name == "_particleSize") {
		return new GetterSetterProperty<float, osgParticle::PrecipitationEffect>("_particleSize", _object.get(), &osgParticle::PrecipitationEffect::getParticleSize, &osgParticle::PrecipitationEffect::setParticleSize);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgParticle::PrecipitationEffect::getNodeMask, &osgParticle::PrecipitationEffect::setNodeMask);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::PrecipitationEffect::getUserData, &osgParticle::PrecipitationEffect::setUserData);
	}
	if (name == "_particleSpeed") {
		return new GetterSetterProperty<float, osgParticle::PrecipitationEffect>("_particleSpeed", _object.get(), &osgParticle::PrecipitationEffect::getParticleSpeed, &osgParticle::PrecipitationEffect::setParticleSpeed);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::PrecipitationEffect::getName, (setNameFN)&osgParticle::PrecipitationEffect::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgParticle::PrecipitationEffect::getCullingActive, &osgParticle::PrecipitationEffect::setCullingActive);
	}
	if (name == "_cellSize") {
		return new GetterSetterProperty<osg::Vec3, osgParticle::PrecipitationEffect>("_cellSize", _object.get(), &osgParticle::PrecipitationEffect::getCellSize, &osgParticle::PrecipitationEffect::setCellSize);
	}
	if (name == "_nearTransition") {
		return new GetterSetterProperty<float, osgParticle::PrecipitationEffect>("_nearTransition", _object.get(), &osgParticle::PrecipitationEffect::getNearTransition, &osgParticle::PrecipitationEffect::setNearTransition);
	}
	if (name == "_farTransition") {
		return new GetterSetterProperty<float, osgParticle::PrecipitationEffect>("_farTransition", _object.get(), &osgParticle::PrecipitationEffect::getFarTransition, &osgParticle::PrecipitationEffect::setFarTransition);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::PrecipitationEffect::getDataVariance, &osgParticle::PrecipitationEffect::setDataVariance, osg_object_datavariance);
	}
	if (name == "_particleColor") {
		return new GetterSetterProperty<osg::Vec4, osgParticle::PrecipitationEffect>("_particleColor", _object.get(), &osgParticle::PrecipitationEffect::getParticleColor, &osgParticle::PrecipitationEffect::setParticleColor);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgParticle::PrecipitationEffect::getDescriptions, (setDescriptionsFN)&osgParticle::PrecipitationEffect::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticlePrecipitationEffect::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticlePrecipitationEffect::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticlePrecipitationEffect::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticlePrecipitationEffect::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticlePrecipitationEffect::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::PrecipitationEffect, RefosgParticlePrecipitationEffect> _registerRefosgParticlePrecipitationEffect;
