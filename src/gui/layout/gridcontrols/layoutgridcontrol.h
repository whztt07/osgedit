#ifndef __LAYOUT_GRID_CONTROL_H__
#define __LAYOUT_GRID_CONTROL_H__

#include <osg/Referenced>
#include <osg/ref_ptr>
#include <string>
#include <reflection/classreflection.h>
#include <reflection/propertyreflection.h>
#include <osg/Vec4f>
#include <osg/Matrix>
#include <gtkmm/table.h>
#include <common/visitor.h>

#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include "export.h"

/**
 * Layout grid control abstract superclass.
 */
class GRID_CONTROLS_EXPORT LayoutGridControl: public osg::Referenced {
public:
	typedef std::vector< osg::ref_ptr< LayoutGridControl > > Vector;

	/**
	 * Returns a column of the appropiate type
     */
	virtual Gtk::TreeModelColumnBase *getColumn() = 0;

	/**
	 * Returns the appropiate cell renderer
     */
	virtual Gtk::CellRenderer *getCellRenderer() = 0;

	/**
	 * Will be called by GTK each time it needs to render a cell, to feed the
     * renderer with appropiate data.
     */
	virtual void updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator&) = 0;

	/**
	 * Sets the tree model and column index
	 * @param viewModel The model used for GTK
	 * @param model_column The column index in Reflection table
     */
	void configure(Glib::RefPtr<Gtk::ListStore> viewModel,
				   ClassReflection *cref,
				   const std::string &tableProperty,
				   unsigned model_column) {
		_viewModel = viewModel;
		_modelColumn = model_column;
		_cref = cref;
        _tableProperty = tableProperty;
        fillViewModel();
	}

	/**
	 * Re-read current reflection data
     */
	void refresh() { fillViewModel(); }
protected:
	/**
	 * Initializes viewModel with cref data
     */
	virtual void fillViewModel() = 0;

	inline Gtk::TreeModel::iterator path2iter(const std::string &path_string) {
		Gtk::TreePath path(path_string);
		Gtk::TreeModel::iterator iter = _viewModel->get_iter(path);
        return iter;
	}

	Glib::RefPtr<Gtk::ListStore> _viewModel; ///< Tree model
	osg::ref_ptr<ClassReflection> _cref; ///< Class reflection
	std::string _tableProperty; ///< The table property being edited
	unsigned _modelColumn; ///< Column index for the TableAttribute (NOT THE VIEW MODEL!!)
};

#endif//__LAYOUT_GRID_CONTROL_H__
