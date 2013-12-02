#include "classreflection.h"
#include "reflectioncache.h"
#include "hierarchymanager.h"

ClassReflection::ClassReflection() {
}

ClassReflection *ClassReflection::getChild(unsigned i) {
	osg::Object *child = getChildObject(i);
    if (child != 0)
		return ReflectionCache::instance()->reflect(child);
	else
		return 0;
}

void ClassReflection::addChild(ClassReflection *child) {
	this->addChild(child->getObject());
	HierarchyManager::instance()->notifyAddChild(this, child);
}

/// Removes a child object from the best group
void ClassReflection::removeChild(ClassReflection *child) {
    this->removeChild(child->getObject());
	HierarchyManager::instance()->notifyDelChild(this, child);
}

