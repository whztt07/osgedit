#include <reflection/reflectionregistry.h>
#include <osgSim/DOFTransform>
#include <stdexcept>

/**
 * Reflector of class osgSim::DOFTransform
 */
class RefosgSimDOFTransform: public ClassReflection {
public:
	RefosgSimDOFTransform();
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
	osg::ref_ptr<osgSim::DOFTransform> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_nodeMask","_minScale","_incrementTranslate","_cullingActive","_currentHPR","_currentScale","_maxTranslate","_descriptions","_minTranslate","_limitationFlags","_incrementScale","_userData","_maxScale","_minHPR","_incrementHPR","_animationOn","_referenceFrame","_currentTranslate","_maxHPR","_dataVariance"};
ClassReflection::PropertyNames RefosgSimDOFTransform::_names(_propnames, _propnames+22);

ClassReflection::PropertyNames RefosgSimDOFTransform::_table_names;

std::string RefosgSimDOFTransform::_class_name("osgSim::DOFTransform");

std::string RefosgSimDOFTransform::_class_description(" DOFTransform - encapsulates Multigen DOF behavior     ");

std::string RefosgSimDOFTransform::_osg_version("1.2");


/**********************************************************/
RefosgSimDOFTransform::RefosgSimDOFTransform() {
}

/**********************************************************/
void RefosgSimDOFTransform::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::DOFTransform*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_transform_referenceframe: public Enum<osg::Transform::ReferenceFrame> {
public:
	Enum_osg_transform_referenceframe() {
		add("RELATIVE_RF", osg::Transform::RELATIVE_RF);
		add("ABSOLUTE_RF", osg::Transform::ABSOLUTE_RF);
		add("ABSOLUTE_RF_INHERIT_VIEWPOINT", osg::Transform::ABSOLUTE_RF_INHERIT_VIEWPOINT);
	}
} osg_transform_referenceframe;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimDOFTransform::addChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
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
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgSimDOFTransform::removeChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
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
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgSimDOFTransform::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getCullCallback();
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
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgSimDOFTransform::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimDOFTransform::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::DOFTransform::getInitialBound, &osgSim::DOFTransform::setInitialBound);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::DOFTransform::getNodeMask, &osgSim::DOFTransform::setNodeMask);
	}
	if (name == "_minScale") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_minScale", _object.get(), &osgSim::DOFTransform::getMinScale, &osgSim::DOFTransform::setMinScale);
	}
	if (name == "_incrementTranslate") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_incrementTranslate", _object.get(), &osgSim::DOFTransform::getIncrementTranslate, &osgSim::DOFTransform::setIncrementTranslate);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::DOFTransform::getCullingActive, &osgSim::DOFTransform::setCullingActive);
	}
	if (name == "_currentHPR") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_currentHPR", _object.get(), &osgSim::DOFTransform::getCurrentHPR, &osgSim::DOFTransform::setCurrentHPR);
	}
	if (name == "_currentScale") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_currentScale", _object.get(), &osgSim::DOFTransform::getCurrentScale, &osgSim::DOFTransform::setCurrentScale);
	}
	if (name == "_maxTranslate") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_maxTranslate", _object.get(), &osgSim::DOFTransform::getMaxTranslate, &osgSim::DOFTransform::setMaxTranslate);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::DOFTransform::getDescriptions, (setDescriptionsFN)&osgSim::DOFTransform::setDescriptions);
	}
	if (name == "_minTranslate") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_minTranslate", _object.get(), &osgSim::DOFTransform::getMinTranslate, &osgSim::DOFTransform::setMinTranslate);
	}
	if (name == "_limitationFlags") {
		return new GetterSetterProperty<unsigned long, osgSim::DOFTransform>("_limitationFlags", _object.get(), &osgSim::DOFTransform::getLimitationFlags, &osgSim::DOFTransform::setLimitationFlags);
	}
	if (name == "_incrementScale") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_incrementScale", _object.get(), &osgSim::DOFTransform::getIncrementScale, &osgSim::DOFTransform::setIncrementScale);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::DOFTransform::getUserData, &osgSim::DOFTransform::setUserData);
	}
	if (name == "_maxScale") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_maxScale", _object.get(), &osgSim::DOFTransform::getMaxScale, &osgSim::DOFTransform::setMaxScale);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::DOFTransform::getDataVariance, &osgSim::DOFTransform::setDataVariance, osg_object_datavariance);
	}
	if (name == "_minHPR") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_minHPR", _object.get(), &osgSim::DOFTransform::getMinHPR, &osgSim::DOFTransform::setMinHPR);
	}
	if (name == "_incrementHPR") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_incrementHPR", _object.get(), &osgSim::DOFTransform::getIncrementHPR, &osgSim::DOFTransform::setIncrementHPR);
	}
	if (name == "_animationOn") {
		return new GetterSetterProperty<bool, osgSim::DOFTransform>("_animationOn", _object.get(), &osgSim::DOFTransform::getAnimationOn, &osgSim::DOFTransform::setAnimationOn);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::Transform::ReferenceFrame, osg::Transform>("_referenceFrame", _object.get(), &osgSim::DOFTransform::getReferenceFrame, &osgSim::DOFTransform::setReferenceFrame, osg_transform_referenceframe);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::DOFTransform::getName, (setNameFN)&osgSim::DOFTransform::setName);
	}
	if (name == "_currentTranslate") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_currentTranslate", _object.get(), &osgSim::DOFTransform::getCurrentTranslate, &osgSim::DOFTransform::setCurrentTranslate);
	}
	if (name == "_maxHPR") {
		return new GetterSetterProperty<osg::Vec3, osgSim::DOFTransform>("_maxHPR", _object.get(), &osgSim::DOFTransform::getMaxHPR, &osgSim::DOFTransform::setMaxHPR);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimDOFTransform::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimDOFTransform::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimDOFTransform::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimDOFTransform::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimDOFTransform::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::DOFTransform, RefosgSimDOFTransform> _registerRefosgSimDOFTransform;
