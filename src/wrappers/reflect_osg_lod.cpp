#include <reflection/reflectionregistry.h>
#include <osg/LOD>
#include <stdexcept>

/**
 * Reflector of class osg::LOD
 */
class RefosgLOD: public ClassReflection {
public:
	RefosgLOD();
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
	osg::ref_ptr<osg::LOD> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_rangeMode","_cullingActive","_radius","_rangeList","_centerMode","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgLOD::_names(_propnames, _propnames+11);

static std::string _tablepropnames[] = {"_ranges"};
ClassReflection::PropertyNames RefosgLOD::_table_names(_tablepropnames, _tablepropnames+1);

std::string RefosgLOD::_class_name("osg::LOD");

std::string RefosgLOD::_class_description(" LOD - Level Of Detail group node which allows switching between children depending on distance from eye point. Typical uses are for load balancing - objects further away from the eye point are rendered at a lower level of detail, and at times of high stress on the graphics pipeline lower levels of detail can also be chosen by adjusting the viewers's Camera/CullSettings LODScale value. Each child has a corresponding valid range consisting of a minimum and maximum distance. Given a distance to the viewer (d), LOD displays a child if min <= d < max. LOD may display multiple children simultaneously if their corresponding ranges overlap. Children can be in any order, and don't need to be sorted by range or amount of detail. If the number of ranges (m) is less than the number of children (n), then children m+1 through n are ignored.     ");

std::string RefosgLOD::_osg_version("1.2");


/**********************************************************/
RefosgLOD::RefosgLOD() {
}

/**********************************************************/
void RefosgLOD::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::LOD*>(obj);
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
void RefosgLOD::addChild(osg::Object *child) {
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
void RefosgLOD::removeChild(osg::Object *child) {
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
osg::Object *RefosgLOD::getChildObject(unsigned i) {
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
unsigned RefosgLOD::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLOD::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::LOD::getInitialBound, &osg::LOD::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::LOD::getUserData, &osg::LOD::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::LOD::getNodeMask, &osg::LOD::setNodeMask);
	}
	if (name == "_rangeMode") {
		return new GetterSetterEnumProperty<osg::LOD::RangeMode, osg::LOD>("_rangeMode", _object.get(), &osg::LOD::getRangeMode, &osg::LOD::setRangeMode, osg_lod_rangemode);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::LOD::getName, (setNameFN)&osg::LOD::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::LOD::getCullingActive, &osg::LOD::setCullingActive);
	}
	if (name == "_radius") {
		// Getter overloaded, must specify one type
		typedef float (osg::LOD::*getRadiusFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LOD::*setRadiusFN)(float) ;
		return new GetterSetterProperty<float, osg::LOD>("_radius", _object.get(), (getRadiusFN)&osg::LOD::getRadius, (setRadiusFN)&osg::LOD::setRadius);
	}
	if (name == "_rangeList") {
		return new GetterSetterProperty<osg::LOD::RangeList, osg::LOD>("_rangeList", _object.get(), &osg::LOD::getRangeList, &osg::LOD::setRangeList);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::LOD::getDataVariance, &osg::LOD::setDataVariance, osg_object_datavariance);
	}
	if (name == "_centerMode") {
		return new GetterSetterEnumProperty<osg::LOD::CenterMode, osg::LOD>("_centerMode", _object.get(), &osg::LOD::getCenterMode, &osg::LOD::setCenterMode, osg_lod_centermode);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::LOD::getDescriptions, (setDescriptionsFN)&osg::LOD::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
class Prop_ranges_Min: public TemplateProperty<float> {
public:
	Prop_ranges_Min(std::string name, osg::LOD *obj, int row): TemplateProperty<float>(name), _obj(obj), _row(row) {}
	virtual float get() { return _obj->getMinRange(_row); }
	virtual void setImpl(float &t) {
		_obj->setRange(_row, t,_obj->getMaxRange(_row));
	}
private:
	osg::LOD *_obj;
	unsigned _row;
};
class Prop_ranges_Max: public TemplateProperty<float> {
public:
	Prop_ranges_Max(std::string name, osg::LOD *obj, int row): TemplateProperty<float>(name), _obj(obj), _row(row) {}
	virtual float get() { return _obj->getMaxRange(_row); }
	virtual void setImpl(float &t) {
		_obj->setRange(_row, _obj->getMinRange(_row),t);
	}
private:
	osg::LOD *_obj;
	unsigned _row;
};
unsigned RefosgLOD::getNumTablePropertyColumns(const std::string &name) {
	if (name == "_ranges") { return 2; }
	throw PropertyNotFoundException(name);
}
unsigned RefosgLOD::getNumTablePropertyRows(const std::string &name) {
	if (name == "_ranges") { return _object->getNumChildren(); }
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLOD::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	if (name == "_ranges") {
		if (col == 0) {
			return new Prop_ranges_Min(name, _object.get(), row);
		}
		if (col == 1) {
			return new Prop_ranges_Max(name, _object.get(), row);
		}
	}
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLOD::getTablePropertyColumnTitles(const std::string &name) {
	static std::string _rangesColTitles[] = {"Min","Max"};
	if (name == "_ranges") { return PropertyNames(_rangesColTitles, _rangesColTitles+2); }
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLOD::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	if (name == "_ranges") {
		for (unsigned i=0; i < _object->getNumChildren(); i++) {
			titles.push_back(_object->getChild(i)->getName());
		}
	}
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::LOD, RefosgLOD> _registerRefosgLOD;
