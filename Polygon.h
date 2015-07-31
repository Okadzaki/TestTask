#pragma once
#include "BaseFigure.h"
#include <vector>
class Polygon :
	public BaseFigure
{
private:
	std::vector<double> points;
public:
	Polygon();
	virtual ~Polygon();
};

