#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

int
M(int * x, int n)
{
  float sum = 0;
  int i;

  for (i = 0; i < n; i++)
    sum += x[i];

  return ( (int) sum/3);
}

p_node
alloc_node()
{
  p_node n;

  n = (p_node) malloc(sizeof(Node));
  if (n == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return n;
}

p_node *
alloc_vertex(int n)
{
  p_node *v;

  v = (p_node *) malloc(n * sizeof(p_node));
  if (v == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return v;
}


p_graph
alloc_graph()
{
  p_graph g;

  g = (p_graph) malloc(sizeof(Graph));
  if (g == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return g;
}

p_graph
create_graph(int * v, int n)
{
  int i;
  p_graph g;

  g = alloc_graph();
  g->v = alloc_vertex(n);
  g->vals = v;
  g->n = n;

  for (i = 0; i < n; i++)
    g->v[i] = NULL;

  return g;
}

void destroy_list(p_node l)
{
  if (l != NULL)
  {
    destroy_list(l->next);
    free(l);
  }
}

void
destroy_graph(p_graph g)
{
  int i;
  if (g != NULL)
  {
    if (g->v != NULL)
    {
      for (i = 0; i < g->n; i++)
      {
        destroy_list(g->v[i]->next);
        free(g->v[i]);
      }
      free(g->v);
    }
    free(g);
  }
}

p_node
add_node(p_node l, int n)
{
  p_node new;
  new = alloc_node();

  new->val = n;
  new->next = l;

  return new;
}


p_graph
add_edge(p_graph g, int u, int v)
{
  g->v[u] = add_node(g->v[u], v);
  g->v[v] = add_node(g->v[v], u);

  return g;
}

void
print_bored(p_graph g)
{
}
