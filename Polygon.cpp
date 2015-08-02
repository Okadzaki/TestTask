
#include "Polygon.h"

void Polygon::draw(WDraw &drawer) {
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();

	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		drawer.drawSegment(it->first, it->second);
	}

}


std::pair<Point2d, Point2d> Polygon::boundingBox() {
	//find min left

	std::vector<Point2d>::iterator min_left = points.begin();
	for (auto it = points.begin(); it != points.end(); ++it)
		if (it->x() < min_left->x())
			min_left = it;

	//find max right
	std::vector<Point2d>::iterator max_right = points.begin();
	for (auto it = points.begin(); it != points.end(); ++it)
		if (it->x() > max_right->x())
			max_right = it;

	//find heigher
	std::vector<Point2d>::iterator height_it = points.begin();
	for (auto it = points.begin(); it != points.end(); ++it)
		if (it->y() > height_it->y())
			height_it = it;

	//find lower
	std::vector<Point2d>::iterator lower_it = points.begin();
	for (auto it = points.begin(); it != points.end(); ++it)
		if (it->y() < lower_it->y())
			lower_it = it;

	//Create rectangle
	/*
	Point2d first(min_left->x(), height_it->y());
	Point2d second(max_right->x(), height_it->y());
	Point2d third(max_right->x(), lower_it->y());
	Point2d fourth(min_left->x(), lower_it->y());
	*/
	return std::pair<Point2d, Point2d>(Point2d(min_left->x(), height_it->y()), Point2d(max_right->x(), lower_it->y()));


}

void Polygon::read(DataProvider &provider) {
	points.clear();
	int params_num = provider.rdInt();
	for (int i = 0; i < params_num / 2; ++i) {
		double x = provider.rdDouble(),
			y = provider.rdDouble();
		points.push_back(Point2d(x, y));
	}
}
std::vector<std::pair<Point2d, Point2d>> Polygon::getSegmets() {
	std::vector<std::pair<Point2d, Point2d>> result;
	result.clear();
	for (std::vector<Point2d>::size_type i = 1; i != points.size(); i++)
		result.push_back(std::pair<Point2d, Point2d>(points[i - 1], points[i]));
	result.push_back(std::pair<Point2d, Point2d>(points.front(), points.back()));
	return result;
};

double Polygon::segmentsSum() {
	double sum = 0;
	std::vector<std::pair<Point2d, Point2d>> segments = this->getSegmets();
	for (std::vector<std::pair<Point2d, Point2d>>::iterator it = segments.begin(); it != segments.end(); ++it) {
		sum += sqrt(pow(it->second.x() - it->first.x(), 2) + pow(it->second.y() - it->first.y(), 2));
	}
	return sum;
}
