#ifndef __COMMAND_HISTORY_H__
#define __COMMAND_HISTORY_H__

#include <exception>
#include <set>
#include <vector>
#include <osg/ref_ptr>
#include <sigc++/sigc++.h>
#include <osg/Timer>
#include "export.h"

class Command;

class CMD_EXPORT CommandHistory {
public:
	typedef std::vector< osg::ref_ptr<Command> > CommandVector;

	class NothingToUndoException: public std::exception {};
	class NothingToRedoException: public std::exception {};
	/**
	 * Adds an executed command to the history
     */
    void pushCommand(Command *c);

	/**
	 * Undoes the last executed command
     */
	void undo();

	/**
	 * Redoes the last executed command
     */
    void redo();

	/**
	 * Clears the history
     */
	void clear();

	/**
	 * Singleton design pattern
     */
	static CommandHistory *instance();

	/**
	 * Get the command vector
     */
	inline const CommandVector &getCommands() const { return _commands; }

	/**
	 * Get the position in the command vector
     */
	inline unsigned getPosition() const { return _position; }

	/**
	 * Changes muted state. If muted, won't send signal events
     */
	inline void setMuted(bool muted=true) { _muted = muted; }

	/**
	 * If the history is disabled, commands are not recorded
     */
	inline void setEnabled(bool enabled) { _enabled = enabled; }

	/**
	 * It checks whether some command is executed.
     * Usefull for testing if the scene has been modified
     */
	inline bool hasExecutions() const {
        return _position != 0;
	}

    /// Called when some command is executed
	sigc::signal<void> signal_do;

    /// Called when some command is un-executed
	sigc::signal<void> signal_undo;

    /// Called when some command is re-executed
	sigc::signal<void> signal_redo;

    /// Called when the command stack is deleted
	sigc::signal<void> signal_clear;

    /// Called on do, undo, and redo cases. Only to avoid connecting to the three signals
	sigc::signal<void> signal_command;
private:
	CommandHistory(): _position(0), _muted(false), _enabled(true), _last_command_ts(osg::Timer::instance()->tick()) {}

    //void notify();

	CommandVector _commands; ///< Latest executed commands

	unsigned _position; ///< Position in history

    bool _muted; ///< True to send events, false not to

	bool _enabled; ///< True to record commands, false not to

	osg::Timer_t _last_command_ts; ///< Timestamp of the last command
};

#endif//__COMMAND_HISTORY_H__
