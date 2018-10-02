#include "fila.h"
#include "pilha.h"
#include <stdio.h>

p_player
test_jogador()
{
  p_player p;

  p = new_player();
  printf("New player created.\n");
  p = add_card(p, 1);
  printf("Added new ace.\n");
  p = add_card(p, 2);
  printf("Added new ace.\n");

  printf("p->n_aces: %d\n", p->n_aces);
  printf("p->sum_others: %d\n", p->sum_others);
  printf("get_score(p): %d\n", get_score(p));

  return p;
}

p_queue
test_fila()
{
  p_queue q;

  q = new_queue();
  printf("New queue created.\n");

  return q;
}

int
main()
{
  p_player p;

  p = test_jogador();

  destroy_player(p);
  printf("Player destroyed.\n");

  return 0;
}
