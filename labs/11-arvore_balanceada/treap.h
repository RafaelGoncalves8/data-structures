#ifndef treap_h
#define treap_h

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

typedef struct TreapStruct
{
    int key, priority;
    struct TreapStruct *up, *right, *left;
}
Treap;

typedef Treap * p_treap;

/* Cria estrutura de treap. */
p_treap
create_treap();

/* Rotaciona para a direita. */
p_treap
cw_rot(p_treap t);

/* Rotaciona para a esquerda. */
p_treap
ccw_rot(p_treap t);

/* Insere elemento na treap. */
p_treap
insert_elem(p_treap t, int n);

/* Cria nova treap que eh a diferenca simetrica de A e B. */
p_treap
diff(p_treap A, p_treap B);

/* Imprime chaves da treap em ordem decrescente. */
void
print_treap(p_treap t);

/* Destroi treap e libera memoria alocada. */
void
destroy_treap(p_treap t);

#endif
