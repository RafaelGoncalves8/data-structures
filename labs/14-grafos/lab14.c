/*
 * Lab 14
 * Rafael Gonçalves
 *
 * Objetivos: Usar a estrutura de grafos para representar grupos de
 * pessoas, identificar padrao de pessoas entediadas e imprimir
 * pessoas em grupos entediados em ordem crescente.
 */

#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

int
M(int x)
{
  return ( (int) sum(x)/3);
}

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


int
main()
{
  int i;      /* Indexador para vertices e arestas. */
  int m, n;   /* Numero de pessoas n, numero de relacoes (arestas) m. */
  int u, v;   /* Vertices u e v de cada aresta entre u e v. */
  int *ages;  /* Vetor das idades das n pessoas do grafo. */
  p_graph g;  /* Grafo f para representar as pessoas e as relacoes. */

  scanf("%d %d", &n, &m);

  ages = alloc_vec(n);

  for (i = 0; i < n; i++)
    scanf("%d", &ages[i]);

  g = create_graph(ages);
  free(ages);

  for (i = 0; i < m; i++)
  {
    scanf("%d %d", u, v);
    g = add_edge(g, u, v);
  }

  print_bored(g);

  destroy_graph(g);

  return 0;
}
