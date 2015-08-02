#include "UnknownFigure.h"


void UnknownFigure::draw(WDraw &drawer) {
	throw UnknownObjectException();
}

void UnknownFigure::boundingBox(WDraw &drawer) {
	throw UnknownObjectException();
}

void UnknownFigure::read(DataProvider &provider) {
	int params_num = provider.rdInt();
	for (int i = 0; i < params_num; ++i) {
		params.push_back(provider.rdDouble());
	}
}

std::vector<std::pair<Point2d, Point2d>> UnknownFigure::getSegmets() {
	std::vector<std::pair<Point2d, Point2d>> result;
	result.clear();
	result.push_back(std::pair<Point2d, Point2d>(Point2d(0, 0), Point2d(0, 0)));
	return result;
}
