#ifndef __SELECTION_H__
#define __SELECTION_H__

#include <osg/Referenced>
#include <osg/Node>
#include <osg/ref_ptr>
#include <sigc++/sigc++.h>

#include <reflection/classreflection.h>
#include "export.h"

namespace osgedit {

class COMMON_EXPORT Selection: public osg::Referenced {
public:
	/**
	 * Objects can have several parents, so we have to identify a selection
     * by the complete path, and not only the object reference.
     */
	typedef std::vector< osg::ref_ptr<ClassReflection> > ObjectPath;

    /// Gets the number of items selected
	inline unsigned getNumItems() const { return _items.size(); }

    /// Gets one selected item
	inline ObjectPath& getItem(int i) { return _items[i]; }

    /// Clears the selection list
	void clear();

    /// Adds one item to the selection
	void addItem(ObjectPath& item);

    /// Removes one item from the selection
	void removeItem(ObjectPath &item);

    /// Called when the selection is changed
	sigc::signal<void> signal_changed;

    /// Singleton
	static Selection *instance();
protected:
    /// Propagates the local to world matrix to interested classes
	//void propagateLocalToWorld();

	Selection();
private:
	typedef std::vector< ObjectPath > SelectionList;
    SelectionList _items; ///< The selected items
};

}//namespace osgedit

#endif//__SELECTION_H__
