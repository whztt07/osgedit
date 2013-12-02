#ifndef __ROTATION_CONTROL_3D_H__
#define __ROTATION_CONTROL_3D_H__

#include <osg/MatrixTransform>
#include <osg/AutoTransform>
#include <gui/controls3d/control3d.h>

typedef TemplateProperty<osg::Quat> QuatProperty;
typedef TemplateProperty<osg::Matrixd> MatrixdProperty;

/**
 * 3D control to change position of things
 */
class RotationControl3D: public Control3D,
	public Visitor< QuatProperty >,
	public Visitor< MatrixdProperty >
{
public:
	RotationControl3D();

	bool picked(osg::Vec3 from, osg::Vec3 to, double &depth);

	void button_press(osg::Vec3 coord, osg::Vec2 scoord);

	void button_release(osg::Vec3 coord, osg::Vec2 scoord);

	void drag(osg::Vec3 coord, osg::Vec2 scoord);

	osg::Node *getNode() { return _node.get(); }

	void apply(QuatProperty *prop);

	void apply(MatrixdProperty *prop);

    void refresh();

protected:
	osg::Quat computeDelta(osg::Vec2 scoord);
private:
	osg::ref_ptr<osg::MatrixTransform> _node; //< Visible node
	osg::ref_ptr<osg::MatrixTransform> _colliders; ///< Colliders for picking
	osg::ref_ptr<osg::AutoTransform> _autoTransform; ///< Automatic to-screen transformation
	osg::Vec2 _dragSource; ///< Mouse position where the drag begins
	osg::Quat _rotSource; ///< Rotation when the drag begins
	osg::Matrixd _matSource; ///< Target matrix when the drag begins
	osg::Matrix _sourceMatrix; ///< Node matrix at drag begin
	typedef enum {
		X,
		Y,
		Z
	} Axis;
    Axis _axis; ///< Rotation axis

	osg::ref_ptr<QuatProperty> _target; ///< Property being controlled by this 3D control
	osg::ref_ptr<MatrixdProperty> _targetM; ///< Property being controlled by this 3D control
};

#endif//__ROTATION_CONTROL_3D_H__
