#include "actionfactory.h"

ActionFactory::ActionFactory() {
    _actionGroup = Gtk::ActionGroup::create();
}

ActionFactory *ActionFactory::instance() {
	static ActionFactory *_instance = new ActionFactory;
    return _instance;
}

void ActionFactory::addActionToGroup(const std::string &action, const std::string &label) {
	_actionGroup->add(Gtk::Action::create(action, label),
					  sigc::bind<std::string>(sigc::mem_fun(*this, &ActionFactory::on_run_request), action));
}

void ActionFactory::addActionToGroup(const std::string &name, const Gtk::StockID &stock, const std::string &label, const std::string &tooltip) {
	_actionGroup->add(Gtk::Action::create(name, stock, label, tooltip),
					  sigc::bind<std::string>(sigc::mem_fun(*this, &ActionFactory::on_run_request), name));
}

bool ActionFactory::run(const std::string &actionName) throw (UnknownClassException) {
	osg::ref_ptr<Action> action = get(actionName);
	return action->run();
}

void ActionFactory::on_run_request(std::string action) {
    run(action);
}
