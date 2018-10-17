#ifndef arvore_h
#define arvore_h

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

/* Cria no com valor dado por s. */
p_node
create_node(char * s);

/* Adiciona arvores b e c no no a. */
p_node
add_nodes(p_node a, p_node b, p_node c);

/* Le a expressao e cria a arvore que a representa. */
p_node
read_expr();

/* Resolve uma expressao matematica dado operando op e numeros n1 e n2. */
int
eval_expr(char op, int n1, int n2);

/* Destroi recursivamente a arvore liberando a memoria alocada para cada no. */
void
destroy_tree(p_node node);

/* Simplifica a expressao e devolve a menor arvore possivel. */
p_node
simplify_expr(p_node expr);

/* Imprime uma expressao em estrutura de arvore. */
void
print_expr(p_node expr);

#endif
