#include "Polygon.hpp"
#include "PolygonAlgorithm.hpp"

#include <iostream>

int main()
{
    // Triangle
    CPolygon t1;
    t1._vecPoints.push_back(CPoint(1,3));
    t1._vecPoints.push_back(CPoint(0,2));
    t1._vecPoints.push_back(CPoint(2,2));

    // Triangle
    CPolygon t2;
    t2._vecPoints.push_back(CPoint(1,1));
    t2._vecPoints.push_back(CPoint(0,2));
    t2._vecPoints.push_back(CPoint(2,2));

    // Triangle
    CPolygon t3;
    t3._vecPoints.push_back(CPoint(1,-5));
    t3._vecPoints.push_back(CPoint(0,2));
    t3._vecPoints.push_back(CPoint(2,2));

    // Triangle
    CPolygon t4;
    t4._vecPoints.push_back(CPoint(-5,-5));
    t4._vecPoints.push_back(CPoint(0,2));
    t4._vecPoints.push_back(CPoint(2,2));

    // Triangle
    CPolygon t5;
    t5._vecPoints.push_back(CPoint(5,-5));
    t5._vecPoints.push_back(CPoint(0,2));
    t5._vecPoints.push_back(CPoint(2,2));

    // Rect
    CPolygon r1;
    r1._vecPoints.push_back(CPoint(0,0));
    r1._vecPoints.push_back(CPoint(0,2));
    r1._vecPoints.push_back(CPoint(2,2));
    r1._vecPoints.push_back(CPoint(2,0));

    //
    ISpTriangleInPolygon i1;
    if(i1.isTriangleInPolygon(t1,r1))
    {
        std::cout<< "Triangle t1 in Rect" <<std::endl;
    }

    if(i1.isTriangleInPolygon(t2,r1))
    {
        std::cout<< "Triangle t2 in Rect" <<std::endl;
    }

    if(i1.isTriangleInPolygon(t3,r1))
    {
        std::cout<< "Triangle t3 in Rect" <<std::endl;
    }
    
    if(i1.isTriangleInPolygon(t4,r1))
    {
        std::cout<< "Triangle t4 in Rect" <<std::endl;
    }

    if(i1.isTriangleInPolygon(t5,r1))
    {
        std::cout<< "Triangle t5 in Rect" <<std::endl;
    }

    getchar();
    
    return 0;
}