#include <osg/Transform>
#include "selection.h"

using namespace osgedit;

Selection *Selection::instance() {
	static Selection *_instance = new Selection;
    return _instance;
}

Selection::Selection() {
}

void Selection::removeItem(ObjectPath &item) {
	SelectionList::iterator iter = _items.begin();
	while (iter != _items.end() && *iter != item) iter++;
	if (iter != _items.end()) {
        _items.erase(iter);
	}
    signal_changed.emit();
}

void Selection::addItem(ObjectPath& item) {
	_items.push_back(item);
	if (_items.size() == 1) {
		//propagateLocalToWorld();
	}
    signal_changed.emit();
}

/*
void Selection::propagateLocalToWorld() {
	osg::NodePath np;
    ObjectPath &op = _items[0];
    // We must skip last one because it contains the local transform
	for (unsigned i=0; i < op.size()-1; i++) {
		osg::Node *node = dynamic_cast<osg::Node*>(op[i]->getObject());
		if (node != 0) {
            np.push_back(node);
		}
	}
	Control3DManager::instance()->setLocalToWorld(osg::computeLocalToWorld(np));
}
*/

void Selection::clear() {
	_items.clear();
	signal_changed.emit();
}
