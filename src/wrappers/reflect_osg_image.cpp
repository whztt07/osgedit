#include <reflection/reflectionregistry.h>
#include <osg/Image>
#include <stdexcept>

/**
 * Reflector of class osg::Image
 */
class RefosgImage: public ClassReflection {
public:
	RefosgImage();
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
	osg::ref_ptr<osg::Image> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_packing","_fileName","_dataType","_internalTextureFormat","_pixelFormat","_modifiedCount","_allocationMode","_origin","_dataVariance"};
ClassReflection::PropertyNames RefosgImage::_names(_propnames, _propnames+11);

ClassReflection::PropertyNames RefosgImage::_table_names;

std::string RefosgImage::_class_name("osg::Image");

std::string RefosgImage::_class_description(" Image class for encapsulating the storage texture image data.     ");

std::string RefosgImage::_osg_version("1.2");


/**********************************************************/
RefosgImage::RefosgImage() {
}

/**********************************************************/
void RefosgImage::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Image*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_image_origin: public Enum<osg::Image::Origin> {
public:
	Enum_osg_image_origin() {
		add("BOTTOM_LEFT", osg::Image::BOTTOM_LEFT);
		add("TOP_LEFT", osg::Image::TOP_LEFT);
	}
} osg_image_origin;
static class Enum_osg_image_allocationmode: public Enum<osg::Image::AllocationMode> {
public:
	Enum_osg_image_allocationmode() {
		add("NO_DELETE", osg::Image::NO_DELETE);
		add("USE_NEW_DELETE", osg::Image::USE_NEW_DELETE);
		add("USE_MALLOC_FREE", osg::Image::USE_MALLOC_FREE);
	}
} osg_image_allocationmode;
static class Enum_glenum_pixelFormat: public Enum<GLenum> {
public:
	Enum_glenum_pixelFormat() {
		add("GL_COLOR_INDEX", GL_COLOR_INDEX);
		add("GL_RED", GL_RED);
		add("GL_GREEN", GL_GREEN);
		add("GL_BLUE", GL_BLUE);
		add("GL_ALPHA", GL_ALPHA);
		add("GL_RGB", GL_RGB);
		add("GL_RGBA", GL_RGBA);
		add("GL_LUMINANCE", GL_LUMINANCE);
		add("GL_LUMINANCE_ALPHA", GL_LUMINANCE_ALPHA);
	}
} glenum_pixelFormat;
static class Enum_glenum_dataType: public Enum<GLenum> {
public:
	Enum_glenum_dataType() {
		add("GL_UNSIGNED_BYTE", GL_UNSIGNED_BYTE);
		add("GL_BYTE", GL_BYTE);
		add("GL_UNSIGNED_SHORT", GL_UNSIGNED_SHORT);
		add("GL_SHORT", GL_SHORT);
		add("GL_UNSIGNED_INT", GL_UNSIGNED_INT);
		add("GL_INT", GL_INT);
		add("GL_FLOAT", GL_FLOAT);
		add("GL_BITMAP", GL_BITMAP);
	}
} glenum_dataType;

using namespace osg;

/**********************************************************/
void RefosgImage::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgImage::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgImage::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgImage::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgImage::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Image::getUserData, &osg::Image::setUserData);
	}
	if (name == "_packing") {
		// Getter overloaded, must specify one type
		typedef unsigned int (osg::Image::*getPackingFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Image::*setPackingFN)(unsigned int) ;
		return new GetterSetterProperty<unsigned int, osg::Image>("_packing", _object.get(), (getPackingFN)&osg::Image::getPacking, (setPackingFN)&osg::Image::setPacking);
	}
	if (name == "_fileName") {
		return new GetterSetterProperty<std::string, osg::Image>("_fileName", _object.get(), &osg::Image::getFileName, &osg::Image::setFileName);
	}
	if (name == "_dataType") {
		return new GetterSetterEnumProperty<GLenum, osg::Image>("_dataType", _object.get(), &osg::Image::getDataType, &osg::Image::setDataType, glenum_dataType);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Image::getDataVariance, &osg::Image::setDataVariance, osg_object_datavariance);
	}
	if (name == "_internalTextureFormat") {
		return new GetterSetterProperty<GLint, osg::Image>("_internalTextureFormat", _object.get(), &osg::Image::getInternalTextureFormat, &osg::Image::setInternalTextureFormat);
	}
	if (name == "_pixelFormat") {
		return new GetterSetterEnumProperty<GLenum, osg::Image>("_pixelFormat", _object.get(), &osg::Image::getPixelFormat, &osg::Image::setPixelFormat, glenum_pixelFormat);
	}
	if (name == "_modifiedCount") {
		return new GetterSetterProperty<unsigned int, osg::Image>("_modifiedCount", _object.get(), &osg::Image::getModifiedCount, &osg::Image::setModifiedCount);
	}
	if (name == "_allocationMode") {
		return new GetterSetterEnumProperty<osg::Image::AllocationMode, osg::Image>("_allocationMode", _object.get(), &osg::Image::getAllocationMode, &osg::Image::setAllocationMode, osg_image_allocationmode);
	}
	if (name == "_origin") {
		// Getter overloaded, must specify one type
		typedef osg::Image::Origin (osg::Image::*getOriginFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Image::*setOriginFN)(osg::Image::Origin) ;
		return new GetterSetterEnumProperty<osg::Image::Origin, osg::Image>("_origin", _object.get(), (getOriginFN)&osg::Image::getOrigin, (setOriginFN)&osg::Image::setOrigin, osg_image_origin);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Image::getName, (setNameFN)&osg::Image::setName);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgImage::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgImage::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgImage::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgImage::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgImage::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Image, RefosgImage> _registerRefosgImage;
