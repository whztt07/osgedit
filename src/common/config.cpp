#include <stdexcept>
#include "config.h"
#include <command/commandhistory.h>

#include <fstream>
#include <stdlib.h>

#include <common/log.h>

#define CONFIG_FILE ".osgeditrc"

using namespace osgedit;

Config::Config() {}

Config *Config::instance() {
	static Config *_instance = new Config;
    return _instance;
}

std::string Config::getConfigDir() const {
	char *home = getenv("HOME");
	if (home != NULL) {
		return std::string(home);
	} else {
		char *tmp = getenv("TEMP");
		if (tmp != NULL) {
			return std::string(tmp);
		} else {
			return "";
		}
	}
}

void Config::load() {
	CommandHistory::instance()->setEnabled(false);
	std::string cfgFileName = getConfigDir() + "/" + CONFIG_FILE;

	std::ifstream cfgFile(cfgFileName.c_str(), std::ios::out);
	if (!cfgFile) {
		LOG("Can't open configuration file '" + cfgFileName + "', using defaults", Log::INFO);
	} else {
		std::string propName;
		while (!cfgFile.eof()) {
			propName = "";
			cfgFile >> propName;
			if (propName == "") continue;
			if (_properties.find(propName) != _properties.end()) {
				osg::ref_ptr<PropertySerializer> _serializer = _serializers[propName];
				_serializer->readFrom(cfgFile, _properties[propName].get());
			} else {
				LOG("Unknown property " + propName, Log::WARNING);
			}
	
		}
		cfgFile.close();
	}
	CommandHistory::instance()->setEnabled(true);
}

void Config::save() {
	std::string cfgFileName = getConfigDir() + "/" + CONFIG_FILE;

	std::ofstream cfgFile(cfgFileName.c_str(), std::ios::out);
	PropertyMap::iterator iter = _properties.begin();
	for (;iter != _properties.end(); iter++) {
		cfgFile << iter->first << " ";
		osg::ref_ptr<PropertySerializer> _serializer = _serializers[iter->first];
		_serializer->writeTo(cfgFile, iter->second.get());
		cfgFile << std::endl;
	}
    cfgFile.close();
}

void Config::setObject(osg::Object *obj) {
	throw std::logic_error("Config doesn't allow to set object");
}

unsigned Config::getNumProperties() const {
    return _properties.size();
}

PropertyReflection *Config::getProperty(const std::string &name) {
	PropertyMap::iterator iter = _properties.find(name);
	if (iter != _properties.end()) {
		return iter->second.get();
	} else {
		throw PropertyNotFoundException(name);
	}
}

osg::Object* Config::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

PropertyReflection *Config::getTableProperty(const std::string &name, unsigned row, unsigned col) {
    throw std::out_of_range("child");
}

const std::string &Config::getType() const {
	static std::string type="Config";
    return type;
}
const std::string &Config::getName() {
	static std::string name="configuration";
    return name;
}
const std::string &Config::getOSGVersion() const {
	static std::string osgVersion = "1.0";
    return osgVersion;
}
const std::string &Config::getDescription() const {
	static std::string desc="OSGEdit configuration";
    return desc;
}

