#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include "positioncontrol3d.h"
#include <command/commandhistory.h>
#include <gui/controls3d/control3dfactory.h>

// All measures are in pixels
#define NPIXELS 100
#define ARROW_WIDTH 5
#define ARROW_LENGTH 10
#define PICK_WIDTH 20

PositionControl3D::PositionControl3D(): _axis(X) {
	_node = new osg::MatrixTransform;
	osg::Geode *geode = new osg::Geode;
	osg::Geometry *geom = new osg::Geometry;
	osg::Vec3Array *vertices = new osg::Vec3Array();
	vertices->push_back(osg::Vec3(0,0,0)*NPIXELS);
	vertices->push_back(osg::Vec3(1,0,0)*NPIXELS);
	vertices->push_back(osg::Vec3(0,0,0)*NPIXELS);
	vertices->push_back(osg::Vec3(0,1,0)*NPIXELS);
	vertices->push_back(osg::Vec3(0,0,0)*NPIXELS);
	vertices->push_back(osg::Vec3(0,0,1)*NPIXELS);

	osg::Vec4Array *colors = new osg::Vec4Array();
	colors->push_back(osg::Vec4(1,0,0,1));
	colors->push_back(osg::Vec4(1,0,0,1));
	colors->push_back(osg::Vec4(0,1,0,1));
	colors->push_back(osg::Vec4(0,1,0,1));
	colors->push_back(osg::Vec4(0,0,1,1));
	colors->push_back(osg::Vec4(0,0,1,1));

	geom->setVertexArray(vertices);
	geom->setColorArray(colors);
    geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	geom->addPrimitiveSet(new osg::DrawArrays(GL_LINES, 0, vertices->size()));
	geode->addDrawable(geom);

	osg::Quat rot;
	osg::Cone *cone = 0;
	osg::ShapeDrawable *drawable = 0;

	cone = new osg::Cone(osg::Vec3(1,0,0)*NPIXELS, ARROW_WIDTH, ARROW_LENGTH);
	rot.makeRotate(osg::Vec3(0,0,1), osg::Vec3(1,0,0));
	cone->setRotation(rot);
	drawable = new osg::ShapeDrawable(cone);
	drawable->setColor(osg::Vec4(1,0,0,1));
	geode->addDrawable(drawable);

	cone = new osg::Cone(osg::Vec3(0,1,0)*NPIXELS, ARROW_WIDTH, ARROW_LENGTH);
	rot.makeRotate(osg::Vec3(0,0,1), osg::Vec3(0,1,0));
	cone->setRotation(rot);
	drawable = new osg::ShapeDrawable(cone);
	drawable->setColor(osg::Vec4(0,1,0,1));
	geode->addDrawable(drawable);

	cone = new osg::Cone(osg::Vec3(0,0,1)*NPIXELS, ARROW_WIDTH, ARROW_LENGTH);
    drawable = new osg::ShapeDrawable(cone);
	drawable->setColor(osg::Vec4(0,0,1,1));
	geode->addDrawable(drawable);

	_autoTransform = new osg::AutoTransform();
    _autoTransform->setAutoScaleToScreen(true);

	_autoTransform->addChild(geode);
	_node->addChild(_autoTransform.get());

	osg::Geode *colliders = new osg::Geode();

	_xCollider = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.6, 0, 0)*NPIXELS, NPIXELS, PICK_WIDTH, PICK_WIDTH));
	colliders->addDrawable(_xCollider.get());

	_yCollider = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0.6, 0)*NPIXELS, PICK_WIDTH, NPIXELS, PICK_WIDTH));
	colliders->addDrawable(_yCollider.get());

	_zCollider = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0, 0, 0.6)*NPIXELS, PICK_WIDTH, PICK_WIDTH, NPIXELS));
	colliders->addDrawable(_zCollider.get());

	_allCollider = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0,0,0),PICK_WIDTH,PICK_WIDTH,PICK_WIDTH));
	colliders->addDrawable(_allCollider.get());

	_colliders=new osg::MatrixTransform();
	_colliders->addChild(colliders);
}

bool PositionControl3D::picked(osg::Vec3 from, osg::Vec3 to, double &depth) {

	osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(from, to);
	osgUtil::IntersectionVisitor ivisitor(intersector.get());
	osg::Vec3f scale = _autoTransform->getScale();
	_colliders->setMatrix( osg::Matrix::scale(scale) * _node->getMatrix() );
	_colliders->accept(ivisitor);

	if (intersector->containsIntersections()) {
		osgUtil::LineSegmentIntersector::Intersection intersection = intersector->getFirstIntersection();
		depth = intersection.ratio;
		if (intersection.drawable == _xCollider) {
            _axis = X;
		} else if (intersection.drawable == _yCollider) {
            _axis = Y;
		} else if (intersection.drawable == _zCollider) {
            _axis = Z;
		} else if (intersection.drawable == _allCollider) {
            _axis = ALL;
		}
		return true;
	} else {
        return false;
	}
}

void PositionControl3D::button_press(osg::Vec3 coord, osg::Vec2 scoord) {
	_dragSource = coord;
	if (_target.valid()) {
		_posSource = _target->get();
	} else if (_target4.valid()) {
		osg::Vec4f v = _target4->get();
		_posSource.set(v.x(), v.y(), v.z());
	} else if (_targetM.valid()) {
		_matSource = _targetM->get();
	}
	_sourceMatrix = _node->getMatrix();
	CommandHistory::instance()->setMuted(true);
}

void PositionControl3D::button_release(osg::Vec3 coord, osg::Vec2 scoord) {
	CommandHistory::instance()->setMuted(false);
    /// Refresh the values to generate propagation over the UI
	if (_target.valid()) {
		osg::Vec3d v = _target->get();
		_target->set( v );
	} else if (_target4.valid()) {
		osg::Vec4f v = _target4->get();
        _target4->set(v);
	} else if (_targetM.valid()) {
		osg::Matrix m = _targetM->get();
        _targetM->set(m);
	}
}

void PositionControl3D::drag(osg::Vec3 coord, osg::Vec2 scoord) {
	osg::Vec3 dif = computeDelta(coord);
	osg::Matrix deltaMatrix = osg::Matrix::translate(dif);
    _node->setMatrix(deltaMatrix * _sourceMatrix);
    _colliders->setMatrix(deltaMatrix * _sourceMatrix);
	if (_target.valid()) {
		osg::Vec3d newpos = _posSource + dif;
		_target->set( newpos );
	} else if (_target4.valid()) {
		osg::Vec3d newpos = _posSource + dif;
		osg::Vec4f vec4 = _target4->get();
        vec4.x() = newpos.x();
        vec4.y() = newpos.y();
		vec4.z() = newpos.z();
        _target4->set(vec4);
	} else if (_targetM.valid()) {
		osg::Matrixd newmat = _matSource * osg::Matrixd::translate(dif);
		_targetM->set(newmat);
	}
}

osg::Vec3 PositionControl3D::computeDelta(osg::Vec3 coord) {
	osg::Vec3 dif = coord - _dragSource;

    // Now we mask it
	switch (_axis) {
	case X: dif = osg::Vec3(dif.x(), 0, 0); break;
	case Y: dif = osg::Vec3(0, dif.y(), 0); break;
	case Z: dif = osg::Vec3(0, 0, dif.z()); break;
	case ALL: break;
	}
    return dif;
}

void PositionControl3D::apply(Vec3dProperty *prop) {
    _target = prop;
    refresh();
}

void PositionControl3D::apply(Vec4fProperty *prop) {
    _target4 = prop;
    refresh();
}

void PositionControl3D::apply(MatrixdProperty *prop) {
    _targetM = prop;
    refresh();
}

void PositionControl3D::refresh() {
	osg::Vec3 position;
	if (_target.valid()) {
		position = _target->get();
	} else if (_target4.valid()) {
		osg::Vec4f v = _target4->get();
		position.set(v.x(), v.y(), v.z());
	} else if (_targetM.valid()) {
		position = _targetM->get().getTrans();
	}
	_node->setMatrix(osg::Matrix::translate(position) * _localToWorld );
	_colliders->setMatrix(_node->getMatrix());
}

REGISTER_CONTROL_3D(PositionControl3D);
