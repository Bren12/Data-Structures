#include "GraphType.h"

/***********************************************************/
/******************** unweightedGraph ********************/
/********************* AdjecancyMatrix *********************/
/***********************************************************/
template <class VertexType>
class unweightedGraph : public GraphType<VertexType, bool>
{
public:
    unweightedGraph(int max);
    void addEdge(VertexType fromVertex, VertexType toVertex);
};

/*
* Constructor. Initializes the vertices list and adjacency matrix
* of the graph to a size max.
*
* @param max maximum number of elements that will be stored in the
* graph.
*/
template <class VertexType>
unweightedGraph<VertexType>::unweightedGraph(int max)
{
    this->size = 0;
    this->vertices.resize(max);
    this->edges.resize(max);

    for (int i = 0; i < max; i++)
    {
        this->edges[i].resize(max, false);
    }
}

/*
* Add an edge to the graph.
*
* @param fromVertex vertex from  which the edge points from.
* @param toVertex vertex to  which the edge points towards.
*/
template <class VertexType>
void unweightedGraph<VertexType>::addEdge(VertexType fromVertex, VertexType toVertex)
{
    GraphType<VertexType, bool>::addEdge(fromVertex, toVertex, true);
}