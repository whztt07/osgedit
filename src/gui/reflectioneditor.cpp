#include <gui/layout/layoutcache.h>
#include "reflectioneditor.h"

ReflectionEditor::ReflectionEditor(): _hAdj(0,0,0), _vAdj(0,0,0), _viewPort(_hAdj, _vAdj) {
	set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
	add(_viewPort);
    _viewPort.set_border_width(4);
	_viewPort.set_shadow_type(Gtk::SHADOW_NONE);
    show_all();
}

ReflectionEditor *ReflectionEditor::instance() {
    static ReflectionEditor *_instance = new ReflectionEditor;
    return _instance;
}

void ReflectionEditor::edit(ClassReflection *cref) {
	if (_currentLayout.valid()) {
		_viewPort.remove();
        _currentLayout->disconnect();
	}
	_currentLayout = LayoutCache::instance()->get(cref);
	_viewPort.add(*_currentLayout->getWidget());
	show_all();
}
