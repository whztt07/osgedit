#ifndef __OSGEDIT_PLUGIN_H__
#define __OSGEDIT_PLUGIN_H__

#include <glibmm/module.h>
#include <vector>
#include <string>
#include <osg/Referenced>
#include <osg/ref_ptr>
#include "export.h"

/**
 * OSGEdit plugins add the following items to the application:
 * - New controls for editing osg properties
 * - New actions for the menus
 * - New 3D controls for editing properties directly in the 3D area
 * - New wrappers for osg::Objects that allow editing other nodekits
 */
class PLUGIN_EXPORT Plugin: public osg::Referenced {
public:
	/// Plugin::Vector
	typedef std::vector< osg::ref_ptr<Plugin> > Vector;

	typedef std::vector<std::string> NameList;

	/**
	 * Plugin loading exception
     */
	class LoadException: public std::exception {
	public:
		LoadException(const std::string &err): _err(err) {}
        virtual ~LoadException() throw() {}
		virtual const char *what() const throw() { return _err.c_str(); }
	private:
		std::string _err;
	};

	Plugin(const std::string &libName) throw (std::exception);

	~Plugin() { delete _module; }

	/**
	 * Get the list of actions provided by this plugin
     */
	NameList getProvidedActions() { return _providedActions; }

	/**
	 * Get the list of wrappers provided by this plugin
     */
	NameList getProvidedWrappers() { return _providedWrappers; }

	/**
	 * Get the list of controls provided by this plugin
     */
	NameList getProvidedControls() { return _providedControls; }

	/**
	 * Get the list of 3D controls provided by this plugin
     */
	NameList getProvidedControls3D() { return _providedControls3D; }
protected:
	void on_action_registered(std::string action);

	void on_control_registered(std::string control);

	void on_control3d_registered(std::string control);

private:
	std::string _libName; ///< Plugin library name
	Glib::Module *_module; ///< The library
	NameList _providedActions; ///< Actions registered by this plugin
    NameList _providedWrappers; ///< Wrappers registered by this plugin
    NameList _providedControls; ///< Controls registered by this plugin
    NameList _providedControls3D; ///< 3D Controls registered by this plugin
};

#endif//__OSGEDIT_PLUGIN_H__
