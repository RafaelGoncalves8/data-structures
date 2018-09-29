#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

p_stack
alloc_stack()
{
  p_stack stack;

  stack = (p_stack) malloc(sizeof(StackNode));
  if (stack == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return stack;
}


/* Aloca memoria dinamicamente e cria uma pilha vazia. */
p_stack
new_stack()
{
  return NULL;
}

/* Insere elemento no topo da pilha. */
p_stack
push(p_stack stack, int c)
{
  p_stack new;

  new = alloc_stack();
  new->val = c;
  new->next = stack;

  return new;
}

/* Remove elemento do topo da pilha e retorna o valor do mesmo. */
int
pop(p_stack stack)
{
  int ans;
  p_stack tmp;

  tmp = stack;
  ans = stack->val;
  stack = stack->next;

  free(tmp);

  return ans;
}

/* Retorna o valor do elemento no topo da pilha. */
int
top(p_stack stack)
{
  return stack->val;
}

/* Destoi a pilha e libera memoria alocada dinamicamente. */
void
destroy_stack(p_stack stack)
{
  while (stack != NULL)
    pop(stack);
}
