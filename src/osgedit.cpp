#include <gtkmm/main.h>
#ifndef WIN32
# include <gtksourceviewmm/init.h>
#endif
#include <gtkmm/messagedialog.h>
#include <gui/mainwindow.h>
#include <sdk/osgedit.h>
#include <plugin/extensionregistry.h>

#include <glibmm/module.h>
#include <iostream>

#include <gui/logwindow.h>

using namespace osgedit;

int main(int argc, char *argv[]) {
	Gtk::Main app(&argc, &argv);
#ifndef WIN32
	gtksourceview::init();
#endif

	Log::instance()->addImpl(LogWindow::instance());
	ExtensionRegistry::instance()->load();

	OSGEdit::ArgVector args;
	for (int i=1; i < argc; i++) {
		args.push_back(argv[i]);
	}

	OSGEdit::start(args);
    return 0;
}

