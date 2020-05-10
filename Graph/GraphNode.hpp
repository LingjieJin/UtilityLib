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
    int visited;
    
    CGraphNode() { visited = 0; content = NULL;}
    ~CGraphNode() {}

    static void getReference(std::vector<CGraphNode> &src, std::vector<CGraphNode *> &ref);
    /*
    使用广度优先搜索方式寻找相关节点
    */
    static void visitedByBFS(CGraphNode *node);


    static void spiltNodesToSets(std::vector<CGraphNode *> &graph, std::vector<std::vector<CGraphNode *>> &sets);
};


#endif