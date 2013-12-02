#include <reflection/reflectionregistry.h>
#include <osg/Switch>
#include <stdexcept>

/**
 * Reflector of class osg::Switch
 */
class RefosgSwitch: public ClassReflection {
public:
	RefosgSwitch();
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
	osg::ref_ptr<osg::Switch> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_newChildDefaultValue","_initialBound","_userData","_nodeMask","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSwitch::_names(_propnames, _propnames+8);

static std::string _tablepropnames[] = {"_values"};
ClassReflection::PropertyNames RefosgSwitch::_table_names(_tablepropnames, _tablepropnames+1);

std::string RefosgSwitch::_class_name("osg::Switch");

std::string RefosgSwitch::_class_description(" Switch is a Group node that allows switching between children. Typical uses would be for objects which might need to be rendered differently at different times, for instance a switch could be used to represent the different states of a traffic light.     ");

std::string RefosgSwitch::_osg_version("1.2");


/**********************************************************/
RefosgSwitch::RefosgSwitch() {
}

/**********************************************************/
void RefosgSwitch::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Switch*>(obj);
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
void RefosgSwitch::addChild(osg::Object *child) {
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
void RefosgSwitch::removeChild(osg::Object *child) {
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
osg::Object *RefosgSwitch::getChildObject(unsigned i) {
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
unsigned RefosgSwitch::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSwitch::getProperty(const std::string &name) {
	if (name == "_newChildDefaultValue") {
		return new GetterSetterProperty<bool, osg::Switch>("_newChildDefaultValue", _object.get(), &osg::Switch::getNewChildDefaultValue, &osg::Switch::setNewChildDefaultValue);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::Switch::getInitialBound, &osg::Switch::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Switch::getUserData, &osg::Switch::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::Switch::getNodeMask, &osg::Switch::setNodeMask);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Switch::getName, (setNameFN)&osg::Switch::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::Switch::getCullingActive, &osg::Switch::setCullingActive);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Switch::getDataVariance, &osg::Switch::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::Switch::getDescriptions, (setDescriptionsFN)&osg::Switch::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
class Prop_values_Enabled: public TemplateProperty<bool> {
public:
	Prop_values_Enabled(std::string name, osg::Switch *obj, int row): TemplateProperty<bool>(name), _obj(obj), _row(row) {}
	virtual bool get() { return _obj->getValue(_row); }
	virtual void setImpl(bool &t) { _obj->setValue(_row, t); }
private:
	osg::Switch *_obj;
	unsigned _row;
};
unsigned RefosgSwitch::getNumTablePropertyColumns(const std::string &name) {
	if (name == "_values") { return 1; }
	throw PropertyNotFoundException(name);
}
unsigned RefosgSwitch::getNumTablePropertyRows(const std::string &name) {
	if (name == "_values") { return _object->getNumChildren(); }
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSwitch::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	if (name == "_values") {
		if (col == 0) {
			return new Prop_values_Enabled(name, _object.get(), row);
		}
	}
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSwitch::getTablePropertyColumnTitles(const std::string &name) {
	static std::string _valuesColTitles[] = {"Enabled"};
	if (name == "_values") { return PropertyNames(_valuesColTitles, _valuesColTitles+1); }
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSwitch::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	if (name == "_values") {
		for (unsigned i=0; i < _object->getNumChildren(); i++) {
			titles.push_back(_object->getChild(i)->getName());
		}
	}
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Switch, RefosgSwitch> _registerRefosgSwitch;
