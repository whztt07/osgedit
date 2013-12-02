#include "extensionregistry.h"
#include <common/log.h>

ExtensionRegistry *ExtensionRegistry::instance() {
	static ExtensionRegistry *_instance = new ExtensionRegistry();
    return _instance;
}

void ExtensionRegistry::load() {
    loadFrom(EXT_DIR);
}

/// Load all extensions from a given path
void ExtensionRegistry::loadFrom(const std::string &path) {
	try {
		Glib::Dir dir(path);
		std::string extName;
		while ( (extName=dir.read_name()) != "") {
			std::string extdir = Glib::build_filename(path, extName);
			try {
                _extensions.push_back(new Extension(extdir));
				LOG("Extension " + extName + " loaded", Log::INFO);
			} catch (Plugin::LoadException &e) {
				LOG("Error loading extension " + extdir + ": " + e.what(), Log::ERROR);
			}
		}
	} catch (Glib::FileError &e) {}
}
