#ifndef __LAYOUT_GRID_H__
#define __LAYOUT_GRID_H__

#include <osg/Referenced>
#include <map>
#include <string>
#include "gridcontrols/layoutgridcontrol.h"
#include <gtkmm/table.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treeview.h>
#include <gtkmm/label.h>
#include "export.h"

/**
 * A grid of data for a layout
 */
class LAY_EXPORT LayoutGrid: public osg::Referenced {
public:
	LayoutGrid();

	/// Adds a control for editing a table property column
	void addColumnControl(int column, const std::string &title, LayoutGridControl *control);

    /// Connect the layout grid to an actual class reflection
	void connect(ClassReflection *cref, const std::string &tableProperty);

	/**
	 * Puts the grid in the layout table.
	 * @param table The GTK table
	 * @param row The next free row in the table
     * @return The next row after the render (may have used several rows)
     */
	unsigned render(Gtk::Table *table, unsigned row);

	/**
	 * Re-read current reflection data
     */
	void refresh();

	/**
	 * Get the number of controls in use
     */
	unsigned getNumControls() { return _controls.size(); }
private:
	typedef std::map<int, osg::ref_ptr<LayoutGridControl> > ControlMap;
    ControlMap _controls; ///< Controls for each column
	Gtk::TreeModel::ColumnRecord _columns; ///< Gtk columns definition
	Glib::RefPtr<Gtk::ListStore> _store; ///< Gtk model
	Gtk::TreeView *_tree; ///< Gtk view
	Gtk::Label *_label; ///< Tree label
};

#endif//__LAYOUT_GRID_H__
