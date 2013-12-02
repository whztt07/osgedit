#ifndef __REFLECTION_REGISTRY_H__
#define __REFLECTION_REGISTRY_H__

#include <reflection/classreflection.h>
#include <string>
#include <map>
#include <iostream>

/**
 * @brief Registry of osg wrappers
 *
 * Don't use this class to get directly ClassReflection's for osg::Objects, use
 * ReflectionCache instead.
 */
class REFLECTION_EXPORT ReflectionRegistry {
public:
	class UnknownClassException: public std::exception {
	public:
		UnknownClassException(std::string classname): _classname(classname){}
		virtual ~UnknownClassException() throw() {}
		virtual const char * what () const throw() { return _classname.c_str(); }
	private:
		std::string _classname;
	};

    /// Abstract wrapper allocator
	class WrapperAllocator: public osg::Referenced {
	public:
		virtual ClassReflection *allocate() = 0;
	};
    /// Concrete wrapper allocator, templated
	template <class wrapperClass>
		class TemplateWrapperAllocator: public WrapperAllocator {
		public:
			virtual ClassReflection *allocate() { return new wrapperClass; }
		};

    static ReflectionRegistry *instance();

	/// Adds a new wrapper to the registry
	void addWrapper(std::string className, WrapperAllocator *allocator);

protected:
    friend class ReflectionCache;
	/**
	 * Gets the wrapper for an OSG object
	 * Don't use this directly, use ReflectionCache::reflect instead
     */
	ClassReflection *reflect(osg::Object *object) throw (UnknownClassException);

private:
	ReflectionRegistry() {}
	typedef std::map< std::string, osg::ref_ptr<WrapperAllocator> > WrapperRegistry;
	WrapperRegistry _registry;
};


/**
 * Trick to automatically register new wrapper classes
 * Usage:
 *  RegisterWrapperClass<osg::XXX, RefosgXXX> _registerProxy;
 */
template <class osgClass, class wrapperClass>
class RegisterWrapperClass {
public:
	RegisterWrapperClass() {
		ReflectionRegistry::WrapperAllocator *allocator = new ReflectionRegistry::TemplateWrapperAllocator<wrapperClass>;
		osg::ref_ptr<osgClass> osgc = new osgClass();
        ReflectionRegistry *registry = ReflectionRegistry::instance();
		if (osgc.valid() && registry) {
			registry->addWrapper(osgc->className(), allocator);
		} else {
			std::cerr << "RegisterWrapperClass: Not enough memory!" << std::endl;
		}
	}
private:
};

#endif//__REFLECTION_REGISTRY_H__
