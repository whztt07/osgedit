#include <reflection/reflectionregistry.h>
#include <osg/LightModel>
#include <stdexcept>

/**
 * Reflector of class osg::LightModel
 */
class RefosgLightModel: public ClassReflection {
public:
	RefosgLightModel();
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
	osg::ref_ptr<osg::LightModel> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_localViewer","_twoSided","_userData","_updateCallback","_colorControl","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgLightModel::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgLightModel::_table_names;

std::string RefosgLightModel::_class_name("osg::LightModel");

std::string RefosgLightModel::_class_description("     ");

std::string RefosgLightModel::_osg_version("1.2");


/**********************************************************/
RefosgLightModel::RefosgLightModel() {
}

/**********************************************************/
void RefosgLightModel::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::LightModel*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_lightmodel_colorcontrol: public Enum<osg::LightModel::ColorControl> {
public:
	Enum_osg_lightmodel_colorcontrol() {
		add("SEPARATE_SPECULAR_COLOR", osg::LightModel::SEPARATE_SPECULAR_COLOR);
		add("SINGLE_COLOR", osg::LightModel::SINGLE_COLOR);
	}
} osg_lightmodel_colorcontrol;

using namespace osg;

/**********************************************************/
void RefosgLightModel::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgLightModel::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgLightModel::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgLightModel::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgLightModel::getProperty(const std::string &name) {
	if (name == "_localViewer") {
		return new GetterSetterProperty<bool, osg::LightModel>("_localViewer", _object.get(), &osg::LightModel::getLocalViewer, &osg::LightModel::setLocalViewer);
	}
	if (name == "_twoSided") {
		return new GetterSetterProperty<bool, osg::LightModel>("_twoSided", _object.get(), &osg::LightModel::getTwoSided, &osg::LightModel::setTwoSided);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::LightModel::getUserData, &osg::LightModel::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::LightModel::getDataVariance, &osg::LightModel::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::LightModel::getUpdateCallback, &osg::LightModel::setUpdateCallback);
	}
	if (name == "_colorControl") {
		return new GetterSetterEnumProperty<osg::LightModel::ColorControl, osg::LightModel>("_colorControl", _object.get(), &osg::LightModel::getColorControl, &osg::LightModel::setColorControl, osg_lightmodel_colorcontrol);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::LightModel::getName, (setNameFN)&osg::LightModel::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::LightModel::getEventCallback, &osg::LightModel::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgLightModel::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgLightModel::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgLightModel::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLightModel::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgLightModel::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::LightModel, RefosgLightModel> _registerRefosgLightModel;
