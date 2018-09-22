/*
 * Lab 08
 * Rafael Gonçalves
 *
 * Objetivo: Representar numeros inteiros muito grandes usando listas ligadas
 * e implementar a operacao de soma entre esse novo tipo de dado que chamei de
 * struct DistStruct na interface 'numero_astronomico.h'.
 */

#include "numero_astronomico.h"
#include <stdio.h>
#include <stdlib.h>

int
main()
{
  char c; /* Caracteres de entrada. */

  p_dist dist;     /* Struct representando a soma das distancias. */
  p_dist tmp_dist; /* Struct que guarda temporariamente cada distancia
                    a ser somada */

  dist = new_dist();
  tmp_dist = new_dist();
  scanf(" %c", &c);
  while (c == '+')
  {
    /* Ignora zeros à esquerda. */
    scanf(" %c", &c);
    while (c == '0')
      scanf(" %c", &c);

    /* Armazena em new_dist cada distancia a ser somada. */
    while (c != '+' && c != '#') 
    {
      tmp_dist = add_tail_dist(tmp_dist, c);
      scanf(" %c", &c);
    }

    /*
     * Soma a distancia armazenada, destroi lista temporaria
     * e imprime distancia acumulada.
     */
    dist = add_dist(dist, tmp_dist);
    tmp_dist = destroy_dist(tmp_dist);
    print_dist(dist);
  }

  /* Libera memoria alocada dinamicamente. */
  dist = destroy_dist(dist);

  free(dist);
  free(tmp_dist);

  return 0;
}
