#include <reflection/reflectionregistry.h>
#include <osg/CameraView>
#include <stdexcept>

/**
 * Reflector of class osg::CameraView
 */
class RefosgCameraView: public ClassReflection {
public:
	RefosgCameraView();
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
	osg::ref_ptr<osg::CameraView> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_attitude","_fieldOfView","_initialBound","_userData","_nodeMask","_referenceFrame","_cullingActive","_focalLength","_position","_fieldOfViewMode","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgCameraView::_names(_propnames, _propnames+13);

ClassReflection::PropertyNames RefosgCameraView::_table_names;

std::string RefosgCameraView::_class_name("osg::CameraView");

std::string RefosgCameraView::_class_description(" CameraView - is a Transform that is used to specify camera views from within the scene graph. The application must attach a camera to a CameraView via the NodePath from the top of the scene graph to the CameraView node itself, and accimulate the view matrix from this NodePath.     ");

std::string RefosgCameraView::_osg_version("1.2");


/**********************************************************/
RefosgCameraView::RefosgCameraView() {
}

/**********************************************************/
void RefosgCameraView::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::CameraView*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_cameraview_fieldofviewmode: public Enum<osg::CameraView::FieldOfViewMode> {
public:
	Enum_osg_cameraview_fieldofviewmode() {
		add("UNCONSTRAINED", osg::CameraView::UNCONSTRAINED);
		add("HORIZONTAL", osg::CameraView::HORIZONTAL);
		add("VERTICAL", osg::CameraView::VERTICAL);
	}
} osg_cameraview_fieldofviewmode;
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
void RefosgCameraView::addChild(osg::Object *child) {
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
void RefosgCameraView::removeChild(osg::Object *child) {
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
osg::Object *RefosgCameraView::getChildObject(unsigned i) {
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
unsigned RefosgCameraView::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgCameraView::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::CameraView::getDataVariance, &osg::CameraView::setDataVariance, osg_object_datavariance);
	}
	if (name == "_attitude") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::CameraView::*getAttitudeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::CameraView::*setAttitudeFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::CameraView>("_attitude", _object.get(), (getAttitudeFN)&osg::CameraView::getAttitude, (setAttitudeFN)&osg::CameraView::setAttitude);
	}
	if (name == "_fieldOfView") {
		return new GetterSetterProperty<double, osg::CameraView>("_fieldOfView", _object.get(), &osg::CameraView::getFieldOfView, &osg::CameraView::setFieldOfView);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::CameraView::getInitialBound, &osg::CameraView::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::CameraView::getUserData, &osg::CameraView::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::CameraView::getNodeMask, &osg::CameraView::setNodeMask);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::Transform::ReferenceFrame, osg::Transform>("_referenceFrame", _object.get(), &osg::CameraView::getReferenceFrame, &osg::CameraView::setReferenceFrame, osg_transform_referenceframe);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::CameraView::getName, (setNameFN)&osg::CameraView::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::CameraView::getCullingActive, &osg::CameraView::setCullingActive);
	}
	if (name == "_focalLength") {
		return new GetterSetterProperty<double, osg::CameraView>("_focalLength", _object.get(), &osg::CameraView::getFocalLength, &osg::CameraView::setFocalLength);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef const Vec3d & (osg::CameraView::*getPositionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::CameraView::*setPositionFN)(const Vec3d &) ;
		return new GetterSetterProperty<Vec3d, osg::CameraView>("_position", _object.get(), (getPositionFN)&osg::CameraView::getPosition, (setPositionFN)&osg::CameraView::setPosition);
	}
	if (name == "_fieldOfViewMode") {
		return new GetterSetterEnumProperty<osg::CameraView::FieldOfViewMode, osg::CameraView>("_fieldOfViewMode", _object.get(), &osg::CameraView::getFieldOfViewMode, &osg::CameraView::setFieldOfViewMode, osg_cameraview_fieldofviewmode);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::CameraView::getDescriptions, (setDescriptionsFN)&osg::CameraView::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCameraView::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCameraView::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCameraView::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCameraView::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCameraView::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::CameraView, RefosgCameraView> _registerRefosgCameraView;
