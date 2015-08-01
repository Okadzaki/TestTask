#pragma once
#include "BaseFigure.h"
#include <vector>
class Polygon :
	public BaseFigure
{
private:
	std::vector<Point2d> points;
public:
	Polygon();
	void draw(WDraw &drawer);

	virtual ~Polygon();
};

