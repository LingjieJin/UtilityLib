#include <vector>
#include <list>

class CGraphNode
{
private:
    /* data */
public:
    CGraphNode(/* args */){}
    ~CGraphNode(){}

    std::list<CGraphNode*> m_AdjNode;
    bool visited;
};

class CGraph
{
    public:
    template<typename T>
    CGraph(std::vector<T> vec){}

};

class CGraphAlgorithm
{
private:
    /* data */
public:
    CGraphAlgorithm(/* args */);
    ~CGraphAlgorithm();
};

class CGraphAlgorithm_BFS
{
    public:
        int getGraphNodeSet(std::vector<CGraphNode*>)
};


