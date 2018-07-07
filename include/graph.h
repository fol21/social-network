#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>


/** 
 * * A structure to represent an adjacency list node
*/
typedef struct AdjacencyListNode 
{
    int dest;
    struct AdjacencyListNode* next;
}AdjacencyListNode;

/** 
 * * A structure to represent an adjacency list
 */
typedef struct AdjacencyList 
{
    AdjacencyListNode *head; 
}AdjacencyList;
 
 
/**
 * 
 *  * A structure to represent a graph. A graph
 *  * is an array of adjacency lists.
 *  * Size of array will be V (number of vertices in graph)
 */
typedef struct Graph
{
    int V;
    struct AdjacencyList* array;
}Graph;

AdjacencyListNode* newAdjListNode(int dest);
Graph* createGraph(int V);
void addEdge( Graph* graph, int src, int dest);
void printGraph( Graph* graph);


#endif // !GRAPH_H
