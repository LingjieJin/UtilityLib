#include "Polygon.hpp"
#include "PolygonAlgorithm.hpp"

#include <iostream>

int main()
{
	double q, w;

	CLine l1(0, 0, 9, 9);
	CLine l2(0, 3, 1, 3);

	IPolygonAlgorithmBase a;
	ISpPolygonAlgorithm b;

	if (a.isLineIntersect(l1, l2))
	{
		a.GetCrossPoint(l1._p1, l1._p2, l2._p1, l2._p2, q, w);
		std::cout << "a:line is intersect" << std::endl;
		std::cout << q << ", " << w << std::endl;
	}
	else
	{
		std::cout << "a:line is not intersect" << std::endl;
	}

	if (b.isLineIntersect(l1, l2))
	{
		b.GetCrossPoint(l1._p1, l1._p2, l2._p1, l2._p2, q, w);
		std::cout << "b:line is intersect" << std::endl;
		std::cout << q << ", " << w << std::endl;
	}
	else
	{
		std::cout << "b:line is not intersect" << std::endl;
	}

	getchar();

	return 0;
}