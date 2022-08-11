
#include <stdbool.h>


typedef struct node {
  int key;
  int degree;
  struct node *left_sibling;
  struct node *right_sibling;
  struct node *parent;
  struct node *child;
  bool mark;
  bool visited;
} node;

typedef struct fibheap {
  int n;
  node *min;
  int phi;
  int degree;
} fibheap;

fibheap *make_fib_heap();
void insertion(fibheap *H, node *neww, int val);
node *extract_min(fibheap *H);
void consolidate(fibheap *H);
void fib_heap_link(fibheap *H, node *y, node *x);
node *find_min_node(fibheap *H);
void decrease_key(fibheap *H, node *node, int key);
void cut(fibheap *H, node *node_to_be_decrease, node *parent_node);
void cascading_cut(fibheap *H, node *parent_node);
void Delete_Node(fibheap *H, int dec_key);
fibheap *insertion_procedure();
void print_heap(node *n);
void *find_node(fibheap *H, node *n, int key, int new_key);
fibheap *unionHeap(fibheap *H1, fibheap *H2);

