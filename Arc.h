#pragma once
#include "Circle.h"
class Arc :
	public Circle
{
private:
	double angle_start;
	double angle_stop;
public:
	Arc();
	~Arc();
};

