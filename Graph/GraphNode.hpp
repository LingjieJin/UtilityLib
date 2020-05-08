#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include <vector>
#include <list>
#include <queue>

class CGraphNode
{
public:
    CGraphNode() { visited = 0; content = NULL;}
    ~CGraphNode() {}

    void* content;
    std::vector<CGraphNode *> m_relation;
    bool visited;

    static void visitedByBFS(CGraphNode *node);
    static void spiltNodesToSets(std::vector<CGraphNode *> &graph, std::vector<std::vector<CGraphNode *>> &sets);
};


#endif