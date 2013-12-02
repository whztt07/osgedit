#include <reflection/reflectionregistry.h>
#include <osg/Texture2DArray>
#include <stdexcept>

/**
 * Reflector of class osg::Texture2DArray
 */
class RefosgTexture2DArray: public ClassReflection {
public:
	RefosgTexture2DArray();
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
	osg::ref_ptr<osg::Texture2DArray> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_numMipmapLevels","_sourceFormat","_textureHeight","_internalFormat","_shadow_texture_mode","_clientStorageHint","_shadow_ambient","_borderWidth","_shadow_compare_func","_internalFormatMode","_maxAnisotropy","_textureWidth","_borderColor","_userData","_useHardwareMipMapGeneration","_resizeNonPowerOfTwoHint","_eventCallback","_subloadCallback","_updateCallback","_sourceType","_textureDepth","_dataVariance"};
ClassReflection::PropertyNames RefosgTexture2DArray::_names(_propnames, _propnames+23);

ClassReflection::PropertyNames RefosgTexture2DArray::_table_names;

std::string RefosgTexture2DArray::_class_name("osg::Texture2DArray");

std::string RefosgTexture2DArray::_class_description(" Texture2DArray state class which encapsulates OpenGL 2D array texture functionality. Texture arrays were introduced with Shader Model 4.0 hardware.A 2D texture array does contain textures sharing the same properties (e.g. size, bitdepth,...) in a layered structure. See http://www.opengl.org/registry/specs/EXT/texture_array.txt for more info.     ");

std::string RefosgTexture2DArray::_osg_version("1.2");


/**********************************************************/
RefosgTexture2DArray::RefosgTexture2DArray() {
}

/**********************************************************/
void RefosgTexture2DArray::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Texture2DArray*>(obj);
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
void RefosgTexture2DArray::addChild(osg::Object *child) {
	{GraphicsContext *cobj = dynamic_cast<GraphicsContext *>(child);
	if (cobj != 0) {
		_object->setReadPBuffer(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTexture2DArray::removeChild(osg::Object *child) {
	{GraphicsContext *cobj = dynamic_cast<GraphicsContext *>(child);
	if (cobj != 0) {
		_object->setReadPBuffer(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTexture2DArray::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getReadPBuffer();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTexture2DArray::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexture2DArray::getProperty(const std::string &name) {
	if (name == "_numMipmapLevels") {
		return new GetterSetterProperty<GLsizei, osg::Texture2DArray>("_numMipmapLevels", _object.get(), &osg::Texture2DArray::getNumMipmapLevels, &osg::Texture2DArray::setNumMipmapLevels);
	}
	if (name == "_sourceFormat") {
		return new GetterSetterEnumProperty<GLenum, osg::Texture>("_sourceFormat", _object.get(), &osg::Texture2DArray::getSourceFormat, &osg::Texture2DArray::setSourceFormat, glenum_sourceFormat);
	}
	if (name == "_textureHeight") {
		return new GetterSetterProperty<GLsizei, osg::Texture2DArray>("_textureHeight", _object.get(), &osg::Texture2DArray::getTextureHeight, &osg::Texture2DArray::setTextureHeight);
	}
	if (name == "_internalFormat") {
		return new GetterSetterProperty<GLint, osg::Texture>("_internalFormat", _object.get(), &osg::Texture2DArray::getInternalFormat, &osg::Texture2DArray::setInternalFormat);
	}
	if (name == "_shadow_texture_mode") {
		return new GetterSetterEnumProperty<osg::Texture::ShadowTextureMode, osg::Texture>("_shadow_texture_mode", _object.get(), &osg::Texture2DArray::getShadowTextureMode, &osg::Texture2DArray::setShadowTextureMode, osg_texture_shadowtexturemode);
	}
	if (name == "_clientStorageHint") {
		return new GetterSetterProperty<bool, osg::Texture>("_clientStorageHint", _object.get(), &osg::Texture2DArray::getClientStorageHint, &osg::Texture2DArray::setClientStorageHint);
	}
	if (name == "_shadow_ambient") {
		return new GetterSetterProperty<float, osg::Texture>("_shadow_ambient", _object.get(), &osg::Texture2DArray::getShadowAmbient, &osg::Texture2DArray::setShadowAmbient);
	}
	if (name == "_borderWidth") {
		return new GetterSetterProperty<GLint, osg::Texture>("_borderWidth", _object.get(), &osg::Texture2DArray::getBorderWidth, &osg::Texture2DArray::setBorderWidth);
	}
	if (name == "_shadow_compare_func") {
		return new GetterSetterEnumProperty<osg::Texture::ShadowCompareFunc, osg::Texture>("_shadow_compare_func", _object.get(), &osg::Texture2DArray::getShadowCompareFunc, &osg::Texture2DArray::setShadowCompareFunc, osg_texture_shadowcomparefunc);
	}
	if (name == "_internalFormatMode") {
		return new GetterSetterEnumProperty<osg::Texture::InternalFormatMode, osg::Texture>("_internalFormatMode", _object.get(), &osg::Texture2DArray::getInternalFormatMode, &osg::Texture2DArray::setInternalFormatMode, osg_texture_internalformatmode);
	}
	if (name == "_maxAnisotropy") {
		return new GetterSetterProperty<float, osg::Texture>("_maxAnisotropy", _object.get(), &osg::Texture2DArray::getMaxAnisotropy, &osg::Texture2DArray::setMaxAnisotropy);
	}
	if (name == "_textureWidth") {
		return new GetterSetterProperty<GLsizei, osg::Texture2DArray>("_textureWidth", _object.get(), &osg::Texture2DArray::getTextureWidth, &osg::Texture2DArray::setTextureWidth);
	}
	if (name == "_borderColor") {
		return new GetterSetterProperty<Vec4d, osg::Texture>("_borderColor", _object.get(), &osg::Texture2DArray::getBorderColor, &osg::Texture2DArray::setBorderColor);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Texture2DArray::getUserData, &osg::Texture2DArray::setUserData);
	}
	if (name == "_useHardwareMipMapGeneration") {
		return new GetterSetterProperty<bool, osg::Texture>("_useHardwareMipMapGeneration", _object.get(), &osg::Texture2DArray::getUseHardwareMipMapGeneration, &osg::Texture2DArray::setUseHardwareMipMapGeneration);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Texture2DArray::getDataVariance, &osg::Texture2DArray::setDataVariance, osg_object_datavariance);
	}
	if (name == "_resizeNonPowerOfTwoHint") {
		return new GetterSetterProperty<bool, osg::Texture>("_resizeNonPowerOfTwoHint", _object.get(), &osg::Texture2DArray::getResizeNonPowerOfTwoHint, &osg::Texture2DArray::setResizeNonPowerOfTwoHint);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Texture2DArray::getEventCallback, &osg::Texture2DArray::setEventCallback);
	}
	if (name == "_subloadCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Texture2DArray::SubloadCallback * (osg::Texture2DArray::*getSubloadCallbackFN)() ;
		return new GetterSetterProperty<osg::Texture2DArray::SubloadCallback*, osg::Texture2DArray>("_subloadCallback", _object.get(), (getSubloadCallbackFN)&osg::Texture2DArray::getSubloadCallback, &osg::Texture2DArray::setSubloadCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Texture2DArray::getName, (setNameFN)&osg::Texture2DArray::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Texture2DArray::getUpdateCallback, &osg::Texture2DArray::setUpdateCallback);
	}
	if (name == "_sourceType") {
		return new GetterSetterEnumProperty<GLenum, osg::Texture>("_sourceType", _object.get(), &osg::Texture2DArray::getSourceType, &osg::Texture2DArray::setSourceType, glenum_sourceType);
	}
	if (name == "_textureDepth") {
		return new GetterSetterProperty<GLsizei, osg::Texture2DArray>("_textureDepth", _object.get(), &osg::Texture2DArray::getTextureDepth, &osg::Texture2DArray::setTextureDepth);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexture2DArray::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexture2DArray::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexture2DArray::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexture2DArray::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexture2DArray::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Texture2DArray, RefosgTexture2DArray> _registerRefosgTexture2DArray;
