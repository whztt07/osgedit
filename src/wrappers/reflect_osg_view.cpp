#include <reflection/reflectionregistry.h>
#include <osg/View>
#include <stdexcept>

/**
 * Reflector of class osg::View
 */
class RefosgView: public ClassReflection {
public:
	RefosgView();
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
	osg::ref_ptr<osg::View> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_lightingMode","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgView::_names(_propnames, _propnames+4);

ClassReflection::PropertyNames RefosgView::_table_names;

std::string RefosgView::_class_name("osg::View");

std::string RefosgView::_class_description(" View - maintains a master camera view and a list of slave cameras that are relative to this master camera. Note, if no slave cameras are attached to the view then the master camera does both the control and implementation of the rendering of the scene, but if slave cameras are present then the master controls the view onto the scene, while the slaves implement the rendering of the scene.     ");

std::string RefosgView::_osg_version("1.2");


/**********************************************************/
RefosgView::RefosgView() {
}

/**********************************************************/
void RefosgView::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::View*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_view_lightingmode: public Enum<osg::View::LightingMode> {
public:
	Enum_osg_view_lightingmode() {
		add("NO_LIGHT", osg::View::NO_LIGHT);
		add("HEADLIGHT", osg::View::HEADLIGHT);
		add("SKY_LIGHT", osg::View::SKY_LIGHT);
	}
} osg_view_lightingmode;

using namespace osg;

/**********************************************************/
void RefosgView::addChild(osg::Object *child) {
	{osg::Light *cobj = dynamic_cast<osg::Light *>(child);
	if (cobj != 0) {
		_object->setLight(cobj);
		return;
	}}
	{osg::Camera *cobj = dynamic_cast<osg::Camera *>(child);
	if (cobj != 0) {
		_object->addSlave(cobj);
		return;
	}}
	{osg::Camera *cobj = dynamic_cast<osg::Camera *>(child);
	if (cobj != 0) {
		_object->setCamera(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgView::removeChild(osg::Object *child) {
	{osg::Light *cobj = dynamic_cast<osg::Light *>(child);
	if (cobj != 0) {
		_object->setLight(0);
		return;
	}}
	{osg::Camera *cobj = dynamic_cast<osg::Camera *>(child);
	if (cobj != 0) {
		_object->setCamera(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgView::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getLight();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getCamera();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgView::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt+= _object->getNumSlaves();
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgView::getProperty(const std::string &name) {
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::View::getName, (setNameFN)&osg::View::setName);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::View::getDataVariance, &osg::View::setDataVariance, osg_object_datavariance);
	}
	if (name == "_lightingMode") {
		return new GetterSetterEnumProperty<osg::View::LightingMode, osg::View>("_lightingMode", _object.get(), &osg::View::getLightingMode, &osg::View::setLightingMode, osg_view_lightingmode);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::View::getUserData, &osg::View::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgView::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgView::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgView::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgView::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgView::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::View, RefosgView> _registerRefosgView;
