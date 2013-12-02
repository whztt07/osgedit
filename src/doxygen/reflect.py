#!/usr/bin/python

import xml.dom.minidom
import re
import sys
import string
import xmlparser
import codegenerator

def showParserInfo(parser):
    for a in parser.attributes:
        print "Attribute: "+str(parser.attributes[a])
    print
    for f in parser.methods:
        print "Function: "+str(f)

def main():
    if len(sys.argv) < 2:
        print "Falta al menos un nombre de clase osg"
        sys.exit(-1)
    

    for name in sys.argv[1:]:
        try:
            parser = xmlparser.Parser()
            theclass = parser.parseClassName(name)
            if theclass == None or not theclass.isObject():
                print name+" no es un osg::Object"
            showParserInfo(parser)
        except IOError, err:
            print "ERROR: No existe un xml para la clase"
            print err

    xmlparser.registry.inherit()
    print "Generating code..."
    classes = xmlparser.registry.getObjects()
    for obj in classes:
        generator = codegenerator.Generator(obj)
        generator.generate()
    print xmlparser.registry.stats()


main()
