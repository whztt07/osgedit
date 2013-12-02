#include <reflection/reflectionregistry.h>
#include <osg/CoordinateSystemNode>
#include <stdexcept>

/**
 * Reflector of class osg::CoordinateSystemNode
 */
class RefosgCoordinateSystemNode: public ClassReflection {
public:
	RefosgCoordinateSystemNode();
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
	osg::ref_ptr<osg::CoordinateSystemNode> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_format","_nodeMask","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgCoordinateSystemNode::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgCoordinateSystemNode::_table_names;

std::string RefosgCoordinateSystemNode::_class_name("osg::CoordinateSystemNode");

std::string RefosgCoordinateSystemNode::_class_description(" CoordinateSystem encapsulate the coordinate system that is associated with objects in a scene. For an overview of common earth bases coordinate systems see http://www.colorado.edu/geography/gcraft/notes/coordsys/coordsys_f.html     ");

std::string RefosgCoordinateSystemNode::_osg_version("1.2");


/**********************************************************/
RefosgCoordinateSystemNode::RefosgCoordinateSystemNode() {
}

/**********************************************************/
void RefosgCoordinateSystemNode::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::CoordinateSystemNode*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osg;

/**********************************************************/
void RefosgCoordinateSystemNode::addChild(osg::Object *child) {
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	{EllipsoidModel *cobj = dynamic_cast<EllipsoidModel *>(child);
	if (cobj != 0) {
		_object->setEllipsoidModel(cobj);
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
void RefosgCoordinateSystemNode::removeChild(osg::Object *child) {
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	{EllipsoidModel *cobj = dynamic_cast<EllipsoidModel *>(child);
	if (cobj != 0) {
		_object->setEllipsoidModel(0);
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
osg::Object *RefosgCoordinateSystemNode::getChildObject(unsigned i) {
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	if (i < 1) {
		return _object->getEllipsoidModel();
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
unsigned RefosgCoordinateSystemNode::getNumChildren() {
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
PropertyReflection* RefosgCoordinateSystemNode::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::CoordinateSystemNode::getInitialBound, &osg::CoordinateSystemNode::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::CoordinateSystemNode::getUserData, &osg::CoordinateSystemNode::setUserData);
	}
	if (name == "_format") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::CoordinateSystemNode::*getFormatFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::CoordinateSystemNode::*setFormatFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::CoordinateSystemNode>("_format", _object.get(), (getFormatFN)&osg::CoordinateSystemNode::getFormat, (setFormatFN)&osg::CoordinateSystemNode::setFormat);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::CoordinateSystemNode::getNodeMask, &osg::CoordinateSystemNode::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::CoordinateSystemNode::getName, (setNameFN)&osg::CoordinateSystemNode::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::CoordinateSystemNode::getCullingActive, &osg::CoordinateSystemNode::setCullingActive);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::CoordinateSystemNode::getDataVariance, &osg::CoordinateSystemNode::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::CoordinateSystemNode::getDescriptions, (setDescriptionsFN)&osg::CoordinateSystemNode::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCoordinateSystemNode::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCoordinateSystemNode::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCoordinateSystemNode::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCoordinateSystemNode::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCoordinateSystemNode::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::CoordinateSystemNode, RefosgCoordinateSystemNode> _registerRefosgCoordinateSystemNode;
