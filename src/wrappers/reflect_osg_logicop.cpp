#include <reflection/reflectionregistry.h>
#include <osg/LogicOp>
#include <stdexcept>

/**
 * Reflector of class osg::LogicOp
 */
class RefosgLogicOp: public ClassReflection {
public:
	RefosgLogicOp();
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
	osg::ref_ptr<osg::LogicOp> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_opcode","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgLogicOp::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgLogicOp::_table_names;

std::string RefosgLogicOp::_class_name("osg::LogicOp");

std::string RefosgLogicOp::_class_description(" Encapsulates OpenGL LogicOp state.     ");

std::string RefosgLogicOp::_osg_version("1.2");


/**********************************************************/
RefosgLogicOp::RefosgLogicOp() {
}

/**********************************************************/
void RefosgLogicOp::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::LogicOp*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_logicop_opcode: public Enum<osg::LogicOp::Opcode> {
public:
	Enum_osg_logicop_opcode() {
		add("CLEAR", osg::LogicOp::CLEAR);
		add("SET", osg::LogicOp::SET);
		add("COPY", osg::LogicOp::COPY);
		add("COPY_INVERTED", osg::LogicOp::COPY_INVERTED);
		add("NOOP", osg::LogicOp::NOOP);
		add("INVERT", osg::LogicOp::INVERT);
		add("AND", osg::LogicOp::AND);
		add("NAND", osg::LogicOp::NAND);
		add("OR", osg::LogicOp::OR);
		add("NOR", osg::LogicOp::NOR);
		add("XOR", osg::LogicOp::XOR);
		add("EQUIV", osg::LogicOp::EQUIV);
		add("AND_REVERSE", osg::LogicOp::AND_REVERSE);
		add("AND_INVERTED", osg::LogicOp::AND_INVERTED);
		add("OR_REVERSE", osg::LogicOp::OR_REVERSE);
		add("OR_INVERTED", osg::LogicOp::OR_INVERTED);
	}
} osg_logicop_opcode;

using namespace osg;

/**********************************************************/
void RefosgLogicOp::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgLogicOp::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgLogicOp::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgLogicOp::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLogicOp::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::LogicOp::getUserData, &osg::LogicOp::setUserData);
	}
	if (name == "_opcode") {
		// Getter overloaded, must specify one type
		typedef osg::LogicOp::Opcode (osg::LogicOp::*getOpcodeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::LogicOp::*setOpcodeFN)(osg::LogicOp::Opcode) ;
		return new GetterSetterEnumProperty<osg::LogicOp::Opcode, osg::LogicOp>("_opcode", _object.get(), (getOpcodeFN)&osg::LogicOp::getOpcode, (setOpcodeFN)&osg::LogicOp::setOpcode, osg_logicop_opcode);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::LogicOp::getName, (setNameFN)&osg::LogicOp::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::LogicOp::getUpdateCallback, &osg::LogicOp::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::LogicOp::getDataVariance, &osg::LogicOp::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::LogicOp::getEventCallback, &osg::LogicOp::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgLogicOp::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgLogicOp::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLogicOp::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLogicOp::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLogicOp::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::LogicOp, RefosgLogicOp> _registerRefosgLogicOp;
