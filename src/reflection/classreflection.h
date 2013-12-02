#ifndef CLASS_REFLECTION_H
#define CLASS_REFLECTION_H

#include "propertyreflection.h"
#include <osg/Object>

/**
 * OSGEdit introspection mechanism, based on OSG one, but enhanced with
 * more information.
 *
 * @author Ruben
 */
class REFLECTION_EXPORT ClassReflection: public osg::Referenced {
public:
	class PropertyNotFoundException: public std::exception {
	public:
		PropertyNotFoundException(std::string classname): _classname(classname){}
		virtual ~PropertyNotFoundException() throw() {}
		virtual const char * what () const throw() { return _classname.c_str(); }
	private:
		std::string _classname;
	};

	class InvalidTypeException: public std::exception {};

	typedef std::vector<std::string> PropertyNames;

	ClassReflection();

	virtual void setObject(osg::Object *obj) = 0;

	virtual osg::Object *getObject() = 0;

	virtual const std::string &getType() const = 0;

	inline virtual const std::string &getName() {
		return getObject()->getName();
	}

	/// Get the version of OSG with which this will work well
	virtual const std::string &getOSGVersion() const = 0;

	/// Get user-friendly description of the property
	virtual const std::string &getDescription() const = 0;


	/////// Simple properties

	/// Counts the number of properties associated
	virtual unsigned getNumProperties() const = 0;

	/// Access to one of the properties
	virtual PropertyReflection *getProperty(const std::string &name) = 0;

	/// Return property names
	virtual const PropertyNames &getPropertyNames() = 0;


	/////// Children

	/// Adds a new child entitiy, at the best group
	virtual void addChild(ClassReflection *child);

	/// Removes a child object from the best group
	virtual void removeChild(ClassReflection *child);

	/// Counts the number of child entities referenced
	virtual unsigned getNumChildren() = 0;

	/// Access to one of the children
	virtual ClassReflection *getChild(unsigned i);


	///// Table properties

	/// Gets a cell value for a table property
	virtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col) = 0;

	/// Gets the number of columns of a table property
	virtual unsigned getNumTablePropertyColumns(const std::string &name) = 0;

	/// Gets the number of rows of a table property
	virtual unsigned getNumTablePropertyRows(const std::string &name) = 0;

	/// Gets all the names of table properties
	virtual const PropertyNames &getTablePropertyNames() = 0;

	/// Gets all the names of table columns
	virtual const PropertyNames getTablePropertyColumnTitles(const std::string &name) = 0;

	/// Gets all the names of table rows
	virtual const PropertyNames getTablePropertyRowTitles(const std::string &name) = 0;

protected:
	/// Adds a new child object, at the best group
	virtual void addChild(osg::Object *child) = 0;

	/// Removes a child object from the best group
	virtual void removeChild(osg::Object *child) = 0;

	virtual osg::Object* getChildObject(unsigned i) = 0;

	// Forbid delete operator, all must be done through ref_ptr's
	~ClassReflection() {}
};

#endif//CLASS_REFLECTION_H
