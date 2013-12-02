#include <reflection/reflectionregistry.h>
#include <osg/Sequence>
#include <stdexcept>

/**
 * Reflector of class osg::Sequence
 */
class RefosgSequence: public ClassReflection {
public:
	RefosgSequence();
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
	osg::ref_ptr<osg::Sequence> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_initialBound","_userData","_nodeMask","_mode","_value","_cullingActive","_descriptions","_dataVariance"};
ClassReflection::PropertyNames RefosgSequence::_names(_propnames, _propnames+9);

static std::string _tablepropnames[] = {"_frameTimes"};
ClassReflection::PropertyNames RefosgSequence::_table_names(_tablepropnames, _tablepropnames+1);

std::string RefosgSequence::_class_name("osg::Sequence");

std::string RefosgSequence::_class_description(" Sequence is a Group node which allows automatic, time based switching between children.     ");

std::string RefosgSequence::_osg_version("1.2");


/**********************************************************/
RefosgSequence::RefosgSequence() {
}

/**********************************************************/
void RefosgSequence::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::Sequence*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osg_sequence_sequencemode: public Enum<osg::Sequence::SequenceMode> {
public:
	Enum_osg_sequence_sequencemode() {
		add("START", osg::Sequence::START);
		add("STOP", osg::Sequence::STOP);
		add("PAUSE", osg::Sequence::PAUSE);
		add("RESUME", osg::Sequence::RESUME);
	}
} osg_sequence_sequencemode;

using namespace osg;

/**********************************************************/
void RefosgSequence::addChild(osg::Object *child) {
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
void RefosgSequence::removeChild(osg::Object *child) {
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
osg::Object *RefosgSequence::getChildObject(unsigned i) {
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
unsigned RefosgSequence::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	cnt++;
	cnt++;
	cnt+= _object->getNumChildren();
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgSequence::getProperty(const std::string &name) {
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingSphere, osg::Node>("_initialBound", _object.get(), &osg::Sequence::getInitialBound, &osg::Sequence::setInitialBound);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::Sequence::getUserData, &osg::Sequence::setUserData);
	}
	if (name == "_nodeMask") {
		return new GetterSetterProperty<osg::Node::NodeMask, osg::Node>("_nodeMask", _object.get(), &osg::Sequence::getNodeMask, &osg::Sequence::setNodeMask);
	}
	if (name == "_mode") {
		// Getter overloaded, must specify one type
		typedef osg::Sequence::SequenceMode (osg::Sequence::*getModeFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Sequence::*setModeFN)(osg::Sequence::SequenceMode) ;
		return new GetterSetterEnumProperty<osg::Sequence::SequenceMode, osg::Sequence>("_mode", _object.get(), (getModeFN)&osg::Sequence::getMode, (setModeFN)&osg::Sequence::setMode, osg_sequence_sequencemode);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::Sequence::getName, (setNameFN)&osg::Sequence::setName);
	}
	if (name == "_value") {
		// Getter overloaded, must specify one type
		typedef int (osg::Sequence::*getValueFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Sequence::*setValueFN)(int) ;
		return new GetterSetterProperty<int, osg::Sequence>("_value", _object.get(), (getValueFN)&osg::Sequence::getValue, (setValueFN)&osg::Sequence::setValue);
	}
	if (name == "_cullingActive") {
		return new GetterSetterProperty<bool, osg::Node>("_cullingActive", _object.get(), &osg::Sequence::getCullingActive, &osg::Sequence::setCullingActive);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::Sequence::getDataVariance, &osg::Sequence::setDataVariance, osg_object_datavariance);
	}
	if (name == "_descriptions") {
		// Getter overloaded, must specify one type
		typedef osg::Node::DescriptionList & (osg::Node::*getDescriptionsFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osg::Node::*setDescriptionsFN)(const osg::Node::DescriptionList &) ;
		return new GetterSetterProperty<osg::Node::DescriptionList, osg::Node>("_descriptions", _object.get(), (getDescriptionsFN)&osg::Sequence::getDescriptions, (setDescriptionsFN)&osg::Sequence::setDescriptions);
	}
	throw PropertyNotFoundException(name);
}
class Prop_frameTimes_Time: public TemplateProperty<float> {
public:
	Prop_frameTimes_Time(std::string name, osg::Sequence *obj, int row): TemplateProperty<float>(name), _obj(obj), _row(row) {}
	virtual float get() { return _obj->getTime(_row); }
	virtual void setImpl(float &t) { _obj->setTime(_row, t); }
private:
	osg::Sequence *_obj;
	unsigned _row;
};
unsigned RefosgSequence::getNumTablePropertyColumns(const std::string &name) {
	if (name == "_frameTimes") { return 1; }
	throw PropertyNotFoundException(name);
}
unsigned RefosgSequence::getNumTablePropertyRows(const std::string &name) {
	if (name == "_frameTimes") { return _object->getNumChildren(); }
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgSequence::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	if (name == "_frameTimes") {
		if (col == 0) {
			return new Prop_frameTimes_Time(name, _object.get(), row);
		}
	}
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSequence::getTablePropertyColumnTitles(const std::string &name) {
	static std::string _frameTimesColTitles[] = {"Time"};
	if (name == "_frameTimes") { return PropertyNames(_frameTimesColTitles, _frameTimesColTitles+1); }
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgSequence::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	if (name == "_frameTimes") {
		for (unsigned i=0; i < _object->getNumChildren(); i++) {
			titles.push_back(_object->getChild(i)->getName());
		}
	}
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osg::Sequence, RefosgSequence> _registerRefosgSequence;
