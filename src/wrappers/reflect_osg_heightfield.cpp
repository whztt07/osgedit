#include <reflection/reflectionregistry.h>
#include <osg/Shape>
#include <stdexcept>

/**
 * Reflector of class osg::HeightField
 */
class RefosgHeightField: public ClassReflection {
public:
	RefosgHeightField();
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
	osg::ref_ptr<osg::HeightField> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_rotation","_borderWidth","_userData","_skirtHeight","_origin","_dataVariance"};
ClassReflection::PropertyNames RefosgHeightField::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgHeightField::_table_names;

std::string RefosgHeightField::_class_name("osg::HeightField");

std::string RefosgHeightField::_class_description("     ");

std::string RefosgHeightField::_osg_version("1.2");


/**********************************************************/
RefosgHeightField::RefosgHeightField() {
}

/**********************************************************/
void RefosgHeightField::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::HeightField*>(obj);
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
void RefosgHeightField::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgHeightField::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgHeightField::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgHeightField::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgHeightField::getProperty(const std::string &name) {
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const Quat & (osg::HeightField::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::HeightField::*setRotationFN)(const Quat &) ;
		return new GetterSetterProperty<Quat, osg::HeightField>("_rotation", _object.get(), (getRotationFN)&osg::HeightField::getRotation, (setRotationFN)&osg::HeightField::setRotation);
	}
	if (name == "_borderWidth") {
		return new GetterSetterProperty<unsigned int, osg::HeightField>("_borderWidth", _object.get(), &osg::HeightField::getBorderWidth, &osg::HeightField::setBorderWidth);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::HeightField::getUserData, &osg::HeightField::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::HeightField::getName, (setNameFN)&osg::HeightField::setName);
	}
	if (name == "_skirtHeight") {
		return new GetterSetterProperty<float, osg::HeightField>("_skirtHeight", _object.get(), &osg::HeightField::getSkirtHeight, &osg::HeightField::setSkirtHeight);
	}
	if (name == "_origin") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osg::HeightField::*getOriginFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::HeightField::*setOriginFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osg::HeightField>("_origin", _object.get(), (getOriginFN)&osg::HeightField::getOrigin, (setOriginFN)&osg::HeightField::setOrigin);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::HeightField::getDataVariance, &osg::HeightField::setDataVariance, osg_object_datavariance);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgHeightField::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgHeightField::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgHeightField::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgHeightField::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgHeightField::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::HeightField, RefosgHeightField> _registerRefosgHeightField;
