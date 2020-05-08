#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include <vector>
#include <list>
#include <queue>

class CGraphNode
{
public:
    std::vector<CGraphNode *> m_relation;
    void* content;
    bool visited;
    
    CGraphNode() { visited = 0; content = NULL;}
    ~CGraphNode() {}

    static void visitedByBFS(CGraphNode *node);
    static void spiltNodesToSets(std::vector<CGraphNode *> &graph, std::vector<std::vector<CGraphNode *>> &sets);
};


#endif