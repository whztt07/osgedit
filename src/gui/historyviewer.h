#ifndef __HISTORY_VIEWER_H__
#define __HISTORY_VIEWER_H__

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/treeview.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>
#include <gtkmm/liststore.h>
#include <command/commandhistory.h>
#include "export.h"

class GUI_EXPORT HistoryViewer: public Gtk::Window {
public:
	HistoryViewer();

    virtual ~HistoryViewer();

	void on_button_close();
	void on_button_undo();
	void on_button_redo();

    void on_history_changed();
private:
	void fillHistory();

	//Tree model columns:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns() {
			add(col_name);
			add(col_executed);
		}

		Gtk::TreeModelColumn<Glib::ustring> col_name;
		Gtk::TreeModelColumn<bool> col_executed;
	};

	ModelColumns _columns;

	//Child widgets:
	Gtk::VBox _vBox;
	Gtk::ScrolledWindow _scrolledWindow;
	Gtk::TreeView _treeView;
	Glib::RefPtr<Gtk::ListStore> _treeModel;
	Gtk::HButtonBox _buttonBox;
	Gtk::Button _closeButton;
	Gtk::Button _undoButton;
	Gtk::Button _redoButton;
};

#endif//__HISTORY_VIEWER_H__
