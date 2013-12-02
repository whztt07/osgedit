#include <reflection/reflectionregistry.h>
#include <osgText/Text>
#include <stdexcept>

/**
 * Reflector of class osgText::Text
 */
class RefosgTextText: public ClassReflection {
public:
	RefosgTextText();
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
	osg::ref_ptr<osgText::Text> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_kerningType","_drawMode","_initialBound","_lineSpacing","_useVertexBufferObjects","_alignment","_position","_drawCallback","_maximumHeight","_backdropImplementation","_characterSizeMode","_userData","_layout","_colorGradientMode","_text","_rotation","_eventCallback","_useDisplayList","_backdropColor","_axisAlignment","_autoRotateToScreen","_backdropType","_updateCallback","_color","_cullCallback","_supportsDisplayList","_maximumWidth","_dataVariance"};
ClassReflection::PropertyNames RefosgTextText::_names(_propnames, _propnames+29);

ClassReflection::PropertyNames RefosgTextText::_table_names;

std::string RefosgTextText::_class_name("osgText::Text");

std::string RefosgTextText::_class_description("     ");

std::string RefosgTextText::_osg_version("1.2");


/**********************************************************/
RefosgTextText::RefosgTextText() {
}

/**********************************************************/
void RefosgTextText::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgText::Text*>(obj);
}
static class Enum_osgtext_text_backdropimplementation: public Enum<osgText::Text::BackdropImplementation> {
public:
	Enum_osgtext_text_backdropimplementation() {
		add("POLYGON_OFFSET", osgText::Text::POLYGON_OFFSET);
		add("NO_DEPTH_BUFFER", osgText::Text::NO_DEPTH_BUFFER);
		add("DEPTH_RANGE", osgText::Text::DEPTH_RANGE);
		add("STENCIL_BUFFER", osgText::Text::STENCIL_BUFFER);
	}
} osgtext_text_backdropimplementation;
static class Enum_osgtext_text_axisalignment: public Enum<osgText::Text::AxisAlignment> {
public:
	Enum_osgtext_text_axisalignment() {
		add("XY_PLANE", osgText::Text::XY_PLANE);
		add("REVERSED_XY_PLANE", osgText::Text::REVERSED_XY_PLANE);
		add("XZ_PLANE", osgText::Text::XZ_PLANE);
		add("REVERSED_XZ_PLANE", osgText::Text::REVERSED_XZ_PLANE);
		add("YZ_PLANE", osgText::Text::YZ_PLANE);
		add("REVERSED_YZ_PLANE", osgText::Text::REVERSED_YZ_PLANE);
		add("SCREEN", osgText::Text::SCREEN);
		add("USER_DEFINED_ROTATION", osgText::Text::USER_DEFINED_ROTATION);
	}
} osgtext_text_axisalignment;
static class Enum_osgtext_text_alignmenttype: public Enum<osgText::Text::AlignmentType> {
public:
	Enum_osgtext_text_alignmenttype() {
		add("LEFT_TOP", osgText::Text::LEFT_TOP);
		add("LEFT_CENTER", osgText::Text::LEFT_CENTER);
		add("LEFT_BOTTOM", osgText::Text::LEFT_BOTTOM);
		add("CENTER_TOP", osgText::Text::CENTER_TOP);
		add("CENTER_CENTER", osgText::Text::CENTER_CENTER);
		add("CENTER_BOTTOM", osgText::Text::CENTER_BOTTOM);
		add("RIGHT_TOP", osgText::Text::RIGHT_TOP);
		add("RIGHT_CENTER", osgText::Text::RIGHT_CENTER);
		add("RIGHT_BOTTOM", osgText::Text::RIGHT_BOTTOM);
		add("LEFT_BASE_LINE", osgText::Text::LEFT_BASE_LINE);
		add("CENTER_BASE_LINE", osgText::Text::CENTER_BASE_LINE);
		add("RIGHT_BASE_LINE", osgText::Text::RIGHT_BASE_LINE);
		add("LEFT_BOTTOM_BASE_LINE", osgText::Text::LEFT_BOTTOM_BASE_LINE);
		add("CENTER_BOTTOM_BASE_LINE", osgText::Text::CENTER_BOTTOM_BASE_LINE);
		add("RIGHT_BOTTOM_BASE_LINE", osgText::Text::RIGHT_BOTTOM_BASE_LINE);
		add("BASE_LINE", osgText::Text::BASE_LINE);
	}
} osgtext_text_alignmenttype;
static class Enum_osgtext_text_layout: public Enum<osgText::Text::Layout> {
public:
	Enum_osgtext_text_layout() {
		add("LEFT_TO_RIGHT", osgText::Text::LEFT_TO_RIGHT);
		add("RIGHT_TO_LEFT", osgText::Text::RIGHT_TO_LEFT);
		add("VERTICAL", osgText::Text::VERTICAL);
	}
} osgtext_text_layout;
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;
static class Enum_osgtext_text_colorgradientmode: public Enum<osgText::Text::ColorGradientMode> {
public:
	Enum_osgtext_text_colorgradientmode() {
		add("SOLID", osgText::Text::SOLID);
		add("PER_CHARACTER", osgText::Text::PER_CHARACTER);
		add("OVERALL", osgText::Text::OVERALL);
	}
} osgtext_text_colorgradientmode;
static class Enum_osgtext_text_backdroptype: public Enum<osgText::Text::BackdropType> {
public:
	Enum_osgtext_text_backdroptype() {
		add("DROP_SHADOW_BOTTOM_RIGHT", osgText::Text::DROP_SHADOW_BOTTOM_RIGHT);
		add("DROP_SHADOW_CENTER_RIGHT", osgText::Text::DROP_SHADOW_CENTER_RIGHT);
		add("DROP_SHADOW_TOP_RIGHT", osgText::Text::DROP_SHADOW_TOP_RIGHT);
		add("DROP_SHADOW_BOTTOM_CENTER", osgText::Text::DROP_SHADOW_BOTTOM_CENTER);
		add("DROP_SHADOW_TOP_CENTER", osgText::Text::DROP_SHADOW_TOP_CENTER);
		add("DROP_SHADOW_BOTTOM_LEFT", osgText::Text::DROP_SHADOW_BOTTOM_LEFT);
		add("DROP_SHADOW_CENTER_LEFT", osgText::Text::DROP_SHADOW_CENTER_LEFT);
		add("DROP_SHADOW_TOP_LEFT", osgText::Text::DROP_SHADOW_TOP_LEFT);
		add("OUTLINE", osgText::Text::OUTLINE);
		add("NONE", osgText::Text::NONE);
	}
} osgtext_text_backdroptype;
static class Enum_osgtext_text_charactersizemode: public Enum<osgText::Text::CharacterSizeMode> {
public:
	Enum_osgtext_text_charactersizemode() {
		add("OBJECT_COORDS", osgText::Text::OBJECT_COORDS);
		add("SCREEN_COORDS", osgText::Text::SCREEN_COORDS);
		add("OBJECT_COORDS_WITH_MAXIMUM_SCREEN_SIZE_CAPPED_BY_FONT_HEIGHT", osgText::Text::OBJECT_COORDS_WITH_MAXIMUM_SCREEN_SIZE_CAPPED_BY_FONT_HEIGHT);
	}
} osgtext_text_charactersizemode;

using namespace osgText;

using namespace osg;

/**********************************************************/
void RefosgTextText::addChild(osg::Object *child) {
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(cobj);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(cobj);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgTextText::removeChild(osg::Object *child) {
	{StateSet *cobj = dynamic_cast<StateSet *>(child);
	if (cobj != 0) {
		_object->setStateSet(0);
		return;
	}}
	{Shape *cobj = dynamic_cast<Shape *>(child);
	if (cobj != 0) {
		_object->setShape(0);
		return;
	}}
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgTextText::getChildObject(unsigned i) {
	if (i < 1) {
		return _object->getStateSet();
	} else {
		i -= 1;
	}
	if (i < 1) {
		return _object->getShape();
	} else {
		i -= 1;
	}
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgTextText::getNumChildren() {
	unsigned cnt = 0;
	cnt++;
	cnt++;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgTextText::getProperty(const std::string &name) {
	if (name == "_kerningType") {
		return new GetterSetterProperty<KerningType, osgText::Text>("_kerningType", _object.get(), &osgText::Text::getKerningType, &osgText::Text::setKerningType);
	}
	if (name == "_drawMode") {
		return new GetterSetterProperty<unsigned int, osgText::Text>("_drawMode", _object.get(), &osgText::Text::getDrawMode, &osgText::Text::setDrawMode);
	}
	if (name == "_initialBound") {
		return new GetterSetterProperty<BoundingBox, osg::Drawable>("_initialBound", _object.get(), &osgText::Text::getInitialBound, &osgText::Text::setInitialBound);
	}
	if (name == "_lineSpacing") {
		return new GetterSetterProperty<float, osgText::Text>("_lineSpacing", _object.get(), &osgText::Text::getLineSpacing, &osgText::Text::setLineSpacing);
	}
	if (name == "_useVertexBufferObjects") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useVertexBufferObjects", _object.get(), &osgText::Text::getUseVertexBufferObjects, &osgText::Text::setUseVertexBufferObjects);
	}
	if (name == "_alignment") {
		// Getter overloaded, must specify one type
		typedef osgText::Text::AlignmentType (osgText::Text::*getAlignmentFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgText::Text::*setAlignmentFN)(osgText::Text::AlignmentType) ;
		return new GetterSetterEnumProperty<osgText::Text::AlignmentType, osgText::Text>("_alignment", _object.get(), (getAlignmentFN)&osgText::Text::getAlignment, (setAlignmentFN)&osgText::Text::setAlignment, osgtext_text_alignmenttype);
	}
	if (name == "_position") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec3 & (osgText::Text::*getPositionFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgText::Text::*setPositionFN)(const osg::Vec3 &) ;
		return new GetterSetterProperty<osg::Vec3, osgText::Text>("_position", _object.get(), (getPositionFN)&osgText::Text::getPosition, (setPositionFN)&osgText::Text::setPosition);
	}
	if (name == "_drawCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::DrawCallback * (osg::Drawable::*getDrawCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::DrawCallback*, osg::Drawable>("_drawCallback", _object.get(), (getDrawCallbackFN)&osgText::Text::getDrawCallback, &osgText::Text::setDrawCallback);
	}
	if (name == "_maximumHeight") {
		return new GetterSetterProperty<float, osgText::Text>("_maximumHeight", _object.get(), &osgText::Text::getMaximumHeight, &osgText::Text::setMaximumHeight);
	}
	if (name == "_backdropImplementation") {
		return new GetterSetterEnumProperty<osgText::Text::BackdropImplementation, osgText::Text>("_backdropImplementation", _object.get(), &osgText::Text::getBackdropImplementation, &osgText::Text::setBackdropImplementation, osgtext_text_backdropimplementation);
	}
	if (name == "_characterSizeMode") {
		return new GetterSetterEnumProperty<osgText::Text::CharacterSizeMode, osgText::Text>("_characterSizeMode", _object.get(), &osgText::Text::getCharacterSizeMode, &osgText::Text::setCharacterSizeMode, osgtext_text_charactersizemode);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgText::Text::getUserData, &osgText::Text::setUserData);
	}
	if (name == "_layout") {
		// Getter overloaded, must specify one type
		typedef osgText::Text::Layout (osgText::Text::*getLayoutFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgText::Text::*setLayoutFN)(osgText::Text::Layout) ;
		return new GetterSetterEnumProperty<osgText::Text::Layout, osgText::Text>("_layout", _object.get(), (getLayoutFN)&osgText::Text::getLayout, (setLayoutFN)&osgText::Text::setLayout, osgtext_text_layout);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgText::Text::getDataVariance, &osgText::Text::setDataVariance, osg_object_datavariance);
	}
	if (name == "_colorGradientMode") {
		return new GetterSetterEnumProperty<osgText::Text::ColorGradientMode, osgText::Text>("_colorGradientMode", _object.get(), &osgText::Text::getColorGradientMode, &osgText::Text::setColorGradientMode, osgtext_text_colorgradientmode);
	}
	if (name == "_text") {
		// Getter overloaded, must specify one type
		typedef String & (osgText::Text::*getTextFN)() ;
		// Setter overloaded, must specify one type
		typedef void (osgText::Text::*setTextFN)(const String &) ;
		return new GetterSetterProperty<String, osgText::Text>("_text", _object.get(), (getTextFN)&osgText::Text::getText, (setTextFN)&osgText::Text::setText);
	}
	if (name == "_rotation") {
		// Getter overloaded, must specify one type
		typedef const osg::Quat & (osgText::Text::*getRotationFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgText::Text::*setRotationFN)(const osg::Quat &) ;
		return new GetterSetterProperty<osg::Quat, osgText::Text>("_rotation", _object.get(), (getRotationFN)&osgText::Text::getRotation, (setRotationFN)&osgText::Text::setRotation);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::EventCallback * (osg::Drawable::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::EventCallback*, osg::Drawable>("_eventCallback", _object.get(), (getEventCallbackFN)&osgText::Text::getEventCallback, &osgText::Text::setEventCallback);
	}
	if (name == "_useDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_useDisplayList", _object.get(), &osgText::Text::getUseDisplayList, &osgText::Text::setUseDisplayList);
	}
	if (name == "_backdropColor") {
		return new GetterSetterProperty<osg::Vec4, osgText::Text>("_backdropColor", _object.get(), &osgText::Text::getBackdropColor, &osgText::Text::setBackdropColor);
	}
	if (name == "_axisAlignment") {
		return new GetterSetterEnumProperty<osgText::Text::AxisAlignment, osgText::Text>("_axisAlignment", _object.get(), &osgText::Text::getAxisAlignment, &osgText::Text::setAxisAlignment, osgtext_text_axisalignment);
	}
	if (name == "_autoRotateToScreen") {
		return new GetterSetterProperty<bool, osgText::Text>("_autoRotateToScreen", _object.get(), &osgText::Text::getAutoRotateToScreen, &osgText::Text::setAutoRotateToScreen);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgText::Text::getName, (setNameFN)&osgText::Text::setName);
	}
	if (name == "_backdropType") {
		return new GetterSetterEnumProperty<osgText::Text::BackdropType, osgText::Text>("_backdropType", _object.get(), &osgText::Text::getBackdropType, &osgText::Text::setBackdropType, osgtext_text_backdroptype);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::UpdateCallback * (osg::Drawable::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::UpdateCallback*, osg::Drawable>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osgText::Text::getUpdateCallback, &osgText::Text::setUpdateCallback);
	}
	if (name == "_color") {
		// Getter overloaded, must specify one type
		typedef const osg::Vec4 & (osgText::Text::*getColorFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osgText::Text::*setColorFN)(const osg::Vec4 &) ;
		return new GetterSetterProperty<osg::Vec4, osgText::Text>("_color", _object.get(), (getColorFN)&osgText::Text::getColor, (setColorFN)&osgText::Text::setColor);
	}
	if (name == "_cullCallback") {
		// Getter overloaded, must specify one type
		typedef osg::Drawable::CullCallback * (osg::Drawable::*getCullCallbackFN)() ;
		return new GetterSetterProperty<osg::Drawable::CullCallback*, osg::Drawable>("_cullCallback", _object.get(), (getCullCallbackFN)&osgText::Text::getCullCallback, &osgText::Text::setCullCallback);
	}
	if (name == "_supportsDisplayList") {
		return new GetterSetterProperty<bool, osg::Drawable>("_supportsDisplayList", _object.get(), &osgText::Text::getSupportsDisplayList, &osgText::Text::setSupportsDisplayList);
	}
	if (name == "_maximumWidth") {
		return new GetterSetterProperty<float, osgText::Text>("_maximumWidth", _object.get(), &osgText::Text::getMaximumWidth, &osgText::Text::setMaximumWidth);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgTextText::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgTextText::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgTextText::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTextText::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgTextText::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgText::Text, RefosgTextText> _registerRefosgTextText;
