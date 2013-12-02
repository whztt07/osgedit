#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <iostream>
#include <osg/Referenced>

inline static std::string quote(const std::string &value) {
	if (value.find(' ') < value.size() || value.size() == 0) {
		return  "\"" + value + "\"";
	} else {
		return value;
	}
}

/**
 * Parses a string from an input stream, handling quotes if it has spaces
 */
inline static std::string parseString(std::istream & input) {
	std::string value;
	char c;
	do {
		input.read(&c, 1);
	} while (c == ' ');
	if (c == '"') {
        input.read(&c, 1);
		while (c != '"' && c != '\n' && !input.eof()) {
			value+=c;
            input.read(&c, 1);
		}
	} else {
		input >> value;
		value = std::string()+c+value;
	}
    return value;
}


/**
 * Property serializer interface
 */
class PropertySerializer: public osg::Referenced {
public:
	virtual std::ostream& writeTo (std::ostream& output, PropertyReflection *prop) {
        return output;
	}
	virtual std::istream& readFrom (std::istream& input, PropertyReflection *prop) {
        return input;
	}
};

/**
 * Property serializer implementation for template properties
 */
template <typename T>
class TemplatePropertySerializer: public PropertySerializer {
public:
	virtual std::ostream& writeTo (std::ostream& output, PropertyReflection *prop) {
		TemplateProperty<T> *tprop = dynamic_cast< TemplateProperty<T> * >(prop);
		if (tprop!= NULL) {
			return output << tprop->get();
		} else {
            return output;
		}
	}
	virtual std::istream& readFrom (std::istream& input, PropertyReflection *prop) {
		TemplateProperty<T> *tprop = dynamic_cast< TemplateProperty<T> * >(prop);
		if (tprop!= NULL) {
			T t;
			std::istream &newstr = input >> t;
			tprop->set(t);
            return newstr;
		} else {
            return input;
		}
	}
};

/**
 * Property serializer implementation for template properties
 * Templace specialization case for strings.
 */
template <>
class TemplatePropertySerializer<std::string>: public PropertySerializer {
public:
	virtual std::ostream& writeTo (std::ostream& output, PropertyReflection *prop) {
		TemplateProperty<std::string> *tprop = dynamic_cast< TemplateProperty<std::string> * >(prop);
		if (tprop!= NULL) {
			std::string value = tprop->get();
            return output << quote(value);
		} else {
            return output;
		}
	}
	virtual std::istream& readFrom (std::istream& input, PropertyReflection *prop) {
		TemplateProperty<std::string> *tprop = dynamic_cast< TemplateProperty<std::string> * >(prop);
		if (tprop!= NULL) {
			std::string value = parseString(input);
			tprop->set(value);
            return input;
		} else {
            return input;
		}
	}
};

/**
 * Property serializer implementation for enum properties
 */
class EnumPropertySerializer: public PropertySerializer {
public:
	virtual std::ostream& writeTo (std::ostream& output, PropertyReflection *prop) {
		EnumProperty *eprop = dynamic_cast< EnumProperty * >(prop);
		if (eprop!= NULL) {
			return output << quote(eprop->get());
		} else {
            return output;
		}
	}
	virtual std::istream& readFrom (std::istream& input, PropertyReflection *prop) {
		EnumProperty *eprop = dynamic_cast< EnumProperty * >(prop);
		if (eprop!= NULL) {
			std::string str = parseString(input);
			eprop->set(str);
            return input;
		} else {
            return input;
		}
	}
};



#endif//__SERIALIZER_H__

