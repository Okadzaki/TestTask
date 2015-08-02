#pragma once
#include "BaseFigure.h"
class Circle :
	public BaseFigure
{
protected:
	Point2d center;
	double radius;
public:
	Circle() {};
	virtual void draw(WDraw &drawer);
	std::pair<Point2d, Point2d> boundingBox();
	std::vector<std::pair<Point2d, Point2d>> getSegmets();

	void read(DataProvider &provider);
	 FigureTypes type() { return FigureTypes::circle; };

	 ~Circle() {};
};

