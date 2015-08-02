#pragma once
#include "BaseFigure.h"

class Square :
	public BaseFigure
{
private:
	Point2d points[2];
public:
	void draw(WDraw &drawer);
	std::pair<Point2d, Point2d> boundingBox();
	std::vector<std::pair<Point2d, Point2d>> getSegmets();
	FigureTypes type() { return FigureTypes::square; };
	void read(DataProvider &data);
	~Square() {};
};

