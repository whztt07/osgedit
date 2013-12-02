#include <reflection/reflectionregistry.h>
#include <osg/TexEnvCombine>
#include <stdexcept>

/**
 * Reflector of class osg::TexEnvCombine
 */
class RefosgTexEnvCombine: public ClassReflection {
public:
	RefosgTexEnvCombine();
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
	osg::ref_ptr<osg::TexEnvCombine> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_source1_RGB","_combine_RGB","_operand0_Alpha","_operand2_Alpha","_scale_Alpha","_source0_RGB","_source1_Alpha","_userData","_operand2_RGB","_operand1_RGB","_operand1_Alpha","_eventCallback","_source0_Alpha","_scale_RGB","_source2_Alpha","_updateCallback","_operand0_RGB","_source2_RGB","_combine_Alpha","_constantColor","_dataVariance"};
ClassReflection::PropertyNames RefosgTexEnvCombine::_names(_propnames, _propnames+22);

ClassReflection::PropertyNames RefosgTexEnvCombine::_table_names;

std::string RefosgTexEnvCombine::_class_name("osg::TexEnvCombine");

std::string RefosgTexEnvCombine::_class_description(" TexEnvCombine encapsulates the OpenGL glTexEnvCombine (texture environment) state.     ");

std::string RefosgTexEnvCombine::_osg_version("1.2");


/**********************************************************/
RefosgTexEnvCombine::RefosgTexEnvCombine() {
}

/**********************************************************/
void RefosgTexEnvCombine::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TexEnvCombine*>(obj);
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
void RefosgTexEnvCombine::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTexEnvCombine::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTexEnvCombine::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTexEnvCombine::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexEnvCombine::getProperty(const std::string &name) {
	if (name == "_source1_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_source1_RGB", _object.get(), &osg::TexEnvCombine::getSource1_RGB, &osg::TexEnvCombine::setSource1_RGB);
	}
	if (name == "_combine_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_combine_RGB", _object.get(), &osg::TexEnvCombine::getCombine_RGB, &osg::TexEnvCombine::setCombine_RGB);
	}
	if (name == "_operand0_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_operand0_Alpha", _object.get(), &osg::TexEnvCombine::getOperand0_Alpha, &osg::TexEnvCombine::setOperand0_Alpha);
	}
	if (name == "_operand2_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_operand2_Alpha", _object.get(), &osg::TexEnvCombine::getOperand2_Alpha, &osg::TexEnvCombine::setOperand2_Alpha);
	}
	if (name == "_scale_Alpha") {
		return new GetterSetterProperty<float, osg::TexEnvCombine>("_scale_Alpha", _object.get(), &osg::TexEnvCombine::getScale_Alpha, &osg::TexEnvCombine::setScale_Alpha);
	}
	if (name == "_source0_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_source0_RGB", _object.get(), &osg::TexEnvCombine::getSource0_RGB, &osg::TexEnvCombine::setSource0_RGB);
	}
	if (name == "_source1_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_source1_Alpha", _object.get(), &osg::TexEnvCombine::getSource1_Alpha, &osg::TexEnvCombine::setSource1_Alpha);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TexEnvCombine::getUserData, &osg::TexEnvCombine::setUserData);
	}
	if (name == "_operand2_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_operand2_RGB", _object.get(), &osg::TexEnvCombine::getOperand2_RGB, &osg::TexEnvCombine::setOperand2_RGB);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TexEnvCombine::getDataVariance, &osg::TexEnvCombine::setDataVariance, osg_object_datavariance);
	}
	if (name == "_operand1_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_operand1_RGB", _object.get(), &osg::TexEnvCombine::getOperand1_RGB, &osg::TexEnvCombine::setOperand1_RGB);
	}
	if (name == "_operand1_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_operand1_Alpha", _object.get(), &osg::TexEnvCombine::getOperand1_Alpha, &osg::TexEnvCombine::setOperand1_Alpha);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::TexEnvCombine::getEventCallback, &osg::TexEnvCombine::setEventCallback);
	}
	if (name == "_source0_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_source0_Alpha", _object.get(), &osg::TexEnvCombine::getSource0_Alpha, &osg::TexEnvCombine::setSource0_Alpha);
	}
	if (name == "_scale_RGB") {
		return new GetterSetterProperty<float, osg::TexEnvCombine>("_scale_RGB", _object.get(), &osg::TexEnvCombine::getScale_RGB, &osg::TexEnvCombine::setScale_RGB);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TexEnvCombine::getName, (setNameFN)&osg::TexEnvCombine::setName);
	}
	if (name == "_source2_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_source2_Alpha", _object.get(), &osg::TexEnvCombine::getSource2_Alpha, &osg::TexEnvCombine::setSource2_Alpha);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::TexEnvCombine::getUpdateCallback, &osg::TexEnvCombine::setUpdateCallback);
	}
	if (name == "_operand0_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_operand0_RGB", _object.get(), &osg::TexEnvCombine::getOperand0_RGB, &osg::TexEnvCombine::setOperand0_RGB);
	}
	if (name == "_source2_RGB") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_source2_RGB", _object.get(), &osg::TexEnvCombine::getSource2_RGB, &osg::TexEnvCombine::setSource2_RGB);
	}
	if (name == "_combine_Alpha") {
		return new GetterSetterProperty<GLint, osg::TexEnvCombine>("_combine_Alpha", _object.get(), &osg::TexEnvCombine::getCombine_Alpha, &osg::TexEnvCombine::setCombine_Alpha);
	}
	if (name == "_constantColor") {
		return new GetterSetterProperty<osg::Vec4, osg::TexEnvCombine>("_constantColor", _object.get(), &osg::TexEnvCombine::getConstantColor, &osg::TexEnvCombine::setConstantColor);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexEnvCombine::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexEnvCombine::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexEnvCombine::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexEnvCombine::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexEnvCombine::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TexEnvCombine, RefosgTexEnvCombine> _registerRefosgTexEnvCombine;
