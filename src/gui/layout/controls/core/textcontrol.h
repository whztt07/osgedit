#ifndef __TEXT_CONTROL_H__
#define __TEXT_CONTROL_H__

#include <gtkmm/label.h>
#include <gtkmm/entry.h>
#include <gui/layout/controls/layoutcontrol.h>
#include <osgText/String>

typedef TemplateProperty<std::string> StringProperty;
typedef TemplateProperty<osgText::String> osgStringProperty;

/**
 * Text Control, supports std::string properties only
 */
class TextControl: public LayoutControl,
	public Visitor< StringProperty >,
	public Visitor< osgStringProperty > {
public:
	TextControl();

    virtual unsigned render(Gtk::Table *table, unsigned row);

	void apply(StringProperty *prop);
	void apply(osgStringProperty *prop);

	void on_activate_text();

    void setLabel(const std::string &label);

	virtual void refresh();
private:
	Gtk::Label *_label;
	Gtk::Entry *_entry;
	osg::ref_ptr<StringProperty> _target;
	osg::ref_ptr<osgStringProperty> _targetOSG;
};

#endif//__TEXT_CONTROL_H__
