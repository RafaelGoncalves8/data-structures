#include "treap.h"
#include <stdlib.h>
#include <stdio.h>

/* Aloca memoria para o tipo Treap e checa se foi alocado com sucesso. */
p_treap
alloc_node()
{
  p_treap node;

  node = (p_treap) malloc(sizeof(Treap));
  if (node == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return node;
}

/* Cria estrutura de treap vazia. */
p_treap
create_treap()
{
  return NULL;
}

/* Rotaciona para a direita. */
p_treap
cw_rot(p_treap t)
{
  p_treap x = t->left;
  t->left = x->right;
  x->right = t;

  return x;
}

/* Rotaciona para a esquerda. */
p_treap
ccw_rot(p_treap t)
{
  p_treap x = t->right;
  t->right = x->left;
  x->left = t;

  return x;
}

/* Insere elemento na treap. */
p_treap
insert_elem(p_treap t, int n)
{
  p_treap new;

  if (t == NULL)
  {
    new = alloc_node();

    new->key = n;
    new->priority = rand();
    new->right = new->left = NULL;

    return new;
  }
  if (n < t->key)
    t->left = insert_elem(t->left, n);
  else
    t->right = insert_elem(t->right, n);

  /* Balancear treap. */
  if (t->left != NULL && (t->left->priority > t->priority))
    t = cw_rot(t);
  else if (t->right != NULL && (t->right->priority > t->priority))
    t = ccw_rot(t);

  return t;
}

/* Retorna 1 se o elemento e esta em A e 0 caso contrario. */
int
is_in(int e, p_treap A)
{
  if (A == NULL)
    return 0;
  else if (A->key >= e)
    return (A->key == e || is_in(e, A->left));
  else
    return (is_in(e, A->right));
}

/* Armazena em S os elementos de A que nao estao em B. */
p_treap
diff_rec(p_treap A, p_treap B, p_treap S)
{
  if (A != NULL)
  {
    if (!is_in(A->key, B))
      S = insert_elem(S, A->key);
    S = diff_rec(A->left, B, S);
    S = diff_rec(A->right, B, S);
  }

  return S;
}

/* Cria nova treap que eh a diferenca simetrica de A e B. */
p_treap
diff(p_treap A, p_treap B)
{
  p_treap S;

  S = create_treap();

  S = diff_rec(A, B, S);
  S = diff_rec(B, A, S);

  return S;
}

/* Imprime chaves da treap em ordem decrescente. */
void
print_treap(p_treap t)
{
  if (t != NULL)
  {
    if (t->right != NULL)
      print_treap(t->right);

    printf("%d ", t->key);

    if (t->left != NULL)
      print_treap(t->left);
  }
}

/* Destroi treap e libera memoria alocada. */
void
destroy_treap(p_treap t)
{
  if (t == NULL)
    return;
  if (t->right == NULL && t->left == NULL)
  {
    free(t);
  }
  else
  {
    if (t->right != NULL)
      destroy_treap(t->right);
    if (t->left != NULL)
      destroy_treap(t->left);
    free(t);
  }
}
