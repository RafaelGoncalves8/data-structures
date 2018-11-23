#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

/* Aloca memoria dinamicamente para um vetor de n inteiros. */
int *
alloc_vec(int n)
{
  int * v;

  v = (int *) malloc(n * sizeof(int));
  if (v == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return v;
}

/* Aloca memoria dinamicamente para no de lista ligada. */
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

/* Aloca memoria dinamicamente para vetor de listas ligadas de tamanho n. */
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

/* Aloca memoria dinamicamente para a estrutura grafo. */
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

/* Cria grafo g com vetor de idades v de tamanho n. */
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

/* Destroi lista l. */
void destroy_list(p_node l)
{
  if (l != NULL)
  {
    destroy_list(l->next);
    free(l);
  }
}

/* Destroi estrutura de grafo g. */
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

/* Adiciona no em lista ligada. */
p_node
add_node(p_node l, int n)
{
  p_node new;
  new = alloc_node();

  new->val = n;
  new->next = l;

  return new;
}

/* Adiciona aresta entre u e v. */
p_graph
add_edge(p_graph g, int u, int v)
{
  g->v[u] = add_node(g->v[u], v);
  g->v[v] = add_node(g->v[v], u);

  return g;
}

/* Retorna 1 se o vertice n esta em grupo entediado, 0 caso contrario. */
int
is_bored(p_graph g, int n)
{
  float m;
  int ans = 0;
  p_node p, q, r;

  /* Para cada amigo de n. */
  for (p = g->v[n]; !ans && p != NULL; p = p->next)
  {
    /* Para cada amigo do amigo de n. */
    for (q = g->v[p->val]; !ans && q != NULL; q = q->next)
    {
      /* Para cada amigo do amigo do amigo de n. */
      for (r = g->v[q->val]; !ans && r != NULL; r = r->next)
      {
        /* Se eh um grupo. */
        if (r->val == n)
        {
          /* Calcula m e compara com as idades. */
          m = g->vals[p->val] + g->vals[q->val] + g->vals[n];
          m = m/3;
          if (2*g->vals[p->val] < m
           || 2*g->vals[q->val] < m
           || 2*g->vals[n] < m)
            ans = 1; /* Esta num grupo entediado. */
        }
      }
    }
  }

  return ans;
}

/* Imprime vertices em grupos entediados. */
void
print_bored(p_graph g)
{
  int i;

  for (i = 0; i < g->n; i++)
    if (is_bored(g, i))
      printf("%d\n", i);
}
