#pragma once
#include "BaseFigure.h"

class Square :
	public BaseFigure
{
private:
	Point2d points[2];
public:
	Square();
	void draw(WDraw &drawer);
	~Square();
};

