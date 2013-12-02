#include <reflection/reflectionregistry.h>
#include <osg/Texture3D>
#include <stdexcept>

/**
 * Reflector of class osg::Texture3D
 */
class RefosgTexture3D: public ClassReflection {
public:
	RefosgTexture3D();
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
	osg::ref_ptr<osg::Texture3D> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_numMipmapLevels","_sourceFormat","_textureHeight","_internalFormat","_shadow_texture_mode","_clientStorageHint","_shadow_ambient","_borderWidth","_shadow_compare_func","_internalFormatMode","_maxAnisotropy","_textureWidth","_borderColor","_userData","_useHardwareMipMapGeneration","_resizeNonPowerOfTwoHint","_eventCallback","_subloadCallback","_updateCallback","_sourceType","_textureDepth","_dataVariance"};
ClassReflection::PropertyNames RefosgTexture3D::_names(_propnames, _propnames+23);

ClassReflection::PropertyNames RefosgTexture3D::_table_names;

std::string RefosgTexture3D::_class_name("osg::Texture3D");

std::string RefosgTexture3D::_class_description(" Encapsulates OpenGl 2D texture functionality. Doesn't support cube maps, so ignore face parameters.     ");

std::string RefosgTexture3D::_osg_version("1.2");


/**********************************************************/
RefosgTexture3D::RefosgTexture3D() {
}

/**********************************************************/
void RefosgTexture3D::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Texture3D*>(obj);
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
void RefosgTexture3D::addChild(osg::Object *child) {
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
void RefosgTexture3D::removeChild(osg::Object *child) {
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
osg::Object *RefosgTexture3D::getChildObject(unsigned i) {
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
unsigned RefosgTexture3D::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexture3D::getProperty(const std::string &name) {
	if (name == "_numMipmapLevels") {
		return new GetterSetterProperty<GLsizei, osg::Texture3D>("_numMipmapLevels", _object.get(), &osg::Texture3D::getNumMipmapLevels, &osg::Texture3D::setNumMipmapLevels);
	}
	if (name == "_sourceFormat") {
		return new GetterSetterEnumProperty<GLenum, osg::Texture>("_sourceFormat", _object.get(), &osg::Texture3D::getSourceFormat, &osg::Texture3D::setSourceFormat, glenum_sourceFormat);
	}
	if (name == "_textureHeight") {
		return new GetterSetterProperty<GLsizei, osg::Texture3D>("_textureHeight", _object.get(), &osg::Texture3D::getTextureHeight, &osg::Texture3D::setTextureHeight);
	}
	if (name == "_internalFormat") {
		return new GetterSetterProperty<GLint, osg::Texture>("_internalFormat", _object.get(), &osg::Texture3D::getInternalFormat, &osg::Texture3D::setInternalFormat);
	}
	if (name == "_shadow_texture_mode") {
		return new GetterSetterEnumProperty<osg::Texture::ShadowTextureMode, osg::Texture>("_shadow_texture_mode", _object.get(), &osg::Texture3D::getShadowTextureMode, &osg::Texture3D::setShadowTextureMode, osg_texture_shadowtexturemode);
	}
	if (name == "_clientStorageHint") {
		return new GetterSetterProperty<bool, osg::Texture>("_clientStorageHint", _object.get(), &osg::Texture3D::getClientStorageHint, &osg::Texture3D::setClientStorageHint);
	}
	if (name == "_shadow_ambient") {
		return new GetterSetterProperty<float, osg::Texture>("_shadow_ambient", _object.get(), &osg::Texture3D::getShadowAmbient, &osg::Texture3D::setShadowAmbient);
	}
	if (name == "_borderWidth") {
		return new GetterSetterProperty<GLint, osg::Texture>("_borderWidth", _object.get(), &osg::Texture3D::getBorderWidth, &osg::Texture3D::setBorderWidth);
	}
	if (name == "_shadow_compare_func") {
		return new GetterSetterEnumProperty<osg::Texture::ShadowCompareFunc, osg::Texture>("_shadow_compare_func", _object.get(), &osg::Texture3D::getShadowCompareFunc, &osg::Texture3D::setShadowCompareFunc, osg_texture_shadowcomparefunc);
	}
	if (name == "_internalFormatMode") {
		return new GetterSetterEnumProperty<osg::Texture::InternalFormatMode, osg::Texture>("_internalFormatMode", _object.get(), &osg::Texture3D::getInternalFormatMode, &osg::Texture3D::setInternalFormatMode, osg_texture_internalformatmode);
	}
	if (name == "_maxAnisotropy") {
		return new GetterSetterProperty<float, osg::Texture>("_maxAnisotropy", _object.get(), &osg::Texture3D::getMaxAnisotropy, &osg::Texture3D::setMaxAnisotropy);
	}
	if (name == "_textureWidth") {
		return new GetterSetterProperty<GLsizei, osg::Texture3D>("_textureWidth", _object.get(), &osg::Texture3D::getTextureWidth, &osg::Texture3D::setTextureWidth);
	}
	if (name == "_borderColor") {
		return new GetterSetterProperty<Vec4d, osg::Texture>("_borderColor", _object.get(), &osg::Texture3D::getBorderColor, &osg::Texture3D::setBorderColor);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Texture3D::getUserData, &osg::Texture3D::setUserData);
	}
	if (name == "_useHardwareMipMapGeneration") {
		return new GetterSetterProperty<bool, osg::Texture>("_useHardwareMipMapGeneration", _object.get(), &osg::Texture3D::getUseHardwareMipMapGeneration, &osg::Texture3D::setUseHardwareMipMapGeneration);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Texture3D::getDataVariance, &osg::Texture3D::setDataVariance, osg_object_datavariance);
	}
	if (name == "_resizeNonPowerOfTwoHint") {
		return new GetterSetterProperty<bool, osg::Texture>("_resizeNonPowerOfTwoHint", _object.get(), &osg::Texture3D::getResizeNonPowerOfTwoHint, &osg::Texture3D::setResizeNonPowerOfTwoHint);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Texture3D::getEventCallback, &osg::Texture3D::setEventCallback);
	}
	if (name == "_subloadCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Texture3D::SubloadCallback * (osg::Texture3D::*getSubloadCallbackFN)() ;
		return new GetterSetterProperty<osg::Texture3D::SubloadCallback*, osg::Texture3D>("_subloadCallback", _object.get(), (getSubloadCallbackFN)&osg::Texture3D::getSubloadCallback, &osg::Texture3D::setSubloadCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Texture3D::getName, (setNameFN)&osg::Texture3D::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Texture3D::getUpdateCallback, &osg::Texture3D::setUpdateCallback);
	}
	if (name == "_sourceType") {
		return new GetterSetterEnumProperty<GLenum, osg::Texture>("_sourceType", _object.get(), &osg::Texture3D::getSourceType, &osg::Texture3D::setSourceType, glenum_sourceType);
	}
	if (name == "_textureDepth") {
		return new GetterSetterProperty<GLsizei, osg::Texture3D>("_textureDepth", _object.get(), &osg::Texture3D::getTextureDepth, &osg::Texture3D::setTextureDepth);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexture3D::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexture3D::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexture3D::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexture3D::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexture3D::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Texture3D, RefosgTexture3D> _registerRefosgTexture3D;
