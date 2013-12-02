#include <reflection/reflectionregistry.h>
#include <osgText/Font>
#include <stdexcept>

/**
 * Reflector of class osgText::Font
 */
class RefosgTextFont: public ClassReflection {
public:
	RefosgTextFont();
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
	osg::ref_ptr<osgText::Font> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_magFilterHint","_userData","_implementation","_minFilterHint","_dataVariance"};
ClassReflection::PropertyNames RefosgTextFont::_names(_propnames, _propnames+6);

ClassReflection::PropertyNames RefosgTextFont::_table_names;

std::string RefosgTextFont::_class_name("osgText::Font");

std::string RefosgTextFont::_class_description(" Pure virtual base class for fonts. Concrete implementation are the DefaultFont found in src/osgText/DefaultFont.cpp and FreeTypeFont found in src/osgPlugins/freetype/FreeTypeFont.cpp     ");

std::string RefosgTextFont::_osg_version("1.2");


/**********************************************************/
RefosgTextFont::RefosgTextFont() {
}

/**********************************************************/
void RefosgTextFont::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgText::Font*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgText;
using namespace osg;

/**********************************************************/
void RefosgTextFont::addChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{osg::TexEnv *cobj = dynamic_cast<osg::TexEnv *>(child);
	if (cobj != 0) {
		_object->setTexEnv(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTextFont::removeChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{osg::TexEnv *cobj = dynamic_cast<osg::TexEnv *>(child);
	if (cobj != 0) {
		_object->setTexEnv(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTextFont::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getTexEnv();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTextFont::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTextFont::getProperty(const std::string &name) {
	if (name == "_magFilterHint") {
		return new GetterSetterProperty<osg::Texture::FilterMode, osgText::Font>("_magFilterHint", _object.get(), &osgText::Font::getMagFilterHint, &osgText::Font::setMagFilterHint);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgText::Font::getUserData, &osgText::Font::setUserData);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgText::Font::getDataVariance, &osgText::Font::setDataVariance, osg_object_datavariance);
	}
	if (name == "_implementation") {
		// Getter overloaded, must specify one type
		typedef osgText::Font::FontImplementation * (osgText::Font::*getImplementationFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osgText::Font::*setImplementationFN)(osgText::Font::FontImplementation *) ;
		return new GetterSetterProperty<osgText::Font::FontImplementation*, osgText::Font>("_implementation", _object.get(), (getImplementationFN)&osgText::Font::getImplementation, (setImplementationFN)&osgText::Font::setImplementation);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgText::Font::getName, (setNameFN)&osgText::Font::setName);
	}
	if (name == "_minFilterHint") {
		return new GetterSetterProperty<osg::Texture::FilterMode, osgText::Font>("_minFilterHint", _object.get(), &osgText::Font::getMinFilterHint, &osgText::Font::setMinFilterHint);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTextFont::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTextFont::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTextFont::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTextFont::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTextFont::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgText::Font, RefosgTextFont> _registerRefosgTextFont;
