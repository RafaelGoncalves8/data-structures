/*
 * Lab11 - Rafael Gonçalves
 *
 * Objetivo: Implementar um algoritimo que calcula a diferenca
 * simetrica entre dois conjuntos A e B com tempo de execucao
 * O(nlogn). Para tal, sera usado a estrutura treap.
 */

#include "treap.h"
#include <stdio.h>
#include <string.h>

int
main()
{
  p_treap A, B, tmp; /* Conjuntos A, B e solucao S. */
  int e;    /* Elemento a ser inserido no conjunto. */
  int m, n; /* Numero m de elementos para cada um dos n conjuntos. */
  int i, j; /* Indexadores para os lacos. */

  scanf("%d", &n);

  A = create_treap();

  for (i = 0; i < n; i++)
  {
    B = create_treap();
    scanf("%d", &m);

    for (j = 0; j < m; j++)
    {
      scanf("%d", &e);
      B = insert_elem(B, e);
    }

#if DEBUG
    printf("A: ");
    print_treap(A);
    printf("\nB: ");
    print_treap(B);
    printf("\nS: ");
#endif

    tmp = A;
    A = diff(A, B);

    destroy_treap(tmp);
    destroy_treap(B);

#if DEBUG
    print_treap(A);
    printf("\n");
#endif
  }

  print_treap(A);
  printf("\n");

  destroy_treap(A);

  return 0;
}
