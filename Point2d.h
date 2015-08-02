#pragma once

class Point2d
{
public:
	Point2d() : m_dX(0.0), m_dY(0.0) {};
	Point2d(double xx, double yy) : m_dX(xx), m_dY(yy) {};
	virtual ~Point2d(void) {};
    double x() const { return m_dX; }
    double y() const { return m_dY; }

private:
    double m_dX;
    double m_dY;
};
