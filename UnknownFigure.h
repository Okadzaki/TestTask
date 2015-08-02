#pragma once
#include "BaseFigure.h"
#include <vector>
#include "Exceptions.h"
class UnknownFigure :
	public BaseFigure
{
private:
	std::vector<double> params;
public:
	UnknownFigure() {};
	virtual void draw(WDraw &drawer);
	virtual void boundingBox(WDraw &drawer);
	virtual void read(DataProvider &provider);
	virtual FigureTypes type() { return FigureTypes::unknown;  }

	std::vector<std::pair<Point2d, Point2d>> getSegmets();
	virtual ~UnknownFigure() {};
};
