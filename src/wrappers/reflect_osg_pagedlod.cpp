#include <reflection/reflectionregistry.h>
#include <osg/PagedLOD>
#include <stdexcept>

/**
 * Reflector of class osg::PagedLOD
 */
class RefosgPagedLOD: public ClassReflection {
public:
	RefosgPagedLOD();
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
	osg::ref_ptr<osg::PagedLOD> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_databasePath","_numChildrenThatCannotBeExpired","_initialBound","_userData","_nodeMask","_cullingActive","_radius","_rangeList","_rangeMode","_frameNumberOfLastTraversal","_centerMode","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgPagedLOD::_names(_propnames, _propnames+14);

ClassReflection::PropertyNames RefosgPagedLOD::_table_names;

std::string RefosgPagedLOD::_class_name("osg::PagedLOD");

std::string RefosgPagedLOD::_class_description(" PagedLOD.     ");

std::string RefosgPagedLOD::_osg_version("1.2");


/**********************************************************/
RefosgPagedLOD::RefosgPagedLOD() {
}

/**********************************************************/
void RefosgPagedLOD::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::PagedLOD*>(obj);
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

using namespace osg;

/**********************************************************/
void RefosgPagedLOD::addChild(osg::Object *child) {
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
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(cobj);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
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
void RefosgPagedLOD::removeChild(osg::Object *child) {
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
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(0);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
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
osg::Object *RefosgPagedLOD::getChildObject(unsigned i) {
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
		return _object->getEventCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getStateSet();
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
unsigned RefosgPagedLOD::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgPagedLOD::getProperty(const std::string &name) {
	if (name == "_databasePath") {
		return new GetterSetterProperty<std::string, osg::PagedLOD>("_databasePath", _object.get(), &osg::PagedLOD::getDatabasePath, &osg::PagedLOD::setDatabasePath);
	}
	if (name == "_numChildrenThatCannotBeExpired") {
		return new GetterSetterProperty<unsigned int, osg::PagedLOD>("_numChildrenThatCannotBeExpired", _object.get(), &osg::PagedLOD::getNumChildrenThatCannotBeExpired, &osg::PagedLOD::setNumChildrenThatCannotBeExpired);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::PagedLOD::getInitialBound, &osg::PagedLOD::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::PagedLOD::getUserData, &osg::PagedLOD::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::PagedLOD::getNodeMask, &osg::PagedLOD::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::PagedLOD::getName, (setNameFN)&osg::PagedLOD::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::PagedLOD::getDataVariance, &osg::PagedLOD::setDataVariance, osg_object_datavariance);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::PagedLOD::getCullingActive, &osg::PagedLOD::setCullingActive);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::LOD::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LOD::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::LOD>("_radius", _object.get(), (getRadiusFN)&osg::PagedLOD::getRadius, (setRadiusFN)&osg::PagedLOD::setRadius);
	}
	if (name == "_rangeList") {
		return new GetterSetterProperty<osg::LOD::RangeList, osg::LOD>("_rangeList", _object.get(), &osg::PagedLOD::getRangeList, &osg::PagedLOD::setRangeList);
	}
	if (name == "_rangeMode") {
		return new GetterSetterEnumProperty<osg::LOD::RangeMode, osg::LOD>("_rangeMode", _object.get(), &osg::PagedLOD::getRangeMode, &osg::PagedLOD::setRangeMode, osg_lod_rangemode);
	}
	if (name == "_frameNumberOfLastTraversal") {
		return new GetterSetterProperty<int, osg::PagedLOD>("_frameNumberOfLastTraversal", _object.get(), &osg::PagedLOD::getFrameNumberOfLastTraversal, &osg::PagedLOD::setFrameNumberOfLastTraversal);
	}
	if (name == "_centerMode") {
		return new GetterSetterEnumProperty<osg::LOD::CenterMode, osg::LOD>("_centerMode", _object.get(), &osg::PagedLOD::getCenterMode, &osg::PagedLOD::setCenterMode, osg_lod_centermode);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::PagedLOD::getDescriptions, (setDescriptionsFN)&osg::PagedLOD::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgPagedLOD::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgPagedLOD::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgPagedLOD::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPagedLOD::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgPagedLOD::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::PagedLOD, RefosgPagedLOD> _registerRefosgPagedLOD;
