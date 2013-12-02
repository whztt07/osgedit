#ifndef __FILE_CONTROL_H__
#define __FILE_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/filechooserbutton.h>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<std::string> StringProperty;

/**
 * Text Control, supports std::string properties only
 */
class FileControl: public LayoutControl,
	public Visitor< StringProperty > {
public:
	FileControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(StringProperty *prop);

	void on_selection_changed();

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::FileChooserButton *_fileChooser;
	osg::ref_ptr<StringProperty> _target;
};

#endif//__FILE_CONTROL_H__
