#include <graph.h>
 
/** 
 * * A utility function to create a new adjacency list node
 */
AdjacencyListNode* new_AdjacencyListNode(int dest)
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
Graph* create_Graph(int V, Person* persons)
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
    {
        graph->array[i].head = NULL;
        graph->array[i].person = persons[i];
    }
 
    return graph;
}
 
/**
 * *  Adds an edge to an undirected or directed graph
 */
void add_Edge(Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the begining
    AdjacencyListNode* newNode = new_AdjacencyListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // // Since graph is undirected, add an edge from
    // // dest to src also
    // newNode = new_AdjacencyListNode(src);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
    
    // Obs: You can also call this function twice 
    // with src and dest inverted
}

void remove_edge(Graph* graph, int src, int dest)
{
    AdjacencyList newList;
    newList.head = NULL;
    newList.person = graph->array[src].person;

    AdjacencyListNode* pCrawl = graph->array[src].head;

    while (pCrawl)
    {
        if(pCrawl->dest != dest)
        {
            AdjacencyListNode* newNode = new_AdjacencyListNode(pCrawl->dest);
            newNode->next = newList.head;
            newList.head = newNode;
        }
        pCrawl = pCrawl->next;
    }
    graph->array[src] = newList;
}

/**
 * * Maps dest number with person from graph's AdjList
 */
Person map_dest_person(Graph* graph, int dest)
{
    return graph->array[dest].person;
}
 
/**
 * * A utility function to print the adjacency list 
 * * representation of graph
 */
void print_Graph( Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
         AdjacencyListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d (id: %s %d)\n %s(head) ", 
            v, 
            graph->array[v].person.name,
            graph->array[v].person.age,
            graph->array[v].person.name
        );
        while (pCrawl)
        {
            printf("-> %s", map_dest_person(graph, pCrawl->dest).name);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
/**
 * * A utility function to print the average of edges 
 * 
 */
double average_edges( Graph* graph)
{
    int v;
    int count = 0;
    for (v = 0; v < graph->V; ++v)
    {
        AdjacencyListNode* pCrawl = graph->array[v].head;
        while (pCrawl)
        {
            count++;
            pCrawl = pCrawl->next;
        }
    }
    double avg = count/graph->V;
    return avg;
}