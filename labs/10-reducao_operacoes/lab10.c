/*
 * Lab 10 - Rafael Goncalves
 *
 * Objetivo: Usar uma arvore binaria para reduzir as operacoes
 * matematicas em sua forma mais simples.
 */

#include <stdio.h>
#include "arvore.h"

int main()
{
  p_node expr;

  expr = read_expr();

#if DEBUG
  print_expr(expr);
  printf("\n");
#endif

  expr = simplify_expr(expr);

  print_expr(expr);
  printf("\n");

  destroy_tree(expr);

  return 0;
}
