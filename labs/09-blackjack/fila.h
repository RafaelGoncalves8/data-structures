#ifndef fila_h
#define fila_h

#include "jogador.h"

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

#define DUMMY NULL

/* Fila circular. */
typedef struct QueueNodeStruct 
{
  struct QueueNodeStruct * next;
  p_player val;
}
QueueNode;

typedef QueueNode * p_queue_node;

typedef struct QueueStruct
{
  p_queue_node tail;
}
Queue;

typedef Queue * p_queue;

/* Cria uma fila vazia (apenas no dummy). */
p_queue
new_queue();

/* Destoi a fila e libera memoria alocada dinamicamente. */
void
destroy_queue(p_queue queue);

/* Insere elemento no topo da fila. */
void
enqueue(p_queue queue, p_player p);

/* Remove elemento do topo da fila e retorna o valor do mesmo. */
p_player
dequeue(p_queue queue);

p_player
first(p_queue queue);

#endif
