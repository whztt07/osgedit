#ifndef __OBJECT_TREE_H__
#define __OBJECT_TREE_H__

#include <gtkmm/treeview.h>
#include <gtkmm/treestore.h>
#include <reflection/classreflection.h>
#include "export.h"

class GUI_EXPORT ObjectTree: public Gtk::TreeView {
public:
    ObjectTree();
    virtual ~ObjectTree();

	void setRoot(osg::Object *obj);

	/**
	 * Selects each instance of cref in the tree
	 */
    void select(ClassReflection *cref, bool additive=false);

protected:
	void on_selection_changed();

    void on_signal_edited(const Glib::ustring &, const Glib::ustring&);

	void refresh();

    /// Operator to be called on each row to refresh it
	bool refreshForEach(const Gtk::TreeModel::Path&, const Gtk::TreeModel::iterator&);

    /// Connected to the HierarchyManager
	void on_add_child(ClassReflection *parent, ClassReflection *child);

    /// Connected to the HierarchyManager
    void on_del_child(ClassReflection *parent, ClassReflection *child);

private:
    /// Operator to add the child on each row where the parent is
	bool addForEach(const Gtk::TreeModel::Path&, const Gtk::TreeModel::iterator& iter,ClassReflection *parent, ClassReflection *child);

    /// Operator to select every child that matches a ClassReflection
	bool selectForEach(const Gtk::TreeModel::Path&, const Gtk::TreeModel::iterator& iter, ClassReflection *target);

	bool findAndDelete(Gtk::TreeModel::iterator &iter, Gtk::TreeModel::iterator &piter, ClassReflection *parent, ClassReflection *child);

	void recurseChildren(ClassReflection *cref, Gtk::TreeModel::Row &row);

	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:
		ModelColumns() {
			add(m_col_name);
			add(m_col_reflection);
			add(m_col_pixbuf);
		}
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
		Gtk::TreeModelColumn< osg::ref_ptr<ClassReflection> > m_col_reflection;
		Gtk::TreeModelColumn< Glib::RefPtr<Gdk::Pixbuf >  > m_col_pixbuf;
	};

	class OsgTreeModel: public Gtk::TreeStore {
	public:
		OsgTreeModel();
		static Glib::RefPtr<OsgTreeModel> create();

		ModelColumns _columns;
	protected:
		virtual bool row_draggable_vfunc(const Gtk::TreeModel::Path& path) const;
		virtual bool row_drop_possible_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data) const;
		virtual bool drag_data_received_vfunc(const Gtk::TreeModel::Path& dest, const Gtk::SelectionData& selection_data);
        virtual void on_row_changed (const TreeModel::Path& path, const TreeModel::iterator& iter);
	private:
	};

	Glib::RefPtr<OsgTreeModel> _model;
};

#endif//__OBJECT_TREE_H__
