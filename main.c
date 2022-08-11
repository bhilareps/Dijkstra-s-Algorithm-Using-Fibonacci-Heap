#include"fibheap.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include"graph.h"
#include"./MinFibHeap/minheap.h"

void dijkstra(struct Graph* graph, int src)
{
	int V = graph->V;
	int dist[V];	
	struct MinHeap* Fibheap = createMinHeap(V);
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		Fibheap->array[v] = newMinHeapNode(v,dist[v]);
		Fibheap->pos[v] = v;
	}
	Fibheap->array[src] =newMinHeapNode(src, dist[src]);
	Fibheap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(Fibheap, src, dist[src]);
	Fibheap->size = V;
	while (!isEmpty(Fibheap))
	{
		struct MinHeapNode* FibHeapNode =extractMin(Fibheap);
		int u = FibHeapNode->v;
		struct AdjListNode* temp = graph->array[u].head;
		while (temp != NULL)
		{
			int v = temp->dest;
			if (isInMinHeap(Fibheap, v) && dist[u] != INT_MAX && temp->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + temp->weight;
				decreaseKey(Fibheap, v, dist[v]);
			}
			temp = temp->next;
		}
	}
	printArr(dist, V);
}





int main(int argc, char **argv) 
{
    int chc;
    printf("What do you want to implemennt?\n");
    printf("1.Fibonacci Heap Implementation\n");
    printf("2.Dijstra's Algorithm\n");
    printf("\n Enter your Choice: ");
    scanf("%d",&chc);
    if(chc==1)
    {
        node *new_node, *min_node, *extracted_min, *node_to_be_decrease, *find_use;
      fibheap *heap, *h1, *h2;
      int operation_no, new_key, dec_key, ele, i, no_of_nodes;
      heap = (fibheap *)malloc(sizeof(fibheap));
      heap = NULL;
      while (1) {
        printf(" \n Operations \n 1. Create Fibonacci heap \n 2. Insert nodes into fibonacci heap \n 3. Find min \n 4. Union \n 5. Extract min \n 6. Decrease key \n 7.Delete node \n 8. print heap \n 9. exit \n enter operation_no = ");
        scanf("%d", &operation_no);

        switch (operation_no) {
          case 1:
            heap = make_fib_heap();
            break;

          case 2:
            if (heap == NULL) {
              heap = make_fib_heap();
            }
            printf(" enter number of nodes to be insert = ");
            scanf("%d", &no_of_nodes);
            for (i = 1; i <= no_of_nodes; i++) {
              printf("\n node %d and its key value = ", i);
              scanf("%d", &ele);
              insertion(heap, new_node, ele);
            }
            break;

          case 3:
            min_node = find_min_node(heap);
            if (min_node == NULL)
              printf("No minimum value");
            else
              printf("\n min value = %d", min_node->key);
            break;

          case 4:
            if (heap == NULL) {
              printf("\n no FIbonacci heap created \n ");
              break;
            }
            h1 = insertion_procedure();
            heap = unionHeap(heap, h1);
            printf("Unified Heap:\n");
            print_heap(heap->min);
            break;

          case 5:
            if (heap == NULL)
              printf("Empty Fibonacci heap");
            else {
              extracted_min = extract_min(heap);
              printf("\n min value = %d", extracted_min->key);
              printf("\n Updated heap: \n");
              print_heap(heap->min);
            }
            break;

          case 6:
            if (heap == NULL)
              printf("Fibonacci heap is empty");
            else {
              printf(" \n node to be decreased = ");
              scanf("%d", &dec_key);
              printf(" \n enter the new key = ");
              scanf("%d", &new_key);
              find_use = heap->min;
              find_node(heap, find_use, dec_key, new_key);
              printf("\n Key decreased- Corresponding heap:\n");
              print_heap(heap->min);
            }
            break;
          case 7:
            if (heap == NULL)
              printf("Fibonacci heap is empty");
            else {
              printf(" \n Enter node key to be deleted = ");
              scanf("%d", &dec_key);
              Delete_Node(heap,dec_key);
              printf("\n node Deleted- Corresponding heap:\n");
              print_heap(heap->min);
              break;
            }
          case 8:
            print_heap(heap->min);
            break;

          case 9:
            free(new_node);
            free(heap);
            exit(0);

          default:
            printf("Invalid choice ");
        }
      }
    }
    else if (chc==2)
    {
      int V = 9;
      struct Graph* graph = createGraph(V);
      FILE *fp;
      fp=fopen("graph.txt","r");
      int x;
      fscanf(fp,"%d",&x);
      int v=x;
      for (int i = 0; i < v; i++)
      {
        fscanf(fp,"%d",&x);
        int src=x;
        fscanf(fp,"%d",&x);
        int des=x;
        fscanf(fp,"%d",&x);
        int weight=x;
        addEdge(graph, src, des, weight);
      }

      dijkstra(graph, 0);
    }
    else
    {
      printf("Please Enter Valid Number(choice)");
    }
 
}