#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <helpers.h>



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
    Person person;
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

AdjacencyListNode* new_AdjacencyListNode(int dest);
Graph* create_Graph(int V, Person* persons);
void add_Edge( Graph* graph, int src, int dest);
Person map_dest_person(Graph* graph, int dest);
void print_Graph( Graph* graph);


#endif // !GRAPH_H
