#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <sigc++/sigc++.h>
#include <osg/Referenced>
#include <osg/ref_ptr>
#include <map>
#include <string>

class UnknownClassException: public std::exception {
public:
	UnknownClassException(const std::string &classname): _classname(classname){}
	virtual ~UnknownClassException() throw() {}
	virtual const char * what () const throw() { return _classname.c_str(); }
private:
	std::string _classname;
};


/**
 * Generic factory
 */
template <class Item>
class Factory {
public:
	/// Abstract class allocator
	class Allocator: public osg::Referenced {
	public:
		virtual Item *allocate() const = 0;
	};

	/// Concrete class allocator, templated
	template <class ConcreteItem>
	class TemplateAllocator: public Allocator {
	public:
		virtual Item *allocate() const { return new ConcreteItem; }
	};


    /// Gets an item of the factory
	inline Item *get(const std::string &className) {
		if ( _items.find(className) != _items.end() ) {
			Item *item = _items[className]->allocate();
			if (item != 0) {
				return item;
			} else {
				throw std::bad_alloc();
			}
		} else {
			throw UnknownClassException(className);
		}
    }

	/// Adds a new Item to the factory
	inline void add(const std::string &className, Allocator *allocator) {
		_items[className] = allocator;
        signal_register.emit(className);
	}

	/**
	 * Trick to automatically register new control classes
	 * Usage:
	 *  RegisterControlClass<osg::XXX, RefosgXXX> _registerProxy;
	 */
	template <class ConcreteItem>
	class RegisterProxy {
	public:
		RegisterProxy(const std::string &className, Factory *factory) {
			Allocator *allocator = new TemplateAllocator<ConcreteItem>;
			factory->add(className, allocator);
		}
	};

    /// Called when a new item is registered
	sigc::signal<void, std::string> signal_register;
private:
	typedef std::map< std::string, osg::ref_ptr<Allocator> > RegisteredItems;
    RegisteredItems _items;
};

#endif//__FACTORY_H__
