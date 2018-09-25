#include "numero_astronomico.h"
#include <stdlib.h>
#include <stdio.h>

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/* Aloca memoria para ponteiro para Node. */
p_node
alloc_node()
{
  p_node node;
  node = (p_node) malloc(sizeof(Node));
  if (node == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return node;
}

/* Aloca memoria para ponteiro para Dist. */
p_dist
alloc_dist()
{
  p_dist dist;
  dist = (p_dist) malloc(sizeof(Dist));
  if (dist == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return dist;
}

/* Cria dist vazia. */
p_dist
new_dist()
{
  p_dist dist;

  dist = alloc_dist();

  dist->head = NULL;
  dist->tail = NULL;

  return dist;
}

/* Adiciona elemento (digito) no fim (tail) da lista ligada. */
p_dist
add_tail_dist(p_dist dist, char c)
{
  p_node new; 

  new = alloc_node();
  new->val = c;
  new->next = NULL;

  if (dist->head == NULL)
  {
    new->prev = NULL;
    dist->tail = new;
    dist->head = new;
  }
  else
  {
    new->prev = dist->tail;
    dist->tail->next = new;
    dist->tail = new;
  }

  return dist;
}

/* Adiciona elemento (digito) no inicio (head) da lista ligada. */
p_dist
add_head_dist(p_dist dist, char c)
{
  p_node new;

  new = alloc_node();
  new->val = c;
  new->prev = NULL;

  if (dist->tail == NULL)
  {
    new->next = NULL;
    dist->head = new;
    dist->tail = new;
  }
  else
  {
    new->next = dist->head;
    dist->head->prev = new;
    dist->head = new;
  }

  return dist;
}

/* Soma duas distancias (soma listas ligadas elemento a elemento). */
p_dist
add_dist(p_dist d1, p_dist d2)
{
  p_dist ans;    /* Nova dist que sera a soma de d1 e d2. */
  p_node p, q;   /* Posicao de d1 e d2, respectivamente. */
  int val;       /* Valor de cada elemento de ans. */
  int  overflow; /* Flag de overflow da soma. */

  p = d1->tail;
  q = d2->tail;

  ans = alloc_dist();
  ans = new_dist();

  overflow = 0;
  while (p != NULL && q != NULL) /* Enquanto ha elemento em d1 e d2. */
  {
    val = (p->val - '0') + (q->val - '0') + overflow;
    if (val >= 10)
    {
      val -= 10;
      overflow = 1;
    }
    else
    {
      overflow = 0;
    }
    ans = add_head_dist(ans, val + '0');
    p = p->prev;
    q = q->prev;
  }

  if (p == NULL) /* Se nao ha elemento em d1. */
  {
    while (q != NULL)
    {
      val = (q->val - '0') + overflow;
      if (val >= 10)
      {
        val -= 10;
        overflow = 1;
      }
      else
      {
        overflow = 0;
      }
      ans = add_head_dist(ans, val + '0');
      q = q->prev;
    }
  }
  else /* q == NULL. Nao ha elemento em d2. */
  {
    while (p != NULL)
    {
      val = (p->val - '0') + overflow;
      if (val >= 10)
      {
        val -= 10;
        overflow = 1;
      }
      else
      {
        overflow = 0;
      }
      ans = add_head_dist(ans, val + '0');
      p = p->prev;
    }
  }

  if (overflow == 1)
    ans = add_head_dist(ans, overflow + '0');

  free(p);
  free(q);

  d1 = destroy_dist(d1);

  return ans;
}

/* Imprime numero astronomico. */
void
print_dist(p_dist dist)
{
  p_node p;

  p = dist->head;

  while (p != NULL)
  {
    printf("%c", p->val);
    p = p->next;
  }
  printf("\n");
}

/* Remove todos os elementos da lista ligada, libera memoria de dist  e devolve NULL. */
p_dist
destroy_dist(p_dist dist)
{
  p_node p;
  p_node next_p;

  p = dist->head;

  while (p != NULL)
  {
    next_p = p->next;
    free(p);
    p = next_p;
  }

  free(dist);

  return NULL;
}
