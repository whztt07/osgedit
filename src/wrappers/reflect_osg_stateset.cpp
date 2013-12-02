#include <reflection/reflectionregistry.h>
#include <osg/StateSet>
#include "textureunit.h"
#include <sstream>

static std::string getModeName(int mode);

/**
 * Reflector of class osg::StateSet
 */
class RefosgStateSet: public ClassReflection {
public:
	RefosgStateSet();
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
	osg::ref_ptr<osg::StateSet> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_binName","_renderingHint","_uniformList","_updateCallback","_binMode","_binNum","_eventCallback","_dataVariance"};
ClassReflection::PropertyNames RefosgStateSet::_names(_propnames, _propnames+10);

static std::string _tablepropnames[] = {"_modes"};
ClassReflection::PropertyNames RefosgStateSet::_table_names(_tablepropnames, _tablepropnames+1);


std::string RefosgStateSet::_class_name("osg::StateSet");

std::string RefosgStateSet::_class_description(" Stores a set of modes and attributes which respresent a set of OpenGL state. Notice that a StateSet contains just a subset of the whole OpenGL state. In OSG, each Drawable and each Node has a reference to a StateSet. These StateSets can be shared between different Drawables and Nodes (that is, several Drawables and Nodes can reference the same StateSet). Indeed, this practice is recommended whenever possible, as this minimizes expensive state changes in the graphics pipeline.     ");

std::string RefosgStateSet::_osg_version("1.2");


/**********************************************************/
RefosgStateSet::RefosgStateSet() {
}

/**********************************************************/
void RefosgStateSet::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::StateSet*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
	}
} osg_object_datavariance;
static class Enum_osg_stateset_renderbinmode: public Enum<osg::StateSet::RenderBinMode> {
public:
	Enum_osg_stateset_renderbinmode() {
		add("INHERIT_RENDERBIN_DETAILS", osg::StateSet::INHERIT_RENDERBIN_DETAILS);
		add("USE_RENDERBIN_DETAILS", osg::StateSet::USE_RENDERBIN_DETAILS);
		add("OVERRIDE_RENDERBIN_DETAILS", osg::StateSet::OVERRIDE_RENDERBIN_DETAILS);
	}
} osg_stateset_renderbinmode;

using namespace osg;

/**********************************************************/
void RefosgStateSet::addChild(osg::Object *child) {
	osg::StateAttribute *attr = dynamic_cast<osg::StateAttribute *>(child);
	if (attr == 0) { throw InvalidTypeException(); }
	_object->setAttributeAndModes(attr, osg::StateAttribute::ON);
}

/**********************************************************/
void RefosgStateSet::removeChild(osg::Object *child) {
	osg::StateAttribute *attr = dynamic_cast<osg::StateAttribute *>(child);
	if (attr != 0) {
		_object->removeAttribute(attr);
        return;
	}
	TextureUnit *tunit = dynamic_cast<osg::TextureUnit*>(child);
	if (tunit != 0) {
		osg::StateSet::TextureAttributeList& tattrs = _object->getTextureAttributeList();
		osg::StateSet::AttributeList& attrs = tattrs[tunit->getUnit()];
		osg::StateSet::AttributeList::iterator iter = attrs.begin();
		for (; iter != attrs.end(); iter++) {
			_object->removeAttribute(iter->second.first.get());
		}
	}
}

/**********************************************************/
osg::Object *RefosgStateSet::getChildObject(unsigned i) {
	osg::StateSet::AttributeList& attrs = _object->getAttributeList();
	if (i < attrs.size()) {
		osg::StateSet::AttributeList::iterator iter = attrs.begin();
        for (;i>0; i--) iter++;
        return iter->second.first.get();
	} else {
		return new osg::TextureUnit(i - attrs.size(), _object.get());
	}
}

/**********************************************************/
unsigned RefosgStateSet::getNumChildren() {
	osg::StateSet::AttributeList& attrs = _object->getAttributeList();
	osg::StateSet::TextureAttributeList& tattrs = _object->getTextureAttributeList();
	osg::StateSet::TextureModeList& tmodes = _object->getTextureModeList();
	if (tattrs.size() > tmodes.size()) {
		return attrs.size() + tattrs.size();
	} else {
		return attrs.size() + tmodes.size();
	}
}

/**********************************************************/
PropertyReflection* RefosgStateSet::getProperty(const std::string &name) {
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osg::StateSet::getUserData, &osg::StateSet::setUserData);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osg::StateSet::getName, (setNameFN)&osg::StateSet::setName);
	}
	if (name == "_binName") {
		return new GetterSetterProperty<std::string, osg::StateSet>("_binName", _object.get(), &osg::StateSet::getBinName, &osg::StateSet::setBinName);
	}
	if (name == "_renderingHint") {
		return new GetterSetterProperty<int, osg::StateSet>("_renderingHint", _object.get(), &osg::StateSet::getRenderingHint, &osg::StateSet::setRenderingHint);
	}
	if (name == "_uniformList") {
		// Getter overloaded, must specify one type
		typedef osg::StateSet::UniformList & (osg::StateSet::*getUniformListFN)() ;
		return new GetterSetterProperty<osg::StateSet::UniformList, osg::StateSet>("_uniformList", _object.get(), (getUniformListFN)&osg::StateSet::getUniformList, &osg::StateSet::setUniformList);
	}
	if (name == "_updateCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateSet::Callback * (osg::StateSet::*getUpdateCallbackFN)() ;
		return new GetterSetterProperty<osg::StateSet::Callback*, osg::StateSet>("_updateCallback", _object.get(), (getUpdateCallbackFN)&osg::StateSet::getUpdateCallback, &osg::StateSet::setUpdateCallback);
	}
	if (name == "_binMode") {
		return new GetterSetterEnumProperty<osg::StateSet::RenderBinMode, osg::StateSet>("_binMode", _object.get(), &osg::StateSet::getRenderBinMode, &osg::StateSet::setRenderBinMode, osg_stateset_renderbinmode);
	}
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osg::StateSet::getDataVariance, &osg::StateSet::setDataVariance, osg_object_datavariance);
	}
	if (name == "_binNum") {
		return new GetterSetterProperty<int, osg::StateSet>("_binNum", _object.get(), &osg::StateSet::getBinNumber, &osg::StateSet::setBinNumber);
	}
	if (name == "_eventCallback") {
		// Getter overloaded, must specify one type
		typedef osg::StateSet::Callback * (osg::StateSet::*getEventCallbackFN)() ;
		return new GetterSetterProperty<osg::StateSet::Callback*, osg::StateSet>("_eventCallback", _object.get(), (getEventCallbackFN)&osg::StateSet::getEventCallback, &osg::StateSet::setEventCallback);
	}
	throw PropertyNotFoundException(name);
}

class Prop_modes: public TemplateProperty<bool> {
public:
	Prop_modes(std::string name, osg::StateSet *obj, int mode, int mask): TemplateProperty<bool>(name), _obj(obj), _mode(mode), _mask(mask) {}
	virtual bool get() {
		return _obj->getMode(_mode) & _mask;
	}
	virtual void setImpl(bool &t) {
		if (t) {
			_obj->setMode(_mode, _obj->getMode(_mode) | _mask);
		} else {
            _obj->setMode(_mode, _obj->getMode(_mode) & ~_mask);
		}
	}
private:
	osg::StateSet *_obj;
	unsigned _mode;
    int _mask;
};
unsigned RefosgStateSet::getNumTablePropertyColumns(const std::string &name) {
	if (name == "_modes") { return 4; }
	throw PropertyNotFoundException(name);
}
unsigned RefosgStateSet::getNumTablePropertyRows(const std::string &name) {
	if (name == "_modes") { return _object->getModeList().size(); }
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgStateSet::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	if (name == "_modes") {
		osg::StateSet::ModeList::const_iterator iter =_object->getModeList().begin();
        for (unsigned i=0;i<row;i++,iter++){}

		if (col == 0) {
			return new Prop_modes(name, _object.get(), iter->first, osg::StateAttribute::ON);
		} else if (col == 1) {
			return new Prop_modes(name, _object.get(), iter->first, osg::StateAttribute::OVERRIDE);
		} else if (col == 2) {
			return new Prop_modes(name, _object.get(), iter->first, osg::StateAttribute::PROTECTED);
		} else if (col == 3) {
			return new Prop_modes(name, _object.get(), iter->first, osg::StateAttribute::INHERIT);
		}
	}
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgStateSet::getTablePropertyColumnTitles(const std::string &name) {
	static std::string _modesColTitles[] = {"On", "Override", "Protected", "Inherit"};
	if (name == "_modes") { return PropertyNames(_modesColTitles, _modesColTitles+4); }
	throw PropertyNotFoundException(name);
}

const ClassReflection::PropertyNames RefosgStateSet::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	if (name == "_modes") {
		const osg::StateSet::ModeList &modes = _object->getModeList();
		osg::StateSet::ModeList::const_iterator iter = modes.begin();
		while (iter != modes.end()) {
			titles.push_back(getModeName(iter->first));
			iter++;
		}
	}
	return titles;
}

static std::string getModeName(int mode) {
	switch (mode) {
	case GL_FOG: return "GL_FOG";
	case GL_LIGHTING: return "GL_LIGHTING";
	case GL_TEXTURE_1D: return "GL_TEXTURE_1D";
	case GL_TEXTURE_2D: return "GL_TEXTURE_2D";
	case GL_LINE_STIPPLE: return "GL_LINE_STIPPLE";
	case GL_POLYGON_STIPPLE: return "GL_POLYGON_STIPPLE";
	case GL_CULL_FACE: return "GL_CULL_FACE";
	case GL_ALPHA_TEST: return "GL_ALPHA_TEST";
	case GL_BLEND: return "GL_BLEND";
	case GL_INDEX_LOGIC_OP: return "GL_INDEX_LOGIC_OP";
	case GL_COLOR_LOGIC_OP: return "GL_COLOR_LOGIC_OP";
	case GL_DITHER: return "GL_DITHER";
	case GL_STENCIL_TEST: return "GL_STENCIL_TEST";
	case GL_DEPTH_TEST: return "GL_DEPTH_TEST";
	case GL_CLIP_PLANE0: return "GL_CLIP_PLANE0";
	case GL_CLIP_PLANE1: return "GL_CLIP_PLANE1";
	case GL_CLIP_PLANE2: return "GL_CLIP_PLANE2";
	case GL_CLIP_PLANE3: return "GL_CLIP_PLANE3";
	case GL_CLIP_PLANE4: return "GL_CLIP_PLANE4";
	case GL_CLIP_PLANE5: return "GL_CLIP_PLANE5";
	case GL_LIGHT0: return "GL_LIGHT0";
	case GL_LIGHT1: return "GL_LIGHT1";
	case GL_LIGHT2: return "GL_LIGHT2";
	case GL_LIGHT3: return "GL_LIGHT3";
	case GL_LIGHT4: return "GL_LIGHT4";
	case GL_LIGHT5: return "GL_LIGHT5";
	case GL_LIGHT6: return "GL_LIGHT6";
	case GL_LIGHT7: return "GL_LIGHT7";
	case GL_TEXTURE_GEN_S: return "GL_TEXTURE_GEN_S";
	case GL_TEXTURE_GEN_T: return "GL_TEXTURE_GEN_T";
	case GL_TEXTURE_GEN_R: return "GL_TEXTURE_GEN_R";
	case GL_TEXTURE_GEN_Q: return "GL_TEXTURE_GEN_Q";
	case GL_MAP1_VERTEX_3: return "GL_MAP1_VERTEX_3";
	case GL_MAP1_VERTEX_4: return "GL_MAP1_VERTEX_4";
	case GL_MAP1_COLOR_4: return "GL_MAP1_COLOR_4";
	case GL_MAP1_INDEX: return "GL_MAP1_INDEX";
	case GL_MAP1_NORMAL: return "GL_MAP1_NORMAL";
	case GL_MAP1_TEXTURE_COORD_1: return "GL_MAP1_TEXTURE_COORD_1";
	case GL_MAP1_TEXTURE_COORD_2: return "GL_MAP1_TEXTURE_COORD_2";
	case GL_MAP1_TEXTURE_COORD_3: return "GL_MAP1_TEXTURE_COORD_3";
	case GL_MAP1_TEXTURE_COORD_4: return "GL_MAP1_TEXTURE_COORD_4";
	case GL_MAP2_VERTEX_3: return "GL_MAP2_VERTEX_3";
	case GL_MAP2_VERTEX_4: return "GL_MAP2_VERTEX_4";
	case GL_MAP2_COLOR_4: return "GL_MAP2_COLOR_4";
	case GL_MAP2_INDEX: return "GL_MAP2_INDEX";
	case GL_MAP2_NORMAL: return "GL_MAP2_NORMAL";
	case GL_MAP2_TEXTURE_COORD_1: return "GL_MAP2_TEXTURE_COORD_1";
	case GL_MAP2_TEXTURE_COORD_2: return "GL_MAP2_TEXTURE_COORD_2";
	case GL_MAP2_TEXTURE_COORD_3: return "GL_MAP2_TEXTURE_COORD_3";
	case GL_MAP2_TEXTURE_COORD_4: return "GL_MAP2_TEXTURE_COORD_4";
	case GL_POINT_SMOOTH: return "GL_POINT_SMOOTH";
	case GL_LINE_SMOOTH: return "GL_LINE_SMOOTH";
	case GL_POLYGON_SMOOTH: return "GL_POLYGON_SMOOTH";
	case GL_SCISSOR_TEST: return "GL_SCISSOR_TEST";
	case GL_COLOR_MATERIAL: return "GL_COLOR_MATERIAL";
	case GL_NORMALIZE: return "GL_NORMALIZE";
	case GL_AUTO_NORMAL: return "GL_AUTO_NORMAL";
	case GL_POLYGON_OFFSET_POINT: return "GL_POLYGON_OFFSET_POINT";
	case GL_POLYGON_OFFSET_LINE: return "GL_POLYGON_OFFSET_LINE";
	case GL_POLYGON_OFFSET_FILL: return "GL_POLYGON_OFFSET_FILL";
	case GL_VERTEX_ARRAY: return "GL_VERTEX_ARRAY";
	case GL_NORMAL_ARRAY: return "GL_NORMAL_ARRAY";
	case GL_COLOR_ARRAY: return "GL_COLOR_ARRAY";
	case GL_INDEX_ARRAY: return "GL_INDEX_ARRAY";
	case GL_TEXTURE_COORD_ARRAY: return "GL_TEXTURE_COORD_ARRAY";
	case GL_EDGE_FLAG_ARRAY: return "GL_EDGE_FLAG_ARRAY";
	}
	std::ostringstream stream;
	stream << "0x" << std::hex << mode << std::endl;
    return stream.str();
}

/** REGISTERING **/
RegisterWrapperClass<osg::StateSet, RefosgStateSet> _registerRefosgStateSet;
