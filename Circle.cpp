
#include "Circle.h"
#include <math.h>
 void Circle::draw(WDraw &drawer) {

	 std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();

	 for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		 drawer.drawSegment(it->first, it->second);
	 }
}

 std::pair<Point2d, Point2d> Circle::boundingBox() {
	 return std::pair<Point2d, Point2d>(Point2d(center.x() + radius, center.y() + radius), Point2d(center.x() - radius, center.y() - radius));
 }

 void Circle::read(DataProvider &provider) {
	 int params_num = provider.rdInt();
	 if (params_num != 3) {
		 throw std::logic_error("Bad params number.");
	 }

	 double x = provider.rdDouble(),
		 y = provider.rdDouble();
	 center = Point2d(x, y);
	 radius = provider.rdDouble();
 }

 std::vector<std::pair<Point2d, Point2d>> Circle::getSegmets() {
	 std::vector<std::pair<Point2d, Point2d>> result;
	 result.clear();
	 for (int i = 1; i <= 360; i++) {
		 Point2d prev(center.x() + radius*cos(i - 1), center.y() + radius*sin(i - 1));
		 Point2d current(center.x() + radius*cos(i), center.y() + radius*sin(i));
		 result.push_back(std::pair<Point2d, Point2d>(prev, current));
	 }
	 return result;
 }