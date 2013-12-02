from SCons.Util import Split
import os

includes=['#/src']
libdir_release=['#/lib']
libdir_debug=['#/libd']
rpath_release='lib'
rpath_debug='libd'
core_plugin_dir='extensions/core/plugins'
libs=Split("""
	osg
	osgDB
	osgUtil
	osgParticle
	osgFX
	osgSim
	osgShadow
	osgText
	osgViewer
""")

def getDefaultEnvironment(Environment, debug=False):
    if debug:
        env = Environment(CPPPATH=includes, LIBPATH=libdir_debug, LIBS=libs, RPATH=rpath_debug)
    else:
        env = Environment(CPPPATH=includes, LIBPATH=libdir_release, LIBS=libs, RPATH=rpath_release)
    if debug:
        env['PLUGIN_SUFFIX']='d'
    else:
        env['PLUGIN_SUFFIX']=''
    env['PLUGIN_DIR']=core_plugin_dir
    return env

def getEnv(variable, default):
	if variable in os.environ:
		return os.environ[variable]
	else:
		return default

