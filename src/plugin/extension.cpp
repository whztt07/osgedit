#include "extension.h"
#include <common/log.h>
#include <osgDB/FileUtils>

#define EXT_PLUGINS_DIR "plugins"
#define EXT_LAYOUTS_DIR "layouts"
#define EXT_DATA_DIR "data"

Extension::Extension(const std::string &directory) {
	Glib::Dir dir(directory);

	Glib::Dir::iterator iter = dir.begin();
	for (; iter != dir.end(); iter++) {
		std::string dirEntry = *iter;
		if (dirEntry == EXT_PLUGINS_DIR) {
			std::string plugdir = Glib::build_filename(directory, dirEntry);
			try {
				Glib::Dir subdir(plugdir);
				std::string pluginName;
				while ( (pluginName=subdir.read_name()) != "") {
					std::string fileName = Glib::build_filename(plugdir, pluginName);
					try {
						Plugin *plugin = new Plugin(fileName);
						_plugins.push_back(plugin);
						LOG("Plugin " + pluginName + " loaded", Log::INFO);
					} catch (Plugin::LoadException &e) {
						LOG("Error loading plugin " + fileName + ": " + e.what(), Log::ERROR);
					}
				}
			} catch (Glib::FileError &e) {
				LOG("Can not access to the extension plugins directory: "+plugdir, Log::ERROR);
			}

		} else if (dirEntry == EXT_LAYOUTS_DIR) {
			std::string laydir = Glib::build_filename(directory, dirEntry);
			osgDB::getDataFilePathList().push_back(laydir);

		} else if (dirEntry == EXT_DATA_DIR) {
			std::string datadir = Glib::build_filename(directory, dirEntry);
			osgDB::getDataFilePathList().push_back(datadir);
		}
	}
}
