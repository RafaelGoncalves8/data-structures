/* Cria lista ligada vazia. */
p_dist
new_dist(p_dist dist)
{
  dist->head = NULL;
  dist->tail = NULL;

  return dist;
}

/* Adiciona elemento (digito) no fim (tail) da lista ligada. */
p_dist
add_tail_dist(p_dist dist, char c)
{
  tmp = (LinkedList *) malloc(sizeof(LinkedList));
  dist->tail->val = c;
  dist->tail->next->prev = tmp;
  dist->tail = tmp;
  if (dist->head == NULL)
    dist->head = tmp;

  return dist;
}

/* Adiciona elemento (digito) no inicio (head) da lista ligada. */
p_dist
add_head_dist(p_dist dist, char c)
{
  tmp = (LinkedList *) malloc(sizeof(LinkedList));
  dist->head->val = c;
  dist->head->prev->next = tmp;
  dist->head = tmp;
  if (dist->tail == NULL)
    dist->tail = tmp;

  return dist;
}

/* Soma duas distancias (soma listas ligadas elemento a elemento). */
p_dist
add_dist(p_dist d1, p_dist d2)
{
  LinkedList * p, q;
  int val, overflow;
  p = d1->tail;
  q = d2->tail;

  overflow = 0;
  while (p != NULL && q != NULL)
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
  }

  if (p == NULL)
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
    }
  }
  else /* q == NULL. */
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
    }
  }

  free(p);
  free(q);

  return ans;
}

/* Remove todos os elementos da lista ligada e devolve lista vazia. */
p_dist
destroy_dist(p_dist dist)
{
  LinkedList * p, tmp;
  p = dist->tail;
  while (p != NULL)
  {
    tmp = p;
    free(tmp);
    p = p->prev;
  }

  free(dist->head);
  free(dist->tail);
  free(p);
  free(tmp);

  return dist;
}
