#pragma once
#include "Point2d.h"
#include "WDraw.h"
#include "DataProvider.h"
#include "TypesEnum.h"
#include <string>
#include <vector>
class BaseFigure
{
private:
	BaseFigure(const BaseFigure&) = delete;
public:
	BaseFigure() {};
	virtual std::vector<std::pair<Point2d, Point2d>> getSegmets() = 0;
	virtual void draw(WDraw &drawer)=0;
	virtual double segmentsSum() = 0;
	virtual std::pair<Point2d, Point2d> boundingBox() = 0;
	virtual ~BaseFigure() {};
	virtual FigureTypes type() = 0;
	virtual void read(DataProvider &data) = 0;
};
