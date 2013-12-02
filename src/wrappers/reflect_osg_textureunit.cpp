#include <stdexcept>
#include <reflection/reflectionregistry.h>
#include "textureunit.h"
#include <sstream>

/**
 * FAKE class reflection for the FAKE textureUnit object. Used only to ease
 * editing of statesets.
 */


static std::string getModeName(int mode);

/**
 * Reflector of class TextureUnit
 */
class RefosgTextureUnit: public ClassReflection {
public:
	RefosgTextureUnit();
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
	osg::ref_ptr<osg::TextureUnit> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

ClassReflection::PropertyNames RefosgTextureUnit::_names;

static std::string _tablepropnames[] = {"_textureModes"};
ClassReflection::PropertyNames RefosgTextureUnit::_table_names(_tablepropnames, _tablepropnames+1);


std::string RefosgTextureUnit::_class_name("osg::TextureUnit");

std::string RefosgTextureUnit::_class_description(" Represents an StateSet texture unit. This class doesn't exist in OSG. ");

std::string RefosgTextureUnit::_osg_version("1.2");


/**********************************************************/
RefosgTextureUnit::RefosgTextureUnit() {
}

/**********************************************************/
void RefosgTextureUnit::setObject(osg::Object *obj) {
	_object = dynamic_cast<osg::TextureUnit*>(obj);
}

using namespace osg;

/**********************************************************/
void RefosgTextureUnit::addChild(osg::Object *child) {
	osg::StateAttribute *attr = dynamic_cast<osg::StateAttribute *>(child);
	if (attr == 0) { throw InvalidTypeException(); }
	_object->getStateSet()->setTextureAttributeAndModes(_object->getUnit(), attr, osg::StateAttribute::ON);
}

/**********************************************************/
void RefosgTextureUnit::removeChild(osg::Object *child) {
    osg::StateAttribute *attr = dynamic_cast<osg::StateAttribute *>(child);
	if (attr == 0) { throw InvalidTypeException(); }
	_object->getStateSet()->removeTextureAttribute(_object->getUnit(), attr);
}

/**********************************************************/
osg::Object *RefosgTextureUnit::getChildObject(unsigned i) {
	osg::StateSet *set = _object->getStateSet();
	osg::StateSet::TextureAttributeList& tattrs = set->getTextureAttributeList();
	osg::StateSet::AttributeList& attrs = tattrs[_object->getUnit()];
	osg::StateSet::AttributeList::iterator iter = attrs.begin();
	for (;i>0; i--) iter++;
	return iter->second.first.get();
}

/**********************************************************/
unsigned RefosgTextureUnit::getNumChildren() {
	osg::StateSet *set = _object->getStateSet();
	osg::StateSet::TextureAttributeList& tattrs = set->getTextureAttributeList();
	osg::StateSet::AttributeList& attrs = tattrs[_object->getUnit()];
	return attrs.size();
}

/**********************************************************/
PropertyReflection* RefosgTextureUnit::getProperty(const std::string &name) {
	throw PropertyNotFoundException(name);
}

class Prop_texModes: public TemplateProperty<bool> {
public:
	Prop_texModes(std::string name, osg::StateSet *obj, int unit, int mode, int mask): TemplateProperty<bool>(name), _obj(obj), _unit(unit), _mode(mode), _mask(mask) {}
	virtual bool get() {
		return _obj->getTextureMode(_unit, _mode) & _mask;
	}
	virtual void setImpl(bool &t) {
		if (t) {
			_obj->setTextureMode(_unit, _mode, _obj->getTextureMode(_unit, _mode) | _mask);
		} else {
            _obj->setTextureMode(_unit, _mode, _obj->getTextureMode(_unit, _mode) & ~_mask);
		}
	}
private:
	osg::StateSet *_obj;
    unsigned _unit;
	unsigned _mode;
    int _mask;
};

unsigned RefosgTextureUnit::getNumTablePropertyColumns(const std::string &name) {
	if (name == "_textureModes") { return 4; }
	throw PropertyNotFoundException(name);
}

unsigned RefosgTextureUnit::getNumTablePropertyRows(const std::string &name) {
	osg::StateSet *set = _object->getStateSet();
	osg::StateSet::TextureModeList &tmodes = set->getTextureModeList();
	if (name == "_textureModes") {
		// This texture unit may not have modes, only attributes
		if (tmodes.size() > _object->getUnit()) {
			return tmodes[_object->getUnit()].size();
		} else {
            return 0;
		}
	}
	throw PropertyNotFoundException(name);
}

PropertyReflection *RefosgTextureUnit::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	if (name == "_textureModes") {
		osg::StateSet *set = _object->getStateSet();
		osg::StateSet::TextureModeList &tmodes = set->getTextureModeList();
		osg::StateSet::ModeList::const_iterator iter =tmodes[_object->getUnit()].begin();
        for (unsigned i=0;i<row;i++,iter++){}

		if (col == 0) {
			return new Prop_texModes(name, set, _object->getUnit(), iter->first, osg::StateAttribute::ON);
		} else if (col == 1) {
			return new Prop_texModes(name, set, _object->getUnit(), iter->first, osg::StateAttribute::OVERRIDE);
		} else if (col == 2) {
			return new Prop_texModes(name, set, _object->getUnit(), iter->first, osg::StateAttribute::PROTECTED);
		} else if (col == 3) {
			return new Prop_texModes(name, set, _object->getUnit(), iter->first, osg::StateAttribute::INHERIT);
		}
	}
	throw PropertyNotFoundException(name);
}

const ClassReflection::PropertyNames RefosgTextureUnit::getTablePropertyColumnTitles(const std::string &name) {
	static std::string _modesColTitles[] = {"On", "Override", "Protected", "Inherit"};
	if (name == "_textureModes") { return PropertyNames(_modesColTitles, _modesColTitles+4); }
	throw PropertyNotFoundException(name);
}

const ClassReflection::PropertyNames RefosgTextureUnit::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	if (name == "_textureModes") {
        osg::StateSet *set = _object->getStateSet();
		osg::StateSet::TextureModeList &tmodes = set->getTextureModeList();
		if (tmodes.size() <= _object->getUnit()) return titles;

		const osg::StateSet::ModeList &modes = tmodes[_object->getUnit()];
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
RegisterWrapperClass<osg::TextureUnit, RefosgTextureUnit> _registerRefosgTextureUnit;
