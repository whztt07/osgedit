#include <osgDB/FileUtils>

#include "controls/controlfactory.h"
#include "xmllayoutbuilder.h"
#include "autolayoutgrid.h"

#include <common/log.h>

// Macros for core controls (always registered)
#define TEXT_CONTROL "TextControl"
#define CHECK_CONTROL "CheckControl"
#define NUMERIC_CONTROL "NumericControl"
#define ENUM_CONTROL "EnumControl"
#define COLOR_CONTROL "ColorControl"
#define VEC3D_CONTROL "Vec3dControl"
#define MATRIXD_CONTROL "MatrixdControl"

inline static std::string genXMLName (const std::string &className) {
	std::string outStr = "";
	for (unsigned i=0;i<className.size();i++) {
		if (className[i] == ':') {
            outStr+="_";
			i++;
		} else if (className[i] >= 'A' && className[i] <='Z' ) {
            outStr+=className[i]+'a'-'A';
		} else {
            outStr+=className[i];
		}
	}
	return osgDB::findDataFile(outStr+".xml");
}

XmlLayoutBuilder::XmlLayoutBuilder() {
    _layout = new Layout();
}

void XmlLayoutBuilder::process(xmlpp::Element *item) {
	std::string nodeName = item->get_name();
	if (nodeName == "item") {
		std::string propertyName = item->get_attribute("property")->get_value();
		std::string label = item->get_attribute("label")->get_value();
		std::string controlName = item->get_attribute("control")->get_value();

		try {
			LayoutControl *control = FIND_CONTROL(controlName);

			xmlpp::NodeSet parameters = item->find("parameter");
			for (unsigned p=0; p < parameters.size(); p++) {
				xmlpp::Element *parameter = dynamic_cast<xmlpp::Element*>(parameters[p]);
				xmlpp::Element::AttributeList attrs = parameter->get_attributes();
				xmlpp::Attribute *first = *(attrs.begin());
				control->parseParameter(first->get_name(), first->get_value());
			}

			control->setLabel(label);
			_layout->addControl(propertyName, control);
		} catch (UnknownClassException &e) {
			LOG("Unknown class: "+controlName, Log::WARNING);
		}
	} else if (nodeName == "group") {
		std::string label = item->get_attribute("label")->get_value();
        _layout->beginGroup(label);
		xmlpp::Node::NodeList children = item->get_children();
		xmlpp::Node::NodeList::iterator iter = children.begin();
		for (; iter != children.end(); iter++) {
			xmlpp::Element *child = dynamic_cast<xmlpp::Element*>(*iter);
			if (child != NULL) {
				process(child);
			}
		}
        _layout->endGroup();
	} else if (nodeName == "tab") {
        // Tabs can't have children are only markers
		std::string label = item->get_attribute("label")->get_value();
        _layout->beginTab(label);
	}
}

void XmlLayoutBuilder::apply(ClassReflection *cref) {
	std::string objtype = cref->getType();
	std::string filename = genXMLName(objtype);
    bool ignoreMissing = false;
    /// XML Layout
	try {
		xmlpp::DomParser parser;
		parser.parse_file(filename);
		xmlpp::Element *root = parser.get_document()->get_root_node(); //deleted by DomParser.
		std::string ignore_str = root->get_attribute("ignore_missing")->get_value();
        ignoreMissing = (ignore_str == "true");
		xmlpp::Node::NodeList children = root->get_children();
        xmlpp::Node::NodeList::iterator iter = children.begin();
		for (; iter != children.end(); iter++)
		{
			xmlpp::Element *item = dynamic_cast<xmlpp::Element*>(*iter);
			if (item != NULL) {
				process(item);
			}
		}
	} catch (std::exception &e) {
		LOG("Error parsing "+filename+": "+e.what(), Log::WARNING);
	}

    /// Automatic Layout
	if (!ignoreMissing) {
		ClassReflection::PropertyNames names = cref->getPropertyNames();
		ClassReflection::PropertyNames::iterator iter = names.begin();
		for (; iter != names.end(); iter++) {
			std::string name = *iter;
			if (!_layout->hasControl(name)) {
				PropertyReflection *prop = cref->getProperty(name);
				prop->accept(*this);
			}
		}
		ClassReflection::PropertyNames tableNames = cref->getTablePropertyNames();
		for (iter= tableNames.begin(); iter != tableNames.end(); iter++) {
			std::string propName = *iter;
			if (!_layout->hasGrid(propName)) {
				AutoLayoutGrid algrid;
				algrid.apply(cref, propName);
				_layout->addGrid(propName, algrid.getGrid());
			}
		}
	}
}


inline static std::string prettyName(std::string name) {
	std::string output = "";
    bool first = true;
	for (unsigned i=0; i<name.size(); i++) {
		if (name[i] == '_') {
			continue;

		} else if (name[i] >= 'A' && name[i] <= 'Z') {
            output = output + " " + name[i];

		} else if (first) {
            char c = name[i] + 'A' - 'a';
			output = output + c;
            first = false;
		} else {
            output = output + name[i];
		}
	}
    return output;
}

void XmlLayoutBuilder::apply(StringProperty *prop) {
	addControl(TEXT_CONTROL, prop);
}

void XmlLayoutBuilder::apply(osgStringProperty *prop) {
	addControl(TEXT_CONTROL, prop);
}


void XmlLayoutBuilder::apply(BoolProperty *prop) {
	addControl(CHECK_CONTROL, prop);
}

void XmlLayoutBuilder::apply(IntProperty *prop) {
	addControl(NUMERIC_CONTROL, prop);
}
void XmlLayoutBuilder::apply(FloatProperty *prop) {
	addControl(NUMERIC_CONTROL, prop);
}
void XmlLayoutBuilder::apply(DoubleProperty *prop) {
	addControl(NUMERIC_CONTROL, prop);
}

void XmlLayoutBuilder::apply(EnumProperty *prop) {
	addControl(ENUM_CONTROL, prop);
}

void XmlLayoutBuilder::apply(ColorProperty *prop) {
    // Avoid homogeneous position coordinates treated as colors
	if (prop->getName() != "_position") {
		addControl(COLOR_CONTROL, prop);
	}
}

void XmlLayoutBuilder::apply(Vec3dProperty *prop) {
    addControl(VEC3D_CONTROL, prop);
}

void XmlLayoutBuilder::apply(MatrixdProperty *prop) {
    addControl(MATRIXD_CONTROL, prop);
}

void XmlLayoutBuilder::addControl(const std::string &controlName, PropertyReflection *prop) {
    LayoutControl *control = FIND_CONTROL(controlName);
	control->setLabel(prettyName(prop->getName()));
    _layout->addControl(prop->getName(), control);
}
