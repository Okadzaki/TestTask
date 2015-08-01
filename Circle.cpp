
#include "Circle.h"
#include <math.h>
 void Circle::draw(WDraw &drawer) {

	 for (int i = 1; i <= 360; i++) {
		 Point2d prev(center.x() + radius*cos(i-1), center.y() + radius*sin(i-1));
		 Point2d current(center.x() + radius*cos(i), center.y() + radius*sin(i));
		 drawer.drawSegment(prev, current);
	 }
}

