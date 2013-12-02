#include <reflection/reflectionregistry.h>
#include <osgShadow/OccluderGeometry>
#include <stdexcept>

/**
 * Reflector of class osgShadow::OccluderGeometry
 */
class RefosgShadowOccluderGeometry: public ClassReflection {
public:
	RefosgShadowOccluderGeometry();
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
	osg::ref_ptr<osgShadow::OccluderGeometry> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_supportsDisplayList","_useDisplayList","_initialBound","_userData","_useVertexBufferObjects","_updateCallback","_drawCallback","_boundingPolytope","_cullCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgShadowOccluderGeometry::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgShadowOccluderGeometry::_table_names;

std::string RefosgShadowOccluderGeometry::_class_name("osgShadow::OccluderGeometry");

std::string RefosgShadowOccluderGeometry::_class_description(" OccluderGeometry provides a sepecialised geometry representation of objects in scene that occlude light and therefore cast shadows. OccluderGeometry supports the computation of silhouette edges and shadow volume geometries, as well as use as geometry that one can rendering into a shadow map or end caps for the ZP+ algorithm. OccluderGeometry may be of the same resolution as an underlying geometry that it represents, or can be of lower resolution and combine manager seperate geometries together into a single shadow casting object. OccluderGeometry may be attached as UserData to Nodes or to Drawables.     ");

std::string RefosgShadowOccluderGeometry::_osg_version("1.2");


/**********************************************************/
RefosgShadowOccluderGeometry::RefosgShadowOccluderGeometry() {
}

/**********************************************************/
void RefosgShadowOccluderGeometry::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgShadow::OccluderGeometry*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgShadow;
using namespace osg;

/**********************************************************/
void RefosgShadowOccluderGeometry::addChild(osg::Object *child) {
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
void RefosgShadowOccluderGeometry::removeChild(osg::Object *child) {
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
osg::Object *RefosgShadowOccluderGeometry::getChildObject(unsigned i) {
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
unsigned RefosgShadowOccluderGeometry::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadowOccluderGeometry::getProperty(const std::string &name) {
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osgShadow::OccluderGeometry::getSupportsDisplayList, &osgShadow::OccluderGeometry::setSupportsDisplayList);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osgShadow::OccluderGeometry::getUseDisplayList, &osgShadow::OccluderGeometry::setUseDisplayList);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osgShadow::OccluderGeometry::getInitialBound, &osgShadow::OccluderGeometry::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgShadow::OccluderGeometry::getUserData, &osgShadow::OccluderGeometry::setUserData);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useVertexBufferObjects", _object.get(), &osgShadow::OccluderGeometry::getUseVertexBufferObjects, &osgShadow::OccluderGeometry::setUseVertexBufferObjects);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osgShadow::OccluderGeometry::getUpdateCallback, &osgShadow::OccluderGeometry::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgShadow::OccluderGeometry::getDataVariance, &osgShadow::OccluderGeometry::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osgShadow::OccluderGeometry::getDrawCallback, &osgShadow::OccluderGeometry::setDrawCallback);
	}
	if (name == "_boundingPolytope") {
		// Getter overloaded, must specify one type
		typedef osg::Polytope & (osgShadow::OccluderGeometry::*getBoundingPolytopeFN)() ;
		return new GetterSetterProperty<osg::Polytope, osgShadow::OccluderGeometry>("_boundingPolytope", _object.get(), (getBoundingPolytopeFN)&osgShadow::OccluderGeometry::getBoundingPolytope, &osgShadow::OccluderGeometry::setBoundingPolytope);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osgShadow::OccluderGeometry::getCullCallback, &osgShadow::OccluderGeometry::setCullCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgShadow::OccluderGeometry::getName, (setNameFN)&osgShadow::OccluderGeometry::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osgShadow::OccluderGeometry::getEventCallback, &osgShadow::OccluderGeometry::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowOccluderGeometry::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadowOccluderGeometry::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadowOccluderGeometry::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowOccluderGeometry::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadowOccluderGeometry::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgShadow::OccluderGeometry, RefosgShadowOccluderGeometry> _registerRefosgShadowOccluderGeometry;
