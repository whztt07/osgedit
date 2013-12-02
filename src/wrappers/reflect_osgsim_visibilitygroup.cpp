#include <reflection/reflectionregistry.h>
#include <osgSim/VisibilityGroup>
#include <stdexcept>

/**
 * Reflector of class osgSim::VisibilityGroup
 */
class RefosgSimVisibilityGroup: public ClassReflection {
public:
	RefosgSimVisibilityGroup();
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
	osg::ref_ptr<osgSim::VisibilityGroup> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_segmentLength","_volumeIntersectionMask","_initialBound","_userData","_nodeMask","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSimVisibilityGroup::_names(_propnames, _propnames+9);

ClassReflection::PropertyNames RefosgSimVisibilityGroup::_table_names;

std::string RefosgSimVisibilityGroup::_class_name("osgSim::VisibilityGroup");

std::string RefosgSimVisibilityGroup::_class_description(" VisibilityGroup renders (traverses) it's children only when the camera is inside a specified visibility volume. The visibility volume is intersected with a line segment that extends from the current camera's eye-point along the view vector for a given segment length. If an intersection is detected then the node's children are traversed.     ");

std::string RefosgSimVisibilityGroup::_osg_version("1.2");


/**********************************************************/
RefosgSimVisibilityGroup::RefosgSimVisibilityGroup() {
}

/**********************************************************/
void RefosgSimVisibilityGroup::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::VisibilityGroup*>(obj);
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
void RefosgSimVisibilityGroup::addChild(osg::Object *child) {
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	{osg::Node *cobj = dynamic_cast<osg::Node *>(child);
	if (cobj != 0) {
		_object->setVisibilityVolume(cobj);
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
void RefosgSimVisibilityGroup::removeChild(osg::Object *child) {
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	{osg::Node *cobj = dynamic_cast<osg::Node *>(child);
	if (cobj != 0) {
		_object->setVisibilityVolume(0);
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
osg::Object *RefosgSimVisibilityGroup::getChildObject(unsigned i) {
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	if (i < 1) {
		return _object->getVisibilityVolume();
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
unsigned RefosgSimVisibilityGroup::getNumChildren() {
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
PropertyReflection* RefosgSimVisibilityGroup::getProperty(const std::string &name) {
	if (name == "_segmentLength") {
		return new GetterSetterProperty<float, osgSim::VisibilityGroup>("_segmentLength", _object.get(), &osgSim::VisibilityGroup::getSegmentLength, &osgSim::VisibilityGroup::setSegmentLength);
	}
	if (name == "_volumeIntersectionMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osgSim::VisibilityGroup>("_volumeIntersectionMask", _object.get(), &osgSim::VisibilityGroup::getVolumeIntersectionMask, &osgSim::VisibilityGroup::setVolumeIntersectionMask);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::VisibilityGroup::getInitialBound, &osgSim::VisibilityGroup::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::VisibilityGroup::getUserData, &osgSim::VisibilityGroup::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::VisibilityGroup::getNodeMask, &osgSim::VisibilityGroup::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::VisibilityGroup::getName, (setNameFN)&osgSim::VisibilityGroup::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::VisibilityGroup::getCullingActive, &osgSim::VisibilityGroup::setCullingActive);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::VisibilityGroup::getDataVariance, &osgSim::VisibilityGroup::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::VisibilityGroup::getDescriptions, (setDescriptionsFN)&osgSim::VisibilityGroup::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimVisibilityGroup::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimVisibilityGroup::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimVisibilityGroup::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimVisibilityGroup::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimVisibilityGroup::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::VisibilityGroup, RefosgSimVisibilityGroup> _registerRefosgSimVisibilityGroup;
