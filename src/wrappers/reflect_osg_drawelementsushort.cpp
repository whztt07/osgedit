#include <reflection/reflectionregistry.h>
#include <osg/PrimitiveSet>
#include <stdexcept>

/**
 * Reflector of class osg::DrawElementsUShort
 */
class RefosgDrawElementsUShort: public ClassReflection {
public:
	RefosgDrawElementsUShort();
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
	osg::ref_ptr<osg::DrawElementsUShort> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_mode","_modifiedCount","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgDrawElementsUShort::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgDrawElementsUShort::_table_names;

std::string RefosgDrawElementsUShort::_class_name("osg::DrawElementsUShort");

std::string RefosgDrawElementsUShort::_class_description("     ");

std::string RefosgDrawElementsUShort::_osg_version("1.2");


/**********************************************************/
RefosgDrawElementsUShort::RefosgDrawElementsUShort() {
}

/**********************************************************/
void RefosgDrawElementsUShort::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::DrawElementsUShort*>(obj);
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
void RefosgDrawElementsUShort::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgDrawElementsUShort::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgDrawElementsUShort::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgDrawElementsUShort::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgDrawElementsUShort::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::DrawElementsUShort::getDataVariance, &osg::DrawElementsUShort::setDataVariance, osg_object_datavariance);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::PrimitiveSet::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PrimitiveSet::*setModeFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::PrimitiveSet>("_mode", _object.get(), (getModeFN)&osg::DrawElementsUShort::getMode, (setModeFN)&osg::DrawElementsUShort::setMode, glenum_mode);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::PrimitiveSet>("_modifiedCount", _object.get(), &osg::DrawElementsUShort::getModifiedCount, &osg::DrawElementsUShort::setModifiedCount);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::DrawElementsUShort::getName, (setNameFN)&osg::DrawElementsUShort::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::DrawElementsUShort::getUserData, &osg::DrawElementsUShort::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawElementsUShort::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawElementsUShort::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgDrawElementsUShort::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawElementsUShort::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawElementsUShort::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::DrawElementsUShort, RefosgDrawElementsUShort> _registerRefosgDrawElementsUShort;
