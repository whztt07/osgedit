#include <reflection/reflectionregistry.h>
#include <osgSim/LightPointNode>
#include <stdexcept>

/**
 * Reflector of class osgSim::LightPointNode
 */
class RefosgSimLightPointNode: public ClassReflection {
public:
	RefosgSimLightPointNode();
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
	osg::ref_ptr<osgSim::LightPointNode> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_maxPixelSize","_initialBound","_userData","_nodeMask","_pointSprites","_cullingActive","_lightPointList","_minPixelSize","_maxVisibleDistance2","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSimLightPointNode::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgSimLightPointNode::_table_names;

std::string RefosgSimLightPointNode::_class_name("osgSim::LightPointNode");

std::string RefosgSimLightPointNode::_class_description("     ");

std::string RefosgSimLightPointNode::_osg_version("1.2");


/**********************************************************/
RefosgSimLightPointNode::RefosgSimLightPointNode() {
}

/**********************************************************/
void RefosgSimLightPointNode::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::LightPointNode*>(obj);
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
void RefosgSimLightPointNode::addChild(osg::Object *child) {
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
void RefosgSimLightPointNode::removeChild(osg::Object *child) {
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
osg::Object *RefosgSimLightPointNode::getChildObject(unsigned i) {
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
unsigned RefosgSimLightPointNode::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimLightPointNode::getProperty(const std::string &name) {
	if (name == "_maxPixelSize") {
		return new GetterSetterProperty<float, osgSim::LightPointNode>("_maxPixelSize", _object.get(), &osgSim::LightPointNode::getMaxPixelSize, &osgSim::LightPointNode::setMaxPixelSize);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::LightPointNode::getInitialBound, &osgSim::LightPointNode::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::LightPointNode::getUserData, &osgSim::LightPointNode::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::LightPointNode::getNodeMask, &osgSim::LightPointNode::setNodeMask);
	}
	if (name == "_pointSprites") {
		return new GetterSetterProperty<bool, osgSim::LightPointNode>("_pointSprites", _object.get(), &osgSim::LightPointNode::getPointSprite, &osgSim::LightPointNode::setPointSprite);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::LightPointNode::getName, (setNameFN)&osgSim::LightPointNode::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::LightPointNode::getCullingActive, &osgSim::LightPointNode::setCullingActive);
	}
	if (name == "_lightPointList") {
		// Getter overloaded, must specify one type
		typedef osgSim::LightPointNode::LightPointList & (osgSim::LightPointNode::*getLightPointListFN)() ;
		return new GetterSetterProperty<osgSim::LightPointNode::LightPointList, osgSim::LightPointNode>("_lightPointList", _object.get(), (getLightPointListFN)&osgSim::LightPointNode::getLightPointList, &osgSim::LightPointNode::setLightPointList);
	}
	if (name == "_minPixelSize") {
		return new GetterSetterProperty<float, osgSim::LightPointNode>("_minPixelSize", _object.get(), &osgSim::LightPointNode::getMinPixelSize, &osgSim::LightPointNode::setMinPixelSize);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::LightPointNode::getDataVariance, &osgSim::LightPointNode::setDataVariance, osg_object_datavariance);
	}
	if (name == "_maxVisibleDistance2") {
		return new GetterSetterProperty<float, osgSim::LightPointNode>("_maxVisibleDistance2", _object.get(), &osgSim::LightPointNode::getMaxVisibleDistance2, &osgSim::LightPointNode::setMaxVisibleDistance2);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::LightPointNode::getDescriptions, (setDescriptionsFN)&osgSim::LightPointNode::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimLightPointNode::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimLightPointNode::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimLightPointNode::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimLightPointNode::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimLightPointNode::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::LightPointNode, RefosgSimLightPointNode> _registerRefosgSimLightPointNode;
