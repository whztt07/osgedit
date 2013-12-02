#include <reflection/reflectionregistry.h>
#include <osgSim/MultiSwitch>
#include <stdexcept>

/**
 * Reflector of class osgSim::MultiSwitch
 */
class RefosgSimMultiSwitch: public ClassReflection {
public:
	RefosgSimMultiSwitch();
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
	osg::ref_ptr<osgSim::MultiSwitch> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_newChildDefaultValue","_initialBound","_userData","_nodeMask","_cullingActive","_activeSwitchSet","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSimMultiSwitch::_names(_propnames, _propnames+9);

ClassReflection::PropertyNames RefosgSimMultiSwitch::_table_names;

std::string RefosgSimMultiSwitch::_class_name("osgSim::MultiSwitch");

std::string RefosgSimMultiSwitch::_class_description(" MultiSwitch is a Group node which allows switching between sets of selected children. MultiSwtich is based on the OpenFlight switch behaviour.     ");

std::string RefosgSimMultiSwitch::_osg_version("1.2");


/**********************************************************/
RefosgSimMultiSwitch::RefosgSimMultiSwitch() {
}

/**********************************************************/
void RefosgSimMultiSwitch::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::MultiSwitch*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimMultiSwitch::addChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
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
void RefosgSimMultiSwitch::removeChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
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
osg::Object *RefosgSimMultiSwitch::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
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
unsigned RefosgSimMultiSwitch::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimMultiSwitch::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::MultiSwitch::getDataVariance, &osgSim::MultiSwitch::setDataVariance, osg_object_datavariance);
	}
	if (name == "_newChildDefaultValue") {
		return new GetterSetterProperty<bool, osgSim::MultiSwitch>("_newChildDefaultValue", _object.get(), &osgSim::MultiSwitch::getNewChildDefaultValue, &osgSim::MultiSwitch::setNewChildDefaultValue);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::MultiSwitch::getInitialBound, &osgSim::MultiSwitch::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::MultiSwitch::getUserData, &osgSim::MultiSwitch::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::MultiSwitch::getNodeMask, &osgSim::MultiSwitch::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::MultiSwitch::getName, (setNameFN)&osgSim::MultiSwitch::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::MultiSwitch::getCullingActive, &osgSim::MultiSwitch::setCullingActive);
	}
	if (name == "_activeSwitchSet") {
		return new GetterSetterProperty<unsigned int, osgSim::MultiSwitch>("_activeSwitchSet", _object.get(), &osgSim::MultiSwitch::getActiveSwitchSet, &osgSim::MultiSwitch::setActiveSwitchSet);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::MultiSwitch::getDescriptions, (setDescriptionsFN)&osgSim::MultiSwitch::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimMultiSwitch::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimMultiSwitch::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimMultiSwitch::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimMultiSwitch::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimMultiSwitch::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::MultiSwitch, RefosgSimMultiSwitch> _registerRefosgSimMultiSwitch;
