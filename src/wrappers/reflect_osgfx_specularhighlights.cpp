#include <reflection/reflectionregistry.h>
#include <osgFX/SpecularHighlights>
#include <stdexcept>

/**
 * Reflector of class osgFX::SpecularHighlights
 */
class RefosgFXSpecularHighlights: public ClassReflection {
public:
	RefosgFXSpecularHighlights();
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
	osg::ref_ptr<osgFX::SpecularHighlights> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_cullingActive","_enabled","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgFXSpecularHighlights::_names(_propnames, _propnames+8);

ClassReflection::PropertyNames RefosgFXSpecularHighlights::_table_names;

std::string RefosgFXSpecularHighlights::_class_name("osgFX::SpecularHighlights");

std::string RefosgFXSpecularHighlights::_class_description(" This effect applies additive specular highlights at fragment level (instead of OpenGL's vertex-level lighting) by using a cube map and reflective texgen. A texture matrix is computed to rotate the cube map automatically; this makes the specular effect consistent with respect to view direction and light position. The user can choose which light should be used to compute the texture matrix. This effect requires the GL_ARB_texture_env_add extension and one of the cube map extensions (GL_EXT_texture_cube_map, GL_ARB_texture_cube_map or OpenGL v1.3).     ");

std::string RefosgFXSpecularHighlights::_osg_version("1.2");


/**********************************************************/
RefosgFXSpecularHighlights::RefosgFXSpecularHighlights() {
}

/**********************************************************/
void RefosgFXSpecularHighlights::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgFX::SpecularHighlights*>(obj);
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
void RefosgFXSpecularHighlights::addChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(cobj);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
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
void RefosgFXSpecularHighlights::removeChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(0);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
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
osg::Object *RefosgFXSpecularHighlights::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getUpdateCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getCullCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getEventCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getStateSet();
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
unsigned RefosgFXSpecularHighlights::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgFXSpecularHighlights::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgFX::SpecularHighlights::getInitialBound, &osgFX::SpecularHighlights::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgFX::SpecularHighlights::getUserData, &osgFX::SpecularHighlights::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgFX::SpecularHighlights::getNodeMask, &osgFX::SpecularHighlights::setNodeMask);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgFX::SpecularHighlights::getDataVariance, &osgFX::SpecularHighlights::setDataVariance, osg_object_datavariance);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgFX::SpecularHighlights::getCullingActive, &osgFX::SpecularHighlights::setCullingActive);
	}
	if (name == "_enabled") {
		// Getter overloaded, must specify one type
		typedef bool (osgFX::Effect::*getEnabledFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgFX::Effect::*setEnabledFN)(bool) ;
		return new GetterSetterProperty<bool, osgFX::Effect>("_enabled", _object.get(), (getEnabledFN)&osgFX::SpecularHighlights::getEnabled, (setEnabledFN)&osgFX::SpecularHighlights::setEnabled);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgFX::SpecularHighlights::getName, (setNameFN)&osgFX::SpecularHighlights::setName);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgFX::SpecularHighlights::getDescriptions, (setDescriptionsFN)&osgFX::SpecularHighlights::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgFXSpecularHighlights::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgFXSpecularHighlights::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgFXSpecularHighlights::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFXSpecularHighlights::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgFXSpecularHighlights::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgFX::SpecularHighlights, RefosgFXSpecularHighlights> _registerRefosgFXSpecularHighlights;
