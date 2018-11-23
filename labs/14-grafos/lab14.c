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

int
main()
{
  int i;     /* Indexador para vertices e arestas. */
  int m, n;  /* Numero de pessoas n, numero de relacoes (arestas) m. */
  int u, v;  /* Vertices u e v de cada aresta entre u e v. */
  int *ages; /* Vetor das idades das n pessoas do grafo. */
  int num = 0; /* Numero de pessoas no vetor ages. */
  p_graph g; /* Grafo f para representar as pessoas e as relacoes. */

  scanf("%d %d", &n, &m);

  ages = alloc_vec(n);

  for (i = 0; i < n; i++)
  {
    scanf("%d", &ages[i]);
    num++;
  }

#if DEBUG
  printf("Read ages.\n");
#endif

  g = create_graph(ages, num);

  for (i = 0; i < m; i++)
 {
    scanf("%d %d", &u, &v);
    g = add_edge(g, u, v);
  }

#if DEBUG
  printf("Created graph.\n");
#endif

  print_bored(g); 

  free(ages);
  destroy_graph(g);

  return 0;
}
