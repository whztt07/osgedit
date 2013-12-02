#include "xmllayoutbuilder.h"
#include "layoutcache.h"

LayoutCache *LayoutCache::instance() {
	static LayoutCache *_instance = new LayoutCache;
    return _instance;
}

osg::ref_ptr<Layout> LayoutCache::get(ClassReflection *cref) {
	std::string key = cref->getType();
	LayoutMap::iterator iter = _cache.find(key);
	if (iter == _cache.end()) {
        Layout *layout = 0;
		XmlLayoutBuilder builder;
        builder.apply(cref);
		layout = builder.getLayout();
        // We won't cache if some grid is empty
		if (layout->hasEmptyGrids()) {
            layout->connect(cref);
			return layout;
		}
		_cache[key] = layout;
	}
	osg::ref_ptr<Layout> layout = _cache[key];
	layout->connect(cref);
	return layout;
}
