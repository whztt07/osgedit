#include "reflectioncache.h"
#include "reflectionregistry.h"

/// Singleton
ReflectionCache *ReflectionCache::instance() {
	static ReflectionCache *_instance = new ReflectionCache();
    return _instance;
}

/// Get the reflection for an osg::Object
ClassReflection *ReflectionCache::reflect(osg::Object *obj) {
	if (_cache.find(obj) == _cache.end()) {
		try {
			ClassReflection *reflected = ReflectionRegistry::instance()->reflect(obj);
            _cache[obj] = reflected;
		} catch (ReflectionRegistry::UnknownClassException &e) {
            return NULL;
		}

	}
    return _cache[obj].get();
}
