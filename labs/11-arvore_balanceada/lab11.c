/*
 * Lab11 - Rafael Gonçalves
 *
 * Objetivo: Implementar um algoritimo que calcula a diferenca
 * simetrica entre dois conjuntos A e B com tempo de execucao
 * O(nlogn). Para tal, sera usado a estrutura treap.
 */

#include "treap.h"
#include <stdio.h>

int
main()
{
  p_treap A, B, S; /* Conjuntos A, B e solucao S. */
  int e;    /* Elemento a ser inserido no conjunto. */
  int m, n; /* Numero m de elementos para cada um dos n conjuntos. */
  int i, j; /* Indexadores para os lacos. */

  scanf("%d", &n);

  S = create_treap();

  for (i = 0; i < n; i++)
  {
    A = S;
    destroy_treap(S);

    B = create_treap();
    scanf("%d", &m);

    for (j = 0; j < m; j++)
    {
      scanf("%d", &e);
      B = insert_elem(B, e);
    }

    S = diff(A, B);
  }

  print_treap(S);
  printf("\n");

  destroy_treap(A);
  destroy_treap(B);
  destroy_treap(S);

  return 0;
}
