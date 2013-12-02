#include "reflectionregistry.h"
#include <common/log.h>

ReflectionRegistry *ReflectionRegistry::instance() {
	static ReflectionRegistry *_instance = new ReflectionRegistry();
    return _instance;
}

/// Gets the wrapper for an OSG object
ClassReflection *ReflectionRegistry::reflect(osg::Object *object) throw (UnknownClassException) {
	WrapperRegistry::iterator iter = _registry.find(object->className());
	if (iter != _registry.end()) {
		ClassReflection *cref = iter->second->allocate();
		if (cref != 0) {
			cref->setObject(object);
			return cref;
		} else {
			throw std::bad_alloc();
		}
	} else {
        throw UnknownClassException(object->className());
	}
}

/// Adds a new wrapper to the registry
void ReflectionRegistry::addWrapper(std::string className, WrapperAllocator *allocator) {
    _registry[className] = allocator;
#ifdef DEBUG
	LOG("Registering "+className, Log::INFO);
#endif
}
