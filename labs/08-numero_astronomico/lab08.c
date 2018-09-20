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

  p_dist dist;     /* Struct representando a soma das distancias. */
  p_dist new_dist; /* Struct que guarda temporariamente cada distancia
                    a ser somada */

  dist = new_dist();
  scanf("%c ", &c);
  while (c == '+')
  {
    /* (Re)inicializa a lista ligada como lista vazia. */
    new_dist = new_dist();

    /* Ignora zeros à esquerda. */
    scanf("%c ", c);
    while (c == '0')
      scanf("%c ", c);

    /* Armazena em new_dist cada distancia a ser somada. */
    while (c != '#' && c != '+') 
    {
      new_dist = add_digit_dist(new_dist, c);

      scanf("%c ", &c);
    }

    /* Soma a distancia armazenada e imprime distancia acumulada. */
    dist = add_dist(dist, new_list);
    print_dist(dist);
  }

  /* Libera memoria alocada dinamicamente. */
  dist = destroy_dist(dist);
  new_dist = destroy_dist(new_dist);

  free(dist);
  free(new_dist);

  return 0;
}
