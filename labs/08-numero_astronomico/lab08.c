/*
 * Lab 08
 * Rafael Gonçalves
 *
 * Objetivo:
 *
 */

#include "numero_astronomico.h"
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  char c; /* Caractere de entrada. */
  char d; /* Digito de cada distancia a ser somada. */

  p_dist dist;     /* Lista representando a soma das distancias. */
  p_dist new_dist; /* Lista que guarda temporariamente cada distancia
                    a ser somada */

  dist = new_dist();
  scanf("%c ", &c);
  while (c == '+')
  {
    /* (Re)inicializa a lista ligada como lista vazia. */
    new_dist = new_dist();

    scanf("%c ", d);

    /* Armazena em new_dist cada distancia a ser somada. */
    while (d != '#' && d != '+') 
    {
      new_dist = add_digit_dist(new_dist, d);

      scanf("%c ", &d);
    }

    /* Soma a distancia armazenada e imprime distancia acumulada. */
    dist = add_dist(dist, new_list);
    print_dist(dist);
    c = d;
  }

  /* Libera memoria alocada dinamicamente. */
  dist = destroy_dist(dist);
  new_dist = destroy_dist(new_dist);

  free(dist);
  free(new_dist);

  return 0;
}
