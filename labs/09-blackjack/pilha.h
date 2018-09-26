#define MAX_CHAR 3

typedef struct NodeStruct 
{
  struct NodeStruct * next;
  char val[MAX_CHAR];
}
Node;

typedef Node * p_node;

/* Aloca memoria dinamicamente e cria uma pilha vazia. */
p_node
new_stack();

/* Destoi a pilha e libera memoria alocada dinamicamente. */
p_node
destroy_stack(p_node stack);

/* Insere elemento no topo da pilha. */
void
push(p_node stack);

/* Remove elemento do topo da pilha e retorna o valor do mesmo. */
char *
pop(p_node stack);

/* Retorna o valor do elemento no topo da pilha. */
char *
top(p_node stack);


