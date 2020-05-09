#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"

#include <stdio.h>

int main()
{

    CPoint<double> p1 = CPoint<double>(0,0);
    CPoint<double> p2 = CPoint<double>(5,5);
    CPoint<double> p3 = CPoint<double>(8,8);
    CPoint<double> p4 = CPoint<double>(9,9);
    CGraphNode n1 = CGraphNode();
    CGraphNode n2 = CGraphNode();
    CGraphNode n3 = CGraphNode();
    CGraphNode n4 = CGraphNode();

    n1.content = &p1;
    n2.content = &p2;
    n3.content = &p3;
    n4.content = &p4;

    n1.m_relation.push_back(&n2);
    n1.m_relation.push_back(&n4);
    n2.m_relation.push_back(&n4);

    std::vector<CGraphNode*> graps;
    graps.push_back(&n1);
    graps.push_back(&n2);
    graps.push_back(&n3);
    graps.push_back(&n4);

    printf("start spilt....\n");

    std::vector<std::vector<CGraphNode* >> sets;
    CGraphNode::spiltNodesToSets(graps, sets);

    printf("get sets size: %d.\n", sets.size());

    return 0;
}