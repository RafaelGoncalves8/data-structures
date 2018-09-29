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

typedef QueueNode * p_queue;

/* Aloca memoria para uma fila e checa se malloc teve sucesso. */
p_queue
alloc_queue();

/* Cria uma fila vazia (apenas no dummy). */
p_queue
new_queue();

/* Destoi a fila e libera memoria alocada dinamicamente. */
void
destroy_queue(p_queue queue);

/* Insere elemento no topo da fila. */
p_queue
enqueue(p_queue queue, p_player p);

/* Remove elemento do topo da fila e retorna o valor do mesmo. */
p_player
dequeue(p_queue queue);

/* Retorna o valor do elemento no topo da fila. */
p_player
first(p_queue queue);

#endif
