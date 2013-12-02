#include "GraphicsWindowGTK.h"
#include <iostream>

#include <stdio.h>
#include <unistd.h>
#include <gtk/gtk.h>

void fwd_realize(GtkWidget *widget, GraphicsWindowGTK *window) {
    window->on_realize();
}
gint fwd_configure(GtkWidget *widget, GdkEventConfigure *event, GraphicsWindowGTK *window) {
	window->on_configure(event->x, event->y, event->width, event->height);
    return true;
}

GraphicsWindowGTK::GraphicsWindowGTK(GtkWidget *target):
_target(target), _realized(false), _valid(true)
{
	gtk_gl_init (0, 0);

    gdk_threads_enter();
	if (GTK_WIDGET_REALIZED(target)) {
		osg::notify(osg::FATAL)<< "GraphicsWindowGTK: Give me the widget before realizing it!" << std::endl;
        _valid = false;
	}

	/* Try double-buffered visual */
	_glconfig = gdk_gl_config_new_by_mode ((GdkGLConfigMode)
										   (GDK_GL_MODE_RGB   |
											GDK_GL_MODE_DEPTH  |
											GDK_GL_MODE_DOUBLE));
	if (_glconfig == NULL)
    {
        osg::notify(osg::NOTICE)<<"Can't set up a double-buffered visual"<<std::endl;
        osg::notify(osg::NOTICE)<<"Trying single-buffered visual"<<std::endl;

		/* Try single-buffered visual */
		_glconfig = gdk_gl_config_new_by_mode ((GdkGLConfigMode)
											  (GDK_GL_MODE_RGB   |
											   GDK_GL_MODE_DEPTH));
		if (_glconfig == NULL)
		{
			osg::notify(osg::FATAL)<<"No appropriate OpenGL-capable visual found"<<std::endl;
            _valid = false;
		}
	}
	/* Set OpenGL-capability to the widget. */
	gtk_widget_set_gl_capability (_target, _glconfig, NULL, TRUE, GDK_GL_RGBA_TYPE);

	g_signal_connect_after (G_OBJECT (_target), "realize", G_CALLBACK (fwd_realize), this);

	gdk_threads_leave();

	setState( new osg::State );
	getState()->setGraphicsContext(this);
	getState()->setContextID( osg::GraphicsContext::createNewContextID() );
}

void GraphicsWindowGTK::on_realize() {
	std::cerr << "Now it is realized!" << std::endl;
	_realized = true;
}

bool GraphicsWindowGTK::makeCurrentImplementation()  {
	std::cout << "MakeCurrent!" << std::endl;
    gdk_threads_enter();
	GdkGLContext *glcontext = gtk_widget_get_gl_context (_target);
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (_target);
    bool ok = gdk_gl_drawable_gl_begin(gldrawable, glcontext);
    //bool ok = gdk_gl_drawable_make_current(gldrawable, glcontext);
	gdk_threads_leave();
	return ok;
	//return gdk_gl_drawable_make_current(gldrawable, glcontext);
}

bool GraphicsWindowGTK::releaseContextImplementation() {
	std::cout << "Release!" << std::endl;
    gdk_threads_enter();
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (_target);
    gdk_gl_drawable_gl_end (gldrawable);
    gdk_threads_leave();
    return true;
}

void GraphicsWindowGTK::swapBuffersImplementation() {
	std::cout << "SwapBuffers!" << std::endl;
    gdk_threads_enter();
	GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (_target);
    gdk_gl_drawable_swap_buffers(gldrawable);
    gdk_threads_leave();
}

bool GraphicsWindowGTK::realizeImplementation() {
	std::cout << "Realize!" << std::endl;
    gdk_threads_enter();
    gtk_widget_show(_target);
    gdk_threads_leave();
	return _realized;
}

bool GraphicsWindowGTK::isRealizedImplementation() const {
	std::cout << "isRealized: " << _realized << std::endl;
	return _realized;
}

void GraphicsWindowGTK::on_configure(int x, int y, int w, int h) {
	resized(x, y, w, h);
}
