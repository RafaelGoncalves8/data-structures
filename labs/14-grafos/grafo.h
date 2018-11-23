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
  p_node * v; /* Lista de adjacencias. */
  int * vals; /* Valores de idade de cada vertice. */
  int n;      /* Numero de vertices no grafo. */
}
Graph;

typedef Graph * p_graph;

/* Aloca memoria dinamicamente para um vetor de n inteiros. */
int *
alloc_vec(int n);

/* Cria grafo g com vetor de idades v de tamanho n. */
p_graph
create_graph(int * v, int n);

/* Destroi estrutura de grafo g. */
void
destroy_graph(p_graph g);

/* Adiciona aresta entre u e v. */
p_graph
add_edge(p_graph g, int u, int v);

/* Imprime vertices em grupos entediados. */
void
print_bored(p_graph g);

#endif
