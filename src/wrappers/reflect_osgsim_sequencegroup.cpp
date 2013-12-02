#include <reflection/reflectionregistry.h>
#include <osgSim/BlinkSequence>
#include <stdexcept>

/**
 * Reflector of class osgSim::SequenceGroup
 */
class RefosgSimSequenceGroup: public ClassReflection {
public:
	RefosgSimSequenceGroup();
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
	osg::ref_ptr<osgSim::SequenceGroup> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgSimSequenceGroup::_names(_propnames, _propnames+3);

ClassReflection::PropertyNames RefosgSimSequenceGroup::_table_names;

std::string RefosgSimSequenceGroup::_class_name("osgSim::SequenceGroup");

std::string RefosgSimSequenceGroup::_class_description(" sequence group which can be used to synchronize related blink sequences.     ");

std::string RefosgSimSequenceGroup::_osg_version("1.2");


/**********************************************************/
RefosgSimSequenceGroup::RefosgSimSequenceGroup() {
}

/**********************************************************/
void RefosgSimSequenceGroup::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::SequenceGroup*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimSequenceGroup::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgSimSequenceGroup::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgSimSequenceGroup::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgSimSequenceGroup::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimSequenceGroup::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::SequenceGroup::getName, (setNameFN)&osgSim::SequenceGroup::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::SequenceGroup::getDataVariance, &osgSim::SequenceGroup::setDataVariance, osg_object_datavariance);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::SequenceGroup::getUserData, &osgSim::SequenceGroup::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimSequenceGroup::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimSequenceGroup::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimSequenceGroup::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimSequenceGroup::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimSequenceGroup::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::SequenceGroup, RefosgSimSequenceGroup> _registerRefosgSimSequenceGroup;
