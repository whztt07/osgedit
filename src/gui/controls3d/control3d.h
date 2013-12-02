#ifndef __CONTROL_3D_H__
#define __CONTROL_3D_H__

#include <osg/Matrixd>
#include <osg/Vec3>
#include <osg/Vec2>
#include <osg/Node>
#include <osg/Referenced>
#include <reflection/propertyreflection.h>


/**
 * A 3D widget interface for direct manipulation of objects on screen
 */
class Control3D: public osg::Referenced, public BaseVisitor {
public:
	/**
	 * Asks if a segment intersects with the widget (picks it)
	 * @param from Start of the segment
	 * @param to End of the segment
     * @param depth At which depth of the segment was found the control
     */
	virtual bool picked(osg::Vec3 from, osg::Vec3 to, double &depth) = 0;

	/**
	 * Mouse click
	 * @param coord 3D Position in the moment of the click
     * @param scoord Screen coordinate in the moment of the click
     */
	virtual void button_press(osg::Vec3 coord, osg::Vec2 scoord) = 0;

	/**
	 * Mouse button release
	 * @param coord 3D Position in the moment of the button release
     * @param scoord Screen coordinate in the moment of the button release
     */
	virtual void button_release(osg::Vec3 coord, osg::Vec2 scoord) = 0;

	/**
	 * Drag order
	 * @param coord Current 3D Position
     * @param scoord Current screen coordinate
     */
	virtual void drag(osg::Vec3 coord, osg::Vec2 scoord) = 0;

    /// OSG node that represents this widget
	virtual osg::Node *getNode() = 0;

	/**
	 * Re-read the reflection value
     */
	virtual void refresh() = 0;

	/**
	 * Set the local to world matrix
     */
	virtual void setLocalToWorld(const osg::Matrixd &localToWorld) {
		_localToWorld = localToWorld;
        refresh();
	}
protected:
	osg::Matrixd _localToWorld;
};

#endif//__CONTROL_3D_H__
