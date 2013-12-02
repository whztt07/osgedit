#!/bin/sh

# Starts the debug version of OSGEdit

if [ -e "../debug/osgedit" ];then
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../libd
	../debug/osgedit
else
	echo "You must compile first OSGEdit, whith this command in the parent directory:"
	echo " scons debug"
fi
