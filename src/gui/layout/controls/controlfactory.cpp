#include "controlfactory.h"

ControlFactory *ControlFactory::instance() {
	static ControlFactory *_instance = new ControlFactory;
    return _instance;
}
