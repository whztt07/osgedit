#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <reflection/reflectioncache.h>
#include <reflection/hierarchymanager.h>
#include <gui/mainwindow.h>
#include <gui/osgviewport.h>
#include <gui/logwindow.h>
#include <gui/statswindow.h>
#include <gui/configwindow.h>
#include <common/namingcontrol.h>
#include <common/clipboard.h>
#include <common/config.h>
#include <command/commandhistory.h>
#include <gui/historyviewer.h>
#include "osgedit.h"

#include <iostream>

using namespace osgedit;


osg::ref_ptr<ClassReflection> OSGEdit::_sceneRoot;

std::string OSGEdit::_fileName="";

sigc::signal<bool> OSGEdit::_signal_pre_new_scene; ///< New-scene pre callback
sigc::signal<void> OSGEdit::_signal_post_new_scene; ///< New-scene post callback
sigc::signal<bool> OSGEdit::_signal_pre_load_scene; ///< Load-scene pre callback
sigc::signal<void> OSGEdit::_signal_post_load_scene; ///< Load-scene post callback
sigc::signal<bool> OSGEdit::_signal_pre_save_scene; ///< Save-scene pre callback
sigc::signal<void> OSGEdit::_signal_post_save_scene; ///< Save-scene post callback

template <typename T>
	inline bool hasSlots(sigc::signal<T> &signal) {
        return signal.slots().begin() != signal.slots().end();
	}

/**
 * Finds a node recursively
 */
static ClassReflection *findNamedNodeRecursive(ClassReflection *ref, const std::string &name) {
	if (ref == NULL) {
		return NULL;
	}
	if (ref->getName() == name) {
		return ref;
	}
	for (unsigned i=0; i < ref->getNumChildren(); i++) {
		ClassReflection *found = findNamedNodeRecursive(ref->getChild(i), name);
		if (found != NULL) {
            return found;
		}
	}
    return NULL;
}

/**
 * Splits an string into a vector of strings
 * @param str The string to split
 * @param delim A string with the list of character delimiters
 * @return a vector of strings
 */
inline static std::vector<std::string> split(const std::string &str, const std::string &delim) {
	std::vector<std::string> result;
	size_t pos = 0;
	std::string tmp = str;
	while ( ( pos = tmp.find_first_of(delim) ) != tmp.npos ) {
		if ( pos > 0 ) {
			result.push_back( tmp.substr(0, pos) );
		}
		tmp = tmp.substr( pos + 1 );
	}

	if ( tmp.length() > 0 ) {
		result.push_back(tmp);
	}
    return result;
}


/**
 * @brief Finds a node by name.
 * Traverses all the scene graph searching for this name and returns
 * the first match.
 * @param node The name to look for
 */
ClassReflection *OSGEdit::findNamedNode(const std::string &node) {
    return findNamedNodeRecursive(_sceneRoot.get(), node);
}

/**
 * @brief Gets a node by path
 * @param path An unix-like path in the scene graph where folders and
 * files are object names.
 * @example getNodeFromPath("/root/group0/geode1/stateset2")
 */
ClassReflection *OSGEdit::getNodeFromPath(const std::string &path) {
	std::vector<std::string> items = split(path, "/");
	if (items.size() == 0) {
        return NULL;
	}
    // Check the root
	ClassReflection* current = _sceneRoot.get();
	if (current->getName() != items[0]) {
		return NULL;
	}
    // Check each subchild
	for (unsigned i=1; i < items.size(); i++) {
        ClassReflection *match = 0;
		for (unsigned child = 0; child < current->getNumChildren(); child++) {
			ClassReflection *childObj = current->getChild(child);
			if (childObj != NULL && childObj->getName() == items[i]) {
				match = childObj;
				break;
			}
		}
		if (match != NULL) {
            current = match;
		} else {
			return NULL;
		}
	}
	return current;
}

/**
 * Logs a message in the OSGEdit log window
 */
void OSGEdit::log(const std::string &msg, Log::Level level) {
	LOG(msg, level);
}

/**
 * Loads a new scene file in the editor
 * @param fileName The name of the file to load
 */
void OSGEdit::loadSceneFile(const std::string &fileName) {
	if (!hasSlots(_signal_pre_load_scene)
		|| _signal_pre_load_scene.emit()) {
		char *previous=setlocale(LC_ALL,NULL);
		setlocale(LC_ALL,"C");
		osg::Node *node = osgDB::readNodeFile(fileName);
		NamingControl::rename(node);
		setlocale(LC_ALL,previous);

		ClassReflection *reflected = reflect(node);

		if (reflected != NULL) {
			_sceneRoot = reflected;
			MainWindow::instance()->setSceneRoot(node);
			MainWindow::instance()->setTitleFileName(fileName);
			_fileName=fileName;
			_signal_post_load_scene.emit();
		}
	}
}

/**
 * Saves the scene file being edited
 * @param fileName The name of the file to save to
 */
void OSGEdit::saveSceneFile(const std::string &fileName) {
	if (!hasSlots(_signal_pre_save_scene)
		|| _signal_pre_save_scene.emit()) {
		osg::Node *node = dynamic_cast<osg::Node*>(_sceneRoot->getObject());
		char *previous=setlocale(LC_ALL,NULL);
		setlocale(LC_ALL,"C");
		osgDB::writeNodeFile(*node, fileName);
		setlocale(LC_ALL,previous);
		_fileName=fileName;
		MainWindow::instance()->setTitleFileName(fileName);
		_signal_post_save_scene.emit();
	}
}

/**
 * Returns the file name of the scene being edited, or ""
 */
std::string OSGEdit::getSceneFileName() {
    return _fileName;
}

/**
 * Erases the current scene and creates a new one
 */
void OSGEdit::newScene() {
	if (!hasSlots(_signal_pre_new_scene)
		|| _signal_pre_new_scene.emit()) {
		osg::Group *newRoot = new osg::Group;
		newRoot->setName("root");
		_sceneRoot = reflect(newRoot);
		_fileName = "";
		MainWindow::instance()->setSceneRoot(newRoot);
		MainWindow::instance()->setTitleFileName("");
        _signal_post_new_scene.emit();
	}
}

/**
 * Un-do the last command
 */
void OSGEdit::undo() {
	try {
        CommandHistory::instance()->undo();
	} catch (CommandHistory::NothingToUndoException &e) {
		Gtk::MessageDialog dialog("There is nothing to undo.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
	}
}

/**
 * Re-do the last undone command
 */
void OSGEdit::redo() {
	try {
        CommandHistory::instance()->redo();
	} catch (CommandHistory::NothingToRedoException &e) {
		Gtk::MessageDialog dialog("There is nothing to redo.", false, Gtk::MESSAGE_WARNING);
		dialog.run();
	}
}

/**
 * Show the history viewer
 */
void OSGEdit::showHistory() {
    new HistoryViewer();
}

/**
 * Reflect an osg Object to convert it to the reflection SDK
 */
ClassReflection *OSGEdit::reflect(osg::Object *obj) {
    return ReflectionCache::instance()->reflect(obj);
}

/**
 * Automatically names cref and its children if it has an empty name
 */
void OSGEdit::autoName(ClassReflection *cref) {
	NamingControl::rename(cref);
}

/**
 * Get the contents of the clipboard, the last copied thing
 */
ClassReflection* OSGEdit::getClipboardContents() {
	return Clipboard::get();
}

/**
 * Change the contents of the clipboard
 */
void OSGEdit::setClipboardContents(ClassReflection *cref) {
	Clipboard::set(cref);
}

/**
 * Center the camera on one 3D sphere
 */
void OSGEdit::centerCamera(const osg::BoundingSphere &bound) {
    OSGViewport::instance()->getActiveCameraManager()->resetToBound(bound);
}

/**
 * Show the log messages window
 */
void OSGEdit::showLog() {
	LogWindow::instance()->show();
}

/**
 * Show the configuration preferences
 */
void OSGEdit::showConfiguration() {
	ConfigWindow::instance()->show();
}

/**
 * Quit the application
 */
void OSGEdit::quit() {
	Gtk::Main::quit();
	Config::instance()->save();
}

static bool quitAdapter(GdkEventAny*) {
	OSGEdit::quit();
    return false;
}

/**
 * Called by the main program to connect everything
 */
void OSGEdit::start(const ArgVector &args) {
	try {
		MainWindow *window = MainWindow::instance();
		window->signal_delete_event().connect(sigc::ptr_fun(&quitAdapter));
		if (args.size()) {
            loadSceneFile(args[0]);
		} else {
            newScene();
		}
		osgedit::Config::instance()->load();
		Gtk::Main::run();
	} catch(Glib::FileError &e) {
		Gtk::MessageDialog d("Can not start osgedit because the <b>osgedit.ui</b> file is missing: "+e.what(), true, Gtk::MESSAGE_ERROR);
        d.run();
	} catch(Glib::MarkupError &) {
		Gtk::MessageDialog d("Can not start osgedit because the <b>osgedit.ui</b> file is corrupted", true, Gtk::MESSAGE_ERROR);
        d.run();
	}

}

/**
 * Change the active tool
 * @param tool the new active tool
 */
void OSGEdit::setActiveTool(Tool *tool) {
	OSGViewport::instance()->setActiveTool(tool);
}

/**
 * Selects each instance of cref in the graph
 */
void OSGEdit::select(ClassReflection *cref) {
	MainWindow::instance()->getTree().select(cref);
}

/**
 * Signal called every time that an object is added
 * The first item is the parent and the second the child
 */
sigc::signal<void, ClassReflection*, ClassReflection*> &OSGEdit::signal_add_child() {
	return HierarchyManager::instance()->signal_add_child;
}

/**
 * Signal called every time that an object is removed
 * The first item is the parent and the second the child
 */
sigc::signal<void, ClassReflection*, ClassReflection*> &OSGEdit::signal_del_child() {
	return HierarchyManager::instance()->signal_del_child;
}

/**
 * Signal called when some command is executed
 */
sigc::signal<void> &OSGEdit::signal_do() {
	return CommandHistory::instance()->signal_do;
}

/**
 * Signal called when some command is un-executed
 */
sigc::signal<void> &OSGEdit::signal_undo() {
	return CommandHistory::instance()->signal_undo;
}
/**
 * Signal called when some command is re-executed
 */
sigc::signal<void> &OSGEdit::signal_redo() {
	return CommandHistory::instance()->signal_redo;
}

/**
 * Signal called when the command stack is deleted
 */
sigc::signal<void> &OSGEdit::signal_clear() {
	return CommandHistory::instance()->signal_clear;
}

/**
 * Signal called on do, undo, and redo cases. Only to avoid connecting to the three signals
 */
sigc::signal<void> &OSGEdit::signal_command() {
	return CommandHistory::instance()->signal_command;
}

/**
 * Show the properties of the edited scene
 */
void OSGEdit::showSceneProperties() {
	osg::Node *root = dynamic_cast<osg::Node*>(_sceneRoot->getObject());
	if (root != NULL) {
		new StatsWindow(root);
	} else {
		Gtk::MessageDialog d("Can not show statistics, you are not editing a node tree", true, Gtk::MESSAGE_ERROR);
		d.run();
	}
}

/**
 * It checks if the current scene has been modified
 */
bool OSGEdit::sceneModified() {
	return CommandHistory::instance()->hasExecutions();
}
