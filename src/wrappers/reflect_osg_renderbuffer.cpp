#include <reflection/reflectionregistry.h>
#include <osg/FrameBufferObject>
#include <stdexcept>

/**
 * Reflector of class osg::RenderBuffer
 */
class RefosgRenderBuffer: public ClassReflection {
public:
	RefosgRenderBuffer();
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
	osg::ref_ptr<osg::RenderBuffer> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_height","_width","_internalFormat","_dataVariance"};
ClassReflection::PropertyNames RefosgRenderBuffer::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgRenderBuffer::_table_names;

std::string RefosgRenderBuffer::_class_name("osg::RenderBuffer");

std::string RefosgRenderBuffer::_class_description("     ");

std::string RefosgRenderBuffer::_osg_version("1.2");


/**********************************************************/
RefosgRenderBuffer::RefosgRenderBuffer() {
}

/**********************************************************/
void RefosgRenderBuffer::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::RenderBuffer*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_glenum_internalFormat: public Enum<GLenum> {
public:
	Enum_glenum_internalFormat() {
	}
} glenum_internalFormat;

using namespace osg;

/**********************************************************/
void RefosgRenderBuffer::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgRenderBuffer::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgRenderBuffer::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgRenderBuffer::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgRenderBuffer::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::RenderBuffer::getUserData, &osg::RenderBuffer::setUserData);
	}
	if (name == "_height") {
		// Getter overloaded, must specify one type
		typedef int (osg::RenderBuffer::*getHeightFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::RenderBuffer::*setHeightFN)(int) ;
		return new GetterSetterProperty<int, osg::RenderBuffer>("_height", _object.get(), (getHeightFN)&osg::RenderBuffer::getHeight, (setHeightFN)&osg::RenderBuffer::setHeight);
	}
	if (name == "_width") {
		// Getter overloaded, must specify one type
		typedef int (osg::RenderBuffer::*getWidthFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::RenderBuffer::*setWidthFN)(int) ;
		return new GetterSetterProperty<int, osg::RenderBuffer>("_width", _object.get(), (getWidthFN)&osg::RenderBuffer::getWidth, (setWidthFN)&osg::RenderBuffer::setWidth);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::RenderBuffer::getDataVariance, &osg::RenderBuffer::setDataVariance, osg_object_datavariance);
	}
	if (name == "_internalFormat") {
		return new GetterSetterEnumProperty<GLenum, osg::RenderBuffer>("_internalFormat", _object.get(), &osg::RenderBuffer::getInternalFormat, &osg::RenderBuffer::setInternalFormat, glenum_internalFormat);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::RenderBuffer::getName, (setNameFN)&osg::RenderBuffer::setName);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgRenderBuffer::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgRenderBuffer::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgRenderBuffer::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgRenderBuffer::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgRenderBuffer::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::RenderBuffer, RefosgRenderBuffer> _registerRefosgRenderBuffer;
