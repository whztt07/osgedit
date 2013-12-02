#######
# CODE GENERATOR
#

import re
import string
import os

def quote(astr):
    return "\""+re.sub("\"","'",astr)+"\""

def getColName( (colname, type, getter) ):
    return colname



class Generator:
    wrappers_dir = "../wrappers"
    filename_prefix = "reflect_"

    def __init__(self, theclass):
        self.classname = theclass.name
        self.description = theclass.description
        self.attributes = theclass.attributes
        self.include = theclass.include
        self.children = {}
        self.filename = self.genFileName()
        self.reflectedname = self.genReflectedClassName()
        self.osgversion = "1.2"
        self.enums = {}
        self.glenums = {}
        self.filterAttributes()
        self.tableValues = theclass.tableValues

    def filterAttributes(self):
        tmp_attr = {}
        for attrname in self.attributes:
            attr = self.attributes[attrname]
            if 'getter' in attr.capabilities:
                if 'counter' in attr.capabilities and 'remover' in attr.capabilities and 'adder' in attr.capabilities:
                    self.children[attrname] = attr
                elif attr.isObject() and 'setter' in attr.capabilities:
                    self.children[attrname] = attr
                elif 'setter' in attr.capabilities:
                    if not attr.capabilities['getter'].isIndexed():
                        tmp_attr[attrname] = attr
                        if attr.enum:
                            self.enums[attr.type] = attr.enumvalues
                        elif attr.glenum:
                            self.glenums[attr.name] = attr.enumvalues
        self.attributes = tmp_attr

    def genFileName(self):
        return Generator.wrappers_dir + "/" + Generator.filename_prefix + string.lower(re.sub('::', '_', self.classname))+'.cpp'

    def genEnumName(self, enumType, glSuffix=''):
        return string.lower(re.sub('::', '_', enumType))+glSuffix

    def genReflectedClassName(self):
        return 'Ref'+re.sub('::','',self.classname);

    def genAddChild(self):
        out = "\n/**********************************************************/\n"
        out+= "void "+self.reflectedname+"::addChild(osg::Object *child) {\n";
        for childname in self.children:
            child = self.children[childname]
            if 'adder' in child.capabilities:
                adder = child.capabilities['adder']
            else:
                adder = child.capabilities['setter']
            ptype = adder.parameters[0].type
            out+= "\t{"+ptype+"cobj = dynamic_cast<"+ptype+">(child);\n"
            out+= "\tif (cobj != 0) {\n"
            out+= "\t\t_object->"+adder.name+"(cobj);\n"
            out+= "\t\treturn;\n"
            out+= "\t}}\n"
        out+= "\tthrow InvalidTypeException();\n"
        out+= "}\n"
        return out

    def genRemoveChild(self):
        out = "\n/**********************************************************/\n"
        out+= "void "+self.reflectedname+"::removeChild(osg::Object *child) {\n";
        for childname in self.children:
            child = self.children[childname]
            if 'remover' in child.capabilities:
                remover = child.capabilities['remover']
                ptype = remover.parameters[0].type
            else:
                setter = child.capabilities['setter']
                ptype = setter.parameters[0].type
            out+= "\t{"+ptype+"cobj = dynamic_cast<"+ptype+">(child);\n"
            out+= "\tif (cobj != 0) {\n"
            if 'remover' in child.capabilities:

                if len(remover.parameters) > 1:
                        out+= "\t\t_object->"+remover.name+"(cobj, 1);\n"
                else:
                        out+= "\t\t_object->"+remover.name+"(cobj);\n"
                out+= "\t\treturn;\n"

            else:
                out+= "\t\t_object->"+setter.name+"(0);\n"
                out+= "\t\treturn;\n"
            out+= "\t}}\n"
        out+= "\tthrow InvalidTypeException();\n"
        out+= "}\n"
        return out

    def genGetChild(self):
        out = "\n/**********************************************************/\n"
        out+= "osg::Object *"+self.reflectedname+"::getChildObject(unsigned i) {\n"
        for name in self.children:
            child = self.children[name]
            getter = child.capabilities['getter']
            if 'counter' in child.capabilities:
                counter = child.capabilities['counter']
                count = "_object->"+counter.name+"()"
            else:
                count = "1"
            out+= "\tif (i < "+count+") {\n"
            if len(getter.parameters) > 0:
                out+="\t\treturn _object->"+getter.name+"(i);\n"
            else:
                out+= "\t\treturn _object->"+getter.name+"();\n"
            out+= "\t} else {\n"
            out+= "\t\ti -= "+count+";\n"
            out+= "\t}\n"
        out+= "\tthrow std::out_of_range(\"child\");\n"
        out+= "}\n"
        out+= "\n/**********************************************************/\n"
        out+= "unsigned "+self.reflectedname+"::getNumChildren() {\n"
        out+="\tunsigned cnt = 0;\n"
        for name in self.children:
            child = self.children[name]
            if 'counter' in child.capabilities:
                counter = child.capabilities['counter']
                out+= "\tcnt+= _object->"+counter.name+"();\n"
            else:
                out+= "\tcnt++;\n"

        out+="\treturn cnt;\n"
        out+= "}\n"
        return out

    def genTypeDef(self, func):
        conststr = ""
        if func.isconst:
            conststr = "const"
        paramtypes = []
        for p in func.parameters:
            paramtypes.append(p.type)
        return "typedef "+func.returntype+" ("+func.classname+"::*"+func.name+"FN)("+",".join(paramtypes)+") "+conststr+";\n"

    def sortPropNames(self, pnames):
        # Name should be always first
        if '_name' in pnames:
            pnames.remove('_name')
            pnames.insert(0, '_name')

        # Datavariance always last
        if '_dataVariance' in pnames:
            pnames.remove('_dataVariance')
            pnames.append('_dataVariance')

    def genGetProperty(self):
        out = "\n/**********************************************************/\n"
        out+= "PropertyReflection* "+self.reflectedname+"::getProperty(const std::string &name) {\n";
        attr_names = self.attributes.keys()
        for aname in attr_names:
            attribute = self.attributes[aname]
            type = attribute.type
            if attribute.pointer:
                type+="*"
            getter = attribute.capabilities['getter']
            setter = attribute.capabilities['setter']
            classname = self.classname
            if getter.classname == setter.classname:
                classname = getter.classname
            if not getter.isIndexed():
                out+= "\tif (name == \""+aname+"\") {\n"
                #out+= "\t\treturn new ConcretePropertyReflection< "+type+" >(_object->"+getter.name+"());\n"
                gettercast = ""
                settercast = ""
                if getter.overloaded:
                    out+="\t\t// Getter overloaded, must specify one type\n"
                    out+= "\t\t"+self.genTypeDef(getter)
                    gettercast = "("+getter.name+"FN)";
                if setter.overloaded:
                    out+="\t\t// Setter overloaded, must specify one type\n"
                    out+= "\t\t"+self.genTypeDef(setter)
                    settercast = "("+setter.name+"FN)";
                if attribute.enum:
                    enumName = self.genEnumName(attribute.type)
                    out+="\t\treturn new GetterSetterEnumProperty<"+type+", "+classname+">(\""+aname+"\", _object.get(), "+gettercast+"&"+self.classname+"::"+getter.name+", "+settercast+"&"+self.classname+"::"+setter.name+", "+enumName+");\n"
                elif attribute.glenum:
                    enumName = self.genEnumName('GLenum',attribute.name)
                    out+="\t\treturn new GetterSetterEnumProperty<"+type+", "+classname+">(\""+aname+"\", _object.get(), "+gettercast+"&"+self.classname+"::"+getter.name+", "+settercast+"&"+self.classname+"::"+setter.name+", "+enumName+");\n"
                else:
                    out+= "\t\treturn new GetterSetterProperty<"+type+", "+classname+">(\""+aname+"\", _object.get(), "+gettercast+"&"+self.classname+"::"+getter.name+", "+settercast+"&"+self.classname+"::"+setter.name+");\n"
                out+= "\t}\n"

                #print "Getter: "+getter.returntype+" ("+self.classname+"::*)()"+" ["+getter.name+"]"
        out+= "\tthrow PropertyNotFoundException(name);\n"
        out+= "}\n"
        return out

    def genRegister(self):
        out = "\n/** REGISTERING **/\n"
        out+= "RegisterWrapperClass<"+self.classname+", "+self.reflectedname+"> _register"+self.reflectedname+";\n"
        return out;

    def generateClassDefinition(self):
        out = "#include <reflection/reflectionregistry.h>\n"
        out+= "#include <"+self.include+">\n"
        out+= "#include <stdexcept>\n\n"
        out+= "/**\n * Reflector of class "+self.classname+"\n */\n"
        out+= "class "+self.reflectedname+": public ClassReflection {\n"
        out+= "public:\n"
        out+= "\t"+self.reflectedname+"();\n"
        out+= "\tvirtual osg::Object *getObject() { return _object.get(); }\n"
        out+= "\tvirtual void setObject(osg::Object *obj);\n"
        out+= "\tvirtual const std::string &getType() const { return _class_name; }\n"
        out+= "\tvirtual const std::string &getOSGVersion() const { return _osg_version; }\n"
        out+= "\tvirtual const std::string &getDescription() const { return _class_description; }\n"
        out+= "\tvirtual unsigned getNumProperties() const { return _names.size(); }\n"
        out+= "\tvirtual const PropertyNames &getPropertyNames() { return _names; }\n"
        out+= "\tvirtual void addChild(osg::Object *child);\n"
        out+= "\tvirtual void removeChild(osg::Object *child);\n"
        out+= "\tvirtual unsigned getNumChildren();\n"
        out+= "\tvirtual osg::Object *getChildObject(unsigned i);\n"
        out+= "\tvirtual PropertyReflection *getProperty(const std::string &name);\n"
        out+= "\tvirtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col);\n"
        out+= "\tvirtual unsigned getNumTablePropertyColumns(const std::string &name);\n"
        out+= "\tvirtual unsigned getNumTablePropertyRows(const std::string &name);\n"
        out+= "\tvirtual const PropertyNames &getTablePropertyNames() { return _table_names; }\n"
        out+= "\tvirtual const PropertyNames getTablePropertyColumnTitles(const std::string &name);\n"
        out+= "\tvirtual const PropertyNames getTablePropertyRowTitles(const std::string &name);\n"
        out+= "private:\n"
        out+= "\tosg::ref_ptr<"+self.classname+"> _object;\n"
        out+= "\tstatic PropertyNames _names;\n"
        out+= "\tstatic PropertyNames _table_names;\n"
        out+= "\tstatic std::string _class_name;\n"
        out+= "\tstatic std::string _class_description;\n"
        out+= "\tstatic std::string _osg_version;\n"
        out+= "};\n\n"
        if (len(self.attributes)):
            attr_names = self.attributes.keys()
            self.sortPropNames(attr_names)
            out+= "static std::string _propnames[] = {"+','.join(map(quote, attr_names))+"};\n"
            out+= "ClassReflection::PropertyNames "+self.reflectedname+"::_names(_propnames, _propnames+"+str(len(self.attributes))+");\n\n"
        else:
            out+= "ClassReflection::PropertyNames "+self.reflectedname+"::_names;\n\n"

        if (len(self.tableValues)):
            attr_names = self.tableValues.keys()
            out+="static std::string _tablepropnames[] = {"+','.join(map(quote, attr_names))+"};\n"
            out+= "ClassReflection::PropertyNames "+self.reflectedname+"::_table_names(_tablepropnames, _tablepropnames+"+str(len(self.tableValues))+");\n\n"
        else:
            out+= "ClassReflection::PropertyNames "+self.reflectedname+"::_table_names;\n\n"

        out+= "std::string "+self.reflectedname+"::_class_name("+quote(self.classname)+");\n\n"
        out+= "std::string "+self.reflectedname+"::_class_description("+quote(self.description)+");\n\n"
        out+= "std::string "+self.reflectedname+"::_osg_version("+quote(self.osgversion)+");\n\n"
        out+= "\n/**********************************************************/\n"
        out+= self.reflectedname+"::"+self.reflectedname+"() {\n"
        out+= "}\n"
        out+= "\n/**********************************************************/\n"
        out+= "void "+self.reflectedname+"::setObject(osg::Object *obj) {\n"
        out+= "\t_object = dynamic_cast<"+self.classname+"*>(obj);\n"
        out+= "}\n"
        return out

    def generateEnums(self):
        out=""
        for enum in self.enums:
            enumName = self.genEnumName(enum)
            enumPrefix = re.sub("::[^:]*$", "", enum)
            out+="static class Enum_"+enumName+": public Enum<"+enum+"> {\n"
            out+="public:\n"
            out+="\tEnum_"+enumName+"() {\n"
            for i in self.enums[enum]:
                out+="\t\tadd(\""+i+"\", "+enumPrefix+"::"+i+");\n"
            out+="\t}\n"
            out+="} "+enumName+";\n"
        return out;

    def generateGLEnums(self):
        out=""
        for enum in self.glenums:
            enumName = self.genEnumName('GLenum',enum)
            out+="static class Enum_"+enumName+": public Enum<GLenum> {\n"
            out+="public:\n"
            out+="\tEnum_"+enumName+"() {\n"
            for i in self.glenums[enum]:
                out+="\t\tadd(\""+i+"\", "+i+");\n"
            out+="\t}\n"
            out+="} "+enumName+";\n"
        return out;

    def generateTableValues(self):
        out=""
        for tvName in self.tableValues:
            tv = self.tableValues[tvName]
            setter = tv['setter']
            for (column, type, getter) in tv['columns']:
                tvClass = "Prop"+tvName+"_"+column
                out+="class "+tvClass+": public TemplateProperty<"+type+"> {\n"
                out+="public:\n\t"+tvClass+"(std::string name, "+self.classname+" *obj, int row): TemplateProperty<"+type+">(name), _obj(obj), _row(row) {}\n"
                out+="\tvirtual "+type+" get() { return _obj->"+getter+"(_row); }\n"
                if len(tv['columns']) == 1:
                    out+="\tvirtual void setImpl("+type+" &t) { _obj->"+setter+"(_row, t); }\n"
                else:
                    out+="\tvirtual void setImpl("+type+" &t) {\n"
                    out+="\t\t_obj->"+setter+"(_row, "
                    outArr=[]
                    for (col2, type2, getter2) in tv['columns']:
                        if col2 == column:
                            outArr.append('t')
                        else:
                            outArr.append("_obj->"+getter2+"(_row)")
                    out+=",".join(outArr)+");\n"
                    out+="\t}\n"
                out+="private:\n";
                out+="\t"+self.classname+" *_obj;\n\tunsigned _row;\n};\n"
        out+="unsigned "+self.reflectedname+"::getNumTablePropertyColumns(const std::string &name) {\n"
        for tvName in self.tableValues:
            tv = self.tableValues[tvName]
            out+='\tif (name == "'+tvName+'") { return '+str(len(tv['columns']))+'; }\n'
        out+='\tthrow PropertyNotFoundException(name);\n}\n'

        out+="unsigned "+self.reflectedname+"::getNumTablePropertyRows(const std::string &name) {\n"
        for tvName in self.tableValues:
            tv = self.tableValues[tvName]
            out+='\tif (name == "'+tvName+'") { return _object->getNumChildren(); }\n'
        out+='\tthrow PropertyNotFoundException(name);\n}\n'

        out+='PropertyReflection *'+self.reflectedname+'::getTableProperty(const std::string &name, unsigned row, unsigned col) {\n'
        for tvName in self.tableValues:
            tv = self.tableValues[tvName]
            out+='\tif (name == "'+tvName+'") {\n'
            idx = 0
            for (column, type, getter) in tv['columns']:
                tvClass = "Prop"+tvName+"_"+column
                out+='\t\tif (col == '+str(idx)+') {\n'
                out+='\t\t\treturn new '+tvClass+'(name, _object.get(), row);\n'
                out+='\t\t}\n'
                idx+=1
            out+='\t}\n'
        out+='\tthrow PropertyNotFoundException(name);\n}\n'


        out+='const ClassReflection::PropertyNames '+self.reflectedname+'::getTablePropertyColumnTitles(const std::string &name) {\n'
        for tvName in self.tableValues:
            tv = self.tableValues[tvName]
            out+='\tstatic std::string '+tvName+'ColTitles[] = {'+','.join(map(quote, map(getColName, tv['columns'])))+'};\n'
            out+='\tif (name == "'+tvName+'") { return PropertyNames('+tvName+'ColTitles, '+tvName+'ColTitles+'+str(len(tv['columns']))+'); }\n'
        out+='\tthrow PropertyNotFoundException(name);\n}\n'

        out+='const ClassReflection::PropertyNames '+self.reflectedname+'::getTablePropertyRowTitles(const std::string &name) {\n'
        out+='\tPropertyNames titles;\n'
        for tvName in self.tableValues:
            tv = self.tableValues[tvName]
            out+='\tif (name == "'+tvName+'") {\n'
            out+='\t\tfor (unsigned i=0; i < _object->getNumChildren(); i++) {\n'
            out+='\t\t\ttitles.push_back(_object->getChild(i)->getName());\n'
            out+='\t\t}\n'
            out+='\t}\n'
        out+='\treturn titles;\n}\n'

        return out

    def generateClassImplementation(self):
        namespace = re.sub("::.*", "", self.classname)
        out= "\nusing namespace "+namespace+";\n"
        if namespace <> "osg":
                out+= "\nusing namespace osg;\n"
        out+= self.genAddChild()
        out+= self.genRemoveChild()
        out+= self.genGetChild()
        out+= self.genGetProperty()
        out+= self.generateTableValues()

        out+= self.genRegister()
        return out

    def filterSourceFiles(self, file):
        return (re.match(Generator.filename_prefix+".*cpp$", file) <> None)

    def updateScons(self):
        files = filter(self.filterSourceFiles, os.listdir(Generator.wrappers_dir))
        files.sort()
        scfile = open(Generator.wrappers_dir+"/SConscript", "w")
        if scfile <> None:
            scfile.write("Import('env')\n")
            scfile.write("Import('lib_dir')\n")
            scfile.write("plugin_env = env.Copy()\n")
            scfile.write("plugin_env['SHLIBPREFIX']=''\n")
            scfile.write("plugName = '#/'+env['PLUGIN_DIR']+'/core_wrappers'+env['PLUGIN_SUFFIX']\n")
            scfile.write("plugin_env.SharedLibrary(plugName, Split(\"\"\"\n"+"\n".join(files)+"\n\"\"\"))");
            scfile.close()
        else:
            print "Error opening "+Generator.wrappers_dir + "/SConscript"

    def generate(self):
        if os.access(self.filename, os.F_OK):
            return
        file = open(self.filename, "w")
        file.write(self.generateClassDefinition())
        file.write(self.generateEnums())
        file.write(self.generateGLEnums())
        file.write(self.generateClassImplementation())
        file.close()
        self.updateScons()
        print "Generated "+self.filename
