#include <reflection/reflectionregistry.h>
#include <osg/TextureRectangle>
#include <stdexcept>

/**
 * Reflector of class osg::TextureRectangle
 */
class RefosgTextureRectangle: public ClassReflection {
public:
	RefosgTextureRectangle();
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
	osg::ref_ptr<osg::TextureRectangle> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_subloadCallback","_shadow_texture_mode","_clientStorageHint","_textureWidth","_borderColor","_borderWidth","_shadow_compare_func","_useHardwareMipMapGeneration","_userData","_sourceFormat","_internalFormatMode","_updateCallback","_sourceType","_internalFormat","_resizeNonPowerOfTwoHint","_textureHeight","_maxAnisotropy","_eventCallback","_shadow_ambient","_dataVariance"};
ClassReflection::PropertyNames RefosgTextureRectangle::_names(_propnames, _propnames+21);

ClassReflection::PropertyNames RefosgTextureRectangle::_table_names;

std::string RefosgTextureRectangle::_class_name("osg::TextureRectangle");

std::string RefosgTextureRectangle::_class_description(" Texture state class which encapsulates OpenGL texture functionality.     ");

std::string RefosgTextureRectangle::_osg_version("1.2");


/**********************************************************/
RefosgTextureRectangle::RefosgTextureRectangle() {
}

/**********************************************************/
void RefosgTextureRectangle::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TextureRectangle*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_texture_shadowtexturemode: public Enum<osg::Texture::ShadowTextureMode> {
public:
	Enum_osg_texture_shadowtexturemode() {
		add("LUMINANCE", osg::Texture::LUMINANCE);
		add("INTENSITY", osg::Texture::INTENSITY);
		add("ALPHA", osg::Texture::ALPHA);
	}
} osg_texture_shadowtexturemode;
static class Enum_osg_texture_shadowcomparefunc: public Enum<osg::Texture::ShadowCompareFunc> {
public:
	Enum_osg_texture_shadowcomparefunc() {
		add("LEQUAL", osg::Texture::LEQUAL);
		add("GEQUAL", osg::Texture::GEQUAL);
	}
} osg_texture_shadowcomparefunc;
static class Enum_osg_texture_internalformatmode: public Enum<osg::Texture::InternalFormatMode> {
public:
	Enum_osg_texture_internalformatmode() {
		add("USE_IMAGE_DATA_FORMAT", osg::Texture::USE_IMAGE_DATA_FORMAT);
		add("USE_USER_DEFINED_FORMAT", osg::Texture::USE_USER_DEFINED_FORMAT);
		add("USE_ARB_COMPRESSION", osg::Texture::USE_ARB_COMPRESSION);
		add("USE_S3TC_DXT1_COMPRESSION", osg::Texture::USE_S3TC_DXT1_COMPRESSION);
		add("USE_S3TC_DXT3_COMPRESSION", osg::Texture::USE_S3TC_DXT3_COMPRESSION);
		add("USE_S3TC_DXT5_COMPRESSION", osg::Texture::USE_S3TC_DXT5_COMPRESSION);
	}
} osg_texture_internalformatmode;
static class Enum_glenum_sourceType: public Enum<GLenum> {
public:
	Enum_glenum_sourceType() {
		add("GL_UNSIGNED_BYTE", GL_UNSIGNED_BYTE);
		add("GL_BYTE", GL_BYTE);
		add("GL_UNSIGNED_SHORT", GL_UNSIGNED_SHORT);
		add("GL_SHORT", GL_SHORT);
		add("GL_UNSIGNED_INT", GL_UNSIGNED_INT);
		add("GL_INT", GL_INT);
		add("GL_FLOAT", GL_FLOAT);
		add("GL_BITMAP", GL_BITMAP);
	}
} glenum_sourceType;
static class Enum_glenum_sourceFormat: public Enum<GLenum> {
public:
	Enum_glenum_sourceFormat() {
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
} glenum_sourceFormat;

using namespace osg;

/**********************************************************/
void RefosgTextureRectangle::addChild(osg::Object *child) {
	{Image *cobj = dynamic_cast<Image *>(child);
	if (cobj != 0) {
		_object->setImage(cobj);
		return;
	}}
	{GraphicsContext *cobj = dynamic_cast<GraphicsContext *>(child);
	if (cobj != 0) {
		_object->setReadPBuffer(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTextureRectangle::removeChild(osg::Object *child) {
	{Image *cobj = dynamic_cast<Image *>(child);
	if (cobj != 0) {
		_object->setImage(0);
		return;
	}}
	{GraphicsContext *cobj = dynamic_cast<GraphicsContext *>(child);
	if (cobj != 0) {
		_object->setReadPBuffer(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTextureRectangle::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getImage();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getReadPBuffer();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTextureRectangle::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTextureRectangle::getProperty(const std::string &name) {
	if (name == "_subloadCallback") {
		// Getter overloaded, must specify one type
		typedef osg::TextureRectangle::SubloadCallback * (osg::TextureRectangle::*getSubloadCallbackFN)() ;
		return new GetterSetterProperty<osg::TextureRectangle::SubloadCallback*, osg::TextureRectangle>("_subloadCallback", _object.get(), (getSubloadCallbackFN)&osg::TextureRectangle::getSubloadCallback, &osg::TextureRectangle::setSubloadCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TextureRectangle::getDataVariance, &osg::TextureRectangle::setDataVariance, osg_object_datavariance);
	}
	if (name == "_shadow_texture_mode") {
		return new GetterSetterEnumProperty<osg::Texture::ShadowTextureMode, osg::Texture>("_shadow_texture_mode", _object.get(), &osg::TextureRectangle::getShadowTextureMode, &osg::TextureRectangle::setShadowTextureMode, osg_texture_shadowtexturemode);
	}
	if (name == "_clientStorageHint") {
		return new GetterSetterProperty<bool, osg::Texture>("_clientStorageHint", _object.get(), &osg::TextureRectangle::getClientStorageHint, &osg::TextureRectangle::setClientStorageHint);
	}
	if (name == "_textureWidth") {
		return new GetterSetterProperty<GLsizei, osg::TextureRectangle>("_textureWidth", _object.get(), &osg::TextureRectangle::getTextureWidth, &osg::TextureRectangle::setTextureWidth);
	}
	if (name == "_borderColor") {
		return new GetterSetterProperty<Vec4d, osg::Texture>("_borderColor", _object.get(), &osg::TextureRectangle::getBorderColor, &osg::TextureRectangle::setBorderColor);
	}
	if (name == "_borderWidth") {
		return new GetterSetterProperty<GLint, osg::Texture>("_borderWidth", _object.get(), &osg::TextureRectangle::getBorderWidth, &osg::TextureRectangle::setBorderWidth);
	}
	if (name == "_shadow_compare_func") {
		return new GetterSetterEnumProperty<osg::Texture::ShadowCompareFunc, osg::Texture>("_shadow_compare_func", _object.get(), &osg::TextureRectangle::getShadowCompareFunc, &osg::TextureRectangle::setShadowCompareFunc, osg_texture_shadowcomparefunc);
	}
	if (name == "_useHardwareMipMapGeneration") {
		return new GetterSetterProperty<bool, osg::Texture>("_useHardwareMipMapGeneration", _object.get(), &osg::TextureRectangle::getUseHardwareMipMapGeneration, &osg::TextureRectangle::setUseHardwareMipMapGeneration);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TextureRectangle::getUserData, &osg::TextureRectangle::setUserData);
	}
	if (name == "_sourceFormat") {
		return new GetterSetterEnumProperty<GLenum, osg::Texture>("_sourceFormat", _object.get(), &osg::TextureRectangle::getSourceFormat, &osg::TextureRectangle::setSourceFormat, glenum_sourceFormat);
	}
	if (name == "_internalFormatMode") {
		return new GetterSetterEnumProperty<osg::Texture::InternalFormatMode, osg::Texture>("_internalFormatMode", _object.get(), &osg::TextureRectangle::getInternalFormatMode, &osg::TextureRectangle::setInternalFormatMode, osg_texture_internalformatmode);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TextureRectangle::getName, (setNameFN)&osg::TextureRectangle::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::TextureRectangle::getUpdateCallback, &osg::TextureRectangle::setUpdateCallback);
	}
	if (name == "_sourceType") {
		return new GetterSetterEnumProperty<GLenum, osg::Texture>("_sourceType", _object.get(), &osg::TextureRectangle::getSourceType, &osg::TextureRectangle::setSourceType, glenum_sourceType);
	}
	if (name == "_internalFormat") {
		return new GetterSetterProperty<GLint, osg::Texture>("_internalFormat", _object.get(), &osg::TextureRectangle::getInternalFormat, &osg::TextureRectangle::setInternalFormat);
	}
	if (name == "_resizeNonPowerOfTwoHint") {
		return new GetterSetterProperty<bool, osg::Texture>("_resizeNonPowerOfTwoHint", _object.get(), &osg::TextureRectangle::getResizeNonPowerOfTwoHint, &osg::TextureRectangle::setResizeNonPowerOfTwoHint);
	}
	if (name == "_textureHeight") {
		return new GetterSetterProperty<GLsizei, osg::TextureRectangle>("_textureHeight", _object.get(), &osg::TextureRectangle::getTextureHeight, &osg::TextureRectangle::setTextureHeight);
	}
	if (name == "_maxAnisotropy") {
		return new GetterSetterProperty<float, osg::Texture>("_maxAnisotropy", _object.get(), &osg::TextureRectangle::getMaxAnisotropy, &osg::TextureRectangle::setMaxAnisotropy);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::TextureRectangle::getEventCallback, &osg::TextureRectangle::setEventCallback);
	}
	if (name == "_shadow_ambient") {
		return new GetterSetterProperty<float, osg::Texture>("_shadow_ambient", _object.get(), &osg::TextureRectangle::getShadowAmbient, &osg::TextureRectangle::setShadowAmbient);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTextureRectangle::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTextureRectangle::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTextureRectangle::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTextureRectangle::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTextureRectangle::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TextureRectangle, RefosgTextureRectangle> _registerRefosgTextureRectangle;
