#pragma once
#include "Circle.h"
#define PI 3.141

class Arc :
	public Circle
{
private:
	double angle_start;
	double angle_stop;

public:
	Arc() {};
	void draw(WDraw &drawer);
	std::pair<Point2d, Point2d> boundingBox();
	void read(DataProvider &provider);
	double segmentsSum();
	std::vector<std::pair<Point2d, Point2d>> getSegmets();
	FigureTypes type() { return FigureTypes::anc; };

	~Arc() {};
};

