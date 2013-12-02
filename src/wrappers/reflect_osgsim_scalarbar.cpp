#include <reflection/reflectionregistry.h>
#include <osgSim/ScalarBar>
#include <stdexcept>

/**
 * Reflector of class osgSim::ScalarBar
 */
class RefosgSimScalarBar: public ClassReflection {
public:
	RefosgSimScalarBar();
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
	osg::ref_ptr<osgSim::ScalarBar> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_numColors","_initialBound","_userData","_nodeMask","_width","_aspectRatio","_textProperties","_cullingActive","_numLabels","_orientation","_position","_title","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSimScalarBar::_names(_propnames, _propnames+15);

ClassReflection::PropertyNames RefosgSimScalarBar::_table_names;

std::string RefosgSimScalarBar::_class_name("osgSim::ScalarBar");

std::string RefosgSimScalarBar::_class_description(" A ScalarBar is an osg::Geode to render a colored bar representing a range of scalars. The scalar/color ranges are specified by an instance of ScalarsToColors. There are a number of configurable properties on the ScalarBar, such as the orientation, the number of labels to be displayed across the range, the number of distinct colors to use when rendering the bar, text details etc.In summary, the main configurables on the ScalarBar are: The range of scalars represented by the bar, and the colors corresponding to this range - these are specified by the ScalarsToColors object.The number of colors used when rendering the bar geometry - this may be thought of as the bar 'density'.The number of text labels to be used when displaying the bar. The other configurables should be self-explanatory.     ");

std::string RefosgSimScalarBar::_osg_version("1.2");


/**********************************************************/
RefosgSimScalarBar::RefosgSimScalarBar() {
}

/**********************************************************/
void RefosgSimScalarBar::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgSim::ScalarBar*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osgsim_scalarbar_orientation: public Enum<osgSim::ScalarBar::Orientation> {
public:
	Enum_osgsim_scalarbar_orientation() {
		add("HORIZONTAL", osgSim::ScalarBar::HORIZONTAL);
		add("VERTICAL", osgSim::ScalarBar::VERTICAL);
	}
} osgsim_scalarbar_orientation;

using namespace osgSim;
using namespace osg;

/**********************************************************/
void RefosgSimScalarBar::addChild(osg::Object *child) {
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
void RefosgSimScalarBar::removeChild(osg::Object *child) {
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
osg::Object *RefosgSimScalarBar::getChildObject(unsigned i) {
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
unsigned RefosgSimScalarBar::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumDrawables();
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSimScalarBar::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgSim::ScalarBar::getDataVariance, &osgSim::ScalarBar::setDataVariance, osg_object_datavariance);
	}
	if (name == "_numColors") {
		return new GetterSetterProperty<int, osgSim::ScalarBar>("_numColors", _object.get(), &osgSim::ScalarBar::getNumColors, &osgSim::ScalarBar::setNumColors);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osgSim::ScalarBar::getInitialBound, &osgSim::ScalarBar::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgSim::ScalarBar::getUserData, &osgSim::ScalarBar::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osgSim::ScalarBar::getNodeMask, &osgSim::ScalarBar::setNodeMask);
	}
	if (name == "_width") {
		// Getter overloaded, must specify one type
		typedef float (osgSim::ScalarBar::*getWidthFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osgSim::ScalarBar::*setWidthFN)(float) ;
		return new GetterSetterProperty<float, osgSim::ScalarBar>("_width", _object.get(), (getWidthFN)&osgSim::ScalarBar::getWidth, (setWidthFN)&osgSim::ScalarBar::setWidth);
	}
	if (name == "_aspectRatio") {
		return new GetterSetterProperty<float, osgSim::ScalarBar>("_aspectRatio", _object.get(), &osgSim::ScalarBar::getAspectRatio, &osgSim::ScalarBar::setAspectRatio);
	}
	if (name == "_textProperties") {
		return new GetterSetterProperty<osgSim::ScalarBar::TextProperties, osgSim::ScalarBar>("_textProperties", _object.get(), &osgSim::ScalarBar::getTextProperties, &osgSim::ScalarBar::setTextProperties);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgSim::ScalarBar::getName, (setNameFN)&osgSim::ScalarBar::setName);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osgSim::ScalarBar::getCullingActive, &osgSim::ScalarBar::setCullingActive);
	}
	if (name == "_numLabels") {
		return new GetterSetterProperty<int, osgSim::ScalarBar>("_numLabels", _object.get(), &osgSim::ScalarBar::getNumLabels, &osgSim::ScalarBar::setNumLabels);
	}
	if (name == "_orientation") {
		// Getter overloaded, must specify one type
		typedef ScalarBar::Orientation (osgSim::ScalarBar::*getOrientationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::ScalarBar::*setOrientationFN)(ScalarBar::Orientation) ;
		return new GetterSetterEnumProperty<osgSim::ScalarBar::Orientation, osgSim::ScalarBar>("_orientation", _object.get(), (getOrientationFN)&osgSim::ScalarBar::getOrientation, (setOrientationFN)&osgSim::ScalarBar::setOrientation, osgsim_scalarbar_orientation);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgSim::ScalarBar::*getPositionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::ScalarBar::*setPositionFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgSim::ScalarBar>("_position", _object.get(), (getPositionFN)&osgSim::ScalarBar::getPosition, (setPositionFN)&osgSim::ScalarBar::setPosition);
	}
	if (name == "_title") {
		// Getter overloaded, must specify one type
		typedef std::string (osgSim::ScalarBar::*getTitleFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgSim::ScalarBar::*setTitleFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osgSim::ScalarBar>("_title", _object.get(), (getTitleFN)&osgSim::ScalarBar::getTitle, (setTitleFN)&osgSim::ScalarBar::setTitle);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osgSim::ScalarBar::getDescriptions, (setDescriptionsFN)&osgSim::ScalarBar::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimScalarBar::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgSimScalarBar::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSimScalarBar::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimScalarBar::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSimScalarBar::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgSim::ScalarBar, RefosgSimScalarBar> _registerRefosgSimScalarBar;
