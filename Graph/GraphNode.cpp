#include "GraphNode.hpp"
#include "../Polygon/Polygon.hpp"
#include <stdio.h>

void CGraphNode::visitedByBFS(CGraphNode *node)
{
    std::queue<CGraphNode *> help_que;
    help_que.push(node);
    node->visited = 1;
    printf("start x: %f, y:%f\n", ((CPoint<double>*)node->content)->_x,((CPoint<double>*)node->content)->_y);

    while (!help_que.empty())
    {
        CGraphNode *front = help_que.front();
        printf("need to visit %d elements ...\n", front->m_relation.size());
        for (int i = 0; i < front->m_relation.size(); i++)
        {
            front->m_relation[i]->visited = 1;
            help_que.push(front->m_relation[i]);
            printf("push x: %f, y:%f\n", ((CPoint<double>*)front->m_relation[i]->content)->_x,((CPoint<double>*)front->m_relation[i]->content)->_y);
        }
        help_que.pop();
    }
}

void CGraphNode::spiltNodesToSets(std::vector<CGraphNode *> &graph, std::vector<std::vector<CGraphNode *>> &sets)
{
    // clean sets
    printf("clear input vector...\n");
    sets.clear();

    // copy elements
    std::vector<CGraphNode *> copy = graph;

    while (!copy.empty())
    {
        std::vector<CGraphNode *> set;

        CGraphNode *front = copy.front();
        printf("visited copy...\n");
        visitedByBFS(front);
        printf("visited copy end...\n");
        // 遍历copy中的所有元素
        // 查看是否被访问过
        // 如果访问过，证明是在同一个集合中，保存，放入输出MultiSet中
        // 同时删除copy中的元素，进行下一次操作
        for (std::vector<CGraphNode *>::iterator it = copy.begin();
             it != copy.end();)
        {
            if ((*it)->visited == 1)
            {
                printf("copy remove ...\n");
                printf("remove x: %f, y:%f\n", ((CPoint<double>*)(*it)->content)->_x,((CPoint<double>*)(*it)->content)->_y);
                set.push_back(*it);
                copy.erase(it++);
                printf("set size %d...\n", set.size());
                printf("copy size %d, graph size %d..\n", copy.size(), graph.size());
            }
            else
            {
                printf("jump...\n");
                printf("jump x: %f, y:%f\n", ((CPoint<double>*)(*it)->content)->_x,((CPoint<double>*)(*it)->content)->_y);
                it++;
            }
        }
        printf("start push back...\n");
        sets.push_back(set);
        printf("get a set\n");
    }
}