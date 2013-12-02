#include <reflection/reflectionregistry.h>
#include <osg/Shape>
#include <stdexcept>

/**
 * Reflector of class osg::TriangleMesh
 */
class RefosgTriangleMesh: public ClassReflection {
public:
	RefosgTriangleMesh();
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
	osg::ref_ptr<osg::TriangleMesh> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_vertices","_indices","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgTriangleMesh::_names(_propnames, _propnames+5);

ClassReflection::PropertyNames RefosgTriangleMesh::_table_names;

std::string RefosgTriangleMesh::_class_name("osg::TriangleMesh");

std::string RefosgTriangleMesh::_class_description("     ");

std::string RefosgTriangleMesh::_osg_version("1.2");


/**********************************************************/
RefosgTriangleMesh::RefosgTriangleMesh() {
}

/**********************************************************/
void RefosgTriangleMesh::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TriangleMesh*>(obj);
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
void RefosgTriangleMesh::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTriangleMesh::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTriangleMesh::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTriangleMesh::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTriangleMesh::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::TriangleMesh::getName, (setNameFN)&osg::TriangleMesh::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::TriangleMesh::getDataVariance, &osg::TriangleMesh::setDataVariance, osg_object_datavariance);
	}
	if (name == "_vertices") {
		// Getter overloaded, must specify one type
		typedef Vec3Array * (osg::TriangleMesh::*getVerticesFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::TriangleMesh::*setVerticesFN)(Vec3Array *) ;
		return new GetterSetterProperty<Vec3Array*, osg::TriangleMesh>("_vertices", _object.get(), (getVerticesFN)&osg::TriangleMesh::getVertices, (setVerticesFN)&osg::TriangleMesh::setVertices);
	}
	if (name == "_indices") {
		// Getter overloaded, must specify one type
		typedef IndexArray * (osg::TriangleMesh::*getIndicesFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::TriangleMesh::*setIndicesFN)(IndexArray *) ;
		return new GetterSetterProperty<IndexArray*, osg::TriangleMesh>("_indices", _object.get(), (getIndicesFN)&osg::TriangleMesh::getIndices, (setIndicesFN)&osg::TriangleMesh::setIndices);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::TriangleMesh::getUserData, &osg::TriangleMesh::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTriangleMesh::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTriangleMesh::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTriangleMesh::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTriangleMesh::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTriangleMesh::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::TriangleMesh, RefosgTriangleMesh> _registerRefosgTriangleMesh;
