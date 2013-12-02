#ifndef __TEXTURE_UNIT_H__
#define __TEXTURE_UNIT_H__

#include <osg/StateSet>
#include <sstream>

namespace osg {

class TextureUnit: public osg::Object {
public:
	TextureUnit(): _unit(0){}

	TextureUnit(unsigned unit, osg::StateSet *set): _unit(unit), _stateSet(set) {
		std::ostringstream str;
        str << "texUnit<" << unit << ">";
		setName(str.str());
	}

	TextureUnit(const TextureUnit &rhs, const CopyOp&) { }

	META_Object(osg, TextureUnit);

	inline unsigned getUnit() const { return _unit; }

	inline osg::StateSet *getStateSet() { return _stateSet.get(); }
private:
	unsigned _unit;
	osg::ref_ptr<osg::StateSet> _stateSet;
};

}//namespace osg

#endif//__TEXTURE_UNIT_H__
