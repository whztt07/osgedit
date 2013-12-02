#include "command.h"
#include <reflection/classreflection.h>
#include <osg/Group>

/**
 * Add one object to another (as child)
 */
class CommandAdd: public Command {
public:
	class DuplicatedChildException: public std::exception {};
	class NodeLoopException: public std::exception {};

    CommandAdd(ClassReflection *parent, ClassReflection *child): _parent(parent), _child(child)
	{}
	/**
	 * Undo the changes of this command
     */
	virtual void undo() {
		_parent->removeChild(_child.get());
	}

	/**
	 * Get an string representation of the change made by this command
     */
	virtual std::string getChangeString() const {
        return "Add " + _child->getName() + " to " + _parent->getName();
	}
protected:
	/**
	 * Simple node loop checker
     */
	bool checkNodeLoop(osg::Group *parent, osg::Node *child) {
        if (parent == child) return true;
		for (unsigned i=0; i < parent->getNumParents(); i++) {
			if (checkNodeLoop(parent->getParent(i), child)) {
                return true;
			}
		}
        return false;
	}

	/**
	 * Actual execute implementation. Checks for duplicates
     */
	virtual void executeImpl() {
        /// Checking for duplicates
		for (unsigned i=0; i < _parent->getNumChildren(); i++) {
            osg::ref_ptr<ClassReflection> curChild = _parent->getChild(i);
			if (curChild.valid() && _child->getObject() == curChild->getObject()) {
                throw DuplicatedChildException();
			}
		}
        /// Checking for node loops
		osg::Group *parentNode = dynamic_cast<osg::Group*>(_parent->getObject());
		osg::Node *childNode = dynamic_cast<osg::Node*>(_child->getObject());
		if (parentNode != 0 && childNode != 0 && checkNodeLoop(parentNode, childNode)) {
            throw NodeLoopException();
		}
		_parent->addChild(_child.get());
	}
private:
	osg::ref_ptr<ClassReflection> _parent;
	osg::ref_ptr<ClassReflection> _child;
};

