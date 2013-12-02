from SCons.Util import Split
import os
import common
import sys

def getEnvironment(Environment, debug=False):
	env = common.getDefaultEnvironment(Environment, debug)

	try:
		GTKMM_BASEPATH = os.environ['GTKMM_BASEPATH']
		GTK_BASEPATH = os.environ['GTK_BASEPATH']
		OSG_ROOT = os.environ['OSG_ROOT']
	except Exception:
		print "You have to install the following software first:"
		print "\tGTKmm (and ensure that GTKMM_BASEPATH is set)"
		print "\tGTK (and ensure that GTK_BASEPATH is set)"
		print "\tOpenSceneGraph (and ensure that OSG_ROOT is set)"
		print "\tOptionally if you compiled OpenThreads yourself, you may use OT_ROOT to point to it"
		sys.exit(1)
	if 'OT_ROOT' in os.environ:
			OT_ROOT = os.environ['OT_ROOT']
	else:
			OT_ROOT = OSG_ROOT
	try:	
			PLATFORMSDK_ROOT = os.environ['PLATFORMSDK_ROOT']
	except Exception:
		print "Install MS Platform SDK and point PLATFORMSDK_ROOT to its path"
		sys.exit(1)

	env.Append(LIBS=["sigc-2.0"])
	# Include the manifest file into the targets (;1 for exe, ;2 for DLL)
	# We also remove manifest files to avoid problems with plugin directories
	env.Append(LINKCOM  = [env['LINKCOM'], 'mt.exe -nologo -manifest ${TARGET}.manifest -outputresource:$TARGET;1'])
	env.Append(SHLINKCOM  = [env['SHLINKCOM'], 'mt.exe -nologo -manifest ${TARGET}.manifest -outputresource:$TARGET;2'])
	env.Append(LIBPATH=[
			GTKMM_BASEPATH+'\\lib',
			GTK_BASEPATH+'\\lib',
			OSG_ROOT+'\\lib',
			OT_ROOT+'\\lib',
	])
	env.Append(CPPPATH=[
			GTKMM_BASEPATH+'\\include\\libglademm-2.4',
			GTKMM_BASEPATH+'\\lib\\libglademm-2.4\\include',
			GTKMM_BASEPATH+'\\lib\\gtkmm-2.4\\include',
			GTKMM_BASEPATH+'\\include\\gtkmm-2.4',
			GTKMM_BASEPATH+'\\lib\\gdkmm-2.4\\include',
			GTKMM_BASEPATH+'\\include\\gdkmm-2.4',
			GTKMM_BASEPATH+'\\include\\pangomm-1.4',
			GTKMM_BASEPATH+'\\include\\atkmm-1.6',
			GTKMM_BASEPATH+'\\lib\\libxml++-2.6\\include',
			GTKMM_BASEPATH+'\\include\\libxml++-2.6',
			GTKMM_BASEPATH+'\\lib\\glibmm-2.4\\include',
			GTKMM_BASEPATH+'\\include\\glibmm-2.4',
			GTKMM_BASEPATH+'\\include\\cairomm-1.0',
			GTKMM_BASEPATH+'\\lib\\sigc++-2.0\\include',
			GTKMM_BASEPATH+'\\include\\sigc++-2.0',
			GTK_BASEPATH+'\\lib\\gtkglext-1.0\\include',
			GTK_BASEPATH+'\\include\\gtkglext-1.0',
			GTK_BASEPATH+'\\include\\libglade-2.0',
			GTK_BASEPATH+'\\lib\\gtk-2.0\\include',
			GTK_BASEPATH+'\\include\\gtk-2.0',
			GTK_BASEPATH+'\\include\\pango-1.0',
			GTK_BASEPATH+'\\include\\atk-1.0',
			GTK_BASEPATH+'\\lib\\glib-2.0\\include',
			GTK_BASEPATH+'\\include\\glib-2.0',
			GTK_BASEPATH+'\\include\\libxml2',
			GTK_BASEPATH+'\\include\\cairo',
			GTK_BASEPATH+'\\include',
			PLATFORMSDK_ROOT+'\\Include',
			OSG_ROOT+'\\include',
			OT_ROOT+'\\include'
	])
	env.Append(LIBS=Split("""
		glademm-2.4 xml++-2.6 gtkmm-2.4 glade-2.0 gdkmm-2.4 atkmm-1.6 pangomm-1.4 
		glibmm-2.4 cairomm-1.0 sigc-2.0 gtk-win32-2.0 xml2 gdk-win32-2.0 atk-1.0 
		gdk_pixbuf-2.0 pangowin32-1.0 pangocairo-1.0 pango-1.0 cairo gobject-2.0 
		gmodule-2.0 glib-2.0 intl iconv gtkglext-win32-1.0 gdkglext-win32-1.0
	"""))

	if debug:
		env.Append(CCFLAGS=[
			"/vd2",
			"/EHsc",
			"/DWIN32",
			"/GR",
			"/RTC1",
			"/MDd",
			"/Od",
			"/TP"])
	else:
		env.Append(CCFLAGS=[
			"/vd2",
			"/EHsc",
			"/DWIN32",
			"/GR",
			"/RTC1",
			"/MD",
			"/TP"])
	return env

def getAlias(debug=False):
	if debug:
		return [
		'debug/osgedit.exe',
		'debug:core_wrappers',
		'debug:core_actions',
		'debug:core_controls',
		'debug:core_controls3d',
	]
	else:
		return [
		'release/osgedit.exe',
		'core_wrappers',
		'core_actions',
		'core_controls',
		'core_controls3d',
	]

def getPaths():
        libdir = common.getEnv('libdir', '')
        bindir = common.getEnv('bindir', '')
        extensions_dir = common.getEnv('extensions_dir', 'extensions')
        osgedit_datadir = os.path.join('data')

        return (bindir, libdir, extensions_dir, osgedit_datadir)
