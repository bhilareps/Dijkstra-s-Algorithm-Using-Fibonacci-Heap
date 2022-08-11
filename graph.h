#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<stdbool.h>


struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};


struct AdjList
{
	struct AdjListNode *head;
};


struct Graph
{
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src,int dest, int weight);
