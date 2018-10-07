#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Aloca dinamicamente espaco na memoria para o tipo StackNode e
 * devolve um ponteiro para a regiao de memoria alocada.
 */
p_stack_node
alloc_stack_node()
{
  p_stack_node stack_node;

  stack_node = (p_stack_node) malloc(sizeof(StackNode));
  if (stack_node == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return stack_node;
}

/*
 * Aloca dinamicamente espaco na memoria para o tipo Stack e
 * devolve um ponteiro para a regiao de memoria alocada.
 */
p_stack
alloc_stack()
{
  p_stack stack;

  stack = (p_stack) malloc(sizeof(Stack));
  if (stack == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return stack;
}


/* Cria uma pilha vazia. */
p_stack
new_stack()
{
  p_stack stack = alloc_stack();

  stack->top = NULL;

  return stack;
}

/* Insere elemento no topo da pilha. */
void
push(p_stack stack, int c)
{
  p_stack_node new;

  new = alloc_stack_node();
  new->val = c;
  new->next = stack->top;

  stack->top = new;
}

/* Remove elemento do topo da pilha e retorna o valor do mesmo. */
int
pop(p_stack stack)
{
  int ans;
  p_stack_node tmp;

  tmp = stack->top;
  ans = stack->top->val;
  stack->top = stack->top->next;

  free(tmp);

  return ans;
}

/* Retorna o valor do elemento no topo da pilha. */
int
top(p_stack stack)
{
  return stack->top->val;
}

/* Destoi a pilha e libera memoria alocada dinamicamente. */
void
destroy_stack(p_stack stack)
{
  while (stack->top != NULL)
    pop(stack);

  free(stack);
}
