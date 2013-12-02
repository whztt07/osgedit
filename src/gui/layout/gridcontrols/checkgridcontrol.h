#ifndef __CHECK_GRID_CONTROL_H__
#define __CHECK_GRID_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include "layoutgridcontrol.h"

typedef TemplateProperty<bool> BoolProperty;

/**
 * Check Grid Control, supports std::string properties only
 */
class GRID_CONTROLS_EXPORT CheckGridControl: public LayoutGridControl {
public:
	CheckGridControl();

	virtual Gtk::TreeModelColumnBase *getColumn() { return &_column; }

	virtual Gtk::CellRenderer *getCellRenderer() { return &_renderer; }

	void on_toggled(const Glib::ustring& path_string);

	virtual void updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator&);

protected:
    virtual void fillViewModel();

private:
	Gtk::CellRendererToggle _renderer;
    Gtk::TreeModelColumn<bool> _column;
};

#endif//__CHECK_GRID_CONTROL_H__
