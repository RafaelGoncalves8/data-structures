/* Rafael Gonçalves
 *
 * Objetivo: Usar uma estrutura de grafo para representar grupos
 * de amigos e então descobrir o grau maximo de distancia entre
 * amigos por meio de um algoritimo de busca em largura.
 */

#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  int i, j;
  int m, n, k; /* m membros por grupo, n pessoas, k grupos. */
  int id;
  int * v; /* Lista de membros por grupo. */
  p_graph g; /* Grafo. */

  scanf("%d %d", &n, &k);
  g = create_graph(n);

  for (i = 0; i < k; i++)
  {
    scanf("%d", &m);
    v = alloc_vec(m);
    for (j = 0; j < m; j++)
    {
      scanf("%d", &id);
      v[j] = id;
    }
    g = create_group(g, v, m);
    free(v);
  }
#if DEBUG
  printf("created graph\n");
#endif

  print_connections(g);
#if DEBUG
  printf("done bfs\n");
#endif

  destroy_graph(g);

  return 0;
}
