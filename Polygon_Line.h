#pragma once
#include "Polygon.h"
class Polygon_Line :
	public Polygon
{
public:
	Polygon_Line() {};
	void draw(WDraw &drawer);
	FigureTypes type() { return FigureTypes::polygon_line; };
	std::vector<std::pair<Point2d, Point2d>> getSegmets();
	~Polygon_Line() {};
};

