#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"

#include <stdio.h>

int main()
{

    CPoint<double> p1 = CPoint<double>(0,0);
    CPoint<double> p2 = CPoint<double>(1,1);
    CPoint<double> p3 = CPoint<double>(1,2);
    CPoint<double> p4 = CPoint<double>(2,1);
    CGraphNode n1 = CGraphNode();
    CGraphNode n2 = CGraphNode();
    CGraphNode n3 = CGraphNode();
    CGraphNode n4 = CGraphNode();

    n1.content = &p1;
    n2.content = &p2;
    n3.content = &p3;
    n4.content = &p4;

    printf("n1 mem:%p, content:%p, x:%p, y:%p \n", &n1, (&n1.content), &(((CPoint<double>*)n1.content)->_x),&(((CPoint<double>*)n1.content)->_y));
    printf("n2 mem:%p, content:%p, x:%p, y:%p \n", &n2, (&n2.content), &(((CPoint<double>*)n2.content)->_x),&(((CPoint<double>*)n2.content)->_y));
    printf("n3 mem:%p, content:%p, x:%p, y:%p \n", &n3, (&n3.content), &(((CPoint<double>*)n3.content)->_x),&(((CPoint<double>*)n3.content)->_y));
    printf("n4 mem:%p, content:%p, x:%p, y:%p \n", &n4, (&n4.content), &(((CPoint<double>*)n4.content)->_x),&(((CPoint<double>*)n4.content)->_y));
    

    n1.m_relation.push_back(&n2);
    n2.m_relation.push_back(&n4);

    std::vector<CGraphNode*> graps;
    graps.push_back(&n1);
    graps.push_back(&n2);
    graps.push_back(&n3);
    graps.push_back(&n4);


    for (int i = 0; i < graps.size(); i++)
    {
        printf("graph %d, mem:%p, content:%p, x:%f, y:%f\n",i, *&graps[i], &(graps[i]->content), ((CPoint<double>*)graps[i]->content)->_x, ((CPoint<double>*)graps[i]->content)->_y );
    }


    printf("start spilt....\n");
    

    std::vector<std::vector<CGraphNode* >> sets;
    CGraphNode::spiltNodesToSets(graps, sets);

    printf("get sets size: %d.\n", sets.size());

    return 0;
}