#include <reflection/reflectionregistry.h>
#include <osg/LightSource>
#include <stdexcept>

/**
 * Reflector of class osg::LightSource
 */
class RefosgLightSource: public ClassReflection {
public:
	RefosgLightSource();
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
	osg::ref_ptr<osg::LightSource> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_referenceFrame","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgLightSource::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgLightSource::_table_names;

std::string RefosgLightSource::_class_name("osg::LightSource");

std::string RefosgLightSource::_class_description(" Leaf Node for defining a light in the scene.     ");

std::string RefosgLightSource::_osg_version("1.2");


/**********************************************************/
RefosgLightSource::RefosgLightSource() {
}

/**********************************************************/
void RefosgLightSource::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::LightSource*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_lightsource_referenceframe: public Enum<osg::LightSource::ReferenceFrame> {
public:
	Enum_osg_lightsource_referenceframe() {
		add("RELATIVE_RF", osg::LightSource::RELATIVE_RF);
		add("ABSOLUTE_RF", osg::LightSource::ABSOLUTE_RF);
	}
} osg_lightsource_referenceframe;

using namespace osg;

/**********************************************************/
void RefosgLightSource::addChild(osg::Object *child) {
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	{Light *cobj = dynamic_cast<Light *>(child);
	if (cobj != 0) {
		_object->setLight(cobj);
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
void RefosgLightSource::removeChild(osg::Object *child) {
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	{Light *cobj = dynamic_cast<Light *>(child);
	if (cobj != 0) {
		_object->setLight(0);
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
osg::Object *RefosgLightSource::getChildObject(unsigned i) {
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	if (i < 1) {
		return _object->getLight();
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
unsigned RefosgLightSource::getNumChildren() {
	unsigned cnt = 0;
	cnt+= _object->getNumChildren();
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLightSource::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::LightSource::getInitialBound, &osg::LightSource::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::LightSource::getUserData, &osg::LightSource::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::LightSource::getNodeMask, &osg::LightSource::setNodeMask);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::LightSource::ReferenceFrame, osg::LightSource>("_referenceFrame", _object.get(), &osg::LightSource::getReferenceFrame, &osg::LightSource::setReferenceFrame, osg_lightsource_referenceframe);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::LightSource::getName, (setNameFN)&osg::LightSource::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::LightSource::getCullingActive, &osg::LightSource::setCullingActive);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::LightSource::getDataVariance, &osg::LightSource::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::LightSource::getDescriptions, (setDescriptionsFN)&osg::LightSource::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgLightSource::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgLightSource::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLightSource::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLightSource::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLightSource::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::LightSource, RefosgLightSource> _registerRefosgLightSource;
