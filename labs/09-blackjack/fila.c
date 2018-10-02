#include "fila.h"
#include "jogador.h"
#include <stdlib.h>
#include <stdio.h>

/* Aloca memoria para uma fila e checa se malloc teve sucesso. */
p_queue
alloc_queue()
{
  p_queue queue;

  queue = (p_queue) malloc(sizeof(QueueNode));
  if (queue == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return queue;
}

/* Cria uma fila vazia (apenas no dummy). */
p_queue
new_queue()
{
  p_queue dummy;

  dummy = alloc_queue();
  dummy->val = DUMMY;
  dummy->next = dummy;

  return dummy;
}

/* Destoi a fila e libera memoria alocada dinamicamente. */
void
destroy_queue(p_queue queue)
{
  p_queue p, tmp;

  p = queue->next->next; /* Primeiro no depois do dummy. */

  while (p->val != DUMMY)
  {
    tmp = p;
    p = p->next;
    destroy_player(tmp->val);
    free(tmp);
  }

  free(p);
}

/* Insere elemento no inicio da fila. */
p_queue
enqueue(p_queue queue, p_player p)
{
  p_queue new;

  new = alloc_queue();

  new->next = queue->next;
  new->val = p;
  queue->next = new;

  return new;
}

/* Remove elemento do fim da fila e retorna o valor do mesmo. */
p_player
dequeue(p_queue queue)
{
  p_queue tmp;
  p_player ans;

  if (queue->val != DUMMY)
  {
    tmp = queue->next->next;
    queue->next->next = queue->next->next->next;
    ans = tmp->val;
    free(tmp);
  }
  else
  {
    ans = NULL;
  }

  return ans;
}
