#ifndef __TEXT_GRID_CONTROL_H__
#define __TEXT_GRID_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include "layoutgridcontrol.h"

typedef TemplateProperty<std::string> StringProperty;

/**
 * Text Grid Control, supports std::string properties only
 */
class GRID_CONTROLS_EXPORT TextGridControl: public LayoutGridControl {
public:
	TextGridControl();

	virtual Gtk::TreeModelColumnBase *getColumn() { return &_column; }

	virtual Gtk::CellRenderer *getCellRenderer() { return &_renderer; }

	void on_edited(const Glib::ustring& path_string, const Glib::ustring& cell_text);

	virtual void updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator&);
protected:
	virtual void fillViewModel();

private:
	Gtk::CellRendererText _renderer;
    Gtk::TreeModelColumn<Glib::ustring> _column;
};

#endif//__TEXT_GRID_CONTROL_H__
