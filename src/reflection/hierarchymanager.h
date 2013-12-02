#ifndef __HIERARCHY_MANAGER_H__
#define __HIERARCHY_MANAGER_H__

#include "classreflection.h"
#include <sigc++/sigc++.h>

/**
 * Central point for observers that want to know when an object is added or
 * removed in the scenegraph (like the object tree)
 */
class REFLECTION_EXPORT HierarchyManager {
public:
	static HierarchyManager *instance();

    /// Called every time that an object is added
	sigc::signal<void, ClassReflection*, ClassReflection*> signal_add_child;

    /// Called every time that an object is removed
	sigc::signal<void, ClassReflection*, ClassReflection*> signal_del_child;

    /// Call here to notify that some parent has a new child
	void notifyAddChild(ClassReflection *parent, ClassReflection *child);

    /// Call here to notify that some parent lost a child
    void notifyDelChild(ClassReflection *parent, ClassReflection *child);
private:
    HierarchyManager();
};

#endif
