#include <stdlib.h>

typedef struct NodeStruct
{
  int val;
  struct NodeStruct * next;
  struct NodeStruct * prev;
} Node;

typedef Node * p_node;

typedef struct DequeStruct
{
  p_node head;
  p_node tail;
} Deque;

typedef Deque * p_deque;

p_deque
cria_deque(p_deque p)
{
  p->head = NULL;
  p->tail = NULL;

  return p;
}

void
destroi_deque(p_deque p)
{
  while(p->head != NULL && p->tail != NULL)
  {
    tmp1 = p->head->next;
    tmp2 = p->tail->prev;
    free(p->head);
    free(p->tail);
    p->head = tmp1;
    p->tail = tmp2;
  }
  free(tmp1);
  free(tmp2);
  free(p->head);
  free(p->tail);
}

p_deque
insere_inicio(p_deque p, int val)
{
  p_node tmp;
  tmp = (p_node) malloc(sizeof(Node));
  tmp->val = val;
  tmp->prev = NULL;

  if (p->tail != NULL)
  {
    tmp->next = p->head->next;
    tmp->next->prev = tmp;
    p->head = tmp;
  }
  else
  {
    p->tail = tmp;
    p->head = tmp;
    tmp->next = NULL;
  }

  free(tmp);

  return p;
}

p_deque
insere_fim(p_deque p, int val)
{
  p_node tmp;
  tmp = (p_node) malloc(sizeof(Node));
  tmp->val = val;
  tmp->prev = NULL;

  if (p->tail != NULL)
  {
    tmp->prev = p->tail->prev;
    tmp->prev->next = tmp;
    p->tail = tmp;
  }
  else
  {
    p->tail = tmp;
    p->head = tmp;
    tmp->prev = NULL;
  }

  free(tmp);

  return p;
}

p_deque
remove_inicio(p_deque p)
{
  p_deque tmp;
  p->head->next->prev = NULL;
  tmp = p->head;
  p->head = p->head->next;
  free(tmp);

  return p;
}

p_deque
remove_fim(p_deque p)
{
  p_deque tmp;
  p->tail->prev->next = NULL;
  tmp = p->tail;
  p->tail = p->tail->prev;
  free(tmp);

  return p;
}

int
main()
{
  return 0;
}
