#ifndef heap_h
#define heap_h

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/* FAT(i) eh o indice do elemento pai do elemento i no heap. */
#define FAT(i) ((i-1)/2)

/* Cada elemento de entrada que contem nome e peso. */
typedef struct elem
{
    char * name;
    int weight;
    int len;
} Elem;

typedef Elem * p_elem;

/*
 * Estrutura com dois vetores (max-heap e min-heap) para calculo da mediana.
 */
typedef struct max_min_heap
{
    p_elem max, min;
    int max_n, min_n;
} MaxMinHeap;

typedef MaxMinHeap * p_max_min_heap;

/* Cria elemento com nome n e peso w. */
p_elem
create_elem(n, w);

/* Cria estrutura max_min_heap vazia. */
p_max_min_heap
create_heaps(n);

/* Cria o elemento (name, w) e adiciona em um dos heaps na estrutura h. */
p_max_min_heap
add_to_heaps(char * name, int w, p_max_min_heap h);

/*
 * Faz com que a diferenca entre o numero de elementos dos heaps max e min
 * sejam no maximo 1 (para que os elementos nas raizes sejam mediana).
 */
p_max_min_heap
balance_heaps(p_max_min_heap h);

/* Imprime o elemento ou os elementos que sao a mediana do conjunto. */
void
print_median(p_max_min_heap h);

/* Destroi elemento liberando a memoria. */
void
destroy_elem(p_elem e);

/* Destroi a estrutura e seus elementos liberando a memoria. */
void
destroy_heaps(p_max_min_heap h);

#endif
