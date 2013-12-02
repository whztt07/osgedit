#include <reflection/reflectionregistry.h>
#include <osgSim/SphereSegment>
#include <stdexcept>

/**
 * Reflector of class osgSim::SphereSegment
 */
class RefosgSimSphereSegment: public ClassReflection {
public:
	RefosgSimSphereSegment();
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
	osg::ref_ptr<osgSim::SphereSegment> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_surfaceColor","_initialBound","_userData","_density","_nodeMask","_drawMask","_edgeLineColor","_cullingActive","_spokeColor","_centre","_radius","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSimSphereSegment::_names(_propnames, _propnames+14);

ClassReflection::PropertyNames RefosgSimSphereSegment::_table_names;

std::string RefosgSimSphereSegment::_class_name("osgSim::SphereSegment");

std::string RefosgSimSphereSegment::_class_description(" A SphereSegment is a Geode to represent an portion of a sphere (potentially the whole sphere). The sphere is aligned such that the line through the sphere's poles is parallel to the z axis. The sphere segment may be rendered various components switched on or off: The specified area of the sphere surface.  An edge line around the boundary of the specified area of the sphere surface.  Four spokes, where a spoke is the line from the sphere's centre to a corner of the rendered area.  Four planar areas, where the planar areas are formed between the spokes. Caveats: It's worth noting that the line through the sphere's poles is parallel to the z axis. This has implications when specifying the area to be rendered, and specifying areas where the centre of the rendered area is the Z axis may lead to unexpected geometry.  It's possible to render the whole sphere by specifying elevation and azimuth ranges round the full 360 degrees. When doing so you may consider switching the planes, spokes, and edge lines off, to avoid rendering artefacts, e.g. the upper and lower planes will be coincident.      ");

std::string RefosgSimSphereSegment::_osg_version("1.2");


/**********************************************************/
RefosgSimSphereSegment::RefosgSimSphereSegment() {
}

/**********************************************************/
void RefosgSimSphereSegment::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::SphereSegment*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osgsim_spheresegment_drawmask: public Enum<osgSim::SphereSegment::DrawMask> {
public:
	Enum_osgsim_spheresegment_drawmask() {
		add("SURFACE", osgSim::SphereSegment::SURFACE);
		add("SPOKES", osgSim::SphereSegment::SPOKES);
		add("EDGELINE", osgSim::SphereSegment::EDGELINE);
		add("SIDES", osgSim::SphereSegment::SIDES);
		add("ALL", osgSim::SphereSegment::ALL);
	}
} osgsim_spheresegment_drawmask;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimSphereSegment::addChild(osg::Object *child) {
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
	{Drawable *cobj = dynamic_cast<Drawable *>(child);
	if (cobj != 0) {
		_object->addDrawable(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgSimSphereSegment::removeChild(osg::Object *child) {
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
	{Drawable *cobj = dynamic_cast<Drawable *>(child);
	if (cobj != 0) {
		_object->removeDrawable(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgSimSphereSegment::getChildObject(unsigned i) {
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
	if (i < _object->getNumDrawables()) {
		return _object->getDrawable(i);
	} else {
		i -= _object->getNumDrawables();
	}
	if (i < 1) {
		return _object->getCullCallback();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgSimSphereSegment::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumDrawables();
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimSphereSegment::getProperty(const std::string &name) {
	if (name == "_surfaceColor") {
		return new GetterSetterProperty<osg::Vec4, osgSim::SphereSegment>("_surfaceColor", _object.get(), &osgSim::SphereSegment::getSurfaceColor, &osgSim::SphereSegment::setSurfaceColor);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::SphereSegment::getInitialBound, &osgSim::SphereSegment::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::SphereSegment::getUserData, &osgSim::SphereSegment::setUserData);
	}
	if (name == "_density") {
		// Getter overloaded, must specify one type
		typedef int (osgSim::SphereSegment::*getDensityFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::SphereSegment::*setDensityFN)(int) ;
		return new GetterSetterProperty<int, osgSim::SphereSegment>("_density", _object.get(), (getDensityFN)&osgSim::SphereSegment::getDensity, (setDensityFN)&osgSim::SphereSegment::setDensity);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::SphereSegment::getNodeMask, &osgSim::SphereSegment::setNodeMask);
	}
	if (name == "_drawMask") {
		return new GetterSetterEnumProperty<osgSim::SphereSegment::DrawMask, osgSim::SphereSegment>("_drawMask", _object.get(), &osgSim::SphereSegment::getDrawMask, &osgSim::SphereSegment::setDrawMask, osgsim_spheresegment_drawmask);
	}
	if (name == "_edgeLineColor") {
		return new GetterSetterProperty<osg::Vec4, osgSim::SphereSegment>("_edgeLineColor", _object.get(), &osgSim::SphereSegment::getEdgeLineColor, &osgSim::SphereSegment::setEdgeLineColor);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::SphereSegment::getName, (setNameFN)&osgSim::SphereSegment::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::SphereSegment::getCullingActive, &osgSim::SphereSegment::setCullingActive);
	}
	if (name == "_spokeColor") {
		return new GetterSetterProperty<osg::Vec4, osgSim::SphereSegment>("_spokeColor", _object.get(), &osgSim::SphereSegment::getSpokeColor, &osgSim::SphereSegment::setSpokeColor);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::SphereSegment::getDataVariance, &osgSim::SphereSegment::setDataVariance, osg_object_datavariance);
	}
	if (name == "_centre") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgSim::SphereSegment::*getCentreFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::SphereSegment::*setCentreFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgSim::SphereSegment>("_centre", _object.get(), (getCentreFN)&osgSim::SphereSegment::getCentre, (setCentreFN)&osgSim::SphereSegment::setCentre);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osgSim::SphereSegment::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::SphereSegment::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osgSim::SphereSegment>("_radius", _object.get(), (getRadiusFN)&osgSim::SphereSegment::getRadius, (setRadiusFN)&osgSim::SphereSegment::setRadius);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::SphereSegment::getDescriptions, (setDescriptionsFN)&osgSim::SphereSegment::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimSphereSegment::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimSphereSegment::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimSphereSegment::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimSphereSegment::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimSphereSegment::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::SphereSegment, RefosgSimSphereSegment> _registerRefosgSimSphereSegment;
