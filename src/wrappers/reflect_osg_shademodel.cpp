#include <reflection/reflectionregistry.h>
#include <osg/ShadeModel>
#include <stdexcept>

/**
 * Reflector of class osg::ShadeModel
 */
class RefosgShadeModel: public ClassReflection {
public:
	RefosgShadeModel();
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
	osg::ref_ptr<osg::ShadeModel> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_mode","_updateCallback","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgShadeModel::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgShadeModel::_table_names;

std::string RefosgShadeModel::_class_name("osg::ShadeModel");

std::string RefosgShadeModel::_class_description(" Class which encapsulates glShadeModel(..).     ");

std::string RefosgShadeModel::_osg_version("1.2");


/**********************************************************/
RefosgShadeModel::RefosgShadeModel() {
}

/**********************************************************/
void RefosgShadeModel::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::ShadeModel*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_shademodel_mode: public Enum<osg::ShadeModel::Mode> {
public:
	Enum_osg_shademodel_mode() {
		add("FLAT", osg::ShadeModel::FLAT);
		add("SMOOTH", osg::ShadeModel::SMOOTH);
	}
} osg_shademodel_mode;

using namespace osg;

/**********************************************************/
void RefosgShadeModel::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgShadeModel::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgShadeModel::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgShadeModel::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgShadeModel::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::ShadeModel::getUserData, &osg::ShadeModel::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::ShadeModel::Mode (osg::ShadeModel::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::ShadeModel::*setModeFN)(osg::ShadeModel::Mode) ;
		return new GetterSetterEnumProperty<osg::ShadeModel::Mode, osg::ShadeModel>("_mode", _object.get(), (getModeFN)&osg::ShadeModel::getMode, (setModeFN)&osg::ShadeModel::setMode, osg_shademodel_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::ShadeModel::getDataVariance, &osg::ShadeModel::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::ShadeModel::getUpdateCallback, &osg::ShadeModel::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::ShadeModel::getName, (setNameFN)&osg::ShadeModel::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::ShadeModel::getEventCallback, &osg::ShadeModel::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadeModel::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgShadeModel::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgShadeModel::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadeModel::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgShadeModel::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::ShadeModel, RefosgShadeModel> _registerRefosgShadeModel;
