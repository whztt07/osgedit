#include "commandhistory.h"
#include "command.h"

#define TIME_THRESHOLD 1.0 // One second to avoid command join

#include <iostream>

void CommandHistory::pushCommand(Command *c) {
	if (!_enabled) return;

	osg::Timer_t ts = osg::Timer::instance()->tick();
	double delta_s = osg::Timer::instance()->delta_s(_last_command_ts, ts);
	// Aren't we on top of the stack? Let's be again ;-)
	if (_position < _commands.size()) {
		while (_position < _commands.size()) {
			_commands.erase(_commands.begin()+_position);
		}
	}
    // Can we join? Or must push?
	if (_commands.empty()
		|| delta_s > TIME_THRESHOLD
		|| _commands.back()->joinWith(c) == false) {
		_commands.push_back(c);
		_position++;
	}
    _last_command_ts = ts;
	if (!_muted) {
		signal_do.emit();
		signal_command.emit();
	}
}

void CommandHistory::undo() {
	if (_position > 0) {
		_position--;
		_commands[_position]->undo();
	} else {
		throw NothingToUndoException();
	}
	if (!_muted) {
		signal_undo.emit();
		signal_command.emit();
	}
}

void CommandHistory::redo() {
	if (_position < _commands.size()) {
		_commands[_position]->execute(false);
		_position++;
	} else {
		throw NothingToRedoException();
	}
	if (!_muted) {
		signal_redo.emit();
        signal_command.emit();
	}
}

void CommandHistory::clear() {
	_commands.clear();
    _position = 0;
    if (!_muted) signal_clear.emit();
}

CommandHistory *CommandHistory::instance() {
	static CommandHistory *_instance = new CommandHistory;
	return _instance;
}
