/*
 * Lab 10 - Rafael Goncalves
 *
 * Objetivo: Usar uma arvore binaria para reduzir as operacoes
 * matematicas em sua forma mais simples.
 */

#include <stdio.h>
#include <stdlib.h>

/* Codigos utilizados no no da arvore. */
#define 0 NUM
#define 1 VAR
#define 2 OP

/*
 * Conteudo do no da arvore binaria. code pode ser NUM, VAR ou
 * OP. Em cada um destes casos o valor do no esta guardado, 
 * respectivamente, em num, var ou op.
 */
typedef struct ValStruct
{
  int code, num;
  char var, op;
}
Val

typedef Val * p_val;

/* Arvore binaria. */
typedef struct NodeStruct
{
  p_val val;
  struct NodeStruct *right, *left;
}
Node;

typedef Node * p_node;

p_node
read_expr()
{
  return p_node expr;
}

int main()
{
  p_node expr;

  expr = read_expr();
  simplify_expr(expr);
  print_expr(expr);

  destroy_expr(expr);

  return 0;
}
