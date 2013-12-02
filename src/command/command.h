#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <osg/Referenced>
#include "commandhistory.h"
#include "export.h"

/**
 * Command design pattern. Mixed with a bit of memento to get undo/redo
 */
class CMD_EXPORT Command: public osg::Referenced {
public:
	virtual ~Command() {}

	/**
	 * Do the changes of this command and add this to history
     */
	inline void execute(bool addToHistory=true) {
		executeImpl();
		if (addToHistory) CommandHistory::instance()->pushCommand(this);
	}

	/**
	 * Undo the changes of this command
     */
	virtual void undo() = 0;

	/**
	 * Get an string representation of the change made by this command
     */
	virtual std::string getChangeString() const = 0;

	/**
	 * Command join support. The expected result of this call is this command
	 * doing what it did plus what does the cmd command. Both commands must
	 * be joined to this one.
     * @param cmd The command that has to be joined with this one
     */
	virtual bool joinWith(Command *cmd) { return false; }
protected:

	/**
	 * Actual execute implementation
     */
	virtual void executeImpl() = 0;
};

#endif//__COMMAND_H__
