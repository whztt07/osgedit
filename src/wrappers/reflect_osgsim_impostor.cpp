#include <reflection/reflectionregistry.h>
#include <osgSim/Impostor>
#include <stdexcept>

/**
 * Reflector of class osgSim::Impostor
 */
class RefosgSimImpostor: public ClassReflection {
public:
	RefosgSimImpostor();
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
	osg::ref_ptr<osgSim::Impostor> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_impostorThreshold","_cullingActive","_radius","_rangeList","_rangeMode","_centerMode","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSimImpostor::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgSimImpostor::_table_names;

std::string RefosgSimImpostor::_class_name("osgSim::Impostor");

std::string RefosgSimImpostor::_class_description(" Impostor - is a form of Level Of Detail group node which allows both switching between children depending on distance from eye point and image caching.The principle behind Imposters is that they cache an image of real geometry and then the image is drawn in subsequent frames instead of the real geometry. It's a bit like a Billboard *but* is updated at runtime and w.r.t view point. By drawing just the texture mapped quad you can cut down scene complexity and improve performance.For more details have a look at:http://grail.cs.washington.edu/projects/hic/The OSG doesn't implement exactly the same technique as above, but its should be a good starting place. The OSG's impostors are much less intrusive since you don't need to restructure your whole scene to use them.All you need to do to use Impostors is to set up the visible range values for each LOD child of the Impostor, as per osg::LOD, and set an Impostor threshold to tell the renderer at what distance the Impostor's image caching should cut in. The osg::CullVisitor automatically handles all the setting of pre-rendering stages to calculate the required ImpostorSprites (which encapsulates the image cache and quad), and updates them as the view point changes. If you use osg::SceneView/CullVisitor all the complexity of supporting Impostor will be nicely hidden away.TODO: Various improvements are planned for the Impostor- 1) Estimation of how many frames an ImpostorSprite will be reused, if it won't be used more often than a minimum threshold then do not create ImpostorSprite - use the real geometry. 2) Sharing of texture memory between ImpostorSprites. 3) Simple 3D geometry for ImpostorSprite's rather than Billboarding. 4) Shrinking of the ImpostorSprite size to more closely fit the underlying geometry.     ");

std::string RefosgSimImpostor::_osg_version("1.2");


/**********************************************************/
RefosgSimImpostor::RefosgSimImpostor() {
}

/**********************************************************/
void RefosgSimImpostor::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::Impostor*>(obj);
}
static class Enum_osg_lod_centermode: public Enum<osg::LOD::CenterMode> {
public:
	Enum_osg_lod_centermode() {
		add("USE_BOUNDING_SPHERE_CENTER", osg::LOD::USE_BOUNDING_SPHERE_CENTER);
		add("USER_DEFINED_CENTER", osg::LOD::USER_DEFINED_CENTER);
	}
} osg_lod_centermode;
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_lod_rangemode: public Enum<osg::LOD::RangeMode> {
public:
	Enum_osg_lod_rangemode() {
		add("DISTANCE_FROM_EYE_POINT", osg::LOD::DISTANCE_FROM_EYE_POINT);
		add("PIXEL_SIZE_ON_SCREEN", osg::LOD::PIXEL_SIZE_ON_SCREEN);
	}
} osg_lod_rangemode;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimImpostor::addChild(osg::Object *child) {
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
void RefosgSimImpostor::removeChild(osg::Object *child) {
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
osg::Object *RefosgSimImpostor::getChildObject(unsigned i) {
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
unsigned RefosgSimImpostor::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimImpostor::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::Impostor::getInitialBound, &osgSim::Impostor::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::Impostor::getUserData, &osgSim::Impostor::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::Impostor::getNodeMask, &osgSim::Impostor::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::Impostor::getName, (setNameFN)&osgSim::Impostor::setName);
	}
	if (name == "_impostorThreshold") {
		return new GetterSetterProperty<float, osgSim::Impostor>("_impostorThreshold", _object.get(), &osgSim::Impostor::getImpostorThreshold, &osgSim::Impostor::setImpostorThreshold);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::Impostor::getCullingActive, &osgSim::Impostor::setCullingActive);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::LOD::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LOD::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::LOD>("_radius", _object.get(), (getRadiusFN)&osgSim::Impostor::getRadius, (setRadiusFN)&osgSim::Impostor::setRadius);
	}
	if (name == "_rangeList") {
		return new GetterSetterProperty<osg::LOD::RangeList, osg::LOD>("_rangeList", _object.get(), &osgSim::Impostor::getRangeList, &osgSim::Impostor::setRangeList);
	}
	if (name == "_rangeMode") {
		return new GetterSetterEnumProperty<osg::LOD::RangeMode, osg::LOD>("_rangeMode", _object.get(), &osgSim::Impostor::getRangeMode, &osgSim::Impostor::setRangeMode, osg_lod_rangemode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::Impostor::getDataVariance, &osgSim::Impostor::setDataVariance, osg_object_datavariance);
	}
	if (name == "_centerMode") {
		return new GetterSetterEnumProperty<osg::LOD::CenterMode, osg::LOD>("_centerMode", _object.get(), &osgSim::Impostor::getCenterMode, &osgSim::Impostor::setCenterMode, osg_lod_centermode);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::Impostor::getDescriptions, (setDescriptionsFN)&osgSim::Impostor::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimImpostor::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimImpostor::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimImpostor::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimImpostor::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimImpostor::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::Impostor, RefosgSimImpostor> _registerRefosgSimImpostor;
