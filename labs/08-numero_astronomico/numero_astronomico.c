/* Cria lista ligada vazia. */
p_dist
new_dist(p_dist dist)
{
  dist->head = NULL;
  dist->tail = NULL;

  return dist;
}

/* Adiciona elemento (digito) no inicio da lista ligada. */
p_dist
add_digit_dist(p_dist dist, char c)
{
  tmp = (LinkedList *) malloc(sizeof(LinkedList));
  dist->tail->val = c;
  dist->tail->next->prev = tmp;
  dist->tail = tmp;
  if (dist->head == NULL)
    dist->head = tmp;

  return dist;
}

/* Soma duas distancias (soma listas ligadas elemento a elemento). */
p_dist
add_dist(p_dist d1, p_dist d2)
{
}

/* Remove todos os elementos da lista ligada e devolve lista vazia. */
p_dist
destroy_dist(p_dist dist)
{
}
