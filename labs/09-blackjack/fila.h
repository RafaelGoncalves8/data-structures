#ifndef fila_h
#define fila_h

#include "jogador.h"

/* Fila circular. */
typedef struct QueueNodeStruct 
{
  struct QueueNodeStruct * next;
  p_player val;
}
QueueNode;

typedef QueueNode * p_queue;

/* Aloca memoria dinamicamente e cria uma fila vazia. */
p_queue
new_queue();

/* Destoi a fila e libera memoria alocada dinamicamente. */
p_queue
destroy_queue(p_queue queue);

/* Insere elemento no topo da fila. */
void
enqueue(p_queue queue);

/* Remove elemento do topo da fila e retorna o valor do mesmo. */
char
dequeue(p_queue queue);

/* Retorna o valor do elemento no topo da fila. */
char
top(p_queue queue);

#endif
