
#include "Polygon_Line.h"


void Polygon_Line::draw(WDraw &drawer) {
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();
	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		drawer.drawSegment(it->first, it->second);
	}
}

std::vector<std::pair<Point2d, Point2d>> Polygon_Line::getSegmets() {
	std::vector<std::pair<Point2d, Point2d>> result;
	result.clear();
	for (std::vector<Point2d>::size_type i = 1; i != points.size(); i++)
		result.push_back ( std::pair<Point2d, Point2d>(points[i - 1], points[i]));
	return result;
};