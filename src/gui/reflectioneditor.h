#ifndef __REFLECTION_EDITOR_H__
#define __REFLECTION_EDITOR_H__

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/viewport.h>
#include <reflection/classreflection.h>
#include <gui/layout/layout.h>
#include "export.h"

class GUI_EXPORT ReflectionEditor: public Gtk::ScrolledWindow {
public:
    static ReflectionEditor *instance();

    void edit(ClassReflection *cref);
private:
	ReflectionEditor();
	osg::ref_ptr<Layout> _currentLayout;
	Gtk::Adjustment _hAdj;
	Gtk::Adjustment _vAdj;
	Gtk::Viewport _viewPort;
};

#endif//__REFLECTION_EDITOR_H__
