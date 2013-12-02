#ifndef __NAMING_CONTROL_H__
#define __NAMING_CONTROL_H__

#include <osg/Object>
#include <map>
#include <string>
#include <reflection/classreflection.h>
#include "export.h"

class COMMON_EXPORT NamingControl {
public:
	/**
	 * Recursive function to ensure that everything is named
	 */
	static void rename(ClassReflection *cref);

	/**
	 * Another option if you have an object instead of reflection
     */
	static void rename(osg::Object *root);

protected:

	static std::string genName(std::string type);

private:
	static std::map<std::string, int> _indexes;
};

#endif//__NAMING_CONTROL_H__
