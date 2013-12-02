#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <reflection/classreflection.h>
#include <reflection/propertyreflection.h>
#include "serializer.h"
#include "export.h"

namespace osgedit {

/**
 * OSGEdit configuration
 */
class COMMON_EXPORT Config: public ClassReflection {
public:
	class DuplicatedPropertyException: public std::exception {};

    template <typename T>
		void registerProperty(TemplateProperty<T> *prop) throw (DuplicatedPropertyException) {
			if (_properties.find(prop->getName()) == _properties.end()) {
				_properties[prop->getName()] = prop;
				_serializers[prop->getName()] = new TemplatePropertySerializer<T>;
				_propNames.push_back(prop->getName());
			} else {
				throw DuplicatedPropertyException();
			}
		}

	void registerProperty(EnumProperty *prop) throw (DuplicatedPropertyException) {
		if (_properties.find(prop->getName()) == _properties.end()) {
			_properties[prop->getName()] = prop;
			_serializers[prop->getName()] = new EnumPropertySerializer;
			_propNames.push_back(prop->getName());
		} else {
			throw DuplicatedPropertyException();
		}
	}

	void load();
    void save();
public:
	// Reflection support
	virtual void setObject(osg::Object *obj);
	virtual osg::Object *getObject() { return NULL; }
	virtual const std::string &getType() const;
	inline virtual const std::string &getName();
	virtual const std::string &getOSGVersion() const;
	virtual const std::string &getDescription() const;
	virtual unsigned getNumProperties() const;
	virtual PropertyReflection *getProperty(const std::string &name);
	virtual const PropertyNames &getPropertyNames() { return _propNames; }
	virtual unsigned getNumChildren() { return 0; }
	virtual unsigned getNumTablePropertyColumns(const std::string &name) { return 0; }
	virtual unsigned getNumTablePropertyRows(const std::string &name) { return 0; }
	virtual const PropertyNames &getTablePropertyNames() { return _tablePropNames; }
	virtual const PropertyNames getTablePropertyColumnTitles(const std::string &name) { return PropertyNames(); }
	virtual const PropertyNames getTablePropertyRowTitles(const std::string &name) { return PropertyNames(); }
	virtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col);

	/// Singleton design pattern
	static Config *instance();
protected:
	virtual void addChild(osg::Object *child) {}
	virtual void removeChild(osg::Object *child) {}
	virtual osg::Object* getChildObject(unsigned i);
protected:
    Config();
	std::string getConfigDir() const;
private:
	typedef std::map<std::string, osg::ref_ptr<PropertyReflection> > PropertyMap;
	typedef std::map<std::string, osg::ref_ptr<PropertySerializer> > SerializerMap;

	/// Dynamic list of properties
	PropertyMap _properties;

	/// Dynamic list of property serializers
	SerializerMap _serializers;

    /// Fast access to property names
	PropertyNames _propNames;

    /// Empty
	PropertyNames _tablePropNames;
};

}//namespace osgedit

#endif//__CONFIG_H__
