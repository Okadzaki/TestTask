#pragma once
#include "Point2d.h"
#include "WDraw.h"
#include "DataProvider.h"

class BaseFigure
{
private:
	BaseFigure(const BaseFigure&);
	int m_params_num;
public:
	BaseFigure(int params_num) : m_params_num(params_num) {};
	virtual void draw(WDraw &drawer)=0;
	virtual void boundingBox() = 0;
	virtual ~BaseFigure() {};
	virtual void read(DataProvider &data) = 0;
};

/*
// Reading object
DataProvider data;
int id = data.rdInt();
BaseFigure *f = Factory.construct(id);
f.read(data);


*/
