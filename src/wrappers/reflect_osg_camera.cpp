#include <reflection/reflectionregistry.h>
#include <osg/Camera>
#include <osg/View>
#include <stdexcept>

/**
 * Reflector of class osg::Camera
 */
class RefosgCamera: public ClassReflection {
public:
	RefosgCamera();
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
	osg::ref_ptr<osg::Camera> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

#ifndef _WIN32
static std::string _propnames[] = {"_name","_renderTargetImplementation","_initialBound","_nodeMask","_clearMask","_cullingActive","_referenceFrame","_projectionResizePolicy","_readBuffer","_stats","_descriptions","_drawBuffer","_clearColor","_viewMatrix","_cameraThread","_projectionMatrix","_renderer","_userData","_postDrawCallback","_preDrawCallback","_transformOrder","_renderOrder","_allowEventFocus","_displaySettings","_dataVariance"};
ClassReflection::PropertyNames RefosgCamera::_names(_propnames, _propnames+25);
#else
static std::string _propnames[] = {"_name","_renderTargetImplementation","_initialBound","_nodeMask","_clearMask","_cullingActive","_referenceFrame","_projectionResizePolicy","_readBuffer","_stats","_descriptions","_drawBuffer","_clearColor","_viewMatrix","_cameraThread","_projectionMatrix","_renderer","_userData","_postDrawCallback","_preDrawCallback","_transformOrder","_allowEventFocus","_displaySettings","_dataVariance"};
ClassReflection::PropertyNames RefosgCamera::_names(_propnames, _propnames+24);
#endif
ClassReflection::PropertyNames RefosgCamera::_table_names;

std::string RefosgCamera::_class_name("osg::Camera");

std::string RefosgCamera::_class_description(" Camera - is a subclass of Transform which represents encapsulates the settings of a Camera.     ");

std::string RefosgCamera::_osg_version("1.2");


/**********************************************************/
RefosgCamera::RefosgCamera() {
}

/**********************************************************/
void RefosgCamera::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Camera*>(obj);
}
static class Enum_osg_transform_referenceframe: public Enum<osg::Transform::ReferenceFrame> {
public:
	Enum_osg_transform_referenceframe() {
		add("RELATIVE_RF", osg::Transform::RELATIVE_RF);
		add("ABSOLUTE_RF", osg::Transform::ABSOLUTE_RF);
		add("ABSOLUTE_RF_INHERIT_VIEWPOINT", osg::Transform::ABSOLUTE_RF_INHERIT_VIEWPOINT);
	}
} osg_transform_referenceframe;
static class Enum_osg_camera_renderorder: public Enum<osg::Camera::RenderOrder> {
public:
	Enum_osg_camera_renderorder() {
		add("PRE_RENDER", osg::Camera::PRE_RENDER);
		add("NESTED_RENDER", osg::Camera::NESTED_RENDER);
		add("POST_RENDER", osg::Camera::POST_RENDER);
	}
} osg_camera_renderorder;
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_camera_rendertargetimplementation: public Enum<osg::Camera::RenderTargetImplementation> {
public:
	Enum_osg_camera_rendertargetimplementation() {
		add("FRAME_BUFFER_OBJECT", osg::Camera::FRAME_BUFFER_OBJECT);
		add("PIXEL_BUFFER_RTT", osg::Camera::PIXEL_BUFFER_RTT);
		add("PIXEL_BUFFER", osg::Camera::PIXEL_BUFFER);
		add("FRAME_BUFFER", osg::Camera::FRAME_BUFFER);
		add("SEPERATE_WINDOW", osg::Camera::SEPERATE_WINDOW);
	}
} osg_camera_rendertargetimplementation;
static class Enum_osg_camera_transformorder: public Enum<osg::Camera::TransformOrder> {
public:
	Enum_osg_camera_transformorder() {
		add("PRE_MULTIPLY", osg::Camera::PRE_MULTIPLY);
		add("POST_MULTIPLY", osg::Camera::POST_MULTIPLY);
	}
} osg_camera_transformorder;
static class Enum_osg_camera_projectionresizepolicy: public Enum<osg::Camera::ProjectionResizePolicy> {
public:
	Enum_osg_camera_projectionresizepolicy() {
		add("FIXED", osg::Camera::FIXED);
		add("HORIZONTAL", osg::Camera::HORIZONTAL);
		add("VERTICAL", osg::Camera::VERTICAL);
	}
} osg_camera_projectionresizepolicy;
static class Enum_glenum_drawBuffer: public Enum<GLenum> {
public:
	Enum_glenum_drawBuffer() {
	}
} glenum_drawBuffer;
static class Enum_glenum_readBuffer: public Enum<GLenum> {
public:
	Enum_glenum_readBuffer() {
	}
} glenum_readBuffer;

using namespace osg;

/**********************************************************/
void RefosgCamera::addChild(osg::Object *child) {
	{GraphicsContext *cobj = dynamic_cast<GraphicsContext *>(child);
	if (cobj != 0) {
		_object->setGraphicsContext(cobj);
		return;
	}}
	{View *cobj = dynamic_cast<View *>(child);
	if (cobj != 0) {
		_object->setView(cobj);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	{osg::ColorMask *cobj = dynamic_cast<osg::ColorMask *>(child);
	if (cobj != 0) {
		_object->setColorMask(cobj);
		return;
	}}
	{osg::Viewport *cobj = dynamic_cast<osg::Viewport *>(child);
	if (cobj != 0) {
		_object->setViewport(cobj);
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
	{osg::Object *cobj = dynamic_cast<osg::Object *>(child);
	if (cobj != 0) {
		_object->setRenderingCache(cobj);
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
void RefosgCamera::removeChild(osg::Object *child) {
	{GraphicsContext *cobj = dynamic_cast<GraphicsContext *>(child);
	if (cobj != 0) {
		_object->setGraphicsContext(0);
		return;
	}}
	{View *cobj = dynamic_cast<View *>(child);
	if (cobj != 0) {
		_object->setView(0);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	{osg::ColorMask *cobj = dynamic_cast<osg::ColorMask *>(child);
	if (cobj != 0) {
		_object->setColorMask(0);
		return;
	}}
	{osg::Viewport *cobj = dynamic_cast<osg::Viewport *>(child);
	if (cobj != 0) {
		_object->setViewport(0);
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
	{osg::Object *cobj = dynamic_cast<osg::Object *>(child);
	if (cobj != 0) {
		_object->setRenderingCache(0);
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
osg::Object *RefosgCamera::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getGraphicsContext();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getView();
	} else {
		i -= 1;
	}
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	if (i < 1) {
		return _object->getColorMask();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getViewport();
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
		return _object->getRenderingCache();
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
unsigned RefosgCamera::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgCamera::getProperty(const std::string &name) {
	if (name == "_renderTargetImplementation") {
		// Setter overloaded, must specify one type
		typedef void (osg::Camera::*setRenderTargetImplementationFN)(osg::Camera::RenderTargetImplementation) ;
		return new GetterSetterEnumProperty<osg::Camera::RenderTargetImplementation, osg::Camera>("_renderTargetImplementation", _object.get(), &osg::Camera::getRenderTargetImplementation, (setRenderTargetImplementationFN)&osg::Camera::setRenderTargetImplementation, osg_camera_rendertargetimplementation);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::Camera::getInitialBound, &osg::Camera::setInitialBound);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::Camera::getNodeMask, &osg::Camera::setNodeMask);
	}
	if (name == "_clearMask") {
		return new GetterSetterProperty<GLbitfield, osg::Camera>("_clearMask", _object.get(), &osg::Camera::getClearMask, &osg::Camera::setClearMask);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::Camera::getCullingActive, &osg::Camera::setCullingActive);
	}
	if (name == "_referenceFrame") {
		return new GetterSetterEnumProperty<osg::Transform::ReferenceFrame, osg::Transform>("_referenceFrame", _object.get(), &osg::Camera::getReferenceFrame, &osg::Camera::setReferenceFrame, osg_transform_referenceframe);
	}
	if (name == "_projectionResizePolicy") {
		return new GetterSetterEnumProperty<osg::Camera::ProjectionResizePolicy, osg::Camera>("_projectionResizePolicy", _object.get(), &osg::Camera::getProjectionResizePolicy, &osg::Camera::setProjectionResizePolicy, osg_camera_projectionresizepolicy);
	}
	if (name == "_readBuffer") {
		return new GetterSetterEnumProperty<GLenum, osg::Camera>("_readBuffer", _object.get(), &osg::Camera::getReadBuffer, &osg::Camera::setReadBuffer, glenum_readBuffer);
	}
	if (name == "_stats") {
		// Getter overloaded, must specify one type
		typedef osg::Stats * (osg::Camera::*getStatsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Camera::*setStatsFN)(osg::Stats *) ;
		return new GetterSetterProperty<osg::Stats*, osg::Camera>("_stats", _object.get(), (getStatsFN)&osg::Camera::getStats, (setStatsFN)&osg::Camera::setStats);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::Camera::getDescriptions, (setDescriptionsFN)&osg::Camera::setDescriptions);
	}
	if (name == "_drawBuffer") {
		return new GetterSetterEnumProperty<GLenum, osg::Camera>("_drawBuffer", _object.get(), &osg::Camera::getDrawBuffer, &osg::Camera::setDrawBuffer, glenum_drawBuffer);
	}
	if (name == "_clearColor") {
		return new GetterSetterProperty<Vec4, osg::Camera>("_clearColor", _object.get(), &osg::Camera::getClearColor, &osg::Camera::setClearColor);
	}
	if (name == "_viewMatrix") {
		// Getter overloaded, must specify one type
		typedef osg::Matrixd & (osg::Camera::*getViewMatrixFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Camera::*setViewMatrixFN)(const osg::Matrixf &) ;
		return new GetterSetterProperty<Matrixd, osg::Camera>("_viewMatrix", _object.get(), (getViewMatrixFN)&osg::Camera::getViewMatrix, (setViewMatrixFN)&osg::Camera::setViewMatrix);
	}
	if (name == "_cameraThread") {
		// Getter overloaded, must specify one type
		typedef OperationThread * (osg::Camera::*getCameraThreadFN)() ;
		return new GetterSetterProperty<OperationThread*, osg::Camera>("_cameraThread", _object.get(), (getCameraThreadFN)&osg::Camera::getCameraThread, &osg::Camera::setCameraThread);
	}
	if (name == "_projectionMatrix") {
		// Getter overloaded, must specify one type
		typedef osg::Matrixd & (osg::Camera::*getProjectionMatrixFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Camera::*setProjectionMatrixFN)(const osg::Matrixf &) ;
		return new GetterSetterProperty<Matrixd, osg::Camera>("_projectionMatrix", _object.get(), (getProjectionMatrixFN)&osg::Camera::getProjectionMatrix, (setProjectionMatrixFN)&osg::Camera::setProjectionMatrix);
	}
	if (name == "_renderer") {
		// Getter overloaded, must specify one type
		typedef osg::GraphicsOperation * (osg::Camera::*getRendererFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Camera::*setRendererFN)(osg::GraphicsOperation *) ;
		return new GetterSetterProperty<GraphicsOperation*, osg::Camera>("_renderer", _object.get(), (getRendererFN)&osg::Camera::getRenderer, (setRendererFN)&osg::Camera::setRenderer);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Camera::getUserData, &osg::Camera::setUserData);
	}
	if (name == "_postDrawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Camera::DrawCallback * (osg::Camera::*getPostDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Camera::DrawCallback*, osg::Camera>("_postDrawCallback", _object.get(), (getPostDrawCallbackFN)&osg::Camera::getPostDrawCallback, &osg::Camera::setPostDrawCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Camera::getDataVariance, &osg::Camera::setDataVariance, osg_object_datavariance);
	}
	if (name == "_preDrawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Camera::DrawCallback * (osg::Camera::*getPreDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Camera::DrawCallback*, osg::Camera>("_preDrawCallback", _object.get(), (getPreDrawCallbackFN)&osg::Camera::getPreDrawCallback, &osg::Camera::setPreDrawCallback);
	}
	if (name == "_transformOrder") {
		return new GetterSetterEnumProperty<osg::Camera::TransformOrder, osg::Camera>("_transformOrder", _object.get(), &osg::Camera::getTransformOrder, &osg::Camera::setTransformOrder, osg_camera_transformorder);
	}
#ifndef _WIN32
	if (name == "_renderOrder") {
		return new GetterSetterEnumProperty<osg::Camera::RenderOrder, osg::Camera>("_renderOrder", _object.get(), &osg::Camera::getRenderOrder, &osg::Camera::setRenderOrder, osg_camera_renderorder);
	}
#endif
	if (name == "_allowEventFocus") {
		return new GetterSetterProperty<bool, osg::Camera>("_allowEventFocus", _object.get(), &osg::Camera::getAllowEventFocus, &osg::Camera::setAllowEventFocus);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Camera::getName, (setNameFN)&osg::Camera::setName);
	}
	if (name == "_displaySettings") {
		// Getter overloaded, must specify one type
		typedef osg::DisplaySettings * (osg::Camera::*getDisplaySettingsFN)() ;
		return new GetterSetterProperty<osg::DisplaySettings*, osg::Camera>("_displaySettings", _object.get(), (getDisplaySettingsFN)&osg::Camera::getDisplaySettings, &osg::Camera::setDisplaySettings);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgCamera::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgCamera::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgCamera::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCamera::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgCamera::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Camera, RefosgCamera> _registerRefosgCamera;
