#ifndef __META_COMMAND_H__
#define __META_COMMAND_H__

#include "command.h"
#include <vector>

/**
 * Meta-command is actually a group of commands that do/undo/redo in atomically
 */
class MetaCommand: public Command {
public:
	MetaCommand(std::string shortDesc="multi change"): _shortDesc(shortDesc) {}
	/**
	 * Undo the changes of this command
     */
	virtual void undo() {
        for (unsigned i=0;i<_commands.size();i++) _commands[i]->undo();
	}

	/**
	 * Get an string representation of the change made by this command
     */
	virtual std::string getChangeString() const {
        return _shortDesc;
	}

	/**
	 * Adds a sub-command to this meta-command
     */
	void addSubCommand(Command *cmd) { _commands.push_back(cmd); }
protected:
	/**
	 * Actual execute implementation
     */
	virtual void executeImpl() {
        for (unsigned i=0;i<_commands.size();i++) _commands[i]->execute(false);
	}
private:
    /// Short description of what this meta-command does
	std::string _shortDesc;

	typedef std::vector< osg::ref_ptr<Command> > CommandVector;

    /// List of actual commands to execute/unexecute
	CommandVector _commands;
};

#endif//__META_COMMAND_H__
