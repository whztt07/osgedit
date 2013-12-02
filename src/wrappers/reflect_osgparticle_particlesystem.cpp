#include <reflection/reflectionregistry.h>
#include <osgParticle/ParticleSystem>
#include <stdexcept>

/**
 * Reflector of class osgParticle::ParticleSystem
 */
class RefosgParticleParticleSystem: public ClassReflection {
public:
	RefosgParticleParticleSystem();
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
	osg::ref_ptr<osgParticle::ParticleSystem> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_supportsDisplayList","_useDisplayList","_initialBound","_userData","_useVertexBufferObjects","_drawCallback","_updateCallback","_eventCallback","_cullCallback","_freeze_on_cull","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleParticleSystem::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgParticleParticleSystem::_table_names;

std::string RefosgParticleParticleSystem::_class_name("osgParticle::ParticleSystem");

std::string RefosgParticleParticleSystem::_class_description(" The heart of this class library; its purpose is to hold a set of particles and manage particle creation, update, rendering and destruction. You can add this drawable to any Geode as you usually do with other Drawable classes. Each instance of ParticleSystem is a separate set of particles; it provides the interface for creating particles and iterating through them (see the Emitter and Program classes).     ");

std::string RefosgParticleParticleSystem::_osg_version("1.2");


/**********************************************************/
RefosgParticleParticleSystem::RefosgParticleParticleSystem() {
}

/**********************************************************/
void RefosgParticleParticleSystem::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::ParticleSystem*>(obj);
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
void RefosgParticleParticleSystem::addChild(osg::Object *child) {
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleParticleSystem::removeChild(osg::Object *child) {
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleParticleSystem::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getShape();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleParticleSystem::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleParticleSystem::getProperty(const std::string &name) {
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osgParticle::ParticleSystem::getSupportsDisplayList, &osgParticle::ParticleSystem::setSupportsDisplayList);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osgParticle::ParticleSystem::getUseDisplayList, &osgParticle::ParticleSystem::setUseDisplayList);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osgParticle::ParticleSystem::getInitialBound, &osgParticle::ParticleSystem::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::ParticleSystem::getUserData, &osgParticle::ParticleSystem::setUserData);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useVertexBufferObjects", _object.get(), &osgParticle::ParticleSystem::getUseVertexBufferObjects, &osgParticle::ParticleSystem::setUseVertexBufferObjects);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::ParticleSystem::getDataVariance, &osgParticle::ParticleSystem::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osgParticle::ParticleSystem::getDrawCallback, &osgParticle::ParticleSystem::setDrawCallback);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osgParticle::ParticleSystem::getUpdateCallback, &osgParticle::ParticleSystem::setUpdateCallback);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osgParticle::ParticleSystem::getEventCallback, &osgParticle::ParticleSystem::setEventCallback);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osgParticle::ParticleSystem::getCullCallback, &osgParticle::ParticleSystem::setCullCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::ParticleSystem::getName, (setNameFN)&osgParticle::ParticleSystem::setName);
	}
	if (name == "_freeze_on_cull") {
		return new GetterSetterProperty<bool, osgParticle::ParticleSystem>("_freeze_on_cull", _object.get(), &osgParticle::ParticleSystem::getFreezeOnCull, &osgParticle::ParticleSystem::setFreezeOnCull);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleParticleSystem::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleParticleSystem::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleParticleSystem::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleParticleSystem::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleParticleSystem::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::ParticleSystem, RefosgParticleParticleSystem> _registerRefosgParticleParticleSystem;
