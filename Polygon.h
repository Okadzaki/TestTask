#pragma once
#include "BaseFigure.h"
#include <vector>
class Polygon :
	public BaseFigure
{
protected:
	std::vector<Point2d> points;
public:
	Polygon() {};
	virtual void draw(WDraw &drawer);
	std::pair<Point2d, Point2d> boundingBox();
	virtual void read(DataProvider &provider);
	std::vector<std::pair<Point2d, Point2d>> getSegmets();
	double segmentsSum();
	FigureTypes type() { return FigureTypes::polygon; };


	virtual ~Polygon() {};
};

