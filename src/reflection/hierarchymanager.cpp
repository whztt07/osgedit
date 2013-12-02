#include "hierarchymanager.h"

#include <iostream>

HierarchyManager::HierarchyManager() {
}

HierarchyManager* HierarchyManager::instance() {
	static HierarchyManager *_instance = new HierarchyManager;
    return _instance;
}

void HierarchyManager::notifyAddChild(ClassReflection *parent, ClassReflection *child) {
    signal_add_child.emit(parent, child);
}


void HierarchyManager::notifyDelChild(ClassReflection *parent, ClassReflection *child) {
	signal_del_child.emit(parent, child);
}

