#include <reflection/reflectionregistry.h>
#include <osg/PrimitiveSet>
#include <stdexcept>

/**
 * Reflector of class osg::DrawArrays
 */
class RefosgDrawArrays: public ClassReflection {
public:
	RefosgDrawArrays();
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
	osg::ref_ptr<osg::DrawArrays> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_count","_first","_userData","_mode","_modifiedCount","_dataVariance"};
ClassReflection::PropertyNames RefosgDrawArrays::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgDrawArrays::_table_names;

std::string RefosgDrawArrays::_class_name("osg::DrawArrays");

std::string RefosgDrawArrays::_class_description("     ");

std::string RefosgDrawArrays::_osg_version("1.2");


/**********************************************************/
RefosgDrawArrays::RefosgDrawArrays() {
}

/**********************************************************/
void RefosgDrawArrays::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::DrawArrays*>(obj);
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
void RefosgDrawArrays::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgDrawArrays::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgDrawArrays::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgDrawArrays::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgDrawArrays::getProperty(const std::string &name) {
	if (name == "_count") {
		// Getter overloaded, must specify one type
		typedef GLsizei (osg::DrawArrays::*getCountFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::DrawArrays::*setCountFN)(GLsizei) ;
		return new GetterSetterProperty<GLsizei, osg::DrawArrays>("_count", _object.get(), (getCountFN)&osg::DrawArrays::getCount, (setCountFN)&osg::DrawArrays::setCount);
	}
	if (name == "_first") {
		// Getter overloaded, must specify one type
		typedef GLint (osg::DrawArrays::*getFirstFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::DrawArrays::*setFirstFN)(GLint) ;
		return new GetterSetterProperty<GLint, osg::DrawArrays>("_first", _object.get(), (getFirstFN)&osg::DrawArrays::getFirst, (setFirstFN)&osg::DrawArrays::setFirst);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::DrawArrays::getUserData, &osg::DrawArrays::setUserData);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef GLenum (osg::PrimitiveSet::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::PrimitiveSet::*setModeFN)(GLenum) ;
		return new GetterSetterEnumProperty<GLenum, osg::PrimitiveSet>("_mode", _object.get(), (getModeFN)&osg::DrawArrays::getMode, (setModeFN)&osg::DrawArrays::setMode, glenum_mode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::DrawArrays::getDataVariance, &osg::DrawArrays::setDataVariance, osg_object_datavariance);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::PrimitiveSet>("_modifiedCount", _object.get(), &osg::DrawArrays::getModifiedCount, &osg::DrawArrays::setModifiedCount);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::DrawArrays::getName, (setNameFN)&osg::DrawArrays::setName);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawArrays::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgDrawArrays::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgDrawArrays::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawArrays::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgDrawArrays::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::DrawArrays, RefosgDrawArrays> _registerRefosgDrawArrays;
