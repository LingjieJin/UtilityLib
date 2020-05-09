#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include <vector>
#include <list>
#include <queue>

#ifdef __SW_DEBUG
#define DEBUG_PRINT(format,...) printf("File: "__FILE__", Line: %05d: "format" \n",__LINE__, ##__VA_ARGS__)
#define DEBUG_PRINTF(fmt,...) printf(fmt,__VA__ARGS__)
#define ERROR_PRINTF(format,...) fprintf(stderr,format, __VA_ARGS__)  
#define F_LOGI(...) printf(TAG_INFO"%s:%d  ",__FILE__,__LINE__),printf(__VA_ARGS__)
#else  
#define DEBUG_PRINTF(format,...)
#define ERROR_PRINTF(format,...)
#define F_LOGI(...)
#endif  

class CGraphNode
{
public:
    std::vector<CGraphNode *> m_relation;
    void* content;
    int visited;
    
    CGraphNode() { visited = 0; content = NULL;}
    ~CGraphNode() {}

    static void visitedByBFS(CGraphNode *node);
    static void spiltNodesToSets(std::vector<CGraphNode *> &graph, std::vector<std::vector<CGraphNode *>> &sets);
};


#endif