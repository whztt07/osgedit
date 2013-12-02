#include <reflection/reflectionregistry.h>
#include <osg/AutoTransform>
#include <stdexcept>

/**
 * Reflector of class osg::AutoTransform
 */
class RefosgAutoTransform: public ClassReflection {
public:
	RefosgAutoTransform();
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
	osg::ref_ptr<osg::AutoTransform> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rotation","_scale","_initialBound","_autoRotateMode","_nodeMask","_userData","_referenceFrame","_cullingActive","_autoUpdateEyeMovementTolerance","_pivotPoint","_autoScaleToScreen","_position","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgAutoTransform::_names(_propnames, _propnames+15);

ClassReflection::PropertyNames RefosgAutoTransform::_table_names;

std::string RefosgAutoTransform::_class_name("osg::AutoTransform");

std::string RefosgAutoTransform::_class_description(" AutoTransform is a derived form of Transform that automatically scales or rotates to keep its children aligned with screen coordinates.     ");

std::string RefosgAutoTransform::_osg_version("1.2");


/**********************************************************/
RefosgAutoTransform::RefosgAutoTransform() {
}

/**********************************************************/
void RefosgAutoTransform::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::AutoTransform*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_autotransform_autorotatemode: public Enum<osg::AutoTransform::AutoRotateMode> {
public:
	Enum_osg_autotransform_autorotatemode() {
		add("NO_ROTATION", osg::AutoTransform::NO_ROTATION);
		add("ROTATE_TO_SCREEN", osg::AutoTransform::ROTATE_TO_SCREEN);
		add("ROTATE_TO_CAMERA", osg::AutoTransform::ROTATE_TO_CAMERA);
	}
} osg_autotransform_autorotatemode;
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
void RefosgAutoTransform::addChild(osg::Object *child) {
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
void RefosgAutoTransform::removeChild(osg::Object *child) {
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
osg::Object *RefosgAutoTransform::getChildObject(unsigned i) {
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
unsigned RefosgAutoTransform::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgAutoTransform::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::AutoTransform::getDataVariance, &osg::AutoTransform::setDataVariance, osg_object_datavariance);
	}
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::AutoTransform::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::AutoTransform::*setRotationFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::AutoTransform>("_rotation", _object.get(), (getRotationFN)&osg::AutoTransform::getRotation, (setRotationFN)&osg::AutoTransform::setRotation);
	}
	if (name == "_scale") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::AutoTransform::*getScaleFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::AutoTransform::*setScaleFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::AutoTransform>("_scale", _object.get(), (getScaleFN)&osg::AutoTransform::getScale, (setScaleFN)&osg::AutoTransform::setScale);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::AutoTransform::getInitialBound, &osg::AutoTransform::setInitialBound);
	}
	if (name == "_autoRotateMode") {
		return new GetterSetterEnumProperty<osg::AutoTransform::AutoRotateMode, osg::AutoTransform>("_autoRotateMode", _object.get(), &osg::AutoTransform::getAutoRotateMode, &osg::AutoTransform::setAutoRotateMode, osg_autotransform_autorotatemode);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::AutoTransform::getNodeMask, &osg::AutoTransform::setNodeMask);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::AutoTransform::getUserData, &osg::AutoTransform::setUserData);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::Transform::ReferenceFrame, osg::Transform>("_referenceFrame", _object.get(), &osg::AutoTransform::getReferenceFrame, &osg::AutoTransform::setReferenceFrame, osg_transform_referenceframe);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::AutoTransform::getName, (setNameFN)&osg::AutoTransform::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::AutoTransform::getCullingActive, &osg::AutoTransform::setCullingActive);
	}
	if (name == "_autoUpdateEyeMovementTolerance") {
		return new GetterSetterProperty<float, osg::AutoTransform>("_autoUpdateEyeMovementTolerance", _object.get(), &osg::AutoTransform::getAutoUpdateEyeMovementTolerance, &osg::AutoTransform::setAutoUpdateEyeMovementTolerance);
	}
	if (name == "_pivotPoint") {
		return new GetterSetterProperty<Vec3, osg::AutoTransform>("_pivotPoint", _object.get(), &osg::AutoTransform::getPivotPoint, &osg::AutoTransform::setPivotPoint);
	}
	if (name == "_autoScaleToScreen") {
		return new GetterSetterProperty<bool, osg::AutoTransform>("_autoScaleToScreen", _object.get(), &osg::AutoTransform::getAutoScaleToScreen, &osg::AutoTransform::setAutoScaleToScreen);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::AutoTransform::*getPositionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::AutoTransform::*setPositionFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::AutoTransform>("_position", _object.get(), (getPositionFN)&osg::AutoTransform::getPosition, (setPositionFN)&osg::AutoTransform::setPosition);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::AutoTransform::getDescriptions, (setDescriptionsFN)&osg::AutoTransform::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgAutoTransform::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgAutoTransform::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgAutoTransform::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgAutoTransform::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgAutoTransform::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::AutoTransform, RefosgAutoTransform> _registerRefosgAutoTransform;
