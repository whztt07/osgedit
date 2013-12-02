#include <reflection/reflectionregistry.h>
#include <osg/BlendEquation>
#include <stdexcept>

/**
 * Reflector of class osg::BlendEquation
 */
class RefosgBlendEquation: public ClassReflection {
public:
	RefosgBlendEquation();
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
	osg::ref_ptr<osg::BlendEquation> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_equation","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgBlendEquation::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgBlendEquation::_table_names;

std::string RefosgBlendEquation::_class_name("osg::BlendEquation");

std::string RefosgBlendEquation::_class_description(" Encapsulates OpenGL BlendEquation state.     ");

std::string RefosgBlendEquation::_osg_version("1.2");


/**********************************************************/
RefosgBlendEquation::RefosgBlendEquation() {
}

/**********************************************************/
void RefosgBlendEquation::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::BlendEquation*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_blendequation_equation: public Enum<osg::BlendEquation::Equation> {
public:
	Enum_osg_blendequation_equation() {
		add("RGBA_MIN", osg::BlendEquation::RGBA_MIN);
		add("RGBA_MAX", osg::BlendEquation::RGBA_MAX);
		add("ALPHA_MIN", osg::BlendEquation::ALPHA_MIN);
		add("ALPHA_MAX", osg::BlendEquation::ALPHA_MAX);
		add("LOGIC_OP", osg::BlendEquation::LOGIC_OP);
		add("FUNC_ADD", osg::BlendEquation::FUNC_ADD);
		add("FUNC_SUBTRACT", osg::BlendEquation::FUNC_SUBTRACT);
		add("FUNC_REVERSE_SUBTRACT", osg::BlendEquation::FUNC_REVERSE_SUBTRACT);
	}
} osg_blendequation_equation;

using namespace osg;

/**********************************************************/
void RefosgBlendEquation::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgBlendEquation::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgBlendEquation::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgBlendEquation::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgBlendEquation::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::BlendEquation::getUserData, &osg::BlendEquation::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::BlendEquation::getName, (setNameFN)&osg::BlendEquation::setName);
	}
	if (name == "_equation") {
		// Getter overloaded, must specify one type
		typedef osg::BlendEquation::Equation (osg::BlendEquation::*getEquationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::BlendEquation::*setEquationFN)(osg::BlendEquation::Equation) ;
		return new GetterSetterEnumProperty<osg::BlendEquation::Equation, osg::BlendEquation>("_equation", _object.get(), (getEquationFN)&osg::BlendEquation::getEquation, (setEquationFN)&osg::BlendEquation::setEquation, osg_blendequation_equation);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::BlendEquation::getUpdateCallback, &osg::BlendEquation::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::BlendEquation::getDataVariance, &osg::BlendEquation::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::BlendEquation::getEventCallback, &osg::BlendEquation::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgBlendEquation::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgBlendEquation::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgBlendEquation::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBlendEquation::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBlendEquation::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::BlendEquation, RefosgBlendEquation> _registerRefosgBlendEquation;
