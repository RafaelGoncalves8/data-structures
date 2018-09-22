typedef struct NodeStruct 
{
  struct NodeStruct * next;
  struct NodeStruct * prev;
  char val;
}
Node;

typedef Node * p_node;

typedef struct DistStruct
{
  p_node head;
  p_node tail;
}
Dist;

typedef Dist * p_dist;

/* Aloca memoria para ponteiro para Node. */
p_node
alloc_node();

/* Aloca memoria para ponteiro para Dist. */
p_dist
alloc_dist();

/* Cria lista ligada vazia. */
p_dist
new_dist();

/* Adiciona elemento (digito) no fim (tail) da lista ligada. */
p_dist
add_tail_dist(p_dist dist, char c);

/* Adiciona elemento (digito) no inicio (head) da lista ligada. */
p_dist
add_head_dist(p_dist dist, char c);

/* Soma duas distancias (soma listas ligadas elemento a elemento). */
p_dist
add_dist(p_dist d1, p_dist d2);

/* Imprime numero astronomico. */
void
print_dist(p_dist dist);

/* Remove todos os elementos da lista ligada, libera memoria de dist  e devolve NULL. */
p_dist
destroy_dist(p_dist dist);
