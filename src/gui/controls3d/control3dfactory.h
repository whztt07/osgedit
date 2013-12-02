#ifndef __CONTROL_3D_FACTORY_H__
#define __CONTROL_3D_FACTORY_H__

#include "control3d.h"
#include <common/factory.h>
#include "export.h"

/**
 * Control3D factory. Usage:
 * To register a custom control:
 * REGISTER_CONTROL_3D(MyCustomControl3DClass);
 *
 * To find a control by name:
 *
 * Control3D *ctl = FIND_CONTROL_3D(controlName);
 */
class CONTROLS3D_EXPORT Control3DFactory: public Factory<Control3D> {
public:
    static Control3DFactory *instance();

	template <class ConcreteItem>
	class RegisterControl3D: public Factory<Control3D>::RegisterProxy<ConcreteItem> {
	public:
		RegisterControl3D(const std::string &className):
			Factory<Control3D>::RegisterProxy<ConcreteItem>(className, Control3DFactory::instance()) {}
	};
protected:
	Control3DFactory(){}
};


#define REGISTER_CONTROL_3D(Control3DClass) \
	static Control3DFactory::RegisterControl3D<Control3DClass> _proxy(#Control3DClass)

#define FIND_CONTROL_3D(name) \
	Control3DFactory::instance()->get(name)

#endif//__CONTROL_3D_FACTORY_H__
