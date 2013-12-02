#ifndef __SCALE_CONTROL_3D_H__
#define __SCALE_CONTROL_3D_H__

#include <osg/MatrixTransform>
#include <osg/AutoTransform>
#include <gui/controls3d/control3d.h>

typedef TemplateProperty<osg::Vec3d> Vec3dProperty;
typedef TemplateProperty<osg::Matrixd> MatrixdProperty;

/**
 * 3D control to change position of things
 */
class ScaleControl3D: public Control3D,
	public Visitor< Vec3dProperty >,
	public Visitor< MatrixdProperty >
{
public:
	ScaleControl3D();

	bool picked(osg::Vec3 from, osg::Vec3 to, double &depth);

	void button_press(osg::Vec3 coord, osg::Vec2 scoord);

	void button_release(osg::Vec3 coord, osg::Vec2 scoord);

	void drag(osg::Vec3 coord, osg::Vec2 scoord);

	osg::Node *getNode() { return _node.get(); }

	void apply(Vec3dProperty *prop);

	void apply(MatrixdProperty *prop);

    void refresh();
protected:
	osg::Vec3 computeDelta(osg::Vec3 coord);
private:
	osg::ref_ptr<osg::MatrixTransform> _node; //< Visible node
	osg::ref_ptr<osg::MatrixTransform> _colliders; ///< Colliders for picking
	osg::ref_ptr<osg::AutoTransform> _autoTransform; ///< Automatic to-screen transformation
	osg::ref_ptr<osg::Drawable> _xCollider; ///< X axis collider
	osg::ref_ptr<osg::Drawable> _yCollider; ///< Y axis collider
	osg::ref_ptr<osg::Drawable> _zCollider; ///< X axis collider
	osg::ref_ptr<osg::Drawable> _allCollider; ///< Any axis collider
	osg::Vec3 _dragSource; ///< Position where the drag begins
	osg::Vec3 _scaleSource; ///< Scale when the drag begins
	osg::Matrixd _matSource; ///< Target Matrix when the drag begins
	osg::Matrix _sourceMatrix; ///< Node matrix at drag begin
	typedef enum {
		X,
		Y,
		Z,
        ALL
	} Axis;
    Axis _axis; ///< Axis of movement

	osg::ref_ptr<Vec3dProperty> _target; ///< Property being controlled by this 3D control
	osg::ref_ptr<MatrixdProperty> _targetM; ///< Property being controlled by this 3D control
};

#endif//__SCALE_CONTROL_3D_H__
