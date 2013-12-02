#ifndef __TOOL_H__
#define __TOOL_H__

#include <osg/Vec2f>
#include <osg/Vec3f>

/**
 * A tool is a class that can manipulate the scene
 */
class Tool: public osg::Referenced {
public:
	/**
	 * Mouse button_press_event
     * @param from Start of segment in 3D space relative to the mouse coordinates
     * @param to End of segment in 3D space relative to the mouse coordinates
     * @param scoord Screen coordinate in the moment of the click
     */
	virtual void on_button_press(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord) = 0;

	/**
	 * Mouse button release event
     * @param from Start of segment in 3D space relative to the mouse coordinates
     * @param to End of segment in 3D space relative to the mouse coordinates
     * @param scoord Screen coordinate in the moment of the button release
     */
	virtual void on_button_release(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord) = 0;

	/**
	 * Mouse movement event
     * @param from Start of segment in 3D space relative to the mouse coordinates
     * @param to End of segment in 3D space relative to the mouse coordinates
     * @param scoord Current screen coordinate
     */
	virtual void on_mouse_movement(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord) = 0;

};

#endif//__TOOL_H__
