#pragma once
#include "BaseFigure.h"
class Circle :
	public BaseFigure
{
private:
	Point2d center;
	double radius;
public:
	Circle();
	~Circle();
};

