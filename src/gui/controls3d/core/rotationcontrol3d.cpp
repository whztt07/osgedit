#include <math.h>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include <osgDB/ReadFile>
#include <osg/LineWidth>
#include "rotationcontrol3d.h"
#include <gui/controls3d/control3dfactory.h>

#ifndef M_PI
#define M_PI 3.141592654
#endif

// Resolution of the curve
#define RING_VERTICES 32

// All measures are in pixels
#define NPIXELS 100

RotationControl3D::RotationControl3D(): _axis(X) {
	_node = new osg::MatrixTransform;
	_node->getOrCreateStateSet()->setAttributeAndModes(new osg::LineWidth(2.0f), osg::StateAttribute::ON);
	osg::Geode *geode = new osg::Geode;
	osg::Geometry *geom = new osg::Geometry;
	osg::Vec3Array *vertices = new osg::Vec3Array();
	osg::Vec4Array *colors = new osg::Vec4Array();

	for (unsigned i=0; i <= RING_VERTICES; i++) {
        double angle = i * 2 * M_PI / RING_VERTICES;
		vertices->push_back(osg::Vec3(0, NPIXELS*sinf(angle), NPIXELS*cosf(angle)));
		colors->push_back(osg::Vec4(1, 0, 0, 1));
	}
    int strip_size = vertices->size();
	for (unsigned i=0; i <= RING_VERTICES; i++) {
        double angle = i * 2 * M_PI / RING_VERTICES;
		vertices->push_back(osg::Vec3(NPIXELS*sinf(angle), 0, NPIXELS*cosf(angle)));
		colors->push_back(osg::Vec4(0, 1, 0, 1));
	}
	for (unsigned i=0; i <= RING_VERTICES; i++) {
        double angle = i * 2 * M_PI / RING_VERTICES;
		vertices->push_back(osg::Vec3(NPIXELS*sinf(angle), NPIXELS*cosf(angle), 0));
		colors->push_back(osg::Vec4(0, 0, 1, 1));
	}

	geom->setVertexArray(vertices);
	geom->setColorArray(colors);
    geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	geom->addPrimitiveSet(new osg::DrawArrays(GL_LINE_STRIP, 0, strip_size));
	geom->addPrimitiveSet(new osg::DrawArrays(GL_LINE_STRIP, strip_size, strip_size));
	geom->addPrimitiveSet(new osg::DrawArrays(GL_LINE_STRIP, strip_size*2, strip_size));
	geode->addDrawable(geom);

	_autoTransform = new osg::AutoTransform();
    _autoTransform->setAutoScaleToScreen(true);

	_autoTransform->addChild(geode);

    _node->addChild(_autoTransform.get());

	char *previous=setlocale(LC_ALL,NULL);
	setlocale(LC_ALL,"C");
	osg::Node *colliders_real = osgDB::readNodeFile("rotation_colliders.osg");
	setlocale(LC_ALL,previous);

	_colliders=new osg::MatrixTransform();
	_colliders->addChild(colliders_real);
}

bool RotationControl3D::picked(osg::Vec3 from, osg::Vec3 to, double &depth) {

	osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(from, to);
	osgUtil::IntersectionVisitor ivisitor(intersector.get());

	osg::Vec3f scale = _autoTransform->getScale() * NPIXELS;
	_colliders->setMatrix( osg::Matrix::scale(scale) * _node->getMatrix() );
	_colliders->accept(ivisitor);

	_colliders->accept(ivisitor);

	if (intersector->containsIntersections()) {
		osgUtil::LineSegmentIntersector::Intersection intersection = intersector->getFirstIntersection();
		depth = intersection.ratio;
		for (unsigned i=0; i < intersection.nodePath.size(); i++) {
			if (intersection.nodePath[i]->getName() == "X") {
                _axis = X;
			} else if (intersection.nodePath[i]->getName() == "Y") {
                _axis = Y;
			} else if (intersection.nodePath[i]->getName() == "Z") {
                _axis = Z;
			}
		}
		return true;
	} else {
        return false;
	}
}

void RotationControl3D::button_press(osg::Vec3 coord, osg::Vec2 scoord) {
	_dragSource = scoord;
	if (_target.valid()) {
		_rotSource = _target->get();
	} else if (_targetM.valid()) {
        _matSource = _targetM->get();
	}
	_sourceMatrix = _node->getMatrix();
	CommandHistory::instance()->setMuted(true);
}

void RotationControl3D::button_release(osg::Vec3 coord, osg::Vec2 scoord) {
    _node->setMatrix(_sourceMatrix);
	CommandHistory::instance()->setMuted(false);
    /// Refresh the values to generate propagation over the UI
	if (_target.valid()) {
		osg::Quat q = _target->get();
		_target->set( q );
	} else {
		osg::Matrix m = _targetM->get();
        _targetM->set(m);
	}
}

void RotationControl3D::drag(osg::Vec3 coord, osg::Vec2 scoord) {
	osg::Quat dif = computeDelta(scoord);
	osg::Matrix deltaMatrix = osg::Matrix::rotate(dif);
    _node->setMatrix(deltaMatrix * _sourceMatrix);
	if (_target.valid()) {
		osg::Quat newrot = _rotSource * dif;
		 _target->set( newrot );
	} else if (_targetM.valid()) {
		osg::Matrix newmat = _matSource * osg::Matrix::rotate(dif);
        _targetM->set(newmat);
	}
}

osg::Quat RotationControl3D::computeDelta(osg::Vec2 scoord) {
	osg::Vec2 dif = scoord - _dragSource;

    double amount = dif.y()*10;

	osg::Vec3 axis;
	switch(_axis) {
	case X: axis.set(1,0,0); break;
	case Y: axis.set(0,1,0); break;
	case Z: axis.set(0,0,1); break;
	}

	osg::Quat delta(amount, axis);
	return delta;
}

void RotationControl3D::apply(QuatProperty *prop) {
    _target = prop;
    refresh();
}

void RotationControl3D::apply(MatrixdProperty *prop) {
    _targetM = prop;
    refresh();
}

void RotationControl3D::refresh() {
	_node->setMatrix(_localToWorld);
}

REGISTER_CONTROL_3D(RotationControl3D);
