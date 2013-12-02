#include <reflection/reflectionregistry.h>
#include <osg/PrimitiveSet>
#include <stdexcept>

/**
 * Reflector of class osg::DrawElementsUByte
 */
class RefosgDrawElementsUByte: public ClassReflection {
public:
	RefosgDrawElementsUByte();
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
	osg::ref_ptr<osg::DrawElementsUByte> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_mode","_modifiedCount","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgDrawElementsUByte::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgDrawElementsUByte::_table_names;

std::string RefosgDrawElementsUByte::_class_name("osg::DrawElementsUByte");

std::string RefosgDrawElementsUByte::_class_description("     ");

std::string RefosgDrawElementsUByte::_osg_version("1.2");


/**********************************************************/
RefosgDrawElementsUByte::RefosgDrawElementsUByte() {
}

/**********************************************************/
void RefosgDrawElementsUByte::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::DrawElementsUByte*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_glenum_mode: public Enum<GLenum> {
public:
	Enum_glenum_mode() {
	}
} glenum_mode;

using namespace osg;

/**********************************************************/
void RefosgDrawElementsUByte::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgDrawElementsUByte::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgDrawElementsUByte::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgDrawElementsUByte::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgDrawElementsUByte::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::DrawElementsUByte::getDataVariance, &osg::DrawElementsUByte::setDataVariance, osg_object_datavariance);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::PrimitiveSet::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PrimitiveSet::*setModeFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::PrimitiveSet>("_mode", _object.get(), (getModeFN)&osg::DrawElementsUByte::getMode, (setModeFN)&osg::DrawElementsUByte::setMode, glenum_mode);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::PrimitiveSet>("_modifiedCount", _object.get(), &osg::DrawElementsUByte::getModifiedCount, &osg::DrawElementsUByte::setModifiedCount);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::DrawElementsUByte::getName, (setNameFN)&osg::DrawElementsUByte::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::DrawElementsUByte::getUserData, &osg::DrawElementsUByte::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawElementsUByte::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawElementsUByte::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgDrawElementsUByte::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawElementsUByte::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawElementsUByte::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::DrawElementsUByte, RefosgDrawElementsUByte> _registerRefosgDrawElementsUByte;
