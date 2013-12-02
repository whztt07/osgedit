#include <reflection/reflectionregistry.h>
#include <osg/PrimitiveSet>
#include <stdexcept>

/**
 * Reflector of class osg::DrawArrayLengths
 */
class RefosgDrawArrayLengths: public ClassReflection {
public:
	RefosgDrawArrayLengths();
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
	osg::ref_ptr<osg::DrawArrayLengths> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_first","_userData","_mode","_modifiedCount","_dataVariance"};
ClassReflection::PropertyNames RefosgDrawArrayLengths::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgDrawArrayLengths::_table_names;

std::string RefosgDrawArrayLengths::_class_name("osg::DrawArrayLengths");

std::string RefosgDrawArrayLengths::_class_description("     ");

std::string RefosgDrawArrayLengths::_osg_version("1.2");


/**********************************************************/
RefosgDrawArrayLengths::RefosgDrawArrayLengths() {
}

/**********************************************************/
void RefosgDrawArrayLengths::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::DrawArrayLengths*>(obj);
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
void RefosgDrawArrayLengths::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgDrawArrayLengths::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgDrawArrayLengths::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgDrawArrayLengths::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgDrawArrayLengths::getProperty(const std::string &name) {
	if (name == "_first") {
		// Getter overloaded, must specify one type
		typedef GLint (osg::DrawArrayLengths::*getFirstFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::DrawArrayLengths::*setFirstFN)(GLint) ;
		return new GetterSetterProperty<GLint, osg::DrawArrayLengths>("_first", _object.get(), (getFirstFN)&osg::DrawArrayLengths::getFirst, (setFirstFN)&osg::DrawArrayLengths::setFirst);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::DrawArrayLengths::getUserData, &osg::DrawArrayLengths::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::PrimitiveSet::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PrimitiveSet::*setModeFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::PrimitiveSet>("_mode", _object.get(), (getModeFN)&osg::DrawArrayLengths::getMode, (setModeFN)&osg::DrawArrayLengths::setMode, glenum_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::DrawArrayLengths::getDataVariance, &osg::DrawArrayLengths::setDataVariance, osg_object_datavariance);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::PrimitiveSet>("_modifiedCount", _object.get(), &osg::DrawArrayLengths::getModifiedCount, &osg::DrawArrayLengths::setModifiedCount);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::DrawArrayLengths::getName, (setNameFN)&osg::DrawArrayLengths::setName);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawArrayLengths::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawArrayLengths::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgDrawArrayLengths::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawArrayLengths::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawArrayLengths::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::DrawArrayLengths, RefosgDrawArrayLengths> _registerRefosgDrawArrayLengths;
