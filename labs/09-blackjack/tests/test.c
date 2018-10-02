#include "../fila.h"
#include "../pilha.h"
#include <stdio.h>

void
test_stack()
{
  p_stack s;

  s = new_stack();
  printf("New stack created.\n");

  s = push(s, 2);
  printf("Pushed 2 onto stack.\n");
  s = push(s, 5);
  printf("Pushed 5 onto stack.\n");
  printf("Popped %d from stack.\n", pop(&s));
  printf("Top of stack: %d\n", top(s));

  destroy_stack(s);
}


p_player
test_jogador()
{
  p_player p;

  p = new_player();
  printf("    New player created.\n");
  p = add_card(p, 1);
  printf("    Added new ace.\n");
  p = add_card(p, 2);
  printf("    Added new card (2).\n");

  printf("    p->n_aces: %d\n", p->n_aces);
  printf("    p->sum_others: %d\n", p->sum_others);
  printf("    get_score(p): %d\n", get_score(p));

  return p;
}

void
test_fila()
{
  p_queue q;
  p_player p1, p2, p3;

  q = new_queue();
  printf("New queue created.\n");

  p1 = test_jogador();
  p2 = test_jogador();

  q = enqueue(q, p1);
  printf("p1 enqueued.\n");
  q = enqueue(q, p2);
  printf("p2 enqueued.\n");
  p3 = dequeue(q);
  printf("p1 dequeued.\n");

  destroy_player(p3);

  destroy_queue(q);
}

int
main()
{
  test_fila();
  printf("\n");
  test_stack();

  return 0;
}
