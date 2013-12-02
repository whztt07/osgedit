#include "command.h"
#include <reflection/classreflection.h>

/**
 * Delete one object from another's children list
 */
class CommandDelete: public Command {
public:
	CommandDelete(ClassReflection *parent, ClassReflection *child): _parent(parent), _child(child)
	{}
	/**
	 * Undo the changes of this command
     */
	virtual void undo() {
        _parent->addChild(_child.get());
	}

	/**
	 * Get an string representation of the change made by this command
     */
	virtual std::string getChangeString() const {
        return "Remove " + _child->getName() + " from " + _parent->getName();
	}
protected:
	/**
	 * Actual execute implementation
     */
	virtual void executeImpl() {
        _parent->removeChild(_child.get());
	}
private:
	osg::ref_ptr<ClassReflection> _parent;
	osg::ref_ptr<ClassReflection> _child;
};

