#include <reflection/reflectionregistry.h>
#include <osg/TexGenNode>
#include <stdexcept>

/**
 * Reflector of class osg::TexGenNode
 */
class RefosgTexGenNode: public ClassReflection {
public:
	RefosgTexGenNode();
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
	osg::ref_ptr<osg::TexGenNode> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_referenceFrame","_cullingActive","_textureUnit","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgTexGenNode::_names(_propnames, _propnames+9);

ClassReflection::PropertyNames RefosgTexGenNode::_table_names;

std::string RefosgTexGenNode::_class_name("osg::TexGenNode");

std::string RefosgTexGenNode::_class_description(" Node for defining the position of TexGen in the scene.     ");

std::string RefosgTexGenNode::_osg_version("1.2");


/**********************************************************/
RefosgTexGenNode::RefosgTexGenNode() {
}

/**********************************************************/
void RefosgTexGenNode::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TexGenNode*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_texgennode_referenceframe: public Enum<osg::TexGenNode::ReferenceFrame> {
public:
	Enum_osg_texgennode_referenceframe() {
		add("RELATIVE_RF", osg::TexGenNode::RELATIVE_RF);
		add("ABSOLUTE_RF", osg::TexGenNode::ABSOLUTE_RF);
	}
} osg_texgennode_referenceframe;

using namespace osg;

/**********************************************************/
void RefosgTexGenNode::addChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
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
	{TexGen *cobj = dynamic_cast<TexGen *>(child);
	if (cobj != 0) {
		_object->setTexGen(cobj);
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
void RefosgTexGenNode::removeChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
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
	{TexGen *cobj = dynamic_cast<TexGen *>(child);
	if (cobj != 0) {
		_object->setTexGen(0);
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
osg::Object *RefosgTexGenNode::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
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
		return _object->getTexGen();
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
unsigned RefosgTexGenNode::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt+= _object->getNumChildren();
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexGenNode::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::TexGenNode::getInitialBound, &osg::TexGenNode::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TexGenNode::getUserData, &osg::TexGenNode::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::TexGenNode::getNodeMask, &osg::TexGenNode::setNodeMask);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::TexGenNode::ReferenceFrame, osg::TexGenNode>("_referenceFrame", _object.get(), &osg::TexGenNode::getReferenceFrame, &osg::TexGenNode::setReferenceFrame, osg_texgennode_referenceframe);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TexGenNode::getName, (setNameFN)&osg::TexGenNode::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::TexGenNode::getCullingActive, &osg::TexGenNode::setCullingActive);
	}
	if (name == "_textureUnit") {
		return new GetterSetterProperty<unsigned int, osg::TexGenNode>("_textureUnit", _object.get(), &osg::TexGenNode::getTextureUnit, &osg::TexGenNode::setTextureUnit);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TexGenNode::getDataVariance, &osg::TexGenNode::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::TexGenNode::getDescriptions, (setDescriptionsFN)&osg::TexGenNode::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexGenNode::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexGenNode::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexGenNode::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexGenNode::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexGenNode::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TexGenNode, RefosgTexGenNode> _registerRefosgTexGenNode;
