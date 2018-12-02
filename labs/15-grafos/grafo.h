#ifndef grafo_h
#define grafo_h

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

#define DUMMY -1

typedef struct node
{
  int val;
  struct node * next;
}
Node;

typedef Node * p_node;

typedef struct queue
{
  p_node tail;
}
Queue;

typedef Queue * p_queue;

typedef struct graph
{
  p_node * v; /* Lista de adjacencias. */
  int n;      /* Numero de vertices no grafo. */
}
Graph;

typedef Graph * p_graph;

/* Aloca memoria dinamicamente para um vetor de n inteiros. */
int *
alloc_vec(int n);

/* Cria grafo g de tamanho n. */
p_graph
create_graph(int n);

/* Destroi estrutura de grafo g. */
void
destroy_graph(p_graph g);

/* Adiciona aresta entre u e v. */
p_graph
add_edge(p_graph g, int u, int v);

/* Cria grupo (aresta entre os membros) com membros em v no grafo g. */
p_graph
create_group(p_graph g, int * v, int n);

/* Imprime membros sem conexao e grau maximo de distancia. */
void
print_connections(p_graph g);

#endif
