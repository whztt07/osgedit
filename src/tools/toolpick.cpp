#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include <sdk/osgedit.h>
#include "toolpick.h"


#include <iostream>
void ToolPick::on_button_press(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord){
	osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(from, to);
	osgUtil::IntersectionVisitor ivisitor(intersector.get());
	ClassReflection *root = osgedit::OSGEdit::getSceneRoot();
    if (root == NULL) return;
	osg::Node *rootNode = dynamic_cast<osg::Node*> (root->getObject());
	if (rootNode != NULL) {
		rootNode->accept(ivisitor);
	}
	if (intersector->containsIntersections()) {
		osgUtil::LineSegmentIntersector::Intersection intersection = intersector->getFirstIntersection();
		if (intersection.drawable != NULL) {
            ClassReflection *cref = osgedit::OSGEdit::reflect(intersection.drawable.get());
			osgedit::OSGEdit::select(cref);
		}
	}
}

void ToolPick::on_button_release(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord) {

}

void ToolPick::on_mouse_movement(const osg::Vec3f& from, const osg::Vec3f &to, const osg::Vec2f &scoord) {

}
