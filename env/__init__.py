import os

class BuilderUtility:
	def __init__(self, env, isDebug, build_libdir, inst_libdir, inst_plugdir, inst_bindir):
		self.env = env
		self.isDebug = isDebug
		self.build_libdir = build_libdir
		self.inst_libdir = inst_libdir
		self.inst_plugdir = inst_plugdir
		self.inst_bindir = inst_bindir

	def library(self, name, export_define, libs, sources):
		lib_env = self.env.Copy()
		lib_env.Append(CPPDEFINES=export_define)
		lib_env.Append(LIBS=libs)
		shlib = lib_env.SharedLibrary(os.path.join(self.build_libdir, name), sources)
		if not self.isDebug:
			lib_env.Install(self.inst_libdir, shlib[0])

	def plugin(self, name, libs, sources):
		plugin_env = self.env.Copy()
		plugin_env['SHLIBPREFIX']=''
		plugin_env.Append(LIBS=libs)
		if self.isDebug:
			plugin = plugin_env.SharedLibrary('#/extensions/core/plugins/'+name, sources)
			plugin_env.Alias('debug:'+name, plugin)
		else:
			plugin = plugin_env.SharedLibrary(name, sources)
			plugin_env.Install(self.inst_plugdir, plugin[0])
			plugin_env.Alias(name, plugin)

	def program(self, name, libs, sources):
		prog_env = self.env.Copy()
		prog_env.Append(LIBS=libs)
		program = prog_env.Program(name, sources)
		if not self.isDebug:
			prog_env.Install(self.inst_bindir, program)
