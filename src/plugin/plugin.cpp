#include "plugin.h"
#include <actions/actionfactory.h>
#include <gui/layout/controls/controlfactory.h>
#include <gui/controls3d/control3dfactory.h>

#include <iostream>

Plugin::Plugin(const std::string &libName) throw (std::exception) {
    _libName = libName;
	sigc::connection actionConnection = ActionFactory::instance()->signal_register.connect(sigc::mem_fun(*this, &Plugin::on_action_registered));
	sigc::connection controlConnection = ControlFactory::instance()->signal_register.connect(sigc::mem_fun(*this, &Plugin::on_control_registered));
	sigc::connection control3dConnection = Control3DFactory::instance()->signal_register.connect(sigc::mem_fun(*this, &Plugin::on_control3d_registered));
	_module = new Glib::Module(libName);
	actionConnection.disconnect();
	controlConnection.disconnect();
	control3dConnection.disconnect();
	if (! *_module) {
		throw LoadException(Glib::Module::get_last_error());
	}
}

void Plugin::on_action_registered(std::string action) {
	_providedActions.push_back(action);
}

void Plugin::on_control_registered(std::string control) {
	_providedControls.push_back(control);
}

void Plugin::on_control3d_registered(std::string control) {
	_providedControls3D.push_back(control);
}
