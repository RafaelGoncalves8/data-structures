/*
 * Lab 10 - Rafael Goncalves
 *
 * Objetivo: Usar uma arvore binaria para reduzir as operacoes
 * matematicas em sua forma mais simples.
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/* Maxima string que precisaria ser guardado: "-2147483647\0". */
#define MAX 12

/* Codigos utilizados no no da arvore. */
#define NUM 0
#define VAR 1
#define OP  2

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
Val;

typedef Val * p_val;

/* Arvore binaria. */
typedef struct NodeStruct
{
  p_val val;
  struct NodeStruct *right, *left;
}
Node;

typedef Node * p_node;

/* Aloca memoria para um no da arvore se possivel, senao sai do programa. */
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

/* Cria no com valor dado por s. */
p_node
create_node(char * s)
{
  p_node node;

  node = alloc_node();

  if (s[0] < 'z' && s[0] > 'a')
  {
    node->val->code = VAR;
    node->val->var = s[0];
  }
  else if (s[0] == '+' || (s[0] == '-' && s[1] == '\0')
          || s[0] == '*' || s[0] == '/')
  {
    node->val->code = OP;
    node->val->op = s[0];
  }
  else
  {
    node->val->code = NUM;
    node->val->num = atoi(s);
  }

  return node;
}

/* Adiciona arvores b e c no no a. */
p_node
add_nodes(p_node a, p_node b, p_node c)
{
  a->right = b;
  a->left = c;

  return a;
}

/* Le a expressao e cria a arvore que a representa. */
p_node
read_expr()
{
  char c;
  char s[MAX];
  p_node n1, n2, op;

  if ((c = getchar()) != '(')
  {
    ungetc(c, stdin);
    scanf("%s ", s);
    n1 = create_node(s);
  }
  else
  {
    n1 = read_expr();
  }

  scanf("%s ", s);
  op = create_node(s);

  if ((c = getchar()) != '(')
  {
    ungetc(c, stdin);
    scanf("%s ", s);
    n2 = create_node(s);
  }
  else
  {
    n2 = read_expr();
  }

  op = add_nodes(op, n1, n2);

  return op;
}

/* Resolve uma expressao matematica dado operando op e numeros n1 e n2. */
int
eval_expr(char op, int n1, int n2)
{
  int ans;

  switch (op)
  {
    case '+':
      ans = n1 + n2;
      break;
    case '*':
      ans = n1 * n2;
      break;
    case '-':
      ans = n1 - n2;
      break;
    case '/':
      ans = n1 / n2;
      break;
  }

  return ans;
}

/* Simplifica a expressao e devolve a menor arvore possivel. */
p_node
simplify_expr(p_node expr)
{
  int val;

  if (expr->right->val->code == OP)
    expr->right = simplify_expr(expr->right);
  if (expr->left->val->code == OP)
    expr->left = simplify_expr(expr->left);
  if (expr->right->val->code == NUM && expr->right->val->code == NUM)
  {
    val =  eval_expr(expr->val->op,
                     expr->right->val->num, expr->left->val->num);
    expr = create_node(itoa(val));
  }

  return expr;
}

/* Imprime uma expressao em estrutura de arvore. */
void
print_expr(p_node expr)
{
  if (expr->right != NULL)
  {
    printf("(");
    print_expr(expr->right);
    printf(" ");
  }

  if (expr->val->code == NUM)
    printf("%d ", expr->val->num);
  else if (expr->val->code == VAR)
    printf("%c ", expr->val->var);
  else
    printf("%c ", expr->val->op);

  if (expr->left != NULL)
  {
    print_expr(expr->left);
    printf(")");
  }
}

/* Destroi recursivamente a arvore liberando a memoria alocada para cada no. */
void
destroy_tree(p_node node)
{
  if (node->right == NULL && node->left == NULL)
  {
    free(node);
  }
  else
  {
    if (node->right != NULL)
      destroy_tree(node->right);
    if (node->left != NULL)
      destroy_tree(node->left);
    free(node);
  }
}

int main()
{
  p_node expr;

  expr = read_expr(expr);

  expr = simplify_expr(expr);

  print_expr(expr);
  printf("\n");

  destroy_tree(expr);

  return 0;
}
