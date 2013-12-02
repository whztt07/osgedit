#ifndef __OSGEDIT_H__
#define __OSGEDIT_H__

#define VERSION "0.9"

#include <osg/BoundingSphere>
#include <reflection/classreflection.h>
#include <common/selection.h>
#include <tools/tool.h>
#include <common/log.h>
#include "export.h"

namespace osgedit {

/**
 * Main utility class. Provides access to the osgedit features.
 * Implements the Facade design pattern
 */
class SDK_EXPORT OSGEdit {
public:
	typedef std::vector<std::string> ArgVector;

	/**
	 * Called by the main program to connect everything
	 *
     * @param args The arguments received from commandline
     */
	static void start(const ArgVector &args);

	/**
	 * Quit the application
     */
	static void quit();

	/**
	 * Gets the active selection made in the scene
     */
	inline static Selection *getSelection() { return Selection::instance(); }

	/**
	 * Selects each instance of cref in the graph
     */
	static void select(ClassReflection *cref);

	/**
	 * Gets the scene root item
     */
	inline static ClassReflection *getSceneRoot() { return _sceneRoot.get(); }

	/**
	 * @brief Finds a node by name.
	 * Traverses all the scene graph searching for this name and returns
	 * the first match.
     * @param node The name to look for
     */
	static ClassReflection *findNamedNode(const std::string &node);

	/**
	 * @brief Gets a node by path
	 * @param path An unix-like path in the scene graph where folders and
	 * files are object names.
     * @example getNodeFromPath("/root/group0/geode1/stateset2")
     */
    static ClassReflection *getNodeFromPath(const std::string &path);

	/**
	 * Returns the OSGEdit version
     */
	static std::string getVersion() { return VERSION; }

	/**
	 * Logs a message in the OSGEdit log window
     */
	static void log(const std::string &msg, Log::Level level);

	/**
	 * Show the log messages window
     */
	static void showLog();

	/**
	 * Loads a new scene file in the editor
     * @param fileName The name of the file to load from
     */
	static void loadSceneFile(const std::string &fileName);

	/**
	 * Saves the scene file being edited
     * @param fileName The name of the file to save to
     */
    static void saveSceneFile(const std::string &fileName);

	/**
	 * Returns the file name of the scene being edited, or ""
     */
	static std::string getSceneFileName();


	/**
	 * Erases the current scene and creates a new one
     */
	static void newScene();

	/**
	 * Un-do the last command
     */
	static void undo();

	/**
	 * Re-do the last undone command
     */
    static void redo();

	/**
	 * Show the history viewer
     */
	static void showHistory();

	/**
	 * Show the properties of the edited scene
     */
    static void showSceneProperties();

	/**
	 * Reflect an osg Object to convert it to the reflection SDK
     */
	static ClassReflection *reflect(osg::Object *obj);

	/**
	 * Automatically names cref (and its children) if it has an empty name
     * @param cref The graph piece to name automatically
     */
	static void autoName(ClassReflection *cref);

	/**
	 * Get the contents of the clipboard, the last copied thing
     */
	static ClassReflection* getClipboardContents();

	/**
	 * Change the contents of the clipboard
     * @param cref The new contents of the clipboard
     */
    static void setClipboardContents(ClassReflection *cref);

	/**
	 * Center the camera on one 3D sphere
     * @param bound A 3D sphere to focus in the camera
	 */
	static void centerCamera(const osg::BoundingSphere &bound);

	/**
	 * Show the configuration preferences
     */
	static void showConfiguration();

	/**
	 * Change the active tool
     * @param tool the new active tool
     */
    static void setActiveTool(Tool *tool);

	/**
	 * It checks if the current scene has been modified
     */
	static bool sceneModified();

	/////// SIGNALS //////

	/**
	 * Signal called every time that an object is added
	 * The first item is the parent and the second the child
     */
	sigc::signal<void, ClassReflection*, ClassReflection*> &signal_add_child();

	/**
	 * Signal called every time that an object is removed
	 * The first item is the parent and the second the child
     */
	sigc::signal<void, ClassReflection*, ClassReflection*> &signal_del_child();

	/**
	 * Signal called when some command is executed
	 */
	sigc::signal<void> &signal_do();

	/**
	 * Signal called when some command is un-executed
     */
	sigc::signal<void> &signal_undo();

	/**
	 * Signal called when some command is re-executed
     */
	sigc::signal<void> &signal_redo();

	/**
	 * Signal called when the command stack is deleted
     */
	sigc::signal<void> &signal_clear();

	/**
	 * Signal called on do, undo, and redo cases. Only to avoid connecting to the three signals
     */
	sigc::signal<void> &signal_command();

	/**
	 * Signal executed before a new-scene command
     * @return The signal handler must return true if it allows the command, or false to cancel it
     */
	sigc::signal<bool> &signal_pre_new_scene() { return _signal_pre_new_scene; }

	/**
	 * Signal executed after a new-scene command
     */
	sigc::signal<void> &signal_post_new_scene() { return _signal_post_new_scene; }

	/**
	 * Signal executed before an open-scene command
     * @return The signal handler must return true if it allows the command, or false to cancel it
     */
	sigc::signal<bool> &signal_pre_load_scene() { return _signal_pre_load_scene; }

	/**
	 * Signal executed after an open-scene command
     */
	sigc::signal<void> &signal_post_load_scene() { return _signal_post_load_scene; }

	/**
	 * Signal executed before a save-scene command
     * @return The signal handler must return true if it allows the command, or false to cancel it
     */
	sigc::signal<bool> &signal_pre_save_scene() { return _signal_pre_save_scene; }

	/**
	 * Signal executed after a save-scene command
     */
	sigc::signal<void> &signal_post_save_scene() { return _signal_post_save_scene; }

private:
	static osg::ref_ptr<ClassReflection> _sceneRoot; ///< The scene root
	static std::string _fileName; ///< Name of the edited file
	static sigc::signal<bool> _signal_pre_new_scene; ///< New-scene pre callback
	static sigc::signal<void> _signal_post_new_scene; ///< New-scene post callback
	static sigc::signal<bool> _signal_pre_load_scene; ///< Load-scene pre callback
	static sigc::signal<void> _signal_post_load_scene; ///< Load-scene post callback
	static sigc::signal<bool> _signal_pre_save_scene; ///< Save-scene pre callback
	static sigc::signal<void> _signal_post_save_scene; ///< Save-scene post callback

};

}//namespace osgedit

#endif//__OSGEDIT_H__
