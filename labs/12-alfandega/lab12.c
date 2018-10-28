#include "heap.h"
#include <stdio.h>

/* Numero maximo de caracteres no nome. */
#define MAX 20

int
main()
{
  int n; /* Numero de linhas de entrada. */
  int w; /* Peso de cada elemento. */
  char name[MAX]; /* Nome de cada elemento. */
  p_max_min_heap heaps; /* Estrutura que preserva a mediana na raiz. */
  int i; /* Variavel indexadora para o laco for. */

  scanf("%d", &n);

  heaps = create_heaps(n);

  for (i = 0; i < n; i++)
  {
    scanf(" %s %d", name, &w);

    add_to_heaps(name, w, heaps);
#if DEBUG
    print_median(heaps);
#endif
    balance_heaps(heaps);
    print_median(heaps);
  }

  destroy_heaps(heaps);

  return 0;
}
