#ifndef pilha_h
#define pilha_h

#define MAX_CHAR 3

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

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
void
destroy_stack(p_stack stack);

/* Insere elemento no topo da pilha. */
p_stack
push(p_stack stack, int c);

/* Remove elemento do topo da pilha e retorna o valor do mesmo. */
int
pop(p_stack stack);

/* Retorna o valor do elemento no topo da pilha. */
int
top(p_stack stack);

#endif
