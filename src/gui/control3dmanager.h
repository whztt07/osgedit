#ifndef __CONTROL3D_MANAGER_H_
#define __CONTROL3D_MANAGER_H_

#include <osg/Matrixd>
#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include <gtkmm/label.h>
#include <gui/controls3d/control3d.h>
#include <reflection/classreflection.h>
#include "export.h"

typedef TemplateProperty<osg::Vec3d> Vec3dProperty;
typedef TemplateProperty<osg::Vec4f> Vec4fProperty;
typedef TemplateProperty<osg::Quat> QuatProperty;
typedef TemplateProperty<osg::Matrixd> MatrixdProperty;

class GUI_EXPORT Control3DManager: public Gtk::Frame,
	public BaseVisitor,
	public Visitor< Vec3dProperty >,
	public Visitor< Vec4fProperty >,
	public Visitor< QuatProperty >,
	public Visitor< MatrixdProperty >
{
public:

	/**
	 * Connects this manager to a reflected class
     */
	void connect(ClassReflection *reflection);

	/**
	 * Applies the manager to a Vec3 property
     */
	void apply(Vec3dProperty *prop);

	/**
	 * Applies the manager to a Vec4 property
     */
	void apply(Vec4fProperty *prop);

	/**
	 * Applies the manager to a Quat property
     */
	void apply(QuatProperty *prop);

	/**
	 * Applies the manager to a Matrixd property
     */
	void apply(MatrixdProperty *prop);

	/**
	 * Singleton design pattern
     */
	static Control3DManager *instance();

protected:
	Control3DManager();

    /// A row of the model has been changed
	void on_row_changed (const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& iter);

	/**
	 * Notify the controls about the new local to world matrix
     */
	void setLocalToWorld(const osg::Matrix &localToWorld);

	/// The scene selection has been changed
	void on_selection_changed();
private:
	void addControl(PropertyReflection *prop, const std::string &controlName, const std::string &label="");

	//Tree model columns:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord {
	public:
		ModelColumns() {
			add(col_name);
			add(col_visible);
			add(col_control);
		}
		Gtk::TreeModelColumn<Glib::ustring> col_name;
		Gtk::TreeModelColumn<bool> col_visible;
		Gtk::TreeModelColumn< osg::ref_ptr<Control3D> > col_control;
	};

	ModelColumns _columns;

	//Child widgets:
	Gtk::ScrolledWindow _scrolledWindow;
	Gtk::TreeView _treeView;
	Glib::RefPtr<Gtk::ListStore> _treeModel;
	Gtk::Label _label;
};

#endif//__CONTROL3D_MANAGER_H_
