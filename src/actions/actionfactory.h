#ifndef __ACTION_FACTORY_H__
#define __ACTION_FACTORY_H__

#include <gtkmm/actiongroup.h>
#include <common/factory.h>
#include "action.h"

/**
 * ActionFactory is actually an adaptor for Gtk::ActionGroup to the
 * OSGEdit way of doing things
 */
class ACTION_EXPORT ActionFactory: public Factory<Action> {
public:
	static ActionFactory *instance();

	inline Glib::RefPtr<Gtk::ActionGroup> getActions() { return _actionGroup; }


	template <class ConcreteAction>
		class RegisterAction: public Factory<Action>::RegisterProxy<ConcreteAction> {
		public:
			RegisterAction(const std::string &name, const std::string &label): Factory<Action>::RegisterProxy<ConcreteAction>(name, ActionFactory::instance()) {
				ActionFactory::instance()->addActionToGroup(name, label);
			}
			RegisterAction(const std::string &name, const Gtk::StockID &stock, const std::string &label, const std::string &tooltip): Factory<Action>::RegisterProxy<ConcreteAction>(name, ActionFactory::instance()) {
				ActionFactory::instance()->addActionToGroup(name, stock, label, tooltip);
			}
		};

	/**
	 * Run the specified action, if exists
	 */
	bool run(const std::string &action) throw (UnknownClassException);

protected:
	void addActionToGroup(const std::string &action, const std::string &label);
	void addActionToGroup(const std::string &name, const Gtk::StockID &stock, const std::string &label, const std::string &tooltip);

    /// Utility to catch GTK requests and forward them to the actual run method
	void on_run_request(std::string action);
	ActionFactory();
private:
	Glib::RefPtr<Gtk::ActionGroup> _actionGroup;
};

#define REGISTER_ACTION(ActionClass, Label) \
	static ActionFactory::RegisterAction<ActionClass> _proxy_##ActionClass(#ActionClass, Label)

#define REGISTER_ACTION_FULL(ActionClass, GtkStock, Label, Tooltip) \
	static ActionFactory::RegisterAction<ActionClass> _proxy_##ActionClass(#ActionClass, GtkStock, Label, Tooltip)

#endif//__ACTION_FACTORY_H__
