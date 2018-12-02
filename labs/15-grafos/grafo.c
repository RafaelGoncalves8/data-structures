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

/* Destroi lista l. */
void
destroy_list(p_node l)
{
  if (l != NULL)
  {
    destroy_list(l->next);
    free(l);
  }
}

/* Cria uma fila vazia. */
p_queue
new_queue()
{
  p_queue queue;

  queue = alloc_queue();
  queue->tail = NULL;
  queue->head = NULL;

  return queue;
}

/* Destoi a fila e libera memoria alocada dinamicamente. */
void
destroy_queue(p_queue queue)
{
  if (queue->tail != NULL)
    destroy_list(queue->tail);
  free(queue);
}

/* Insere elemento no inicio da fila. */
void
enqueue(p_queue queue, int n)
{
  p_node new;

  new = alloc_node();
  new->next = NULL;
  new->val = n;
  if (queue->tail == NULL)
    queue->tail = new;
  else
    queue->head->next = new;
  queue->head = new;
}

/* Remove elemento do fim da fila e retorna o valor do mesmo. */
int
dequeue(p_queue queue)
{
  p_node tmp = queue->tail;
  int ans = tmp->val;

  queue->tail = queue->tail->next;
  if (queue->tail == NULL)
    queue->head = NULL;
  free(tmp);

  return ans;
}

/* Retorna 1 caso fila esteja vazia, 0 caso contrario. */
int
empty_queue(p_queue queue)
{
  return (queue->tail == NULL);
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
      g = add_edge(g, v[i], v[j]);

  return g;
}

/* Retorna 1 se aresta (u, v) existe, 0 caso contrario. */
int
is_edge(p_graph g, int u, int v)
{
  int ans = 0;
  p_node aux;

  for (aux = g->v[u]; aux != NULL && !ans; aux = aux->next)
    ans = (aux->val == v);
  return ans;
}

/* Busca em largura, devolve vetor de graus de separacao no parametro deg. */
void
bfs(p_graph g, int n, int * deg)
{
  int v;
  p_queue q = new_queue(); /* Fila. */
  p_node p; /* Ponteiro auxiliar. */

  for (v = 0; v < g->n; v++)
  {
    deg[v] = 0; /* deg[i] == 0 significa que nao ha conexao entre i e n. */
  }

  enqueue(q, n);
  while(!empty_queue(q))
  {
    v = dequeue(q);
    for (p = g->v[v]; p != NULL; p = p->next)
    {
      if ((!deg[p->val] && p->val != n) && is_edge(g, v, p->val) )
      {
        deg[p->val] = deg[v] + 1;
        enqueue(q, p->val);
      }
    }
  }
  destroy_queue(q);

  deg[n] = -1; /* Grau de conexao dele com ele mesmo. */
}

/* Imprime elementos impossiveis de serem alcancados pelo vertice i. */
void
print_unreachable(int * v, int n)
{
  int i;

  for (i = 0; i < n; i++)
    if (v[i] == 0)
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
  int * aux = alloc_vec(g->n);

  for (i = 0; i < g->n; i++)
  {
    bfs(g, i, aux);
    print_unreachable(aux, g->n);
    printf("- ");
    print_max(aux, g->n);
    printf("\n");
  }
  free(aux);
}
