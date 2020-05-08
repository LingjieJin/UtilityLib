#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"

#include <stdio.h>

int main()
{

    CPoint<double> p1(0,0);
    CPoint<double> p2(1,1);
    CPoint<double> p3(1,2);
    CPoint<double> p4(2,1);
    CGraphNode n1 = CGraphNode();
    CGraphNode n2 = CGraphNode();
    CGraphNode n3 = CGraphNode();
    CGraphNode n4 = CGraphNode();

    n1.content = &p1;
    n2.content = &p2;
    n3.content = &p3;
    n4.content = &p4;

    n1.m_relation.push_back(&n2);
    n2.m_relation.push_back(&n4);

    std::vector<CGraphNode*> graps;
    graps.push_back(&n1);
    graps.push_back(&n2);
    graps.push_back(&n3);
    graps.push_back(&n4);

    for (int i = 0; i < graps.size(); i++)
    {
        printf("graph %d x: %f, y:%f\n",i, (((CPoint<double>*)graps[i]->content)->_x, ((CPoint<double>*)graps[i]->content)->_y));
    }

    printf("start spilt....\n");
    

    std::vector<std::vector<CGraphNode* >> sets;
    CGraphNode::spiltNodesToSets(graps, sets);

    printf("get sets size: %d.\n", sets.size());

    return 0;
}