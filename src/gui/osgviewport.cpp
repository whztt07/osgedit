#include <gdk/gdkkeysyms.h>
#include <osg/io_utils>
#include <command/commandhistory.h>
#include "osgviewport.h"
#include <sstream>
#include <stdexcept>
#include <common/log.h>
#include <gui/cameras/orthocameramanager.h>
#include <gui/cameras/perspectivecameramanager.h>

#define FPS_UPDATE_TIME 0.5 // seconds

OSGViewport::OSGViewport(): _play_label("play"), _play_icon(Gtk::StockID("gtk-media-play"), Gtk::IconSize(4)), _time_offset(0), _last_pause_time(0)
{
    _managerState = NONE;
    _area.set_size_request(500, 500);
	_topBox.pack_start(_cameraSelector, false, true, 5);
	_topBox.pack_start(_fps, false, true, 5);
	_topBox.pack_start(_focused, false, true, 5);
	_topBox.pack_end(_play, false, true, 5);
	
	_play_hbox.pack_start(_play_icon, Gtk::PACK_SHRINK, 0);
	_play_hbox.pack_start(_play_label, Gtk::PACK_SHRINK, 0);
	_play.set_flags(Gtk::CAN_FOCUS);
	//play_toggle->set_relief(Gtk::RELIEF_NORMAL);
	_play.set_active(true);
	_play.add(_play_hbox);
	
    pack_start(_topBox, false, true);
    pack_start(_area, true, true);
	show_all();
	prepareGLWidget();

	_root = new osg::Group();
	_widgetNodes = new osg::Group();
    _root->addChild(_widgetNodes.get());
	_widgetNodes->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	_widgetNodes->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	_widgetNodes->getOrCreateStateSet()->setBinNumber(20);
	_widgetNodes->getOrCreateStateSet()->setBinName("RenderBin");
	_widgetNodes->getOrCreateStateSet()->setRenderBinMode(osg::StateSet::USE_RENDERBIN_DETAILS);

    _frameStamp=new osg::FrameStamp();
	_sceneView = new osgUtil::SceneView(new osg::DisplaySettings);
	_sceneView->setDefaults();
	_sceneView->setSceneData(_root.get());
    _sceneView->setFrameStamp(_frameStamp.get());

    addCameraManager(new OrthoCameraManager(OrthoCameraManager::FRONT));
    addCameraManager(new OrthoCameraManager(OrthoCameraManager::BACK));
    addCameraManager(new OrthoCameraManager(OrthoCameraManager::LEFT));
    addCameraManager(new OrthoCameraManager(OrthoCameraManager::RIGHT));
    addCameraManager(new OrthoCameraManager(OrthoCameraManager::TOP));
    addCameraManager(new OrthoCameraManager(OrthoCameraManager::BOTTOM));
    addCameraManager(new PerspectiveCameraManager());

	_cameraSelector.signal_changed().connect(sigc::mem_fun(*this, &OSGViewport::on_camera_changed));
    _play.signal_toggled().connect(sigc::mem_fun(*this, &OSGViewport::on_play_toggled));
    setCameraManager("Front");

	Glib::signal_idle().connect(sigc::mem_fun(*this, &OSGViewport::idle_handler));
	_t0 = osg::Timer::instance()->tick();
	_lastFpsUpdateTS = _t0;
    _framesSinceUpdate = 0;

	_area.signal_button_press_event().connect(sigc::mem_fun(*this, &OSGViewport::on_button_press));
	_area.signal_button_release_event().connect(sigc::mem_fun(*this, &OSGViewport::on_button_release));
    _area.signal_motion_notify_event().connect(sigc::mem_fun(*this, &OSGViewport::on_mouse_motion));
    _area.signal_key_press_event().connect(sigc::mem_fun(*this, &OSGViewport::on_key_press));
    _area.signal_key_release_event().connect(sigc::mem_fun(*this, &OSGViewport::on_key_release));
    _area.signal_focus_in_event().connect(sigc::mem_fun(*this, &OSGViewport::on_focus_in));
    _area.signal_focus_out_event().connect(sigc::mem_fun(*this, &OSGViewport::on_focus_out));
	_area.add_events( Gdk::POINTER_MOTION_MASK
					 |Gdk::BUTTON_PRESS_MASK
					 |Gdk::BUTTON_RELEASE_MASK
					 |Gdk::KEY_PRESS_MASK
					 |Gdk::KEY_RELEASE_MASK
					 |Gdk::FOCUS_CHANGE_MASK);
	_area.property_can_focus() = true;
    _area.grab_focus();

	CommandHistory::instance()->signal_command.connect(sigc::mem_fun(this, &OSGViewport::on_history_changed));
}

OSGViewport *OSGViewport::instance() {
	static OSGViewport *_instance = new OSGViewport;
    return _instance;
}

bool OSGViewport::idle_handler() {
    if (!_area.is_realized()) return false;
	GtkWidget *target = GTK_WIDGET(_area.gobj());
	GdkGLContext *glcontext = gtk_widget_get_gl_context (target);
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (target);

	osg::Timer_t t1 = osg::Timer::instance()->tick();
	double time = osg::Timer::instance()->delta_s(_t0, t1);
	_frameStamp->setFrameNumber(_frameStamp->getFrameNumber()+1);
	_frameStamp->setReferenceTime(time);
	if (_play.get_active()) {
		_frameStamp->setSimulationTime(time - _time_offset);
	}
    _cameraManager->setAspectRatio(_area.get_width() / (float) _area.get_height());

	if (gdk_gl_drawable_gl_begin(gldrawable, glcontext)) {
		_sceneView->setViewMatrix(_cameraManager->getViewMatrix());
		_sceneView->setProjectionMatrix(_cameraManager->getProjectionMatrix());
		_sceneView->setViewport(0,0, _area.get_width(), _area.get_height());
        _sceneView->update();
        _sceneView->cull();
        _sceneView->draw();

		gdk_gl_drawable_swap_buffers(gldrawable);
		gdk_gl_drawable_gl_end (gldrawable);
	}
    double timeSinceUpdate = osg::Timer::instance()->delta_s(_lastFpsUpdateTS, t1);
	if (timeSinceUpdate > FPS_UPDATE_TIME) {
		std::ostringstream stream;
        stream.precision(4);
		stream << (_framesSinceUpdate/timeSinceUpdate) << " fps";
		_fps.set_text(stream.str());
		_lastFpsUpdateTS = t1;
		_framesSinceUpdate = 0;
	} else {
        _framesSinceUpdate++;
	}
    return true;
}

void OSGViewport::prepareGLWidget() {
    GtkWidget *target = GTK_WIDGET(_area.gobj());
	if (GTK_WIDGET_REALIZED(target)) {
		LOG("FATAL ERROR: Give me the widget before realizing it!", Log::ERROR);
		exit(1);
	}
	gtk_gl_init (0, 0);
	/* Try double-buffered visual */
	GdkGLConfig *glconfig = gdk_gl_config_new_by_mode ((GdkGLConfigMode)
										   (GDK_GL_MODE_RGB   |
											GDK_GL_MODE_DEPTH  |
											GDK_GL_MODE_DOUBLE));
	if (glconfig == NULL) {
		LOG("Can't set up a double-buffered visual, trying single-buffered", Log::WARNING);
		/* Try single-buffered visual */
		glconfig = gdk_gl_config_new_by_mode ((GdkGLConfigMode)
											  (GDK_GL_MODE_RGB   |
											   GDK_GL_MODE_DEPTH));
		if (glconfig == NULL) {
			LOG("No appropriate OpenGL-capable visual found", Log::ERROR);
            exit(1);
		}
	}
	/* Set OpenGL-capability to the widget. */
	gtk_widget_set_gl_capability (target, glconfig, NULL, TRUE, GDK_GL_RGBA_TYPE);
}

void OSGViewport::addControl3D(Control3D *widget) {
	_widgets.insert(widget);
	_widgetNodes->addChild(widget->getNode());
}

void OSGViewport::removeControl3D(Control3D *widget) {
	_widgetNodes->removeChild(widget->getNode());
	_widgets.erase(widget);
}

void OSGViewport::clearControls3D() {
	Control3DMap::iterator iter = _widgets.begin();
	osg::Vec3 nearPoint, farPoint;
	for (; iter != _widgets.end(); iter++) {
		osg::ref_ptr<Control3D> control = *iter;
        _widgetNodes->removeChild(control->getNode());
	}
	_widgets.clear();
}

bool OSGViewport::on_button_press(GdkEventButton* ev) {
	_area.grab_focus();
	osg::Vec2 scoord(ev->x/_area.get_width(), 1 - ev->y/_area.get_height());
	if (_managerState == WAITCLICK) {
		if (ev->button == 1) {
            _managerState = ORBIT;
		} else if (ev->button == 2) {
            _managerState = PAN;
		} else {
            _managerState = ZOOM;
		}
        _pressCoords = scoord;
	} else {
		Control3DMap::iterator iter = _widgets.begin();
		osg::Vec3 nearPoint, farPoint;
		if (_sceneView->projectWindowXYIntoObject((int)ev->x, _area.get_height()-(int)ev->y, nearPoint, farPoint)) {
			for (; iter != _widgets.end(); iter++) {
				osg::ref_ptr<Control3D> control = *iter;
				double depth = 0;
				if (control->picked(nearPoint, farPoint, depth)) {
					_activeWidget = control;
					osg::Vec3 coord;
					_sceneView->projectWindowIntoObject(osg::Vec3((int)ev->x, _area.get_height()-(int)ev->y, 0.0f), coord);
					_activeWidget->button_press(coord, scoord);
				}
			}
		} else {
			LOG("Can't project coordinates", Log::WARNING);
		}
	}
	if (!_activeWidget.valid() && _activeTool.valid()) {
		osg::Vec3 nearPoint, farPoint;
		if (_sceneView->projectWindowXYIntoObject((int)ev->x, _area.get_height()-(int)ev->y, nearPoint, farPoint)) {
			_activeTool->on_button_press(nearPoint, farPoint, scoord);
		}
	}
	return false;
}

bool OSGViewport::on_button_release(GdkEventButton* ev) {
	if (_managerState != NONE && _managerState != WAITCLICK) {
        _managerState = WAITCLICK;
	} else {
		if (_activeWidget.valid()) {
			osg::Vec2 scoord(ev->x/_area.get_width(), 1 - ev->y/_area.get_height());
			osg::Vec3 coord;
			_sceneView->projectWindowIntoObject(osg::Vec3((int)ev->x, get_height()-(int)ev->y, 0.0f), coord);
			_activeWidget->button_release(coord, scoord);
			_activeWidget = 0;
		}
	}
    return false;
}

bool OSGViewport::on_mouse_motion(GdkEventMotion* ev) {
	osg::Vec2 scoord(ev->x/_area.get_width(), 1 - ev->y/_area.get_height());
	if (_managerState != NONE) {
		osg::Vec2 delta = scoord - _pressCoords;
		if (_managerState == ZOOM) {
			_cameraManager->zoom(delta.y()*5);
		} else if (_managerState == PAN) {
            _cameraManager->pan(-delta*5);
		} else if (_managerState == ORBIT) {
            _cameraManager->orbit(delta);
		}
        _pressCoords = scoord;
	} else {
		if (_activeWidget.valid()) {
			osg::Vec3 coord;
			_sceneView->projectWindowIntoObject(osg::Vec3((int)ev->x, _area.get_height()-(int)ev->y, 0.0f), coord);
			_activeWidget->drag(coord, scoord);
		}
	}
	return false;
}

bool OSGViewport::on_key_press(GdkEventKey* ev) {
	if (ev->keyval == GDK_Control_L) {
        _managerState = WAITCLICK;
	}
    return false;
}


bool OSGViewport::on_key_release(GdkEventKey* ev) {
	if (ev->keyval == GDK_Control_L) {
        _managerState = NONE;
	}
    return false;
}

void OSGViewport::setSceneRoot(osg::Node *node) {
    _root->removeChild(1);
	_root->addChild(node);

	CameraMap::iterator iter = _cameras.begin();
	for (; iter != _cameras.end(); iter++) {
        iter->second->resetToBound(node->getBound());
	}
}

void OSGViewport::on_history_changed() {
	Control3DMap::iterator iter = _widgets.begin();
	for (; iter != _widgets.end(); iter++) {
		osg::ref_ptr<Control3D> control = *iter;
        control->refresh();
	}
}

void OSGViewport::setCameraManager(std::string name) {
	_cameraManager = _cameras[name];
    _cameraSelector.set_active_text(name);
}

void OSGViewport::on_camera_changed() {
    _cameraManager = _cameras[_cameraSelector.get_active_text()];
}

void OSGViewport::addCameraManager(CameraManager *cam) {
	_cameras[cam->getName()] = cam;
	_cameraSelector.append_text(cam->getName());
}

bool OSGViewport::on_focus_in (GdkEventFocus* event) {
	_focused.set_text("[FOCUSED]");
	return false;
}
bool OSGViewport::on_focus_out (GdkEventFocus* event) {
	_focused.set_text("");
	return false;
}

void OSGViewport::on_play_toggled()
{
	osg::Timer_t t1 = osg::Timer::instance()->tick();
	double time = osg::Timer::instance()->delta_s(_t0, t1);
	if (_play.get_active()) {
		_time_offset += time - _last_pause_time;
	} else {
		_last_pause_time = time;
	}
}

