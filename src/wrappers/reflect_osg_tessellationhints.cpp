#include <reflection/reflectionregistry.h>
#include <osg/ShapeDrawable>
#include <stdexcept>

/**
 * Reflector of class osg::TessellationHints
 */
class RefosgTessellationHints: public ClassReflection {
public:
	RefosgTessellationHints();
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
	osg::ref_ptr<osg::TessellationHints> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_targetNumFaces","_detailRatio","_createTextureCoords","_createFrontFace","_createBackFace","_createBottom","_createBody","_createTop","_createNormals","_dataVariance"};
ClassReflection::PropertyNames RefosgTessellationHints::_names(_propnames, _propnames+12);

ClassReflection::PropertyNames RefosgTessellationHints::_table_names;

std::string RefosgTessellationHints::_class_name("osg::TessellationHints");

std::string RefosgTessellationHints::_class_description(" Describe several hints that can be passed to a Tessellator (like the one used by ShapeDrawable) as a mean to try to influence the way it works.     ");

std::string RefosgTessellationHints::_osg_version("1.2");


/**********************************************************/
RefosgTessellationHints::RefosgTessellationHints() {
}

/**********************************************************/
void RefosgTessellationHints::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TessellationHints*>(obj);
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
void RefosgTessellationHints::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTessellationHints::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTessellationHints::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTessellationHints::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTessellationHints::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TessellationHints::getUserData, &osg::TessellationHints::setUserData);
	}
	if (name == "_targetNumFaces") {
		return new GetterSetterProperty<unsigned int, osg::TessellationHints>("_targetNumFaces", _object.get(), &osg::TessellationHints::getTargetNumFaces, &osg::TessellationHints::setTargetNumFaces);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TessellationHints::getDataVariance, &osg::TessellationHints::setDataVariance, osg_object_datavariance);
	}
	if (name == "_detailRatio") {
		return new GetterSetterProperty<float, osg::TessellationHints>("_detailRatio", _object.get(), &osg::TessellationHints::getDetailRatio, &osg::TessellationHints::setDetailRatio);
	}
	if (name == "_createTextureCoords") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createTextureCoords", _object.get(), &osg::TessellationHints::getCreateTextureCoords, &osg::TessellationHints::setCreateTextureCoords);
	}
	if (name == "_createFrontFace") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createFrontFace", _object.get(), &osg::TessellationHints::getCreateFrontFace, &osg::TessellationHints::setCreateFrontFace);
	}
	if (name == "_createBackFace") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createBackFace", _object.get(), &osg::TessellationHints::getCreateBackFace, &osg::TessellationHints::setCreateBackFace);
	}
	if (name == "_createBottom") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createBottom", _object.get(), &osg::TessellationHints::getCreateBottom, &osg::TessellationHints::setCreateBottom);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TessellationHints::getName, (setNameFN)&osg::TessellationHints::setName);
	}
	if (name == "_createBody") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createBody", _object.get(), &osg::TessellationHints::getCreateBody, &osg::TessellationHints::setCreateBody);
	}
	if (name == "_createTop") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createTop", _object.get(), &osg::TessellationHints::getCreateTop, &osg::TessellationHints::setCreateTop);
	}
	if (name == "_createNormals") {
		return new GetterSetterProperty<bool, osg::TessellationHints>("_createNormals", _object.get(), &osg::TessellationHints::getCreateNormals, &osg::TessellationHints::setCreateNormals);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTessellationHints::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTessellationHints::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTessellationHints::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTessellationHints::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTessellationHints::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TessellationHints, RefosgTessellationHints> _registerRefosgTessellationHints;
