#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"

#include <stdio.h>

void cvtPointToNode(std::vector<CPoint<double>> &v_points, std::vector<CGraphNode> &v_nodes)
{
    for (int i = 0; i < v_points.size(); i++)
    {
        CGraphNode node;
        node.content = &v_points[i];
        v_nodes.push_back(node);
    }
}



int main()
{
    std::vector<CPoint<double>> v_points;
    std::vector<CGraphNode> v_nodes;
    std::vector<CGraphNode *> graps;

    CPoint<double> p1 = CPoint<double>(0.0, 0.0);
    CPoint<double> p2 = CPoint<double>(5.0, 5.0);
    CPoint<double> p3 = CPoint<double>(8.0, 8.0);
    CPoint<double> p4 = CPoint<double>(9.999, 9.0999);

    v_points.push_back(p1);
    v_points.push_back(p2);
    v_points.push_back(p3);
    v_points.push_back(p4);

    cvtPointToNode(v_points, v_nodes);

    v_nodes[0].m_relation.push_back(&v_nodes[1]);
    v_nodes[0].m_relation.push_back(&v_nodes[3]);
    v_nodes[1].m_relation.push_back(&v_nodes[3]);

    CGraphNode::getReference(v_nodes, graps);

    printf("start spilt....\n");

    std::vector<std::vector<CGraphNode *>> sets;
    CGraphNode::spiltNodesToSets(graps, sets);

    printf("get sets size: %ld.\n", sets.size());

    for (int i = 0; i < sets.size(); i++)
    {
        for (int j = 0; j < sets[i].size(); j++)
        {
            printf("%d-%d %s\n", i, j, ((CPoint<double> *)sets[i][j]->content)->ToString().c_str());
        }
        
    }
    

    return 0;
}