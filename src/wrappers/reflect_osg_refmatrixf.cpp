#include <reflection/reflectionregistry.h>
#include <osg/Matrixf>
#include <stdexcept>

/**
 * Reflector of class osg::RefMatrixf
 */
class RefosgRefMatrixf: public ClassReflection {
public:
	RefosgRefMatrixf();
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
	osg::ref_ptr<osg::RefMatrixf> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgRefMatrixf::_names(_propnames, _propnames+3);

ClassReflection::PropertyNames RefosgRefMatrixf::_table_names;

std::string RefosgRefMatrixf::_class_name("osg::RefMatrixf");

std::string RefosgRefMatrixf::_class_description("     ");

std::string RefosgRefMatrixf::_osg_version("1.2");


/**********************************************************/
RefosgRefMatrixf::RefosgRefMatrixf() {
}

/**********************************************************/
void RefosgRefMatrixf::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::RefMatrixf*>(obj);
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
void RefosgRefMatrixf::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgRefMatrixf::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgRefMatrixf::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgRefMatrixf::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgRefMatrixf::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::RefMatrixf::getName, (setNameFN)&osg::RefMatrixf::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::RefMatrixf::getDataVariance, &osg::RefMatrixf::setDataVariance, osg_object_datavariance);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::RefMatrixf::getUserData, &osg::RefMatrixf::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgRefMatrixf::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgRefMatrixf::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgRefMatrixf::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgRefMatrixf::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgRefMatrixf::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::RefMatrixf, RefosgRefMatrixf> _registerRefosgRefMatrixf;
