typedef struct NodeStruct 
{
  struct NodeStruct * next;
  char val;
}
Node;

typedef Node * p_node;

/* Aloca memoria dinamicamente e cria uma fila vazia. */
p_node
new_queue();

/* Destoi a fila e libera memoria alocada dinamicamente. */
p_node
destroy_queue(p_node queue);

/* Insere elemento no topo da fila. */
void
enqueue(p_node queue);

/* Remove elemento do topo da fila e retorna o valor do mesmo. */
char
dequeue(p_node queue);

/* Retorna o valor do elemento no topo da fila. */
char
top(p_node queue);
