#include <gui/layout/controls/controlfactory.h>
#include <gtkmm/adjustment.h>
#include "vec3dcontrol.h"

Vec3dControl::Vec3dControl() {
	_frame = Gtk::manage(new Gtk::Frame());
	_frame->set_shadow_type(Gtk::SHADOW_NONE);

	_mainLabel = Gtk::manage(new Gtk::Label());

	Gtk::Table *table = new Gtk::Table(3,2);
    _frame->add(*table);
    _frame->set_label_widget(*_mainLabel);

	std::string labels[3] = { "X", "Y", "Z" };

	for (unsigned i=0; i < 3; i++) {

		Gtk::Adjustment * adj = Gtk::manage(new Gtk::Adjustment(0, G_MININT32, G_MAXINT32, 1, 10, 10));
		_spins[i] = Gtk::manage(new Gtk::SpinButton(*adj, 1, 2));
		_spins[i]->set_width_chars(4);
		Gtk::Label *label = Gtk::manage(new Gtk::Label(labels[i]));
		table->attach(*label, 0, 1, i, i+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
		table->attach(*_spins[i], 1, 2, i, i+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
		_spins[i]->signal_value_changed().connect(sigc::bind<int>(sigc::mem_fun(*this, &Vec3dControl::on_set_value), i));
	}
}

unsigned Vec3dControl::render(Gtk::Table *table, unsigned row) {
    table->attach(*_frame, 0, 2, row, row+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 3);
	return row+1;
}

void Vec3dControl::apply(Vec3dProperty *prop) {
    _target = prop;
    refresh();
}

void Vec3dControl::on_set_value(int i){
	if (_target.valid()) {
		double val = _spins[i]->get_value();
		osg::Vec3d targetValue = _target->get();
		if (val != targetValue[i]) {
            targetValue[i] = val;
			_target->set(targetValue);
		}
	}
}


void Vec3dControl::setLabel(const std::string &label) {
    _mainLabel->set_text("<b>"+label+"</b>");
	_mainLabel->set_use_markup(true);
}

void Vec3dControl::refresh() {
    if (!_target.valid()) return;

    osg::Vec3d targetValue = _target->get();
	for (unsigned i=0; i < 3; i++) {
        _spins[i]->set_value(targetValue[i]);
	}
}

REGISTER_CONTROL(Vec3dControl);
