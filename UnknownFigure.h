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
	virtual void draw(WDraw &drawer)	{ throw UnknownObjectException(); }
	;
	virtual std::pair<Point2d, Point2d> boundingBox() { throw UnknownObjectException(); }
	virtual void read(DataProvider &provider);
	double segmentsSum() {
		throw UnknownObjectException();
	};
	virtual FigureTypes type() { return FigureTypes::unknown;  }

	std::vector<std::pair<Point2d, Point2d>> getSegmets() { throw UnknownObjectException(); };
	virtual ~UnknownFigure() {};
};
