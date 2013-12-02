#ifndef __CONTROL_FACTORY_H__
#define __CONTROL_FACTORY_H__

#include "layoutcontrol.h"
#include <common/factory.h>
#include "export.h"

/**
 * Control factory. Usage:
 * To register a custom control:
 * REGISTER_CONTROL(MyCustomControlClass);
 *
 * To find a control by name:
 *
 * LayoutControl *ctl = FIND_CONTROL(controlName);
 */
class CONTROLS_EXPORT ControlFactory: public Factory<LayoutControl> {
public:
    static ControlFactory *instance();

	template <class ConcreteItem>
	class RegisterControl: public Factory<LayoutControl>::RegisterProxy<ConcreteItem> {
	public:
		RegisterControl(const std::string &className):
			Factory<LayoutControl>::RegisterProxy<ConcreteItem>(className, ControlFactory::instance()) {}
	};
protected:
	ControlFactory(){}
};


#define REGISTER_CONTROL(ControlClass) \
	static ControlFactory::RegisterControl<ControlClass> _proxy(#ControlClass)

#define FIND_CONTROL(name) \
	ControlFactory::instance()->get(name)

#endif//__CONTROL_FACTORY_H__
