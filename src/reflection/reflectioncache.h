#ifndef __REFLECTION_CACHE_H__
#define __REFLECTION_CACHE_H__

#include <reflection/classreflection.h>
#include <map>

/**
 * Cache to avoid generating multiple reflection instances for the same
 * osg::Object.
 */
class REFLECTION_EXPORT ReflectionCache {
public:
    /// Singleton
	static ReflectionCache *instance();

	/// Get the reflection for an osg::Object
	ClassReflection *reflect(osg::Object *obj);
private:
	ReflectionCache(){}
	typedef std::map < osg::Object*, osg::ref_ptr<ClassReflection> > ObjectMap;
    ObjectMap _cache;
};

#endif//__REFLECTION_CACHE_H__
