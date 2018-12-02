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
  int m, n, k;
  int id;
  int * v;
  p_graph g;

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

  print_connections(g);

  destroy_graph(g);

  return 0;
}
