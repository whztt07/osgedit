#include <reflection/reflectionregistry.h>
#include <osg/Geometry>
#include <stdexcept>

/**
 * Reflector of class osg::Geometry
 */
class RefosgGeometry: public ClassReflection {
public:
	RefosgGeometry();
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
	osg::ref_ptr<osg::Geometry> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_fogCoordData","_colorData","_supportsDisplayList","_initialBound","_vertexData","_userData","_cullCallback","_drawCallback","_updateCallback","_secondaryColorData","_normalData","_useVertexBufferObjects","_fastPathHint","_internalOptimizedGeometry","_eventCallback","_useDisplayList","_dataVariance"};
ClassReflection::PropertyNames RefosgGeometry::_names(_propnames, _propnames+18);

ClassReflection::PropertyNames RefosgGeometry::_table_names;

std::string RefosgGeometry::_class_name("osg::Geometry");

std::string RefosgGeometry::_class_description("     ");

std::string RefosgGeometry::_osg_version("1.2");


/**********************************************************/
RefosgGeometry::RefosgGeometry() {
}

/**********************************************************/
void RefosgGeometry::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Geometry*>(obj);
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
void RefosgGeometry::addChild(osg::Object *child) {
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
	{PrimitiveSet *cobj = dynamic_cast<PrimitiveSet *>(child);
	if (cobj != 0) {
		_object->addPrimitiveSet(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgGeometry::removeChild(osg::Object *child) {
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
	{osg::PrimitiveSet *cobj = dynamic_cast<osg::PrimitiveSet*>(child);
	if (cobj != 0) {
		_object->removePrimitiveSet(_object->getPrimitiveSetIndex(cobj), 1);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgGeometry::getChildObject(unsigned i) {
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
	if (i < _object->getNumPrimitiveSets()) {
		return _object->getPrimitiveSet(i);
	} else {
		i -= _object->getNumPrimitiveSets();
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgGeometry::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt+= _object->getNumPrimitiveSets();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgGeometry::getProperty(const std::string &name) {
	if (name == "_fogCoordData") {
		// Getter overloaded, must specify one type
		typedef osg::Geometry::ArrayData & (osg::Geometry::*getFogCoordDataFN)() ;
		return new GetterSetterProperty<osg::Geometry::ArrayData, osg::Geometry>("_fogCoordData", _object.get(), (getFogCoordDataFN)&osg::Geometry::getFogCoordData, &osg::Geometry::setFogCoordData);
	}
	if (name == "_colorData") {
		// Getter overloaded, must specify one type
		typedef osg::Geometry::ArrayData & (osg::Geometry::*getColorDataFN)() ;
		return new GetterSetterProperty<osg::Geometry::ArrayData, osg::Geometry>("_colorData", _object.get(), (getColorDataFN)&osg::Geometry::getColorData, &osg::Geometry::setColorData);
	}
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osg::Geometry::getSupportsDisplayList, &osg::Geometry::setSupportsDisplayList);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osg::Geometry::getInitialBound, &osg::Geometry::setInitialBound);
	}
	if (name == "_vertexData") {
		// Getter overloaded, must specify one type
		typedef osg::Geometry::ArrayData & (osg::Geometry::*getVertexDataFN)() ;
		return new GetterSetterProperty<osg::Geometry::ArrayData, osg::Geometry>("_vertexData", _object.get(), (getVertexDataFN)&osg::Geometry::getVertexData, &osg::Geometry::setVertexData);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Geometry::getUserData, &osg::Geometry::setUserData);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osg::Geometry::getCullCallback, &osg::Geometry::setCullCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Geometry::getDataVariance, &osg::Geometry::setDataVariance, osg_object_datavariance);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osg::Geometry::getDrawCallback, &osg::Geometry::setDrawCallback);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Geometry::getUpdateCallback, &osg::Geometry::setUpdateCallback);
	}
	if (name == "_secondaryColorData") {
		// Getter overloaded, must specify one type
		typedef osg::Geometry::ArrayData & (osg::Geometry::*getSecondaryColorDataFN)() ;
		return new GetterSetterProperty<osg::Geometry::ArrayData, osg::Geometry>("_secondaryColorData", _object.get(), (getSecondaryColorDataFN)&osg::Geometry::getSecondaryColorData, &osg::Geometry::setSecondaryColorData);
	}
	if (name == "_normalData") {
		// Getter overloaded, must specify one type
		typedef osg::Geometry::ArrayData & (osg::Geometry::*getNormalDataFN)() ;
		return new GetterSetterProperty<osg::Geometry::ArrayData, osg::Geometry>("_normalData", _object.get(), (getNormalDataFN)&osg::Geometry::getNormalData, &osg::Geometry::setNormalData);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Geometry>("_useVertexBufferObjects", _object.get(), &osg::Geometry::getUseVertexBufferObjects, &osg::Geometry::setUseVertexBufferObjects);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Geometry::getName, (setNameFN)&osg::Geometry::setName);
	}
	if (name == "_fastPathHint") {
		return new GetterSetterProperty<bool, osg::Geometry>("_fastPathHint", _object.get(), &osg::Geometry::getFastPathHint, &osg::Geometry::setFastPathHint);
	}
	if (name == "_internalOptimizedGeometry") {
		// Getter overloaded, must specify one type
		typedef osg::Geometry * (osg::Geometry::*getInternalOptimizedGeometryFN)() ;
		return new GetterSetterProperty<Geometry*, osg::Geometry>("_internalOptimizedGeometry", _object.get(), (getInternalOptimizedGeometryFN)&osg::Geometry::getInternalOptimizedGeometry, &osg::Geometry::setInternalOptimizedGeometry);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Geometry::getEventCallback, &osg::Geometry::setEventCallback);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osg::Geometry::getUseDisplayList, &osg::Geometry::setUseDisplayList);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgGeometry::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgGeometry::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgGeometry::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgGeometry::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgGeometry::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Geometry, RefosgGeometry> _registerRefosgGeometry;
