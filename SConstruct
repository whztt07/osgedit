import sys
import os

from env import BuilderUtility
from env.common import getEnv

def quote(path):
	return '\\"' + path + '\\"'

def relative(path):
	if len(path) and path[0] == '/':
		return path[1:]
	else:
		return path

if sys.platform == 'win32':
	import env.win32 as enviro
else:
	import env.linux as enviro

release_env = enviro.getEnvironment(Environment, False)
debug_env = enviro.getEnvironment(Environment, True)

# Defining directories
DESTDIR = os.path.abspath(getEnv('DESTDIR', '/'))
(bindir, libdir, extensions_dir, osgedit_datadir) = enviro.getPaths()
osgedit_icondir = os.path.join(osgedit_datadir, 'icons')
core_extension_dir = os.path.join(extensions_dir, 'core')
core_plugins_dir = os.path.join(core_extension_dir, 'plugins')

# Alternatives with DESTDIR prefixed
dest_libdir = os.path.join(DESTDIR, relative(libdir))
dest_bindir = os.path.join(DESTDIR, relative(bindir))
dest_core_plugins_dir = os.path.join(DESTDIR, relative(core_plugins_dir))
dest_core_extension_dir = os.path.join(DESTDIR, relative(core_extension_dir))
dest_osgedit_datadir = os.path.join(DESTDIR, relative(osgedit_datadir))

debug_env.Append(CPPDEFINES=['EXT_DIR='+quote('../extensions'), 'DATA_DIR='+quote('.'), 'ICON_DIR='+quote('../icons')])
release_env.Append(CPPDEFINES=['EXT_DIR=' + quote(extensions_dir), 'DATA_DIR=' + quote(osgedit_datadir), 'ICON_DIR=' + quote(osgedit_icondir)])

release_exports = dict(builder = BuilderUtility(release_env, False, '#/lib', dest_libdir, dest_core_plugins_dir, dest_bindir))
debug_exports = dict(builder  = BuilderUtility(debug_env, True, '#/libd', dest_libdir, dest_core_plugins_dir, dest_bindir))

SConscript(dirs='src', build_dir="release", duplicate=0, exports=release_exports)
SConscript(dirs='src', build_dir="debug", duplicate=0, exports=debug_exports)
Alias('debug', enviro.getAlias(True))
Alias('release', enviro.getAlias(False))
Default('release')

# Generic installations and alias
release_env.Install(dest_core_extension_dir, os.path.join('extensions', 'core', 'data'))
release_env.Install(dest_core_extension_dir, os.path.join('extensions', 'core', 'layouts'))
release_env.Install(dest_osgedit_datadir, os.path.join('src', 'osgedit.ui'))
release_env.Install(dest_osgedit_datadir, 'icons')
release_env.Alias('install', [dest_libdir, dest_bindir, dest_osgedit_datadir])
