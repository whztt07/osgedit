#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include "scalecontrol3d.h"
#include <gui/controls3d/control3dfactory.h>

// All measures are in pixels
#define NPIXELS 100
#define BOX_WIDTH 5
#define PICK_WIDTH 20

ScaleControl3D::ScaleControl3D(): _axis(X) {
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
	osg::Box *box = 0;
	osg::ShapeDrawable *drawable = 0;

	box = new osg::Box(osg::Vec3(1,0,0)*NPIXELS, BOX_WIDTH);
	rot.makeRotate(osg::Vec3(0,0,1), osg::Vec3(1,0,0));
	box->setRotation(rot);
	drawable = new osg::ShapeDrawable(box);
	drawable->setColor(osg::Vec4(1,0,0,1));
	geode->addDrawable(drawable);

	box = new osg::Box(osg::Vec3(0,1,0)*NPIXELS, BOX_WIDTH);
	rot.makeRotate(osg::Vec3(0,0,1), osg::Vec3(0,1,0));
	box->setRotation(rot);
	drawable = new osg::ShapeDrawable(box);
	drawable->setColor(osg::Vec4(0,1,0,1));
	geode->addDrawable(drawable);

	box = new osg::Box(osg::Vec3(0,0,1)*NPIXELS, BOX_WIDTH);
    drawable = new osg::ShapeDrawable(box);
	drawable->setColor(osg::Vec4(0,0,1,1));
	geode->addDrawable(drawable);

	_autoTransform = new osg::AutoTransform();
    _autoTransform->setAutoScaleToScreen(true);

/*	_node->addChild(geode);
	_autoTransform->addChild(_node.get());*/
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

bool ScaleControl3D::picked(osg::Vec3 from, osg::Vec3 to, double &depth) {

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

void ScaleControl3D::button_press(osg::Vec3 coord, osg::Vec2 scoord) {
	_dragSource = coord;
	if (_target.valid()) {
		_scaleSource = _target->get();
	} else if (_targetM.valid()) {
		_matSource = _targetM->get();
	}
	_sourceMatrix = _node->getMatrix();
	CommandHistory::instance()->setMuted(true);
}

void ScaleControl3D::button_release(osg::Vec3 coord, osg::Vec2 scoord) {
    _node->setMatrix(_sourceMatrix);
	CommandHistory::instance()->setMuted(false);
    /// Refresh the values to generate propagation over the UI
	if (_target.valid()) {
		osg::Vec3d v = _target->get();
		_target->set( v );
	} else {
		osg::Matrix m = _targetM->get();
        _targetM->set(m);
	}
}

void ScaleControl3D::drag(osg::Vec3 coord, osg::Vec2 scoord) {
	osg::Vec3 dif = computeDelta(coord);
	osg::Matrix deltaMatrix = osg::Matrix::scale(osg::Vec3(1,1,1)+dif);
    _node->setMatrix(deltaMatrix * _sourceMatrix);
	if (_target.valid()) {
		osg::Vec3d newscale = _scaleSource + dif;
		_target->set( newscale );
	} else if (_targetM.valid()) {
		osg::Matrixd newmat = _matSource * osg::Matrix::scale(osg::Vec3(1,1,1)+dif);
        _targetM->set(newmat);
	}
}

osg::Vec3 ScaleControl3D::computeDelta(osg::Vec3 coord) {
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

void ScaleControl3D::apply(Vec3dProperty *prop) {
    _target = prop;
    refresh();
}

void ScaleControl3D::apply(MatrixdProperty *prop) {
    _targetM = prop;
    refresh();
}

void ScaleControl3D::refresh() {
	_node->setMatrix(_localToWorld);
}

REGISTER_CONTROL_3D(ScaleControl3D);
