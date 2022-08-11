#include"graph.h"


struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode =(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct AdjList*)
	malloc(V * sizeof(struct AdjList));
	for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
	return graph;
}

void addEdge(struct Graph* graph, int src,int dest, int weight)
{
	struct AdjListNode* newNode =newAdjListNode(dest, weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	newNode = newAdjListNode(src, weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}