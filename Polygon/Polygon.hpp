#ifndef CPOLYGON_HPP
#define CPOLYGON_HPP

#include <vector>

class CPoint
{
public:
    double _x;
    double _y;

    CPoint()
    {
        _x = 0;
        _y = 0;
    }

    CPoint(double x, double y)
    {
        _x = x;
        _y = y;
    }

    CPoint(const CPoint &p)
    {
        _x = p._x;
        _y = p._y;
    }

    CPoint& operator=(const CPoint &p)
    {
        _x = p._x;
        _y = p._y;
    }

    ~CPoint() {}
};

class CLine
{
public:
    CPoint _p1;
    CPoint _p2;
    CLine()
    {
        _p1._x = 0;
        _p1._y = 0;
        _p2._x = 0;
        _p2._y = 0;
    }

    CLine(double x1, double y1, double x2, double y2)
    {
        _p1._x = x1;
        _p1._y = y1;
        _p2._x = x2;
        _p2._y = y2;
    }

    CLine(const CPoint &p1, const CPoint &p2)
    {
        _p1._x = p1._x;
        _p1._y = p1._y;
        _p2._x = p2._x;
        _p2._y = p2._y;
    }

    ~CLine() {}
};

class CRect
{
public:
    CPoint p_min, p_max;

    CRect()
    {
        p_min = CPoint();
        p_max = CPoint();
    }

    CRect(double pmin_x, double pmin_y, double pmax_x, double pmax_y)
    {
        p_min = CPoint(pmin_x, pmin_y);
        p_max = CPoint(pmax_x, pmax_y);
    }

    CRect(CPoint &pmin, CPoint &pmax)
    {
        p_min = CPoint(pmin);
        p_max = CPoint(pmax);
    }

    CRect(const CRect &rect)
    {
        p_min = rect.p_min;
        p_max = rect.p_max;
    }

    CRect& operator=(const CRect &rect)
    {
        p_min = rect.p_min;
        p_max = rect.p_max;
    }
};

class CPolygon
{
public:
    std::vector<CPoint> _vecPoints;

    CPolygon() {}

    CPolygon(std::vector<CPoint> &points)
    {
        _vecPoints = std::vector<CPoint>(points);
    }

    CPolygon(CPolygon &polygon)
    {
        _vecPoints = std::vector<CPoint>(polygon._vecPoints);
    }

    ~CPolygon(){}
};

#endif
