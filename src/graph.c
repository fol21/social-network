#include <graph.h>
 
/** 
 * * A utility function to create a new adjacency list node
 */
AdjacencyListNode* newAdjListNode(int dest)
{
    AdjacencyListNode* newNode =
     ( AdjacencyListNode*) malloc(sizeof( AdjacencyListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
/**
 * *  A utility function that creates a graph of V vertices
 */
Graph* createGraph(int V)
{
    Graph* graph = 
        ( Graph*) malloc(sizeof( Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of 
    // array will be V
    graph->array = 
      ( AdjacencyList*) malloc(V * sizeof( AdjacencyList));
 
    // Initialize each adjacency list as empty by 
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
/**
 * *  Adds an edge to an undirected graph
 */
void addEdge( Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the begining
     AdjacencyListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
/**
 * * A utility function to print the adjacency list 
 * * representation of graph
 */
void printGraph( Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
         AdjacencyListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}