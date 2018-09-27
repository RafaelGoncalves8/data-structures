#ifndef pilha_h
#define pilha_h

#define MAX_CHAR 3

typedef struct StackNodeStruct 
{
  struct StackNodeStruct * next;
  int val;
}
StackNode;

typedef StackNode * p_stack;

/* Aloca memoria dinamicamente e cria uma pilha vazia. */
p_stack
new_stack();

/* Destoi a pilha e libera memoria alocada dinamicamente. */
p_stack
destroy_stack(p_stack stack);

/* Insere elemento no topo da pilha. */
void
push(p_stack stack, int c);

/* Remove elemento do topo da pilha e retorna o valor do mesmo. */
int
pop(p_stack stack);

/* Retorna o valor do elemento no topo da pilha. */
int
top(p_stack stack);

#endif
