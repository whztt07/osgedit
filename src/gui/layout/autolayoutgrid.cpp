#include "autolayoutgrid.h"

#include "gridcontrols/textgridcontrol.h"
#include "gridcontrols/checkgridcontrol.h"
#include "gridcontrols/numericgridcontrol.h"

void AutoLayoutGrid::apply(ClassReflection *cref, const std::string &tableProperty) {
    _grid = new LayoutGrid();
	unsigned nRows = cref->getNumTablePropertyRows(tableProperty);
	if (nRows == 0) return;

	ClassReflection::PropertyNames columns = cref->getTablePropertyColumnTitles(tableProperty);
	for (unsigned i=0; i < columns.size(); i++) {
		std::string colName = columns[i];
		PropertyReflection *prop = cref->getTableProperty(tableProperty, 0, i);
		_lastColumn = i;
        _lastName = colName;
		prop->accept(*this);
	}
}

void AutoLayoutGrid::apply(StringProperty *prop) {
	TextGridControl *ctl = new TextGridControl;
    _grid->addColumnControl(_lastColumn, _lastName, ctl);
}


void AutoLayoutGrid::apply(BoolProperty *prop) {
	CheckGridControl *ctl = new CheckGridControl;
    _grid->addColumnControl(_lastColumn, _lastName, ctl);
}

void AutoLayoutGrid::apply(IntProperty *prop) {
	NumericGridControl *ctl = new NumericGridControl(NumericGridControl::INT);
    _grid->addColumnControl(_lastColumn, _lastName, ctl);
}
void AutoLayoutGrid::apply(FloatProperty *prop) {
	NumericGridControl *ctl = new NumericGridControl(NumericGridControl::FLOAT);
    _grid->addColumnControl(_lastColumn, _lastName, ctl);
}
void AutoLayoutGrid::apply(DoubleProperty *prop) {
	NumericGridControl *ctl = new NumericGridControl(NumericGridControl::DOUBLE);
    _grid->addColumnControl(_lastColumn, _lastName, ctl);
}

void AutoLayoutGrid::apply(EnumProperty *prop) {
}

void AutoLayoutGrid::apply(ColorProperty *prop) {
}

