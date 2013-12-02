#ifndef __GRAPHICS_WINDOW_GTKMM_H__
#define __GRAPHICS_WINDOW_GTKMM_H__

#include <osgViewer/GraphicsWindow>
#include <gtk/gtkgl.h>

/**
 * GTK Graphics window for OSG
 */
class GraphicsWindowGTK : public osgViewer::GraphicsWindow
{
public:

	GraphicsWindowGTK(GtkWidget *target);

	virtual void checkEvents() {}

	/** Set the window's position and size.*/
	virtual void setWindowRectangle(int /*x*/, int /*y*/, int /*width*/, int /*height*/) { osg::notify(osg::NOTICE)<<"GraphicsWindow::setWindowRectangle(..) not implemented."<<std::endl; }

	/** Get the window's position and size.*/
	virtual void getWindowRectangle(int& x, int& y, int& width, int& height) { if (_traits.valid()) { x = _traits->x; y = _traits->y; width = _traits->width; height = _traits->height; }  }

	/** Set Window decoration.*/
	virtual void setWindowDecoration(bool /*flag*/) {  osg::notify(osg::NOTICE)<<"GraphicsWindow::setWindowDecoration(..) not implemented."<<std::endl; }

	/** Set Window decoration.*/
	virtual bool getWindowDecoration() const { return _traits.valid() ? _traits->windowDecoration : false; }

	/** Get focus.*/
	virtual void grabFocus() { osg::notify(osg::NOTICE)<<"GraphicsWindow::grabFocus(..) not implemented."<<std::endl; }

	/** Get focus on if the pointer is in this window.*/
	virtual void grabFocusIfPointerInWindow() { osg::notify(osg::NOTICE)<<"GraphicsWindow::grabFocusIfPointerInWindow(..) not implemented."<<std::endl; }

	/** Switch on/off the cursor.*/
	virtual void useCursor(bool /*cursorOn*/) { osg::notify(osg::NOTICE)<<"GraphicsWindow::useCursor(..) not implemented."<<std::endl; }

public:

	/** Return whether a valid and usable GraphicsContext has been created.*/
	virtual bool valid() const { return _valid; }

	/** Realise the GraphicsContext implementation,
	 * Pure virtual - must be implemented by concrate implementations of GraphicsContext. */
	virtual bool realizeImplementation();

	/** Return true if the graphics context has been realised, and is ready to use, implementation.
	 * Pure virtual - must be implemented by concrate implementations of GraphicsContext. */
	virtual bool isRealizedImplementation() const;

	/** Close the graphics context implementation.
	 * Pure virtual - must be implemented by concrate implementations of GraphicsContext. */
	virtual void closeImplementation()  { osg::notify(osg::NOTICE)<<"GraphicsWindow::closeImplementation() not implemented."<<std::endl; }

	/** Make this graphics context current implementation.
	 * Pure virtual - must be implemented by concrate implementations of GraphicsContext. */
	virtual bool makeCurrentImplementation();

	/** Make this graphics context current with specified read context implementation.
	 * Pure virtual - must be implemented by concrate implementations of GraphicsContext. */
	virtual bool makeContextCurrentImplementation(GraphicsContext* /*readContext*/)  { osg::notify(osg::NOTICE)<<"GraphicsWindow::makeContextCurrentImplementation(..) not implemented."<<std::endl; return false;}

	/** Release the graphics context.*/
	virtual bool releaseContextImplementation();

	/** Pure virtual, Bind the graphics context to associated texture implementation.
	 * Pure virtual - must be implemented by concrate implementations of GraphicsContext. */
	virtual void bindPBufferToTextureImplementation(GLenum /*buffer*/)  { osg::notify(osg::NOTICE)<<"GraphicsWindow::bindPBufferToTextureImplementation(..) not implemented."<<std::endl; }

	/** Swap the front and back buffers implementation.
	 * Pure virtual - must be implemented by Concrate implementations of GraphicsContext. */
	virtual void swapBuffersImplementation();

public:
	/*** GTK signals ***/
    void on_realize();

	void on_configure(int x, int y, int w, int h);
public:

	// Override from GUIActionAdapter
	virtual void requestRedraw() {}

	// Override from GUIActionAdapter
	virtual void requestContinuousUpdate(bool /*needed*/=true) {}

	// Override from GUIActionAdapter
	virtual void requestWarpPointer(float /*x*/,float /*y*/) {}

private:
	GdkGLConfig *_glconfig; ///< GdkGL configuration
    GtkWidget *_target; ///< Target widget to do the OpenGL inside
    bool _realized; ///< true if the widget has been realized
    bool _valid;
};

struct GTKWindowingSystemInterface : public osg::GraphicsContext::WindowingSystemInterface
{
    
	GTKWindowingSystemInterface(GtkWidget *target): _target(target) {}
    ~GTKWindowingSystemInterface() {}
    
    /** @return count of attached screens */
    unsigned int getNumScreens(const osg::GraphicsContext::ScreenIdentifier& si)  {
        return 1;
    }

    /** returns the resolution of a specific display */
    void getScreenResolution(const osg::GraphicsContext::ScreenIdentifier& si, unsigned int& width, unsigned int& height) {
        gint w, h;
		gtk_widget_get_size_request(_target, &w, &h);
		width = w;
        height = h;
    }
    
    /** return the top left coord of a specific screen in global screen space */
	void getScreenTopLeft(const osg::GraphicsContext::ScreenIdentifier& si, int& x, int& y) {
		x=0; y=0;
	}

	osg::GraphicsContext* createGraphicsContext(osg::GraphicsContext::Traits* traits) {
        if (traits->pbuffer) return 0;
		else return new GraphicsWindowGTK(_target);
    }
private:
	GtkWidget *_target;
};

#endif//__GRAPHICS_WINDOW_GTKMM_H__
