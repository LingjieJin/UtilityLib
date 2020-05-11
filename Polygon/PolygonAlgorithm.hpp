#ifndef POLYGON_ALGORITHM_HPP
#define POLYGON_ALGORITHM_HPP

#include "Polygon.hpp"

#include <stdlib.h>
#include <cmath>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

template <class T>
class IPolygonAlgorithmBase
{

    ~virtual IPolygonAlgorithmBase(){}
    /**
     * 判断点是否在线段上
     */
    virtual bool isPointOnLine(T p0_x, T p0_y, T p1_x, T p1_y, T p2_x, T p2_y)
    {
        double d1 = (p1_x - p0_x) * (p2_y - p0_y) - (p2_x - p0_x) * (p1_y - p0_y);
        if ((abs(d1) < 0.000001) && ((p0_x - p1_x) * (p0_x - p2_x) <= 0) && ((p0_y - p1_y) * (p0_y - p2_y) <= 0))
        {
            return true;
        }
        return false;
    }

    virtual bool isPointOnLine(T p0_x, T p0_y, CLine<T> &line)
    {
        return isPointOnLine(p0_x, p0_y, line._p1._x, line._p1._y, line._p2._x, line._p2._y);
    }

    virtual bool isPointOnLine(CPoint<T> &point, CLine<T> &line)
    {
        return isPointOnLine(point._x, point._y, line._p1._x, line._p1._y, line._p2._x, line._p2._y);
    }

    /**
     * 判断点是否在矩形内
     * 包括矩形边上
     */
    virtual bool isPointInRect(T x, T y, CRect<T> &rect)
    {
        if (x >= rect.p_min._x && x <= rect.p_max._x && y >= rect.p_min._y && y <= rect.p_max._y)
            return true;
        return false;
    }

    virtual bool isPointInRect(CPoint<T> &point, CRect<T> &rect)
    {
        return isPointInRect(point._x, point._y, rect);
    }

    /**
     * 判断点是否在多边形内
     * 包括多边形边上
     */
    virtual bool isPointInPolygon(const T &x, const T &y, const CPolygon<T> &polygon)
    {
        bool isInside = false;
        int count = 0;

        // quickly check
        CRect<T> r = getPolygonEnvelopRect(p);
        if (!isPointInRect(x, y, r))
        {
            return false;
        }

        //
        double minX = 1.7976931348623158e+308; // double max value
        for (int j = 0; j < polygon._vecPoints.size(); j++)
        {
            minX = MIN(minX, polygon._vecPoints[j]._x);
        }

        // judge point
        double px = x;
        double py = y;
        // line start point
        double linePoint1x = x;
        double linePoint1y = y;
        // line end point
        double linePoint2x = minX - 10; //取最小的X值还小的值作为射线的终点
        double linePoint2y = y;

        //遍历每一条边
        for (int i = 0; i < polygon._vecPoints.size(); i++)
        {
            double cx1 = polygon._vecPoints[i]._x;
            double cy1 = polygon._vecPoints[i]._y;
            double cx2 = polygon._vecPoints[(i + 1) % polygon._vecPoints.size()]._x;
            double cy2 = polygon._vecPoints[(i + 1) % polygon._vecPoints.size()]._y;

            if (isPointOnLine(px, py, cx1, cy1, cx2, cy2))
            {
                return true;
            }

            if (fabs(cy2 - cy1) < 0.000001) //平行则不相交
            {
                continue;
            }

            if (isPointOnLine(cx1, cy1, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
            {
                if (cy1 > cy2) //只保证上端点+1
                {
                    count++;
                }
            }
            else if (isPointOnLine(cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y))
            {
                if (cy2 > cy1) //只保证上端点+1
                {
                    count++;
                }
            }
            else if (isLineIntersect(cx1, cy1, cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y)) //已经排除平行的情况
            {
                count++;
            }
        }

        if (count % 2 == 1)
        {
            isInside = true;
        }

        return isInside;
    }

    virtual bool isPointInPolygon(const CPoint<T> &point, const CPolygon<T> &polygon)
    {
        return isPointInPolygon(point._x, point._y, polygon);
    }

    /**
     * 判断线段是否相交
     * 如果线段交于一点 也是相交
     */
    virtual bool isLineIntersect(T x1, T y1,
                                 T x2, T y2,
                                 T x3, T y3,
                                 T x4, T y4)
    {
        /**
         * 快速排斥：
         * 两个线段为对角线组成的矩形
         * 如果这两个矩形没有重叠的部分，那么两条线段是不可能出现重叠的
        */
        if (!(MIN(x1, x2) <= MAX(x3, x4) && MIN(y3, y4) <= MAX(y1, y2) && MIN(x3, x4) <= MAX(x1, x2) && MIN(y1, y2) <= MAX(y3, y4))) //这里的确如此，这一步是判定两矩形是否相交
            /**
             * 1.线段ab的低点低于cd的最高点（可能重合）
             * 2.cd的最左端小于ab的最右端（可能重合）
             * 3.cd的最低点低于ab的最高点（加上条件1，两线段在竖直方向上重合）
             * 4.ab的最左端小于cd的最右端（加上条件2，两直线在水平方向上重合）
             * 综上4个条件，两条线段组成的矩形是重合的
             * 特别要注意一个矩形含于另一个矩形之内的情况
             */
            return false;
        /**
         * 跨立实验：
         * 如果两条线段相交，那么必须跨立，就是以一条线段为标准，另一条线段的两端点一定在这条线段的两段
         * 也就是说a b两点在线段cd的两端，c d两点在线段ab的两端
        */
        double u, v, w, z; //分别记录两个向量
        u = (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
        v = (x4 - x1) * (y2 - y1) - (x2 - x1) * (y4 - y1);
        w = (x1 - x3) * (y4 - y3) - (x4 - x3) * (y1 - y3);
        z = (x2 - x3) * (y4 - y3) - (x4 - x3) * (y2 - y3);
        return (u * v <= 0.00000001 && w * z <= 0.00000001);
    }

    virtual bool isLineIntersect(const CPoint<T> &p1,
                                 const CPoint<T> &p2,
                                 const CPoint<T> &p3,
                                 const CPoint<T> &p4)
    {
        return isLineIntersect(p1._x, p1._y,
                               p2._x, p2._y,
                               p3._x, p3._y,
                               p4._x, p4._y);
    }

    virtual bool isLineIntersect(const CLine<T> &l1, const CLine<T> &l2)
    {
        return isLineIntersect(l1._p1, l1._p2, l2._p1, l2._p2);
    }

    /**
     * 求线段P1P2与Q1Q2的交点。
     */
    virtual void GetCrossPoint(const CPoint<T> &p1,
                               const CPoint<T> &p2,
                               const CPoint<T> &q1,
                               const CPoint<T> &q2,
                               const T &x, const T &y)
    {
        //求交点
        double tmpLeft = 0.0, tmpRight = 0.0;
        tmpLeft = (q2._x - q1._x) * (p1._y - p2._y) - (p2._x - p1._x) * (q1._y - q2._y);
        tmpRight = (p1._y - q1._y) * (p2._x - p1._x) * (q2._x - q1._x) + q1._x * (q2._y - q1._y) * (p2._x - p1._x) - p1._x * (p2._y - p1._y) * (q2._x - q1._x);

        x = (tmpRight / tmpLeft);

        tmpLeft = (p1._x - p2._x) * (q2._y - q1._y) - (p2._y - p1._y) * (q1._x - q2._x);
        tmpRight = p2._y * (p1._x - p2._x) * (q2._y - q1._y) + (q2._x - p2._x) * (q2._y - q1._y) * (p1._y - p2._y) - q2._y * (q1._x - q2._x) * (p2._y - p1._y);

        y = (tmpRight / tmpLeft);
    }

    virtual void GetCrossPoint(const CLine<T> &l1,
                               const CLine<T> &l2,
                               const CPoint<T> &point)
    {
        return GetCrossPoint(l1._p1, l1._p2, l2._p1, l2._p2, point._x, point._y);
    }


    /**
     * 判断多边形是否相交
     */
    virtual bool isPolygonsIntersect(const CPolygon<T> &p1, const CPolygon<T> &p2)
    {
        int i, j;
        // 1. point judge
        for (i = 0; i < p1._vecPoints.size(); i++)
        {
            if (isPointInPolygon(p1._vecPoints[i]._x, p1._vecPoints[i]._y, p2))
                return true;
        }

        for (i = 0; i < p2._vecPoints.size(); i++)
        {
            if (isPointInPolygon(p2._vecPoints[i]._x, p2._vecPoints[i]._y, p1))
                return true;
        }

        // 2. line judge
        for (i = 0; i < p1._vecPoints.size(); i++)
        {
            for (j = 0; j < p2._vecPoints.size(); j++)
            {
                if (isLineIntersect(p1._vecPoints[i], p1._vecPoints[(i + 1) % p1._vecPoints.size()],
                                    p2._vecPoints[j], p2._vecPoints[(j + 1) % p2._vecPoints.size()]))
                {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * 获取多边形的最大正矩形
     */
    virtual CRect<T> getPolygonEnvelopRect(const CPolygon<T> &p)
    {
        T minx = p._vecPoints[0]._x;
        T maxx = p._vecPoints[0]._x;
        T miny = p._vecPoints[0]._y;
        T maxy = p._vecPoints[0]._y;

        for (int i = 1; i < p._vecPoints.size(); i++)
        {
            if (p._vecPoints[i]._x < minx)
                minx = p._vecPoints[i]._x;
            if (p._vecPoints[i]._x > maxx)
                maxx = p._vecPoints[i]._x;
            if (p._vecPoints[i]._y < miny)
                miny = p._vecPoints[i]._y;
            if (p._vecPoints[i]._y > maxy)
                maxy = p._vecPoints[i]._y;
        }
        return CRect<T>(minx, miny, maxx, maxy);
    }



};

#endif