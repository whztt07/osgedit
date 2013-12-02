#ifndef __EXTENSION_H__
#define __EXTENSION_H__

#include <osg/Referenced>
#include "plugin.h"
#include <gui/layout/layout.h>
#include "export.h"

/**
 * OSGEdit extensions are packages that contain plugins, data needed by
 * these plugins (osg files, images, ...) and new layouts for editing
 * osg objects.
 */
class PLUGIN_EXPORT Extension: public osg::Referenced {
public:
	/// Extension::Vector
	typedef std::vector< osg::ref_ptr<Extension> > Vector;

	/**
	 * Create a new extension
     * @param directory The place in disk where the extension is located
     */
	Extension(const std::string &directory);

	/**
	 * Get the vector of plugins provided by this extension
     */
	const Plugin::Vector &getProvidedPlugins() const { return _plugins; }

	/**
	 * Get the vector of layouts provided by this extension
     */
	const Layout::Vector &getProvidedLayouts() const { return _layouts; }
private:
	std::string _directory;  ///< Directory where the extension is located on disk
	Plugin::Vector _plugins; ///< Plugins provided by the extension package
	Layout::Vector _layouts; ///< Layouts provided by the extension package
};

#endif//__EXTENSION_H__
