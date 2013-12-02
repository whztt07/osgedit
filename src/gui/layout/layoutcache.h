#ifndef __LAYOUT_CACHE_H__
#define __LAYOUT_CACHE_H__

#include <map>
#include "layout.h"
#include "export.h"

class LAY_EXPORT LayoutCache {
public:
	static LayoutCache *instance();

	osg::ref_ptr<Layout> get(ClassReflection *cref);
private:
	LayoutCache(){}

	/// Maps osg class names to layouts
	typedef std::map< std::string, osg::ref_ptr<Layout> > LayoutMap;
	LayoutMap _cache;
};

#endif//__LAYOUT_CACHE_H__
