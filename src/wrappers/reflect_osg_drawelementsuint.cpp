#include <reflection/reflectionregistry.h>
#include <osg/PrimitiveSet>
#include <stdexcept>

/**
 * Reflector of class osg::DrawElementsUInt
 */
class RefosgDrawElementsUInt: public ClassReflection {
public:
	RefosgDrawElementsUInt();
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
	osg::ref_ptr<osg::DrawElementsUInt> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_mode","_modifiedCount","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgDrawElementsUInt::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgDrawElementsUInt::_table_names;

std::string RefosgDrawElementsUInt::_class_name("osg::DrawElementsUInt");

std::string RefosgDrawElementsUInt::_class_description("     ");

std::string RefosgDrawElementsUInt::_osg_version("1.2");


/**********************************************************/
RefosgDrawElementsUInt::RefosgDrawElementsUInt() {
}

/**********************************************************/
void RefosgDrawElementsUInt::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::DrawElementsUInt*>(obj);
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
void RefosgDrawElementsUInt::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgDrawElementsUInt::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgDrawElementsUInt::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgDrawElementsUInt::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgDrawElementsUInt::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::DrawElementsUInt::getDataVariance, &osg::DrawElementsUInt::setDataVariance, osg_object_datavariance);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::PrimitiveSet::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PrimitiveSet::*setModeFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::PrimitiveSet>("_mode", _object.get(), (getModeFN)&osg::DrawElementsUInt::getMode, (setModeFN)&osg::DrawElementsUInt::setMode, glenum_mode);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::PrimitiveSet>("_modifiedCount", _object.get(), &osg::DrawElementsUInt::getModifiedCount, &osg::DrawElementsUInt::setModifiedCount);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::DrawElementsUInt::getName, (setNameFN)&osg::DrawElementsUInt::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::DrawElementsUInt::getUserData, &osg::DrawElementsUInt::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawElementsUInt::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawElementsUInt::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgDrawElementsUInt::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawElementsUInt::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawElementsUInt::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::DrawElementsUInt, RefosgDrawElementsUInt> _registerRefosgDrawElementsUInt;
