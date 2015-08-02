#include "Arc.h"
#include <cmath>
#include <vector>
#include <algorithm>


void Arc::draw(WDraw &drawer) {
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();

	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		drawer.drawSegment(it->first, it->second);
	}
}


std::pair<Point2d, Point2d> Arc::boundingBox() {
	
	std::vector<Point2d> critical_points;
	critical_points.push_back(center);
	critical_points.push_back(Point2d(center.x() + radius * cos(angle_start), center.y() + radius * sin(angle_start)));
	critical_points.push_back(Point2d(center.x() + radius * cos(angle_stop), center.y() + radius * sin(angle_stop)));
	if (0.0 >= angle_start && 0.0 <= angle_stop) {
		critical_points.push_back(Point2d(center.x(), center.y() - radius));
	}
	if (PI / 2 >= angle_start && PI / 2 <= angle_stop) {
		critical_points.push_back(Point2d(center.x() + radius, center.y()));
	}
	if (PI >= angle_start && PI <= angle_stop) {
		critical_points.push_back(Point2d(center.x(), center.y() + radius));
	}
	if (3 * PI / 2 >= angle_start && 3 * PI / 2 <= angle_stop) {
		critical_points.push_back(Point2d(center.x() - radius, center.y()));
	}

	double left_lower_x = std::min_element(critical_points.begin(), critical_points.end(), [](const Point2d& a, const Point2d& b) {
		return a.x() < b.x();
	})->x();

	double left_lower_y = std::min_element(critical_points.begin(), critical_points.end(), [](const Point2d& a, const Point2d& b) {
		return a.y() < b.y();
	})->y();

	double right_upper_x = std::max_element(critical_points.begin(), critical_points.end(), [](const Point2d& a, const Point2d& b) {
		return a.x() > b.x();
	})->x();

	double right_upper_y = std::max_element(critical_points.begin(), critical_points.end(), [](const Point2d& a, const Point2d& b) {
		return a.y() > b.y();
	})->x();
	return std::pair<Point2d, Point2d>(Point2d(left_lower_x, left_lower_y), Point2d(right_upper_x, right_upper_y));
}



void Arc::read(DataProvider &provider) {
	int params_num = provider.rdInt();
	if (params_num != 5) {
		throw std::invalid_argument("Bad params error");
	}
	double x = provider.rdDouble();
	double y = provider.rdDouble();
	center = Point2d(x, y);
	radius = provider.rdDouble();
	angle_start = provider.rdDouble();
	angle_stop = provider.rdDouble();
}

std::vector<std::pair<Point2d, Point2d>> Arc::getSegmets(){
	std::vector<std::pair<Point2d, Point2d>> result;
	result.clear();
	const double INC = PI / 180.0;
	for (double i = angle_start + INC; i <= angle_stop; i += INC) {
		Point2d prev(center.x() + radius*cos(i - INC), center.y() + radius*sin(i - INC));
		Point2d current(center.x() + radius*cos(i), center.y() + radius*sin(i));
		result.push_back(std::pair<Point2d, Point2d>(prev, current));
	}
	return result;
}


double Arc::segmentsSum() {
	double sum = 0;
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();
	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		sum += sqrt(pow(it->second.x() - it->first.x(), 2) + pow(it->second.y() - it->first.y(), 2));
	}
	return sum;
}