#ifndef __SOURCE_CODE_CONTROL_H__
#define __SOURCE_CODE_CONTROL_H__

#include <gtkmm/label.h>
#include <gtksourceviewmm/sourceview.h>
#include <gtkmm/button.h>
#include <gtkmm/scrolledwindow.h>
#include <gui/layout/controls/layoutcontrol.h>

typedef TemplateProperty<std::string> StringProperty;

/**
 * Source code control, supports std::string properties only
 */
class SourceCodeControl: public LayoutControl,
	public Visitor< StringProperty > {
public:
	SourceCodeControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(StringProperty *prop);

	void on_activate_text();

    void setLabel(const std::string &label);

	virtual void refresh();

	virtual void parseParameter(const std::string &property,const std::string &value);
private:
	Gtk::Label *_label;
	gtksourceview::SourceView *_textView;
	Gtk::Button *_updateButton;
	Gtk::ScrolledWindow *_scrolledWindow;
	osg::ref_ptr<StringProperty> _target;
};

#endif//__SOURCE_CODE_CONTROL_H__
