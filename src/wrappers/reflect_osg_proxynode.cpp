#include <reflection/reflectionregistry.h>
#include <osg/ProxyNode>
#include <stdexcept>

/**
 * Reflector of class osg::ProxyNode
 */
class RefosgProxyNode: public ClassReflection {
public:
	RefosgProxyNode();
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
	osg::ref_ptr<osg::ProxyNode> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_databasePath","_initialBound","_userData","_nodeMask","_cullingActive","_radius","_centerMode","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgProxyNode::_names(_propnames, _propnames+10);

ClassReflection::PropertyNames RefosgProxyNode::_table_names;

std::string RefosgProxyNode::_class_name("osg::ProxyNode");

std::string RefosgProxyNode::_class_description(" ProxyNode.     ");

std::string RefosgProxyNode::_osg_version("1.2");


/**********************************************************/
RefosgProxyNode::RefosgProxyNode() {
}

/**********************************************************/
void RefosgProxyNode::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::ProxyNode*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_proxynode_centermode: public Enum<osg::ProxyNode::CenterMode> {
public:
	Enum_osg_proxynode_centermode() {
		add("USE_BOUNDING_SPHERE_CENTER", osg::ProxyNode::USE_BOUNDING_SPHERE_CENTER);
		add("USER_DEFINED_CENTER", osg::ProxyNode::USER_DEFINED_CENTER);
	}
} osg_proxynode_centermode;

using namespace osg;

/**********************************************************/
void RefosgProxyNode::addChild(osg::Object *child) {
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
void RefosgProxyNode::removeChild(osg::Object *child) {
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
osg::Object *RefosgProxyNode::getChildObject(unsigned i) {
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
unsigned RefosgProxyNode::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgProxyNode::getProperty(const std::string &name) {
	if (name == "_databasePath") {
		return new GetterSetterProperty<std::string, osg::ProxyNode>("_databasePath", _object.get(), &osg::ProxyNode::getDatabasePath, &osg::ProxyNode::setDatabasePath);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::ProxyNode::getInitialBound, &osg::ProxyNode::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::ProxyNode::getUserData, &osg::ProxyNode::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::ProxyNode::getNodeMask, &osg::ProxyNode::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::ProxyNode::getName, (setNameFN)&osg::ProxyNode::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::ProxyNode::getCullingActive, &osg::ProxyNode::setCullingActive);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::ProxyNode::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::ProxyNode::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::ProxyNode>("_radius", _object.get(), (getRadiusFN)&osg::ProxyNode::getRadius, (setRadiusFN)&osg::ProxyNode::setRadius);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::ProxyNode::getDataVariance, &osg::ProxyNode::setDataVariance, osg_object_datavariance);
	}
	if (name == "_centerMode") {
		return new GetterSetterEnumProperty<osg::ProxyNode::CenterMode, osg::ProxyNode>("_centerMode", _object.get(), &osg::ProxyNode::getCenterMode, &osg::ProxyNode::setCenterMode, osg_proxynode_centermode);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::ProxyNode::getDescriptions, (setDescriptionsFN)&osg::ProxyNode::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgProxyNode::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgProxyNode::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgProxyNode::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgProxyNode::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgProxyNode::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::ProxyNode, RefosgProxyNode> _registerRefosgProxyNode;
