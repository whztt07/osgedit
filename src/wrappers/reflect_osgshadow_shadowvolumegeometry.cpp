#include <reflection/reflectionregistry.h>
#include <osgShadow/OccluderGeometry>
#include <stdexcept>

/**
 * Reflector of class osgShadow::ShadowVolumeGeometry
 */
class RefosgShadowShadowVolumeGeometry: public ClassReflection {
public:
	RefosgShadowShadowVolumeGeometry();
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
	osg::ref_ptr<osgShadow::ShadowVolumeGeometry> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_supportsDisplayList","_drawMode","_initialBound","_userData","_vertices","_drawCallback","_updateCallback","_cullCallback","_eventCallback","_useVertexBufferObjects","_normals","_useDisplayList","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowShadowVolumeGeometry::_names(_propnames, _propnames+14);

ClassReflection::PropertyNames RefosgShadowShadowVolumeGeometry::_table_names;

std::string RefosgShadowShadowVolumeGeometry::_class_name("osgShadow::ShadowVolumeGeometry");

std::string RefosgShadowShadowVolumeGeometry::_class_description("     ");

std::string RefosgShadowShadowVolumeGeometry::_osg_version("1.2");


/**********************************************************/
RefosgShadowShadowVolumeGeometry::RefosgShadowShadowVolumeGeometry() {
}

/**********************************************************/
void RefosgShadowShadowVolumeGeometry::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::ShadowVolumeGeometry*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osgshadow_shadowvolumegeometry_drawmode: public Enum<osgShadow::ShadowVolumeGeometry::DrawMode> {
public:
	Enum_osgshadow_shadowvolumegeometry_drawmode() {
		add("GEOMETRY", osgShadow::ShadowVolumeGeometry::GEOMETRY);
		add("STENCIL_TWO_PASS", osgShadow::ShadowVolumeGeometry::STENCIL_TWO_PASS);
		add("STENCIL_TWO_SIDED", osgShadow::ShadowVolumeGeometry::STENCIL_TWO_SIDED);
	}
} osgshadow_shadowvolumegeometry_drawmode;

using namespace osgShadow;
using namespace osg;

/**********************************************************/
void RefosgShadowShadowVolumeGeometry::addChild(osg::Object *child) {
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadowShadowVolumeGeometry::removeChild(osg::Object *child) {
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadowShadowVolumeGeometry::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getShape();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadowShadowVolumeGeometry::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowShadowVolumeGeometry::getProperty(const std::string &name) {
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osgShadow::ShadowVolumeGeometry::getSupportsDisplayList, &osgShadow::ShadowVolumeGeometry::setSupportsDisplayList);
	}
	if (name == "_drawMode") {
		return new GetterSetterEnumProperty<osgShadow::ShadowVolumeGeometry::DrawMode, osgShadow::ShadowVolumeGeometry>("_drawMode", _object.get(), &osgShadow::ShadowVolumeGeometry::getDrawMode, &osgShadow::ShadowVolumeGeometry::setDrawMode, osgshadow_shadowvolumegeometry_drawmode);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osgShadow::ShadowVolumeGeometry::getInitialBound, &osgShadow::ShadowVolumeGeometry::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::ShadowVolumeGeometry::getUserData, &osgShadow::ShadowVolumeGeometry::setUserData);
	}
	if (name == "_vertices") {
		// Getter overloaded, must specify one type
		typedef osgShadow::ShadowVolumeGeometry::Vec3List & (osgShadow::ShadowVolumeGeometry::*getVerticesFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osgShadow::ShadowVolumeGeometry::*setVerticesFN)(const osgShadow::ShadowVolumeGeometry::Vec3List &) ;
		return new GetterSetterProperty<osgShadow::ShadowVolumeGeometry::Vec3List, osgShadow::ShadowVolumeGeometry>("_vertices", _object.get(), (getVerticesFN)&osgShadow::ShadowVolumeGeometry::getVertices, (setVerticesFN)&osgShadow::ShadowVolumeGeometry::setVertices);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::ShadowVolumeGeometry::getDataVariance, &osgShadow::ShadowVolumeGeometry::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osgShadow::ShadowVolumeGeometry::getDrawCallback, &osgShadow::ShadowVolumeGeometry::setDrawCallback);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osgShadow::ShadowVolumeGeometry::getUpdateCallback, &osgShadow::ShadowVolumeGeometry::setUpdateCallback);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osgShadow::ShadowVolumeGeometry::getCullCallback, &osgShadow::ShadowVolumeGeometry::setCullCallback);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osgShadow::ShadowVolumeGeometry::getEventCallback, &osgShadow::ShadowVolumeGeometry::setEventCallback);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useVertexBufferObjects", _object.get(), &osgShadow::ShadowVolumeGeometry::getUseVertexBufferObjects, &osgShadow::ShadowVolumeGeometry::setUseVertexBufferObjects);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::ShadowVolumeGeometry::getName, (setNameFN)&osgShadow::ShadowVolumeGeometry::setName);
	}
	if (name == "_normals") {
		// Getter overloaded, must specify one type
		typedef osgShadow::ShadowVolumeGeometry::Vec3List & (osgShadow::ShadowVolumeGeometry::*getNormalsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osgShadow::ShadowVolumeGeometry::*setNormalsFN)(const osgShadow::ShadowVolumeGeometry::Vec3List &) ;
		return new GetterSetterProperty<osgShadow::ShadowVolumeGeometry::Vec3List, osgShadow::ShadowVolumeGeometry>("_normals", _object.get(), (getNormalsFN)&osgShadow::ShadowVolumeGeometry::getNormals, (setNormalsFN)&osgShadow::ShadowVolumeGeometry::setNormals);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osgShadow::ShadowVolumeGeometry::getUseDisplayList, &osgShadow::ShadowVolumeGeometry::setUseDisplayList);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowVolumeGeometry::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowShadowVolumeGeometry::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowShadowVolumeGeometry::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowVolumeGeometry::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowShadowVolumeGeometry::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::ShadowVolumeGeometry, RefosgShadowShadowVolumeGeometry> _registerRefosgShadowShadowVolumeGeometry;
