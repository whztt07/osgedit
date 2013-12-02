#include <reflection/reflectionregistry.h>
#include <osg/Light>
#include <stdexcept>

/**
 * Reflector of class osg::Light
 */
class RefosgLight: public ClassReflection {
public:
	RefosgLight();
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
	osg::ref_ptr<osg::Light> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_specular","_constant_attenuation","_userData","_linear_attenuation","_updateCallback","_spot_exponent","_lightnum","_quadratic_attenuation","_ambient","_position","_direction","_spot_cutoff","_eventCallback","_diffuse","_dataVariance"};
ClassReflection::PropertyNames RefosgLight::_names(_propnames, _propnames+16);

ClassReflection::PropertyNames RefosgLight::_table_names;

std::string RefosgLight::_class_name("osg::Light");

std::string RefosgLight::_class_description(" Light state class which encapsulates OpenGL glLight() functionality.     ");

std::string RefosgLight::_osg_version("1.2");


/**********************************************************/
RefosgLight::RefosgLight() {
}

/**********************************************************/
void RefosgLight::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Light*>(obj);
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
void RefosgLight::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgLight::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgLight::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgLight::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLight::getProperty(const std::string &name) {
	if (name == "_specular") {
		// Getter overloaded, must specify one type
		typedef const Vec4 & (osg::Light::*getSpecularFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Light::*setSpecularFN)(const Vec4 &) ;
		return new GetterSetterProperty<Vec4, osg::Light>("_specular", _object.get(), (getSpecularFN)&osg::Light::getSpecular, (setSpecularFN)&osg::Light::setSpecular);
	}
	if (name == "_constant_attenuation") {
		return new GetterSetterProperty<float, osg::Light>("_constant_attenuation", _object.get(), &osg::Light::getConstantAttenuation, &osg::Light::setConstantAttenuation);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Light::getName, (setNameFN)&osg::Light::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Light::getUserData, &osg::Light::setUserData);
	}
	if (name == "_linear_attenuation") {
		return new GetterSetterProperty<float, osg::Light>("_linear_attenuation", _object.get(), &osg::Light::getLinearAttenuation, &osg::Light::setLinearAttenuation);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Light::getDataVariance, &osg::Light::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Light::getUpdateCallback, &osg::Light::setUpdateCallback);
	}
	if (name == "_spot_exponent") {
		return new GetterSetterProperty<float, osg::Light>("_spot_exponent", _object.get(), &osg::Light::getSpotExponent, &osg::Light::setSpotExponent);
	}
	if (name == "_lightnum") {
		return new GetterSetterProperty<int, osg::Light>("_lightnum", _object.get(), &osg::Light::getLightNum, &osg::Light::setLightNum);
	}
	if (name == "_quadratic_attenuation") {
		return new GetterSetterProperty<float, osg::Light>("_quadratic_attenuation", _object.get(), &osg::Light::getQuadraticAttenuation, &osg::Light::setQuadraticAttenuation);
	}
	if (name == "_ambient") {
		// Getter overloaded, must specify one type
		typedef const Vec4 & (osg::Light::*getAmbientFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Light::*setAmbientFN)(const Vec4 &) ;
		return new GetterSetterProperty<Vec4, osg::Light>("_ambient", _object.get(), (getAmbientFN)&osg::Light::getAmbient, (setAmbientFN)&osg::Light::setAmbient);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef const Vec4 & (osg::Light::*getPositionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Light::*setPositionFN)(const Vec4 &) ;
		return new GetterSetterProperty<Vec4, osg::Light>("_position", _object.get(), (getPositionFN)&osg::Light::getPosition, (setPositionFN)&osg::Light::setPosition);
	}
	if (name == "_direction") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Light::*getDirectionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Light::*setDirectionFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Light>("_direction", _object.get(), (getDirectionFN)&osg::Light::getDirection, (setDirectionFN)&osg::Light::setDirection);
	}
	if (name == "_spot_cutoff") {
		return new GetterSetterProperty<float, osg::Light>("_spot_cutoff", _object.get(), &osg::Light::getSpotCutoff, &osg::Light::setSpotCutoff);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Light::getEventCallback, &osg::Light::setEventCallback);
	}
	if (name == "_diffuse") {
		// Getter overloaded, must specify one type
		typedef const Vec4 & (osg::Light::*getDiffuseFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Light::*setDiffuseFN)(const Vec4 &) ;
		return new GetterSetterProperty<Vec4, osg::Light>("_diffuse", _object.get(), (getDiffuseFN)&osg::Light::getDiffuse, (setDiffuseFN)&osg::Light::setDiffuse);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgLight::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgLight::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLight::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLight::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLight::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Light, RefosgLight> _registerRefosgLight;
