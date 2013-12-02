#include <reflection/reflectionregistry.h>
#include <osg/TexMat>
#include <stdexcept>

/**
 * Reflector of class osg::TexMat
 */
class RefosgTexMat: public ClassReflection {
public:
	RefosgTexMat();
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
	osg::ref_ptr<osg::TexMat> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_matrix","_updateCallback","_eventCallback","_scaleByTextureRectangleSize","_dataVariance"};
ClassReflection::PropertyNames RefosgTexMat::_names(_propnames, _propnames+7);

ClassReflection::PropertyNames RefosgTexMat::_table_names;

std::string RefosgTexMat::_class_name("osg::TexMat");

std::string RefosgTexMat::_class_description(" A texture matrix state class that encapsulates OpenGL texture matrix functionality.     ");

std::string RefosgTexMat::_osg_version("1.2");


/**********************************************************/
RefosgTexMat::RefosgTexMat() {
}

/**********************************************************/
void RefosgTexMat::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TexMat*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osg;

/**********************************************************/
void RefosgTexMat::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTexMat::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTexMat::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTexMat::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTexMat::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TexMat::getUserData, &osg::TexMat::setUserData);
	}
	if (name == "_matrix") {
		// Getter overloaded, must specify one type
		typedef Matrix & (osg::TexMat::*getMatrixFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::TexMat::*setMatrixFN)(const Matrix &) ;
		return new GetterSetterProperty<Matrix, osg::TexMat>("_matrix", _object.get(), (getMatrixFN)&osg::TexMat::getMatrix, (setMatrixFN)&osg::TexMat::setMatrix);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TexMat::getDataVariance, &osg::TexMat::setDataVariance, osg_object_datavariance);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::TexMat::getUpdateCallback, &osg::TexMat::setUpdateCallback);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TexMat::getName, (setNameFN)&osg::TexMat::setName);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateAttribute::Callback * (osg::StateAttribute::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateAttribute::Callback*, osg::StateAttribute>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::TexMat::getEventCallback, &osg::TexMat::setEventCallback);
	}
	if (name == "_scaleByTextureRectangleSize") {
		return new GetterSetterProperty<bool, osg::TexMat>("_scaleByTextureRectangleSize", _object.get(), &osg::TexMat::getScaleByTextureRectangleSize, &osg::TexMat::setScaleByTextureRectangleSize);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexMat::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTexMat::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTexMat::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexMat::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTexMat::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TexMat, RefosgTexMat> _registerRefosgTexMat;
