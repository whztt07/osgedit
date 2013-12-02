#include <reflection/reflectionregistry.h>
#include <osgSim/BlinkSequence>
#include <stdexcept>

/**
 * Reflector of class osgSim::BlinkSequence
 */
class RefosgSimBlinkSequence: public ClassReflection {
public:
	RefosgSimBlinkSequence();
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
	osg::ref_ptr<osgSim::BlinkSequence> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_sequenceGroup","_phaseShift","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgSimBlinkSequence::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgSimBlinkSequence::_table_names;

std::string RefosgSimBlinkSequence::_class_name("osgSim::BlinkSequence");

std::string RefosgSimBlinkSequence::_class_description("     ");

std::string RefosgSimBlinkSequence::_osg_version("1.2");


/**********************************************************/
RefosgSimBlinkSequence::RefosgSimBlinkSequence() {
}

/**********************************************************/
void RefosgSimBlinkSequence::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::BlinkSequence*>(obj);
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
void RefosgSimBlinkSequence::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgSimBlinkSequence::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgSimBlinkSequence::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgSimBlinkSequence::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimBlinkSequence::getProperty(const std::string &name) {
	if (name == "_sequenceGroup") {
		// Getter overloaded, must specify one type
		typedef SequenceGroup * (osgSim::BlinkSequence::*getSequenceGroupFN)() ;
		return new GetterSetterProperty<SequenceGroup*, osgSim::BlinkSequence>("_sequenceGroup", _object.get(), (getSequenceGroupFN)&osgSim::BlinkSequence::getSequenceGroup, &osgSim::BlinkSequence::setSequenceGroup);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::BlinkSequence::getDataVariance, &osgSim::BlinkSequence::setDataVariance, osg_object_datavariance);
	}
	if (name == "_phaseShift") {
		return new GetterSetterProperty<double, osgSim::BlinkSequence>("_phaseShift", _object.get(), &osgSim::BlinkSequence::getPhaseShift, &osgSim::BlinkSequence::setPhaseShift);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::BlinkSequence::getName, (setNameFN)&osgSim::BlinkSequence::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::BlinkSequence::getUserData, &osgSim::BlinkSequence::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimBlinkSequence::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimBlinkSequence::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimBlinkSequence::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimBlinkSequence::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimBlinkSequence::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::BlinkSequence, RefosgSimBlinkSequence> _registerRefosgSimBlinkSequence;
