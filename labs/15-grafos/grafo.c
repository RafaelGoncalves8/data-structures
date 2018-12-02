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

/*
 * Aloca dinamicamente espaco na memoria para o tipo Queue e
 * devolve um ponteiro para a regiao de memoria alocada.
 */
p_queue
alloc_queue()
{
  p_queue queue;

  queue = (p_queue) malloc(sizeof(Queue));
  if (queue == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return queue;
}

/* Cria uma fila vazia (apenas o no dummy). */
p_queue
new_queue()
{
  p_queue queue;
  p_node dummy;

  queue = alloc_queue();

  dummy = alloc_node();
  dummy->val = DUMMY;
  dummy->next = dummy;

  queue->tail = dummy;

  return queue;
}

/* Destoi a fila e libera memoria alocada dinamicamente. */
void
destroy_queue(p_queue queue)
{
  p_node p, tmp;

  p = queue->tail->next->next; /* Primeiro no depois do dummy. */

  while (p->val != DUMMY)
  {
    tmp = p;
    p = p->next;
    free(tmp);
  }

  free(p);
  free(queue);
}

/* Insere elemento no inicio da fila. */
void
enqueue(p_queue queue, int n)
{
  p_node new;

  new = alloc_node();

  new->next = queue->tail->next;
  new->val = n;
  queue->tail->next = new;
  queue->tail = new;
}

/* Remove elemento do fim da fila e retorna o valor do mesmo. */
int
dequeue(p_queue queue)
{
  p_node tmp;
  int ans;

  if (queue->tail->val != DUMMY)
  {
    tmp = queue->tail->next->next;
    queue->tail->next->next = queue->tail->next->next->next;
    ans = tmp->val;
    if (queue->tail == tmp)
      queue->tail = queue->tail->next;
    free(tmp);
  }
  else
  {
    ans = DUMMY;
  }

  return ans;
}

/* Retorna o valor do primeiro no da fila. */
int
empty_queue(p_queue queue)
{
  return (queue->tail->val == DUMMY);
}

/* Cria grafo g de tamanho n. */
p_graph
create_graph(int n)
{
  int i;
  p_graph g;

  g = alloc_graph();
  g->v = alloc_vertex(n);
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
        destroy_list(g->v[i]);
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

/* Cria grupo (aresta entre os membros) com membros em v no grafo g. */
p_graph
create_group(p_graph g, int * v, int n)
{
  int i, j;

  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      g = add_edge(g, i, j);

  return g;
}

/* Retorna 1 se aresta (u, v) existe, 0 caso contrario. */
int
is_edge(p_graph g, int u, int v)
{
  int ans = 0;
  p_node aux;

  for (aux = g->v[u]; aux != NULL && !ans; aux = aux->next)
    ans = (ans || (aux->val == v));
  return ans;
}

/* Busca em largura. */
int *
bfs(p_graph g, int n)
{
  int w, v;
  int * fat = alloc_vec(g->n);
  int * deg = alloc_vec(g->n);
  int * visited = alloc_vec(g->n);
  p_queue q = new_queue();

  for (v = 0; v < g->n; v++)
  {
    fat[v] = -1;
    deg[v] = -1;
    visited[v] = 0;
  }

  enqueue(q, n);
  fat[n] = n;
  visited[n] = 1;

  while(!empty_queue(q))
  {
    v = dequeue(q);
    for (w = 0; w < g->n; w++)
    {
      if (is_edge(g, v, w) && !visited[w])
      {
        visited[w] = 1;
        if (deg[w] < 0)
          deg[w]++;
        deg[w]++; /* ? */
        fat[w] = v;
        enqueue(q, w);
      }
    }
  }
  destroy_queue(q);
  free(visited);

  return deg;
}

/* Imprime elementos impossiveis de serem alcancados pelo vertice i. */
void
print_unreachable(int * v, int n)
{
  int i;

  for (i = 0; i < n; i++)
    if (v[i] == -1)
      printf("%d ", i);
}

/* Imprime maior elemento do vetor. */
void
print_max(int * v, int n)
{
  int i;
  int max = 0;

  for (i = 0; i < n; i++)
    if (v[i] > max)
      max = v[i];

  printf("%d", max);
}

/* Imprime membros sem conexao e grau maximo de distancia. */
void
print_connections(p_graph g)
{
  int i;
  int * aux;

  for (i = 0; i < g->n; i++)
  {
    aux = bfs(g, i);
    print_unreachable(aux, g->n);
    printf("- ");
    print_max(aux, g->n);
    printf("\n");
    free(aux);
  }
}
