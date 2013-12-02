from SCons.Util import Split
from SCons.Script.SConscript import Configure

import common
import os
import sys

def checkPkgConfig(env, package):
	ret = os.system('pkg-config --exists ' + package)
	if ret == 0:
		env.ParseConfig('pkg-config --cflags --libs ' + package)
	else:
		raise Exception("ERROR: You have to install " + package + " development package before compiling osgedit")

def checkDependencies(env):
	conf = Configure(env)
	checkPkgConfig(env, 'gtkmm-2.4')
	checkPkgConfig(env, 'libxml++-2.6')
	checkPkgConfig(env, 'gtkglext-1.0')
	checkPkgConfig(env, 'libgtksourceviewmm-1.0')
	if not conf.CheckCXXHeader('osg/Node'):
		raise Exception('ERROR: You have to install OSG development package before compiling osgedit')
	return conf.Finish()

def getEnvironment(Environment, debug=False):
	env = common.getDefaultEnvironment(Environment, debug)
	try:
		if not env.GetOption('clean'):
			env = checkDependencies(env)
	except Exception, e:
		print e
		sys.exit(1)
	if debug:
		env.Append(CCFLAGS=Split("-g -O0 -DDEBUG -Wall -pedantic"))
		env.Append(LINKFLAGS=Split("-g"))
	else:
		env.Append(CCFLAGS=['-O3'])
		env.Append(LINKFLAGS=['-Wl,-s'])
	return env

def getAlias(debug=False):
	if debug:
		return [
		'debug/osgedit',
		'debug:core_wrappers',
		'debug:core_actions',
		'debug:core_controls',
		'debug:core_controls3d',
	]
	else:
		return [
		'release/osgedit',
		'core_wrappers',
		'core_actions',
		'core_controls',
		'core_controls3d',
	]

def getPaths():
        prefix = os.path.abspath(common.getEnv('prefix', '/usr'))
        libdir = os.path.abspath(common.getEnv('libdir', os.path.join(prefix, 'lib')))
        bindir = os.path.abspath(common.getEnv('bindir', os.path.join(prefix, 'bin')))
        datadir = os.path.abspath(common.getEnv('datadir', os.path.join(prefix, 'share')))
        osgedit_libdir = os.path.join(libdir, 'osgedit')
        extensions_dir = common.getEnv('extensions_dir', os.path.join(osgedit_libdir, 'extensions'))
        osgedit_datadir = os.path.join(datadir, 'osgedit')

        return (bindir, libdir, extensions_dir, osgedit_datadir)
