#include <reflection/reflectionregistry.h>
#include <osg/PositionAttitudeTransform>
#include <stdexcept>

/**
 * Reflector of class osg::PositionAttitudeTransform
 */
class RefosgPositionAttitudeTransform: public ClassReflection {
public:
	RefosgPositionAttitudeTransform();
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
	osg::ref_ptr<osg::PositionAttitudeTransform> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_attitude","_scale","_initialBound","_userData","_nodeMask","_referenceFrame","_cullingActive","_pivotPoint","_position","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgPositionAttitudeTransform::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgPositionAttitudeTransform::_table_names;

std::string RefosgPositionAttitudeTransform::_class_name("osg::PositionAttitudeTransform");

std::string RefosgPositionAttitudeTransform::_class_description(" PositionAttitudeTransform - is a Transform. Sets the coordinate transform via a Vec3 position and Quat attitude.     ");

std::string RefosgPositionAttitudeTransform::_osg_version("1.2");


/**********************************************************/
RefosgPositionAttitudeTransform::RefosgPositionAttitudeTransform() {
}

/**********************************************************/
void RefosgPositionAttitudeTransform::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::PositionAttitudeTransform*>(obj);
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

using namespace osg;

/**********************************************************/
void RefosgPositionAttitudeTransform::addChild(osg::Object *child) {
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
void RefosgPositionAttitudeTransform::removeChild(osg::Object *child) {
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
osg::Object *RefosgPositionAttitudeTransform::getChildObject(unsigned i) {
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
unsigned RefosgPositionAttitudeTransform::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgPositionAttitudeTransform::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::PositionAttitudeTransform::getDataVariance, &osg::PositionAttitudeTransform::setDataVariance, osg_object_datavariance);
	}
	if (name == "_attitude") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::PositionAttitudeTransform::*getAttitudeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PositionAttitudeTransform::*setAttitudeFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::PositionAttitudeTransform>("_attitude", _object.get(), (getAttitudeFN)&osg::PositionAttitudeTransform::getAttitude, (setAttitudeFN)&osg::PositionAttitudeTransform::setAttitude);
	}
	if (name == "_scale") {
		// Getter overloaded, must specify one type
		typedef const Vec3d & (osg::PositionAttitudeTransform::*getScaleFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PositionAttitudeTransform::*setScaleFN)(const Vec3d &) ;
		return new GetterSetterProperty<Vec3d, osg::PositionAttitudeTransform>("_scale", _object.get(), (getScaleFN)&osg::PositionAttitudeTransform::getScale, (setScaleFN)&osg::PositionAttitudeTransform::setScale);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::PositionAttitudeTransform::getInitialBound, &osg::PositionAttitudeTransform::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::PositionAttitudeTransform::getUserData, &osg::PositionAttitudeTransform::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::PositionAttitudeTransform::getNodeMask, &osg::PositionAttitudeTransform::setNodeMask);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::Transform::ReferenceFrame, osg::Transform>("_referenceFrame", _object.get(), &osg::PositionAttitudeTransform::getReferenceFrame, &osg::PositionAttitudeTransform::setReferenceFrame, osg_transform_referenceframe);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::PositionAttitudeTransform::getName, (setNameFN)&osg::PositionAttitudeTransform::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::PositionAttitudeTransform::getCullingActive, &osg::PositionAttitudeTransform::setCullingActive);
	}
	if (name == "_pivotPoint") {
		return new GetterSetterProperty<Vec3d, osg::PositionAttitudeTransform>("_pivotPoint", _object.get(), &osg::PositionAttitudeTransform::getPivotPoint, &osg::PositionAttitudeTransform::setPivotPoint);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef const Vec3d & (osg::PositionAttitudeTransform::*getPositionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PositionAttitudeTransform::*setPositionFN)(const Vec3d &) ;
		return new GetterSetterProperty<Vec3d, osg::PositionAttitudeTransform>("_position", _object.get(), (getPositionFN)&osg::PositionAttitudeTransform::getPosition, (setPositionFN)&osg::PositionAttitudeTransform::setPosition);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::PositionAttitudeTransform::getDescriptions, (setDescriptionsFN)&osg::PositionAttitudeTransform::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgPositionAttitudeTransform::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgPositionAttitudeTransform::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgPositionAttitudeTransform::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPositionAttitudeTransform::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPositionAttitudeTransform::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::PositionAttitudeTransform, RefosgPositionAttitudeTransform> _registerRefosgPositionAttitudeTransform;
