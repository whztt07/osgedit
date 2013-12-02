#include <reflection/reflectionregistry.h>
#include <osg/Billboard>
#include <stdexcept>

/**
 * Reflector of class osg::Billboard
 */
class RefosgBillboard: public ClassReflection {
public:
	RefosgBillboard();
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
	osg::ref_ptr<osg::Billboard> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_normal","_nodeMask","_mode","_axis","_cullingActive","_positionList","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgBillboard::_names(_propnames, _propnames+11);

ClassReflection::PropertyNames RefosgBillboard::_table_names;

std::string RefosgBillboard::_class_name("osg::Billboard");

std::string RefosgBillboard::_class_description(" Billboard is a derived form of Geode that orients its osg::Drawable children to face the eye point. Typical uses incllude trees and particle explosions,     ");

std::string RefosgBillboard::_osg_version("1.2");


/**********************************************************/
RefosgBillboard::RefosgBillboard() {
}

/**********************************************************/
void RefosgBillboard::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Billboard*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_billboard_mode: public Enum<osg::Billboard::Mode> {
public:
	Enum_osg_billboard_mode() {
		add("POINT_ROT_EYE", osg::Billboard::POINT_ROT_EYE);
		add("POINT_ROT_WORLD", osg::Billboard::POINT_ROT_WORLD);
		add("AXIAL_ROT", osg::Billboard::AXIAL_ROT);
	}
} osg_billboard_mode;

using namespace osg;

/**********************************************************/
void RefosgBillboard::addChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(cobj);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(cobj);
		return;
	}}
	{Drawable *cobj = dynamic_cast<Drawable *>(child);
	if (cobj != 0) {
		_object->addDrawable(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgBillboard::removeChild(osg::Object *child) {
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setUpdateCallback(0);
		return;
	}}
	{osg::StateSet *cobj = dynamic_cast<osg::StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setEventCallback(0);
		return;
	}}
	{Drawable *cobj = dynamic_cast<Drawable *>(child);
	if (cobj != 0) {
		_object->removeDrawable(cobj);
		return;
	}}
	{NodeCallback *cobj = dynamic_cast<NodeCallback *>(child);
	if (cobj != 0) {
		_object->setCullCallback(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgBillboard::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getUpdateCallback();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getEventCallback();
	} else {
		i -= 1;
	}
	if (i < _object->getNumDrawables()) {
		return _object->getDrawable(i);
	} else {
		i -= _object->getNumDrawables();
	}
	if (i < 1) {
		return _object->getCullCallback();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgBillboard::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumDrawables();
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgBillboard::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::Billboard::getInitialBound, &osg::Billboard::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Billboard::getUserData, &osg::Billboard::setUserData);
	}
	if (name == "_normal") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Billboard::*getNormalFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Billboard::*setNormalFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Billboard>("_normal", _object.get(), (getNormalFN)&osg::Billboard::getNormal, (setNormalFN)&osg::Billboard::setNormal);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::Billboard::getNodeMask, &osg::Billboard::setNodeMask);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::Billboard::Mode (osg::Billboard::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Billboard::*setModeFN)(osg::Billboard::Mode) ;
		return new GetterSetterEnumProperty<osg::Billboard::Mode, osg::Billboard>("_mode", _object.get(), (getModeFN)&osg::Billboard::getMode, (setModeFN)&osg::Billboard::setMode, osg_billboard_mode);
	}
	if (name == "_axis") {
		// Getter overloaded, must specify one type
		typedef const Vec3 & (osg::Billboard::*getAxisFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Billboard::*setAxisFN)(const Vec3 &) ;
		return new GetterSetterProperty<Vec3, osg::Billboard>("_axis", _object.get(), (getAxisFN)&osg::Billboard::getAxis, (setAxisFN)&osg::Billboard::setAxis);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Billboard::getName, (setNameFN)&osg::Billboard::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::Billboard::getCullingActive, &osg::Billboard::setCullingActive);
	}
	if (name == "_positionList") {
		// Getter overloaded, must specify one type
		typedef osg::Billboard::PositionList & (osg::Billboard::*getPositionListFN)() ;
		return new GetterSetterProperty<osg::Billboard::PositionList, osg::Billboard>("_positionList", _object.get(), (getPositionListFN)&osg::Billboard::getPositionList, &osg::Billboard::setPositionList);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Billboard::getDataVariance, &osg::Billboard::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::Billboard::getDescriptions, (setDescriptionsFN)&osg::Billboard::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgBillboard::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgBillboard::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgBillboard::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBillboard::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgBillboard::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Billboard, RefosgBillboard> _registerRefosgBillboard;
