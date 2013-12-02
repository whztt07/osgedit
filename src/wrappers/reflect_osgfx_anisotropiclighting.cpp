#include <reflection/reflectionregistry.h>
#include <osgFX/AnisotropicLighting>
#include <stdexcept>

/**
 * Reflector of class osgFX::AnisotropicLighting
 */
class RefosgFXAnisotropicLighting: public ClassReflection {
public:
	RefosgFXAnisotropicLighting();
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
	osg::ref_ptr<osgFX::AnisotropicLighting> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_cullingActive","_enabled","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgFXAnisotropicLighting::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgFXAnisotropicLighting::_table_names;

std::string RefosgFXAnisotropicLighting::_class_name("osgFX::AnisotropicLighting");

std::string RefosgFXAnisotropicLighting::_class_description(" This single-pass effect implements a sort of anisotropic lighting that replaces the standard OpenGL lighting model. The final color of vertices is not computed directly, it is the result of a texture lookup on a user-supplied lighting image map. A vertex program is used to compute the s and t texture coordinates as follows: s = (N dot H) ; t = (N dot L) where N is the vertex normal, L is the light-to-vertex vector, H is the half-way vector. This is a good example of how you can use the State::getInitialViewMatrix() method to retrieve the view matrix and perform view-dependant effects without fakes of any kind. This effect requires the ARB_vertex_program extension.     ");

std::string RefosgFXAnisotropicLighting::_osg_version("1.2");


/**********************************************************/
RefosgFXAnisotropicLighting::RefosgFXAnisotropicLighting() {
}

/**********************************************************/
void RefosgFXAnisotropicLighting::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgFX::AnisotropicLighting*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgFX;
using namespace osg;

/**********************************************************/
void RefosgFXAnisotropicLighting::addChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(cobj);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->addChild(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgFXAnisotropicLighting::removeChild(osg::Object *child) {
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(0);
		return;
	}}
	{Node *cobj = dynamic_cast<Node *>(child);
	if (cobj != 0) {
		_object->removeChild(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgFXAnisotropicLighting::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getCullCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getUpdateCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getEventCallback();
	} else {
		i -= 1;
	}
	if (i < _object->getNumChildren()) {
		return _object->getChild(i);
	} else {
		i -= _object->getNumChildren();
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgFXAnisotropicLighting::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgFXAnisotropicLighting::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgFX::AnisotropicLighting::getInitialBound, &osgFX::AnisotropicLighting::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgFX::AnisotropicLighting::getUserData, &osgFX::AnisotropicLighting::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgFX::AnisotropicLighting::getNodeMask, &osgFX::AnisotropicLighting::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgFX::AnisotropicLighting::getName, (setNameFN)&osgFX::AnisotropicLighting::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgFX::AnisotropicLighting::getCullingActive, &osgFX::AnisotropicLighting::setCullingActive);
	}
	if (name == "_enabled") {
		// Getter overloaded, must specify one type
		typedef bool (osgFX::Effect::*getEnabledFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgFX::Effect::*setEnabledFN)(bool) ;
		return new GetterSetterProperty<bool, osgFX::Effect>("_enabled", _object.get(), (getEnabledFN)&osgFX::AnisotropicLighting::getEnabled, (setEnabledFN)&osgFX::AnisotropicLighting::setEnabled);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgFX::AnisotropicLighting::getDataVariance, &osgFX::AnisotropicLighting::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgFX::AnisotropicLighting::getDescriptions, (setDescriptionsFN)&osgFX::AnisotropicLighting::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgFXAnisotropicLighting::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgFXAnisotropicLighting::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgFXAnisotropicLighting::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFXAnisotropicLighting::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFXAnisotropicLighting::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgFX::AnisotropicLighting, RefosgFXAnisotropicLighting> _registerRefosgFXAnisotropicLighting;
