#include <gtkmm/stock.h>
#include <gtkmm/messagedialog.h>
#include "historyviewer.h"
#include <command/command.h>

HistoryViewer::HistoryViewer():
	_closeButton(Gtk::Stock::CLOSE),
    _undoButton(Gtk::Stock::UNDO),
    _redoButton(Gtk::Stock::REDO)
{
	set_title("Undo/Redo history");
	set_border_width(5);
	set_default_size(400, 200);

	add(_vBox);

	//Add the TreeView, inside a ScrolledWindow, with the button underneath:
	_scrolledWindow.add(_treeView);

	//Only show the scrollbars when they are necessary:
	_scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	_vBox.pack_start(_scrolledWindow);
	_vBox.pack_start(_buttonBox, Gtk::PACK_SHRINK);

	_buttonBox.pack_start(_undoButton, Gtk::PACK_SHRINK);
	_buttonBox.pack_start(_redoButton, Gtk::PACK_SHRINK);
	_buttonBox.pack_start(_closeButton, Gtk::PACK_SHRINK);
	_buttonBox.set_border_width(5);
	_buttonBox.set_layout(Gtk::BUTTONBOX_END);
	_closeButton.signal_clicked().connect( sigc::mem_fun(*this, &HistoryViewer::on_button_close) );
	_undoButton.signal_clicked().connect( sigc::mem_fun(*this, &HistoryViewer::on_button_undo) );
	_redoButton.signal_clicked().connect( sigc::mem_fun(*this, &HistoryViewer::on_button_redo) );

	_treeModel = Gtk::ListStore::create(_columns);
	_treeView.set_model(_treeModel);

	fillHistory();
	//CommandHistory::instance()->addCallback( CommandHistory::Callback(this, &HistoryViewer::on_history_changed) );
	CommandHistory::instance()->signal_do.connect(sigc::mem_fun(this, &HistoryViewer::on_history_changed));
	CommandHistory::instance()->signal_undo.connect(sigc::mem_fun(this, &HistoryViewer::on_history_changed));
	CommandHistory::instance()->signal_redo.connect(sigc::mem_fun(this, &HistoryViewer::on_history_changed));
	CommandHistory::instance()->signal_clear.connect(sigc::mem_fun(this, &HistoryViewer::on_history_changed));

	_treeView.append_column("Command", _columns.col_name);
	_treeView.append_column("Executed", _columns.col_executed);

	show_all();
}

HistoryViewer::~HistoryViewer() {
	//CommandHistory::instance()->delCallback( CommandHistory::Callback(this, &HistoryViewer::on_history_changed) );
}

void HistoryViewer::on_button_close() {
    delete this;
}

void HistoryViewer::on_button_undo() {
	try {
        CommandHistory::instance()->undo();
	} catch (CommandHistory::NothingToUndoException &e) {
		Gtk::MessageDialog dialog(*this, "There is nothing to undo.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
	}
}

void HistoryViewer::on_button_redo() {
	try {
        CommandHistory::instance()->redo();
	} catch (CommandHistory::NothingToRedoException &e) {
		Gtk::MessageDialog dialog(*this, "There is nothing to redo.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
	}
}

void HistoryViewer::on_history_changed() {
    _treeModel->clear();
	fillHistory();
}

void HistoryViewer::fillHistory() {
    CommandHistory *history = CommandHistory::instance();
	const CommandHistory::CommandVector &commands = history->getCommands();

    // We use prepend to inverse the list and show recent commands first
	for (unsigned i=0; i < history->getPosition(); i++) {
		std::string name = commands[i]->getChangeString();
		Gtk::TreeModel::Row row = *(_treeModel->prepend());
		row[_columns.col_name] = name;
		row[_columns.col_executed] = true;
	}
	for (unsigned i=history->getPosition(); i < commands.size(); i++) {
		std::string name = commands[i]->getChangeString();
		Gtk::TreeModel::Row row = *(_treeModel->prepend());
		row[_columns.col_name] = name;
		row[_columns.col_executed] = false;
	}
}
