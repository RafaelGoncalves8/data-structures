#ifndef grafo_h
#define grafo_h

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

typedef struct node
{
  int val;
  struct node * next;
}
Node;

typedef Node * p_node;

typedef struct graph
{
  p_node * v;
  int * vals;
  int n;
}
Graph;

typedef Graph * p_graph;

p_graph
create_graph(int * v, int n);

void
destroy_graph(p_graph g);

p_graph
add_edge(p_graph g, int u, int v);

void
print_bored(p_graph g);

#endif
