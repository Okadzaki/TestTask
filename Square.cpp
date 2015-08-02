
#include "Square.h"


void Square::draw(WDraw &drawer) {
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();

	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		drawer.drawSegment(it->first, it->second);
	}

};

std::pair<Point2d, Point2d> Square::boundingBox() {
	return std::pair<Point2d, Point2d>(points[0], points[1]);
};


void Square::read(DataProvider &provider) {
	int params_num = provider.rdInt();
	if (params_num != 4) {
		throw std::logic_error("Bad params number.");
	}
	double left_x = provider.rdDouble();
	double left_y = provider.rdDouble();
	double right_x = provider.rdDouble();
	double right_y = provider.rdDouble();
	points[0] = Point2d(left_x, left_y);
	points[1] = Point2d(right_x, right_y);
}

std::vector<std::pair<Point2d, Point2d>> Square::getSegmets() {
	std::vector<std::pair<Point2d, Point2d>> results;
	results.clear();
	results.push_back(std::pair<Point2d, Point2d>(Point2d(points[0].x(), points[1].y()),points[1]));
	results.push_back(std::pair<Point2d, Point2d>(points[1], Point2d(points[1].x(), points[0].y())));
	results.push_back(std::pair<Point2d, Point2d>(Point2d(points[1].x(), points[0].y()), points[0]));
	results.push_back(std::pair<Point2d, Point2d>(points[0], Point2d(points[0].x(), points[1].y())));

	return results;
}

double Square::segmentsSum() {
	double sum=0;
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();
	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		sum += sqrt(pow(it->second.x() - it->first.x(), 2) + pow(it->second.y() - it->first.y(), 2));
	}
	return sum;
}