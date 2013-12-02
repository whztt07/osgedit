#ifndef __OSG_VIEWPORT_H__
#define __OSG_VIEWPORT_H__

#include <osg/Node>
#include <osg/Timer>

#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/image.h>
#include <osgUtil/SceneView>
#include <tools/tool.h>

#include <gtk/gtkgl.h>
#include <set>

#include <gui/controls3d/control3d.h>
#include <gui/cameras/cameramanager.h>
#include "export.h"

class GUI_EXPORT OSGViewport: public Gtk::VBox {
public:

	bool idle_handler();

    /// Adds a 3D widget to the viewport
	void addControl3D(Control3D *widget);

    /// Removes a 3D widget from the viewport
	void removeControl3D(Control3D *widget);

    /// Removes all the 3D widgets from the viewport
	void clearControls3D();

    /// Sets the active camera manager for the viewport
	void setCameraManager(std::string name);

    /// Sets the scene root node to be shown in the viewport
	void setSceneRoot(osg::Node *node);

    /// Singleton
	static OSGViewport *instance();

    /// Return the active camera manager
	CameraManager* getActiveCameraManager() { return _cameraManager.get(); }

    /// Change the active tool
	void setActiveTool(Tool *tool) { _activeTool = tool; }

    /// Adds a new camera manager to the viewport
	void addCameraManager(CameraManager *cam);

protected:
	OSGViewport();

    void on_history_changed();

	/*** GTK Events ***/
    bool on_button_press(GdkEventButton*);
    bool on_button_release(GdkEventButton*);
    bool on_mouse_motion(GdkEventMotion*);
	bool on_key_press(GdkEventKey*);
	bool on_key_release(GdkEventKey*);
    void on_camera_changed();
	bool on_focus_in (GdkEventFocus* event);
	bool on_focus_out (GdkEventFocus* event);
	void on_play_toggled();
private:
    void prepareGLWidget();

	Gtk::DrawingArea _area; ///< Gtk widget to draw GL into

	Gtk::HBox _topBox; ///< Top horizontal box for components
	Gtk::ComboBoxText _cameraSelector; ///< Selects active camera
	Gtk::Label _fps; ///< Label for showing the framerate
	Gtk::Label _focused; ///< Label for showing the focused state
	
	Gtk::Image _play_icon; ///< Play/pause button image
	Gtk::HBox _play_hbox; ///< Play/pause button hbox
	Gtk::Label _play_label; ///< Play/pause button label
	Gtk::ToggleButton _play; ///< Play/pause for animation, particles, etc.

	double _time_offset; ///< Time offset because of time "pauses"
	double _last_pause_time; ///< Time when the animation was paused for the last time

	osg::ref_ptr<osgUtil::SceneView> _sceneView; ///< OSG scene visor
	osg::ref_ptr<osg::FrameStamp> _frameStamp; ///< Current frame stamp

	osg::Timer_t _t0; ///< Start of execution timestamp
	osg::Timer_t _lastFpsUpdateTS; ///< Timestamp on last fps update
	unsigned _framesSinceUpdate; ///< Frames since last fps update

	osg::ref_ptr<osg::Group> _root; ///< Root node for OSG (actual edited scene, widgets, grid, etc)
	osg::ref_ptr<osg::Group> _widgetNodes; ///< Visible widgets
	typedef std::set< osg::ref_ptr<Control3D> > Control3DMap;
    Control3DMap _widgets; ///< Available 3D widgets
    osg::ref_ptr<Control3D> _activeWidget; ///< Active 3D widget

	osg::ref_ptr< Tool > _activeTool; ///< Active tool

	typedef std::map<std::string, osg::ref_ptr<CameraManager> > CameraMap;

	CameraMap _cameras; ///< Available cameras

	osg::ref_ptr<CameraManager> _cameraManager; ///< Active camera manager
	typedef enum {
		PAN,
		ZOOM,
		ORBIT,
        WAITCLICK,
        NONE
	} CameraManagerState;
	CameraManagerState _managerState; ///< Current state of camera management
	osg::Vec2 _pressCoords; ///< Where did the user pressed?
};

#endif// __OSG_VIEWPORT_H__
