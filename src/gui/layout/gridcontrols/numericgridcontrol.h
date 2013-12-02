#ifndef __NUMERIC_GRID_CONTROL_H__
#define __NUMERIC_GRID_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include "layoutgridcontrol.h"

typedef TemplateProperty<int> IntProperty;
typedef TemplateProperty<float> FloatProperty;
typedef TemplateProperty<double> DoubleProperty;

/**
 * Numeric Grid Control, supports std::string properties only
 */
class GRID_CONTROLS_EXPORT NumericGridControl: public LayoutGridControl {
public:
	typedef enum { INT, FLOAT, DOUBLE } Mode;

	NumericGridControl(Mode mode);

	virtual Gtk::TreeModelColumnBase *getColumn() {
		switch (_mode) {
		case INT: return &_intColumn;
		case FLOAT: return &_floatColumn;
		case DOUBLE: return &_doubleColumn;
		}
        return &_intColumn;
	}

	virtual Gtk::CellRenderer *getCellRenderer() { return &_renderer; }

	void on_edited(const Glib::ustring& path_string, const Glib::ustring& cell_text);

	virtual void updateRenderer(Gtk::CellRenderer *, const Gtk::TreeModel::iterator&);
protected:
	virtual void fillViewModel();

private:
    Mode _mode;
	Gtk::CellRendererText _renderer;
    Gtk::TreeModelColumn<int> _intColumn;
    Gtk::TreeModelColumn<float> _floatColumn;
    Gtk::TreeModelColumn<double> _doubleColumn;
};

#endif//__NUMERIC_GRID_CONTROL_H__
