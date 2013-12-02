#include <reflection/reflectionregistry.h>
#include <osg/AnimationPath>
#include <stdexcept>

/**
 * Reflector of class osg::AnimationPath
 */
class RefosgAnimationPath: public ClassReflection {
public:
	RefosgAnimationPath();
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
	osg::ref_ptr<osg::AnimationPath> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_timeControlPointMap","_loopMode","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgAnimationPath::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgAnimationPath::_table_names;

std::string RefosgAnimationPath::_class_name("osg::AnimationPath");

std::string RefosgAnimationPath::_class_description(" AnimationPath encapsulates a time varying transformation pathway. Can be used for updating camera position and model object position. AnimationPathCallback can be attached directly to Transform nodes to move subgraphs around the scene.     ");

std::string RefosgAnimationPath::_osg_version("1.2");


/**********************************************************/
RefosgAnimationPath::RefosgAnimationPath() {
}

/**********************************************************/
void RefosgAnimationPath::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::AnimationPath*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_animationpath_loopmode: public Enum<osg::AnimationPath::LoopMode> {
public:
	Enum_osg_animationpath_loopmode() {
		add("SWING", osg::AnimationPath::SWING);
		add("LOOP", osg::AnimationPath::LOOP);
		add("NO_LOOPING", osg::AnimationPath::NO_LOOPING);
	}
} osg_animationpath_loopmode;

using namespace osg;

/**********************************************************/
void RefosgAnimationPath::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgAnimationPath::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgAnimationPath::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgAnimationPath::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgAnimationPath::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::AnimationPath::getDataVariance, &osg::AnimationPath::setDataVariance, osg_object_datavariance);
	}
	if (name == "_timeControlPointMap") {
		// Getter overloaded, must specify one type
		typedef osg::AnimationPath::TimeControlPointMap & (osg::AnimationPath::*getTimeControlPointMapFN)() ;
		return new GetterSetterProperty<osg::AnimationPath::TimeControlPointMap, osg::AnimationPath>("_timeControlPointMap", _object.get(), (getTimeControlPointMapFN)&osg::AnimationPath::getTimeControlPointMap, &osg::AnimationPath::setTimeControlPointMap);
	}
	if (name == "_loopMode") {
		return new GetterSetterEnumProperty<osg::AnimationPath::LoopMode, osg::AnimationPath>("_loopMode", _object.get(), &osg::AnimationPath::getLoopMode, &osg::AnimationPath::setLoopMode, osg_animationpath_loopmode);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::AnimationPath::getName, (setNameFN)&osg::AnimationPath::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::AnimationPath::getUserData, &osg::AnimationPath::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgAnimationPath::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgAnimationPath::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgAnimationPath::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgAnimationPath::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgAnimationPath::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::AnimationPath, RefosgAnimationPath> _registerRefosgAnimationPath;
