#ifndef __RICH_PROPERTY_H__
#define __RICH_PROPERTY_H__

#include <osg/Object>
#include <osg/Referenced>
#include <osg/ref_ptr>
#include <vector>
#include <string>
#include <map>
#include <common/functions.h>
#include <common/visitor.h>
#include <command/command.h>
#include "export.h"

/**
 * A property of a class
 */
class REFLECTION_EXPORT PropertyReflection: public osg::Referenced, public BaseVisitable<> {
public:
	PropertyReflection(const std::string &name);
	virtual ~PropertyReflection() {}

	/// Get the version of OSG with which this will work well
	const std::string &getOSGVersion() const { return _osg_version; }

	/// Get user-friendly description of the property
	const std::string &getDescription() const { return _description; }

	/// Get the property name
	const std::string &getName() const { return _name; }

	typedef std::vector< osg::ref_ptr<PropertyReflection> > Vector;

	/// Visitor pattern
	META_VISITABLE();
private:
	std::string _osg_version; ///< The version of OSG with which this will work well
	std::string _description; ///< User-friendly description of the property
	std::string _name; ///< Property name
};

/**
 * Template property, automatically handling a type and giving get/set access to the actual value
 */
template <typename T>
class TemplateProperty: public PropertyReflection {
public:
	TemplateProperty(std::string name): PropertyReflection(name) {}
	virtual T get() = 0;
	void set(T &t) {
		Command *command = new TemplatePropertyCommand<T>(this, t);
		command->execute();
	}

	/// Visitor pattern
	META_VISITABLE();

protected:
	virtual void setImpl(T &t) = 0;

	template <typename T2>
		class TemplatePropertyCommand: public Command {
		public:
			TemplatePropertyCommand(TemplateProperty<T2> *prop, const T &t) {
				_newValue = t;
				_prop = prop;
			}
			virtual void undo() {
				_prop->setImpl(_oldValue);
			}
			virtual std::string getChangeString() const {
				return "Modify "+_prop->getName();
			}
			virtual bool joinWith(Command *cmd) {
				TemplatePropertyCommand<T2> *tpc = dynamic_cast<TemplatePropertyCommand<T2> *>(cmd);
				if (tpc != NULL) {
					_newValue = tpc->_newValue;
					return true;
				} else {
					return false;
				}
			}
		protected:
			virtual void executeImpl() {
				_oldValue = _prop->get();
				_prop->setImpl(_newValue);
			}
		private:
			osg::ref_ptr< TemplateProperty<T2> > _prop;
			T2 _oldValue;
			T2 _newValue;
		};
};

/**
 * Template property that automatically calls getter/setter methods to get/set the actual values
 */
template <typename AttrType, class ObjType, typename SetterReturnType=void>
class GetterSetterProperty: public TemplateProperty<AttrType> {
public:
	template <typename GetterMethod, typename SetterMethod>
		GetterSetterProperty(const std::string &name, ObjType *obj, GetterMethod getter, SetterMethod setter):
	TemplateProperty<AttrType>(name),
		_getter(getter),
		_setter(setter)
	{
		_obj = obj;
	}

	virtual AttrType get() { return _getter(_obj); }
	virtual void setImpl(AttrType &v) { _setter(_obj, v); }

private:
	ObjType *_obj;
	Function<AttrType, ObjType> _getter;
	FunctionArg<void, ObjType, AttrType> _setter;
};

/**
 * Valued property. Values are stored here directly
 */
template <typename T>
class ValuedProperty: public TemplateProperty<T> {
public:
	ValuedProperty(std::string name, T defVal=T()): TemplateProperty<T>(name) {
		_value = defVal;
	}
	virtual T get() { return _value; }
protected:
	virtual void setImpl(T &v) { _value = v; }
private:
	T _value;
};

/**
 * Enumeration type, handling the mapping between enum values and string representations
 */
template <typename EnumType>
class Enum {
public:
	typedef std::map<EnumType, std::string> Enum2String;
	typedef std::map<std::string, EnumType> String2Enum;
	typedef std::vector< std::string > NameList;
	inline void add(const std::string &name, EnumType item) { _enum2string[item] = name; _string2enum[name] = item; _names.push_back(name); }
	inline EnumType get(const std::string &name) { return _string2enum[name]; }
	inline const std::string &get(EnumType item) { return _enum2string[item]; }
	inline const NameList &getNames() { return _names; }
private:
	Enum2String _enum2string;
	String2Enum _string2enum;
	NameList _names;
};

/**
 * Generic enumeration property supporting get/set by string representation of the enum values.
 */

class EnumProperty: public PropertyReflection {
public:
	EnumProperty(const std::string &name): PropertyReflection(name) {}
	virtual const std::string &get() = 0;
	virtual void set(const std::string &v) {
		Command *command = new EnumPropertyCommand(this, v);
		command->execute();
	}
	virtual const std::vector<std::string> &getEnumItems() = 0;

	/// Visitor pattern
	META_VISITABLE();

protected:
	virtual void setImpl(const std::string &v) = 0;

	class EnumPropertyCommand: public Command {
	public:
		EnumPropertyCommand(EnumProperty *prop, const std::string &t) {
			_newValue = t;
			_prop = prop;
		}
		virtual void undo() {
			_prop->setImpl(_oldValue);
		}
		virtual std::string getChangeString() const {
			return "Modify "+_prop->getName();
		}
	protected:
		virtual void executeImpl() {
			_oldValue = _prop->get();
			_prop->setImpl(_newValue);
		}
	private:
		osg::ref_ptr< EnumProperty > _prop;
		std::string _oldValue;
		std::string _newValue;
	};
};

/**
 * Templated enum property. Calls automatically the actual getter setter osg methods
 */
template <typename AttrType, class ObjType, typename SetterReturnType=void>
class GetterSetterEnumProperty: public EnumProperty {
public:
	template <typename GetterMethod, typename SetterMethod>
		GetterSetterEnumProperty(const std::string &name, ObjType *obj, GetterMethod getter, SetterMethod setter, Enum<AttrType> anEnum): EnumProperty(name),
		_getter(getter),
		_setter(setter) {
			_obj = obj;
			_enum = anEnum;
		}
		virtual const std::string &get() { return _enum.get(_getter(_obj)); }

		virtual void setImpl(const std::string &v) {
			AttrType v2 = _enum.get(v);
			_setter(_obj, v2);
		}

		virtual const std::vector<std::string> &getEnumItems() { return _enum.getNames(); }

private:
	ObjType *_obj;
	Enum<AttrType> _enum;
	Function<AttrType, ObjType> _getter;
	FunctionArg<void, ObjType, AttrType> _setter;
};

/**
 * Templated enum property that stores itself the value.
 */
template <typename AttrType>
class ValuedEnumProperty: public EnumProperty {
public:
	ValuedEnumProperty(const std::string &name, Enum<AttrType> anEnum, AttrType defVal=(AttrType)0): EnumProperty(name)
	{
		_enum = anEnum;
		_value = defVal;
	}

	AttrType getValue() { return _value; }

	void setValue(AttrType t) { _value = t; }

	virtual const std::string &get() { return _enum.get(_value); }

	virtual void setImpl(const std::string &v) {
		_value = _enum.get(v);
	}

	virtual const std::vector<std::string> &getEnumItems() { return _enum.getNames(); }

private:
	Enum<AttrType> _enum;
	AttrType _value;
};

#endif//__RICH_PROPERTY_H__
