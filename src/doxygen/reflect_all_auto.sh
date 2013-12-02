#!/bin/sh

CLASSES=$(cat xml/namespace*.xml |grep innerc|sed "s/.*\">//"|sed s/"<.*//"|grep -v ^std)

./reflect.py $CLASSES
