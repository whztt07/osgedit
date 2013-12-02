import xml.dom.minidom
import re
import string
import parserconfig

class Class:
    def __init__(self, name, abstract, parent, include, description, attributes, methods):
        self.name = name
        self.parent = parent
        self.include = include
        self.description = description
        self.attributes = attributes
        self.methods = methods
        self.abstract = abstract

        if self.name in parserconfig.tableValues:
            self.tableValues = parserconfig.tableValues[self.name]
        else:
            self.tableValues = {}

    def isObject(self):
        if self.name == 'osg::Object':
            return True
        if self.parent == None:
            return False
        return self.parent.isObject()

    def __str__(self):
        return self.name+": "+str(self.parent)

class Attribute:
    def __init__(self, name, type, pointer, enum, glenum, description, theclass=None):
        self.name = name
        self.type = type
        self.description = description
        self.capabilities = {}
        self.theclass = theclass
        self.pointer = pointer
        self.enum = enum
        self.glenum = glenum
        self.enumvalues=[]

    def isObject(self):
        if self.theclass == None:
            return False
        else:
            return self.theclass.isObject()

    def setEnumValues(self, values):
        self.enumvalues = values

    def bestChoice(self, mine, funcB):
        if mine.type == "getter":
            if mine.returntype == funcB.returntype:
                if mine.isconst == funcB.isconst:
                    return mine
                else:
                    if mine.isconst:
                        return funcB
                    else:
                        return mine
            else:
                if funcB.returntype == self.type:
                    return funcB
                else:
                    return mine
        elif mine.type == "setter":
            if len(funcB.parameters) == 1 and len(mine.parameters) > 1:
                return funcB
            if len(mine.parameters) == 1 and len(funcB.parameters) > 1:
                return mine
            if len(funcB.parameters) > 0 and (funcB.parameters[0].type == self.type or funcB.parameters[0].type == "const "+self.type+" &"):
                return funcB
            else:
                return mine
        elif mine.type == "remover":
            if funcB.parameters[0].type == self.type:
                return funcB
            else:
                return mine
        else:
            return mine

    def setCapability(self, function):
        overloaded = False
        if function.type in self.capabilities:
            overloaded = True

        if function.type in self.capabilities:
            self.capabilities[function.type] = self.bestChoice(self.capabilities[function.type], function)
        else:
            self.capabilities[function.type] = function

        self.capabilities[function.type].overloaded = overloaded

    def __str__(self):
        return self.name + ': ' + self.type + ' ['+','.join(self.capabilities)+']'+" (class "+str(self.theclass)+")"

class Parameter:
    def __init__(self, name, type, default):
        self.name = name
        self.type = type
        self.default = default

    def __str__(self):
        if self.default != "":
            return self.type + " " + self.name + " = " + self.default
        else:
            return self.type + " " + self.name

class Function:
    def __init__(self, name, type, attribute, returntype, parameters=[], isconst=False, classname=None):
        self.name = name
        self.type = type
        self.attribute = attribute
        self.parameters = parameters
        self.returntype = returntype
        self.isconst = isconst
        self.classname = classname # The class where this method is located
        self.overloaded = False

    def addParameter(self, parameter):
        self.parameters.append(parameter)

    def isIndexed(self):
        return len(self.parameters) > 0

    def __str__(self):
        str_params = ', '.join(map(str, self.parameters))
        return self.name+": "+self.type+" {"+self.attribute+"}"+"("+str_params+")"

def getText(nodes):
    rc = ""
    for node in nodes:
        if node.nodeType == node.TEXT_NODE:
            rc = rc + node.data
        else:
            rc = rc + getText(node.childNodes)
    return rc


def function2attribute(function_name):
    if len(function_name) > 0:
        return ("_"+string.lower(function_name[0])+function_name[1:])
    else:
        return ""

class ClassRegistry:
    def __init__(self):
        self.registry={}

    def register(self, classname, theclass):
        self.registry[classname] = theclass

    def has(self, classname):
        return classname in self.registry

    def get(self, classname):
        if classname in self.registry:
            return self.registry[classname]
        else:
            try:
                aParser = Parser()
                obj = aParser.parseClassName(classname)
                return obj
            except IOError:
                self.register(classname, None)
                return None

    def stats(self):
        count = 0
        count_obj = 0
        for c in self.registry:
            theclass = self.registry[c]
            if theclass != None:
                count+=1
                if not theclass.abstract and theclass.isObject():
                    count_obj+=1
        print "Registered "+str(count)+" classes ("+str(count_obj)+" objects)"

    def getObjects(self):
        objs = []
        for c in self.registry:
            theclass = self.registry[c]
            if theclass != None and not theclass.abstract and theclass.isObject():
                objs.append(theclass)
        return objs

    def adjustParents(self, aclass):
        if aclass.parent == None:
            return
        if len(aclass.parent.attributes) == 0:
            newparent = self.registry[aclass.parent.name]
            aclass.parent = newparent

    def joinAttribs(self, attrDictParent, attrDictChild):
        result = {}
        for item in attrDictParent:
            if not item in attrDictChild:
                result[item] = attrDictParent[item]
        for item in attrDictChild:
            result[item] = attrDictChild[item]
        return result

    def inheritedAttribs(self, aclass):
        if aclass.parent == None:
            return {}
        else:
            return self.joinAttribs(self.inheritedAttribs(aclass.parent), aclass.parent.attributes)

    def inherit(self):
        """
        Populate attributes inherinting from base classes
        """
        for c in self.registry:
            theclass = self.registry[c]
            if theclass != None:
                self.adjustParents(theclass)

        for c in self.registry:
            theclass = self.registry[c]
            if theclass != None:
                theclass.attributes = self.joinAttribs(self.inheritedAttribs(theclass), theclass.attributes)

registry = ClassRegistry()

class Parser:
    def __init__(self):
        self.classname = ""
        self.description = ""
        self.attributes = {}
        self.typedefs = {}
        self.owntypes = []
        self.methods = []
        self.base = None
        self.abstract = False
        self.enums = {}

    def processTypedef(self, element):
        type = getText(element.getElementsByTagName("type"))
        name = getText(element.getElementsByTagName("name"))
        #print name+": "+type
        self.typedefs[name] = type

    def getActualType(self, type):
        if type in self.typedefs:
            type = self.typedefs[type]
        composed = re.match("^(.*<) *([^ ]*) *> *$", type)
        if composed != None:
            type = composed.group(1) + " " + self.getActualType(composed.group(2)) + " >"
        return type

    def getUsefullType(self, type):
        """
        Returns the type, a bool indicating if it's a pointer, and the class or None
        """
        refptr1 = re.match("ref_ptr< *([^ ]+) *>", type)
        refptr2 = re.match("osg::ref_ptr< *([^ ]+) *>", type)
        if refptr1 <> None:
            type = refptr1.group(1)
        elif refptr2 <> None:
            type = refptr2.group(1)
        isconst = re.match("const *(.*)", type)
        if isconst <> None:
            type = isconst.group(1)
        iscref = re.match("([^ ]+) *\&", type)
        if iscref <> None:
            type = iscref.group(1)
        ptr = re.match("([^ ]+) *\*", type)
        if ptr <> None:
            type = ptr.group(1)
        if type in self.owntypes:
            type = self.classname+"::"+type
        if re.match("^osg::", type) == None:
            osgtype = "osg::"+type
        else:
            osgtype = type
        if re.match("^osgParticle::", type) == None:
            osgparticletype = "osgParticle::"+type
        else:
            osgparticletype = type
        # Avoid infinite loops
        if osgtype != self.classname:
            theclass = registry.get(osgtype)
        else:
            theclass = None
        if theclass == None and osgtype != self.classname:
            theclass = registry.get(osgparticletype)
        if isconst <> None:
            type = "const "+type
        if iscref <> None:
            type = type+" &"
        isEnum = (type in self.enums)
        if refptr1 <> None or refptr2 <> None or ptr <> None:
            return (type, True, isEnum, theclass)
        else:
            return (type, False, isEnum, theclass)

    def processVariable(self, element):
        (type, pointer, enum, theclass) = self.getUsefullType(getText(element.getElementsByTagName("type")))
        name = getText(element.getElementsByTagName("name"))
        description = getText(element.getElementsByTagName("detaileddescription"))
        description = re.sub('^[\n \t\r]*','',description)
        glenum = (type=='GLenum')
        attribute = Attribute(name, type, pointer, enum, glenum, description, theclass)
        if enum == True:
            attribute.setEnumValues(self.enums[type])
        if glenum == True:
            completename = self.classname+'::'+name
            if completename in parserconfig.glEnums:
                attribute.setEnumValues(parserconfig.glEnums[completename])
        self.attributes[attribute.name] = attribute
    
    def processFunction(self, element):
        name = getText(element.getElementsByTagName("name"))
        (returntype, rtpointer, rtenum, rttheclass) = self.getUsefullType(getText(element.getElementsByTagName("type")[:1]))
        if rtpointer:
            returntype+=" *"
        protection = element.getAttribute("prot")
        virtual = element.getAttribute("virt")
        if virtual == "pure-virtual":
            self.abstract = True
        isconst = (element.getAttribute("const") == "yes")
        if protection <> "public":
            return
        parameters = []
        for p in element.getElementsByTagName("param"):
            (type, tpointer, tenum, tclass) = self.getUsefullType(getText(p.getElementsByTagName("type")))
            if tpointer:
                type+=" *"
            pname = getText(p.getElementsByTagName("declname"))
            default = getText(p.getElementsByTagName("defval"))
            parameters.append(Parameter(pname, type, default))

        matches = {
            "counter": re.match("^getNum(.*)", name),
            "getter": re.match("^get(.*)", name),
            "setter": re.match("^set(.*)", name),
            "adder": re.match("^add(.*)", name),
            "remover": re.match("^remove(.*)", name)
        }
        for type in matches:
            if matches[type] != None:
                attribute = function2attribute(matches[type].group(1))
                method = Function(name, type, attribute, returntype, parameters, isconst, self.classname)
                valid_attr_names = self.getAttributeNames(method.attribute)
                for attr_name in valid_attr_names:
                    if attr_name in self.attributes:
                        self.attributes[attr_name].setCapability(method)
                self.methods.append(method)
    
    def getAttributeNames(self, name):
        options = [name, name+'s', string.lower(name), string.lower(name+'s')]
        options.append(string.lower(re.sub('([A-Z])', '_\g<1>', name)))
        if name in parserconfig.aliases:
            options = options + parserconfig.aliases[name]
        return options

    def parseClassName(self, classname):
        if registry.has(classname):
            print "Cached!"
            return registry.get(classname)
        else:
            print "Parsing "+classname
            filename = "xml/class"+re.sub("::", "_1_1", classname)+".xml"
            return self.parseFilename(filename)

    def processEnum(self, element):
        values = []
        for i in element.getElementsByTagName("enumvalue"):
            name = getText(i.getElementsByTagName("name"))
            values.append(name)
        enumName = self.classname + "::" + getText(element.getElementsByTagName("name")[:1])
        self.enums[enumName] = values

    def parseFilename(self, filename):
        try:
                dom = xml.dom.minidom.parse(filename)
        except Exception, e:
                print filename+" is not well formed"
                return
        self.classname = getText(dom.getElementsByTagName("compoundname"))
        for i in dom.getElementsByTagName("compounddef")[0].childNodes:
            if i.nodeName == 'detaileddescription':
                self.description = re.sub('\n',' ',getText([i]))
        self.include = dom.getElementsByTagName("location")[0].getAttribute("file")
        self.include = re.sub('.*usr.include.','', self.include)
        baseclass = getText(dom.getElementsByTagName("basecompoundref"))
        if baseclass <> '':
            self.base = registry.get(baseclass)
        elif self.classname in parserconfig.hardWiredParents:
            self.base = registry.get(parserconfig.hardWiredParents[self.classname])
        elms = dom.getElementsByTagName("memberdef")
        inner = dom.getElementsByTagName("innerclass")
        attributes = []
        attr_map = {}
        functions = []
        registry.register(self.classname, Class(self.classname, False, self.base, self.include, self.description, self.attributes, self.methods))
        for iclass in inner:
            classname = getText([iclass])
            match = re.match("^"+self.classname+"::(.*)", classname)
            if match <> None:
                self.owntypes.append(match.group(1))
            else:
                self.owntypes.append(classname)
        for element in elms:
            kind = element.getAttribute("kind")
            if kind == "typedef":
                self.processTypedef(element)
                self.owntypes.append(getText(element.getElementsByTagName("name")))
            elif kind == "enum":
                self.owntypes.append(getText(element.getElementsByTagName("name")[:1]))
                self.processEnum(element)

        for element in elms:
            kind = element.getAttribute("kind")
            if kind == "variable":
                self.processVariable(element)

        for element in elms:
            kind = element.getAttribute("kind")
            if kind == "function":
                self.processFunction(element)

        #if self.base <> None:
        #    for item in self.base.attributes:
        #        if not item in self.attributes:
        #            self.attributes[item] = self.base.attributes[item]

        registry.register(self.classname, Class(self.classname, self.abstract, self.base, self.include, self.description, self.attributes, self.methods))
        return registry.get(self.classname)

