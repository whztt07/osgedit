#ifndef __TOOL_PICK_H__
#define __TOOL_PICK_H__

#include "tool.h"
#include "export.h"

/**
 * OSGEdit tool that allows picking objects directly in the 3D area with the mouse
 */
class TOOLS_EXPORT ToolPick: public Tool {
public:
	virtual void on_button_press(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord);

	virtual void on_button_release(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord);

	virtual void on_mouse_movement(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord);

};

#endif
