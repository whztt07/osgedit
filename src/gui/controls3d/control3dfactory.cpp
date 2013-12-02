#include "control3dfactory.h"

Control3DFactory *Control3DFactory::instance() {
	static Control3DFactory *_instance = new Control3DFactory;
    return _instance;
}
