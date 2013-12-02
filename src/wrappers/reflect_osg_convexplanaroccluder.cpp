#include <reflection/reflectionregistry.h>
#include <osg/ConvexPlanarOccluder>
#include <stdexcept>

/**
 * Reflector of class osg::ConvexPlanarOccluder
 */
class RefosgConvexPlanarOccluder: public ClassReflection {
public:
	RefosgConvexPlanarOccluder();
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
	osg::ref_ptr<osg::ConvexPlanarOccluder> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_holeList","_occluder","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgConvexPlanarOccluder::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgConvexPlanarOccluder::_table_names;

std::string RefosgConvexPlanarOccluder::_class_name("osg::ConvexPlanarOccluder");

std::string RefosgConvexPlanarOccluder::_class_description(" A class for representing convex clipping volumes made up of several ConvexPlanarPolygon.     ");

std::string RefosgConvexPlanarOccluder::_osg_version("1.2");


/**********************************************************/
RefosgConvexPlanarOccluder::RefosgConvexPlanarOccluder() {
}

/**********************************************************/
void RefosgConvexPlanarOccluder::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::ConvexPlanarOccluder*>(obj);
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
void RefosgConvexPlanarOccluder::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgConvexPlanarOccluder::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgConvexPlanarOccluder::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgConvexPlanarOccluder::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgConvexPlanarOccluder::getProperty(const std::string &name) {
	if (name == "_holeList") {
		// Getter overloaded, must specify one type
		typedef osg::ConvexPlanarOccluder::HoleList & (osg::ConvexPlanarOccluder::*getHoleListFN)() ;
		return new GetterSetterProperty<osg::ConvexPlanarOccluder::HoleList, osg::ConvexPlanarOccluder>("_holeList", _object.get(), (getHoleListFN)&osg::ConvexPlanarOccluder::getHoleList, &osg::ConvexPlanarOccluder::setHoleList);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::ConvexPlanarOccluder::getName, (setNameFN)&osg::ConvexPlanarOccluder::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::ConvexPlanarOccluder::getDataVariance, &osg::ConvexPlanarOccluder::setDataVariance, osg_object_datavariance);
	}
	if (name == "_occluder") {
		// Getter overloaded, must specify one type
		typedef ConvexPlanarPolygon & (osg::ConvexPlanarOccluder::*getOccluderFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::ConvexPlanarOccluder::*setOccluderFN)(const ConvexPlanarPolygon &) ;
		return new GetterSetterProperty<ConvexPlanarPolygon, osg::ConvexPlanarOccluder>("_occluder", _object.get(), (getOccluderFN)&osg::ConvexPlanarOccluder::getOccluder, (setOccluderFN)&osg::ConvexPlanarOccluder::setOccluder);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::ConvexPlanarOccluder::getUserData, &osg::ConvexPlanarOccluder::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgConvexPlanarOccluder::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgConvexPlanarOccluder::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgConvexPlanarOccluder::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgConvexPlanarOccluder::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgConvexPlanarOccluder::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::ConvexPlanarOccluder, RefosgConvexPlanarOccluder> _registerRefosgConvexPlanarOccluder;
