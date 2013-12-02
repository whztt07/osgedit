#ifndef __LAYOUT_H__
#define __LAYOUT_H__

#include <osg/Referenced>
#include <osg/ref_ptr>
#include <string>
#include <stack>
#include <reflection/classreflection.h>
#include <gtkmm/table.h>
#include <gtkmm/frame.h>
#include <gtkmm/notebook.h>

#include "controls/layoutcontrol.h"
#include "layoutgrid.h"
#include "export.h"

/**
 * The layout is the visual arrangement of widgets to edit a ClassReflection
 *
 * We inherit from trackable to be automatically disconnected from
 * the command history on deletion
 */
class LAY_EXPORT Layout: public osg::Referenced, public sigc::trackable {
public:
	/// Layout::Vector
	typedef std::vector< osg::ref_ptr<Layout> > Vector;

	Layout();

    virtual ~Layout();

	/// Adds a control for editing a property
	void addControl(const std::string &property, LayoutControl *control);

    /// Adds a grid for editing a table property
	void addGrid(const std::string &tableProperty, LayoutGrid *grid);

    /// Connects the layout to an actual class reflection
	void connect(ClassReflection *reflection);

    /// Disconnect from the reflection API
	void disconnect();
	/**
	 * Returns the widget that represents the layout
     */
	inline Gtk::Widget *getWidget() { return _noteBook; }

	/**
	 * Re-read current reflection data
     */
	void refresh();

	/**
	 * Checks if all the grids have their columns setted. They may not have
	 * them if the grid is empty of data...
     * This is used only for caching purposes
     */
	bool hasEmptyGrids() const;

	/**
     * Check if this layout has some control
     */
	bool hasControl(const std::string &property) {
		return _controls.find(property) != _controls.end();
	}

	/**
     * Check if this layout has some grid
     */
	bool hasGrid(const std::string &property) {
		return _grids.find(property) != _grids.end();
	}

	/**
	 * Begins a new group of controls, inside the parent one
     */
	void beginGroup(const std::string &name);

	/**
	 * Ends a group of controls, returning to the parent one
     */
	void endGroup();

	/**
	 * Begins a new tab of controls, you don't need to end it
     */
    void beginTab(const std::string &name);
protected:
	/**
	 * Group of controls
     */
	class Group: public osg::Referenced {
	public:
		Group(const std::string &name="");
        /// Add a normal control to the group
		void addControl(LayoutControl *control);

		/// Add a grid control to the group
		void addGrid(LayoutGrid *grid);

		/// Add a child group to this group
		void addSubGroup(Group *subgroup);

        /// Get the GTK widget representing the group
		inline Gtk::Widget *getWidget() { return _frame; }
	private:
		Gtk::Frame* _frame; ///< The group frame
		Gtk::Table* _table; ///< GTK table for components
		unsigned _nextRow; ///< Next free row in the GTK table
	};

	/**
	 * Gets the active group, or creates it if doesn't exist
     */
	Group *getActiveGroup();

private:
	typedef std::map< std::string, osg::ref_ptr<LayoutControl> > ControlMap;
	typedef std::map< std::string, osg::ref_ptr<LayoutGrid> > GridMap;
	ControlMap _controls; ///< Map of property names to controls
    GridMap _grids; ///< Map of table property names to grids
	sigc::connection _connection; ///< Connection to the command history
	typedef std::stack < osg::ref_ptr<Group> > GroupStack;
    GroupStack _groupStack; ///< Stack of tables (groups, tabs, ...)
	Gtk::Notebook *_noteBook; ///< Tabs
};

#endif//__LAYOUT_H__
