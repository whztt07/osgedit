#ifndef __EXTENSION_REGISTRY_H__
#define __EXTENSION_REGISTRY_H__

#include "extension.h"

/**
 * The extension registry holds all the loaded extensions.
 */
class PLUGIN_EXPORT ExtensionRegistry {
public:
    /// Singleton
	static ExtensionRegistry *instance();

	/**
	 * Load all the extensions
     */
	void load();

    /// Get the list of extensions
	const Extension::Vector &getExtensions() const { return _extensions; }
private:
    /// Load all extensions from a given path
	void loadFrom(const std::string &path);

	ExtensionRegistry(){}
	Extension::Vector _extensions;
};

#endif//__EXTENSION_REGISTRY_H__
