#include <gui/layout/controls/controlfactory.h>
#include <gtkmm/adjustment.h>
#include "matrixdcontrol.h"

//TODO: DELETE THIS
#include <iostream>
#include <osg/io_utils>

MatrixdControl::MatrixdControl() {
	_label = Gtk::manage(new Gtk::Label());
	_label->set_alignment(0,0.5);

    _table = Gtk::manage(new Gtk::Table());

	for (unsigned y=0;y<4;y++) {
		for (unsigned x=0;x<4;x++) {
            int i = x+y*4;
			Gtk::Adjustment * adj = Gtk::manage(new Gtk::Adjustment(0, G_MININT32, G_MAXINT32, 1, 10, 10));
			_spins[i] = Gtk::manage(new Gtk::SpinButton(*adj, 1, 2));
			_table->attach(*_spins[i], x, x+1, y, y+1, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 0);
			_spins[i]->signal_value_changed().connect(sigc::bind<Gtk::SpinButton*, int, int>(sigc::mem_fun(*this, &MatrixdControl::on_set_value), _spins[i], x, y));
			_spins[i]->set_width_chars(4);
		}
	}
}

unsigned MatrixdControl::render(Gtk::Table *table, unsigned row) {
	table->attach(*_label, 0, 2, row, row+1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	table->attach(*_table, 0, 2, row+1, row+2, Gtk::EXPAND|Gtk::FILL, Gtk::AttachOptions(), 0, 3);
    return row+2;
}

void MatrixdControl::apply(MatrixdProperty *prop) {
    _target = prop;
    refresh();
}

void MatrixdControl::on_set_value(Gtk::SpinButton *spin, unsigned x, unsigned y) {
	if (_target.valid()) {
		double val = spin->get_value();
		osg::Matrixd targetValue = _target->get();
		if (val != targetValue(y,x)) {
            targetValue(y,x) = val;
			_target->set(targetValue);
		}
	}
}

void MatrixdControl::setLabel(const std::string &label) {
    _label->set_text(label);
}

void MatrixdControl::refresh() {
	if (!_target.valid()) return;

    osg::Matrixd targetValue = _target->get();
	for (unsigned y=0;y<4;y++) {
		for (unsigned x=0;x<4;x++) {
			int i = x+y*4;
            _spins[i]->set_value(targetValue(y,x));
		}
	}
}

REGISTER_CONTROL(MatrixdControl);
