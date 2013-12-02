#include <reflection/reflectionregistry.h>
#include <osg/CoordinateSystemNode>
#include <stdexcept>

/**
 * Reflector of class osg::EllipsoidModel
 */
class RefosgEllipsoidModel: public ClassReflection {
public:
	RefosgEllipsoidModel();
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
	osg::ref_ptr<osg::EllipsoidModel> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_radiusEquator","_radiusPolar","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgEllipsoidModel::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgEllipsoidModel::_table_names;

std::string RefosgEllipsoidModel::_class_name("osg::EllipsoidModel");

std::string RefosgEllipsoidModel::_class_description(" EllipsoidModel encapsulates the ellipsoid used to model astronomical bodies, such as sun, planets, moon etc.     ");

std::string RefosgEllipsoidModel::_osg_version("1.2");


/**********************************************************/
RefosgEllipsoidModel::RefosgEllipsoidModel() {
}

/**********************************************************/
void RefosgEllipsoidModel::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::EllipsoidModel*>(obj);
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
void RefosgEllipsoidModel::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgEllipsoidModel::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgEllipsoidModel::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgEllipsoidModel::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgEllipsoidModel::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::EllipsoidModel::getName, (setNameFN)&osg::EllipsoidModel::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::EllipsoidModel::getDataVariance, &osg::EllipsoidModel::setDataVariance, osg_object_datavariance);
	}
	if (name == "_radiusEquator") {
		return new GetterSetterProperty<double, osg::EllipsoidModel>("_radiusEquator", _object.get(), &osg::EllipsoidModel::getRadiusEquator, &osg::EllipsoidModel::setRadiusEquator);
	}
	if (name == "_radiusPolar") {
		return new GetterSetterProperty<double, osg::EllipsoidModel>("_radiusPolar", _object.get(), &osg::EllipsoidModel::getRadiusPolar, &osg::EllipsoidModel::setRadiusPolar);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::EllipsoidModel::getUserData, &osg::EllipsoidModel::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgEllipsoidModel::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgEllipsoidModel::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgEllipsoidModel::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgEllipsoidModel::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgEllipsoidModel::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::EllipsoidModel, RefosgEllipsoidModel> _registerRefosgEllipsoidModel;
