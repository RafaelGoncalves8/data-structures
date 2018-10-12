/*
 * Lab 10 - Rafael Goncalves
 *
 * Objetivo: Usar uma arvore binaria para reduzir as operacoes
 * matematicas em sua forma mais simples.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/* Maxima string que precisaria ser guardado: "-2147483647\0". */
#define MAX 12

/* Codigos utilizados no no da arvore. */
#define NUM 0
#define VAR 1
#define OP  2

/* Arvore binaria. */
typedef struct NodeStruct
{
  char val[MAX];
  int code;
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

  node->right = NULL;
  node->left = NULL;

  if ((s[0] <= 'z') && (s[0] >= 'a') && (s[1] == '\0'))
  {
    node->code = VAR;
  }
  else if (s[0] == '+' || (s[0] == '-' && s[1] == '\0')
          || s[0] == '*' || s[0] == '/')
    node->code = OP;
  else
    node->code = NUM;

  strncpy(node->val, s, MAX);

  return node;
}

/* Adiciona arvores b e c no no a. */
p_node
add_nodes(p_node a, p_node b, p_node c)
{
  a->left = b;
  a->right = c;

  return a;
}

/* Le a expressao e cria a arvore que a representa. */
p_node
read_expr()
{
  char c;      /* char lido de stdin. */
  char s[MAX]; /* string para guardar numeros, operandos e variaveis. */
  p_node n1, n2, op; /* Operandos n1, n2 e operador op. */
  int i = 0;   /* Indice da string s. */

  if ((c = getchar()) == '(')
  {
    getchar(); /* Espaço. */
    n1 = read_expr();

    scanf("%s", s);
    op = create_node(s);

    getchar(); /* Espaço. */
    n2 = read_expr();

    getchar(); /* ). */
    getchar(); /* Espaço. */

    op = add_nodes(op, n1, n2);
  }
  else
  {
    s[i++] = c;
    while ((c = getchar()) != ' ')
      s[i++] = c;
    s[i] = '\0';
    op = create_node(s);
  }

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

/* Simplifica a expressao e devolve a menor arvore possivel. */
p_node
simplify_expr(p_node expr)
{
  int val;      /* Valor da expressao calculada. */
  char s[MAX];  /* String correspondente a val. */
  p_node tmp;   /* Guarda subarvore nao simplificada para liberar a memoria. */

  if (expr->left->code == OP)
    expr->left = simplify_expr(expr->left);
  if (expr->right->code == OP)
    expr->right = simplify_expr(expr->right);
  if (expr->right->code == NUM && expr->left->code == NUM)
  {
    val =  eval_expr(expr->val[0], atoi(expr->left->val),
                     atoi(expr->right->val));
    sprintf(s, "%d", val);
    tmp = expr;
    expr = create_node(s);
    destroy_tree(tmp);
  }

  return expr;
}

/* Imprime uma expressao em estrutura de arvore. */
void
print_expr(p_node expr)
{
  if (expr->left != NULL)
  {
    printf("( ");
    print_expr(expr->left);
  }

  printf("%s ", expr->val);

  if (expr->right != NULL)
  {
    print_expr(expr->right);
    printf(") ");
  }
}

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
