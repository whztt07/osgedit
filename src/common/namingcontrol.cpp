#include <reflection/reflectioncache.h>
#include "namingcontrol.h"
#include <sstream>

std::map<std::string, int> NamingControl::_indexes;

void NamingControl::rename(osg::Object *root) {
	ClassReflection* cref = ReflectionCache::instance()->reflect(root);
	if (cref != NULL) {
		rename(cref);
	}
}

/**
 * Recursive function to ensure that everything is named
 */
void NamingControl::rename(ClassReflection *cref) {
	std::string type = cref->getType();
	if (cref->getName() == "") {
		cref->getObject()->setName(genName(type));
	}
	for (unsigned i=0; i < cref->getNumChildren(); i++) {
		ClassReflection *childref = cref->getChild(i);
		if (childref != NULL) {
			rename(childref);
		}
	}
}

std::string NamingControl::genName(std::string type) {
	if (_indexes.find(type) == _indexes.end()) {
		_indexes[type] = 0;
	}
	_indexes[type]++;
	std::ostringstream stream;
	stream << type << _indexes[type];
	return stream.str();
}
