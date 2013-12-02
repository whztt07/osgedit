#include <stdexcept>
#include <reflection/reflectionregistry.h>
#include <osg/Material>

/**
 * Reflector of class osg::Material
 */
class RefosgMaterial: public ClassReflection {
public:
	RefosgMaterial();
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

	virtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col) { throw PropertyNotFoundException(name); }
	virtual unsigned getNumTablePropertyColumns(const std::string &name) { throw PropertyNotFoundException(name); }
	virtual unsigned getNumTablePropertyRows(const std::string &name) { throw PropertyNotFoundException(name); }
	virtual const PropertyNames &getTablePropertyNames() { return _table_names; }
	virtual const PropertyNames getTablePropertyColumnTitles(const std::string &name) { throw PropertyNotFoundException(name); }
	virtual const PropertyNames getTablePropertyRowTitles(const std::string &name) { throw PropertyNotFoundException(name); }
private:
	osg::ref_ptr<osg::Material> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_colorMode","_updateCallback","_dataVariance","_eventCallback", "_ambientFront", "_ambientBack", "_diffuseFront", "_diffuseBack", "_specularFront", "_specularBack", "_emissionFront", "_emissionBack", "_shininessFront", "_shininessBack","_userData"};
ClassReflection::PropertyNames RefosgMaterial::_names(_propnames, _propnames+16);

ClassReflection::PropertyNames RefosgMaterial::_table_names;

std::string RefosgMaterial::_class_name("osg::Material");

std::string RefosgMaterial::_class_description(" Material - encapsulates OpenGL glMaterial state.     ");

std::string RefosgMaterial::_osg_version("1.2");


/**********************************************************/
RefosgMaterial::RefosgMaterial() {
}

/**********************************************************/
void RefosgMaterial::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Material*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
	}
} osg_object_datavariance;
static class Enum_osg_material_colormode: public Enum<osg::Material::ColorMode> {
public:
	Enum_osg_material_colormode() {
		add("AMBIENT", osg::Material::AMBIENT);
		add("DIFFUSE", osg::Material::DIFFUSE);
		add("SPECULAR", osg::Material::SPECULAR);
		add("EMISSION", osg::Material::EMISSION);
		add("AMBIENT_AND_DIFFUSE", osg::Material::AMBIENT_AND_DIFFUSE);
		add("OFF", osg::Material::OFF);
	}
} osg_material_colormode;

/**
 * Custom property for material colors
 */
class MatColorProperty: public TemplateProperty<osg::Vec4> {
public:
	typedef void (osg::Material::*SetterFn)(osg::Material::Face, const osg::Vec4&);
	typedef const osg::Vec4& (osg::Material::*GetterFn)(osg::Material::Face) const;

	MatColorProperty(std::string name, osg::Material *mat, GetterFn getter, SetterFn setter, osg::Material::Face face): TemplateProperty<osg::Vec4>(name) {
		_mat = mat;
		_face = face;
		_getter = getter;
        _setter = setter;
	}
	virtual osg::Vec4 get() {
        return (_mat->*_getter)(_face);
	}
	virtual void setImpl(osg::Vec4 &t) {
        (_mat->*_setter)(_face, t);
	}
private:
	osg::Material *_mat;
	osg::Material::Face _face;
	GetterFn _getter;
    SetterFn _setter;
};

/**
 * Custom property for material shininess
 */
class MatShininessProperty: public TemplateProperty<float> {
public:
	MatShininessProperty(std::string name, osg::Material *mat, osg::Material::Face face): TemplateProperty<float>(name) {
		_mat = mat;
		_face = face;
	}
	virtual float get() {
        return _mat->getShininess(_face);
	}
	virtual void setImpl(float &t) {
        _mat->setShininess(_face, t);
	}
private:
	osg::Material *_mat;
	osg::Material::Face _face;
};

using namespace osg;

/**********************************************************/
void RefosgMaterial::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgMaterial::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgMaterial::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgMaterial::getNumChildren() {
    return 0;
}

/**********************************************************/
PropertyReflection* RefosgMaterial::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Material::getUserData, &osg::Material::setUserData);
	}
	if (name == "_colorMode") {
		return new GetterSetterEnumProperty<osg::Material::ColorMode, osg::Material>("_colorMode", _object.get(), &osg::Material::getColorMode, &osg::Material::setColorMode, osg_material_colormode);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Material::getName, (setNameFN)&osg::Material::setName);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::Material::getUpdateCallback, &osg::Material::setUpdateCallback);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Material::getDataVariance, &osg::Material::setDataVariance, osg_object_datavariance);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::Material::getEventCallback, &osg::Material::setEventCallback);
	}
	if (name == "_ambientFront") {
		return new MatColorProperty(name, _object.get(), &osg::Material::getAmbient, &osg::Material::setAmbient, osg::Material::FRONT);
	}
	if (name == "_ambientBack") {
		return new MatColorProperty(name, _object.get(), &osg::Material::getAmbient, &osg::Material::setAmbient, osg::Material::BACK);
	}
	if (name == "_diffuseFront") {
		return new MatColorProperty(name, _object.get(), &osg::Material::getDiffuse, &osg::Material::setDiffuse, osg::Material::FRONT);
	}
	if (name == "_diffuseBack") {
		return new MatColorProperty(name, _object.get(), &osg::Material::getDiffuse, &osg::Material::setDiffuse, osg::Material::BACK);
	}
	if (name == "_specularFront") {
		return new MatColorProperty(name, _object.get(), &osg::Material::getSpecular, &osg::Material::setSpecular, osg::Material::FRONT);
	}
	if (name == "_specularBack"){
		return new MatColorProperty(name, _object.get(), &osg::Material::getSpecular, &osg::Material::setSpecular, osg::Material::BACK);
	}

	if (name == "_emissionFront") {
		return new MatColorProperty(name, _object.get(), &osg::Material::getEmission, &osg::Material::setEmission, osg::Material::FRONT);
	}
	if (name == "_emissionBack"){
		return new MatColorProperty(name, _object.get(), &osg::Material::getEmission, &osg::Material::setEmission, osg::Material::BACK);
	}
	if (name == "_shininessFront"){
		return new MatShininessProperty(name, _object.get(), osg::Material::FRONT);
	}
	if (name == "_shininessBack"){
		return new MatShininessProperty(name, _object.get(), osg::Material::BACK);
	}

	throw PropertyNotFoundException(name);
}

/** REGISTERING **/
RegisterWrapperClass<osg::Material, RefosgMaterial> _registerRefosgMaterial;
