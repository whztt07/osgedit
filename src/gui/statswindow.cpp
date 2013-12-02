#include "statswindow.h"
#include <gtkmm/stock.h>
#include <osgUtil/Statistics>
#include <sstream>

inline std::string int2string(int i) {
	std::ostringstream stream;
	stream << i;
    return stream.str();
}

static std::string stats_str[NUM_STATS] = {
	"Primitives",
	"Vertices",
	"Drawables",
    "Groups",
    "StateSets"
};

StatsWindow::StatsWindow(osg::Node *node):
	_statHeader("Stat"),
	_uniqueHeader("Unique"),
	_instancedHeader("Instanced"),
	_buttonBox(Gtk::BUTTONBOX_END),
	_close(Gtk::Stock::CLOSE)
{
    set_title("Stats");
	add(_vBox);
    _vBox.pack_start(_table, true, true);
	_vBox.pack_start(_buttonBox, false, true);
	_buttonBox.pack_start(_close);

	_table.attach(_statHeader, 0, 1, 0, 1, Gtk::EXPAND | Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	_table.attach(_uniqueHeader, 1, 2, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
	_table.attach(_instancedHeader, 2, 3, 0, 1, Gtk::FILL, Gtk::AttachOptions(), 0, 0);

	for (unsigned i=0; i < NUM_STATS; i++) {
        _statLabels[i].set_text(stats_str[i]);
		_table.attach(_statLabels[i], 0, 1, i+1, i+2, Gtk::EXPAND | Gtk::FILL, Gtk::AttachOptions(), 0, 0);
		_table.attach(_uniqueStats[i], 1, 2, i+1, i+2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);
		_table.attach(_instancedStats[i], 2, 3, i+1, i+2, Gtk::FILL, Gtk::AttachOptions(), 0, 0);

	}

	_table.set_row_spacings(5);
	_table.set_col_spacings(15);
    _table.set_border_width(10);

	osgUtil::StatsVisitor visitor;
    node->accept(visitor);
	visitor.totalUpStats();

	unsigned int unique_primitives = 0;
    osgUtil::Statistics::PrimitiveCountMap::iterator pcmitr;
    for(pcmitr = visitor._uniqueStats.GetPrimitivesBegin();
        pcmitr != visitor._uniqueStats.GetPrimitivesEnd();
        ++pcmitr)
    {
        unique_primitives += pcmitr->second;
    }

    unsigned int instanced_primitives = 0;
    for(pcmitr = visitor._instancedStats.GetPrimitivesBegin();
        pcmitr != visitor._instancedStats.GetPrimitivesEnd();
        ++pcmitr)
    {
        instanced_primitives += pcmitr->second;
    }

    _uniqueStats[0].set_text(int2string(unique_primitives));
    _instancedStats[0].set_text(int2string(instanced_primitives));

    _uniqueStats[1].set_text(int2string(visitor._uniqueStats._vertexCount));
    _instancedStats[1].set_text(int2string(visitor._instancedStats._vertexCount));

	_uniqueStats[2].set_text(int2string(visitor._drawableSet.size()));
	_instancedStats[2].set_text(int2string(visitor._numInstancedDrawable));

	_uniqueStats[3].set_text(int2string(visitor._groupSet.size()));
	_instancedStats[3].set_text(int2string(visitor._numInstancedGroup));

	_uniqueStats[4].set_text(int2string(visitor._statesetSet.size()));
	_instancedStats[4].set_text(int2string(visitor._numInstancedStateSet));

    show_all();
	_close.signal_clicked().connect(sigc::mem_fun(*this, &StatsWindow::on_delete_event));
}

void StatsWindow::on_delete_event() {
    delete this;
}
