
#include "Square.h"


void Square::draw(WDraw &drawer) {
	Point2d cournerSecond(points[0].x, points[1].y), cournerFour(points[1].x, points[0].y);
	drawer.drawSegment(points[0], cournerSecond);
	drawer.drawSegment(cournerSecond, points[1]);
	drawer.drawSegment(points[1], cournerFour);
	drawer.drawSegment(cournerFour, points[0]);

};
