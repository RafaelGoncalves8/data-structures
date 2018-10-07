#include "fila.h"
#include "jogador.h"
#include <stdlib.h>
#include <stdio.h>

p_queue_node
alloc_queue_node()
{
  p_queue_node queue_node;

  queue_node = (p_queue_node) malloc(sizeof(QueueNode));
  if (queue_node == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return queue_node;
}

/* Aloca memoria para uma fila e checa se malloc teve sucesso. */
p_queue
alloc_queue()
{
  p_queue queue;

  queue = (p_queue) malloc(sizeof(Queue));
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
  p_queue queue;
  p_queue_node dummy;

  queue = alloc_queue();

  dummy = alloc_queue_node();
  dummy->val = DUMMY;
  dummy->next = dummy;

  queue->tail = dummy;

  return queue;
}

/* Destoi a fila e libera memoria alocada dinamicamente. */
void
destroy_queue(p_queue queue)
{
  p_queue_node p, tmp;

  p = queue->tail->next->next; /* Primeiro no depois do dummy. */

  while (p->val != DUMMY)
  {
    tmp = p;
    p = p->next;
    destroy_player(tmp->val);
    free(tmp);
  }

  free(p);
  free(queue);
}

/* Insere elemento no inicio da fila. */
void
enqueue(p_queue queue, p_player p)
{
  p_queue_node new;

  new = alloc_queue_node();

  new->next = queue->tail->next;
  new->val = p;
  queue->tail->next = new;
  queue->tail = new;
}

/* Remove elemento do fim da fila e retorna o valor do mesmo. */
p_player
dequeue(p_queue queue)
{
  p_queue_node tmp;
  p_player ans;

  if (queue->tail->val != DUMMY)
  {
    tmp = queue->tail->next->next;
    queue->tail->next->next = queue->tail->next->next->next;
    ans = tmp->val;
    if (queue->tail == tmp)
      queue->tail = queue->tail->next;
    free(tmp);
  }
  else
  {
    ans = NULL;
  }

  return ans;
}

p_player
first(p_queue queue)
{
  return queue->tail->next->next->val;
}
