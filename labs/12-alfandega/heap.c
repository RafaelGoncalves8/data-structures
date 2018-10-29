#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Checa se ha memoria e aloca memoria para Elem. */
p_elem
alloc_elem()
{
  p_elem elem;

  elem = (p_elem) malloc(sizeof(Elem));
  if (elem == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return elem;
}

/* Checa se ha memoria e aloca memoria para a lista de Elem. */
p_elem *
alloc_n_elem(n)
{
  p_elem * elems;

  elems = (p_elem *) malloc(n * sizeof(p_elem));
  if (elems == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return elems;
}

/* Checa se ha memoria e aloca memoria para a estrutura do tipo MaxMinHeap. */
p_max_min_heap
alloc_heap()
{
  p_max_min_heap h;

  h = (p_max_min_heap) malloc(sizeof(MaxMinHeap));
  if (h == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return h;
}

/* Cria elemento com nome n e peso w. */
p_elem
create_elem(char * n, int w)
{
  p_elem e;

  e = alloc_elem();
  strcpy(e->name, n);
  e->key = w;

  return e;
}

/* Cria estrutura max_min_heap vazia. */
p_max_min_heap
create_heaps(int n)
{
  p_max_min_heap h;
  int len;

  len  = (n/2) + 1; /* Tamanho maximo de cada heap. */

  h = alloc_heap();

  h->max_n = h->min_n = 0;
  h->max = alloc_n_elem(len);
  h->min = alloc_n_elem(len);
  h->len = len;

  return h;
}

/* Troca elementos entre si. */
void
swap(p_elem * e, int a, int b)
{
  p_elem tmp;

  tmp = e[a];
  e[a] = e[b];
  e[b] = tmp;
}

/* Desce no max-heap. */
void
sift_up_max(p_max_min_heap h, int n)
{
  int max_son;
  if (L_SON(n) < h->max_n)
  {
    max_son = L_SON(n);
    if (R_SON(n) < h->max_n &&
        h->max[L_SON(n)]->key < h->max[R_SON(n)]->key)
      max_son = R_SON(n);
    if (h->max[n]->key < h->max[max_son]->key)
    {
      swap(h->max, n, max_son);
      sift_up_max(h, max_son);
    }
  }
}

/* Desce no min-heap. */
void
sift_up_min(p_max_min_heap h, int n)
{
  int min_son;
  if (L_SON(n) < h->min_n)
  {
    min_son = L_SON(n);
    if (R_SON(n) < h->min_n &&
        h->min[L_SON(n)]->key > h->min[R_SON(n)]->key)
      min_son = R_SON(n);
    if (h->min[n]->key > h->min[min_son]->key)
    {
      swap(h->min, n, min_son);
      sift_up_min(h, min_son);
    }
  }
}
/* Sobe no min-heap. */
void
heapify_min(p_max_min_heap h, int n)
{
  if (n > 0 && h->min[FAT(n)]->key > h->min[n]->key)
  {
    swap(h->min, FAT(n), n);
    heapify_min(h, FAT(n));
  }
}

/* Sobe no max-heap. */
void
heapify_max(p_max_min_heap h, int n)
{
  if (n > 0 && h->max[FAT(n)]->key < h->max[n]->key)
  {
    swap(h->max, FAT(n), n);
    heapify_max(h, FAT(n));
  }
}

/* Adiciona o elemento (name, w) para um dos heaps na estrutura h. */
p_max_min_heap
add_to_heaps(char * name, int w, p_max_min_heap h)
{
  p_elem e;

  e = create_elem(name, w);

  /*
   * Se min vazio ou w eh maior que raiz de min,
   * adiciona e em min.
   */
  if (!h->min_n || w >= h->min[0]->key)
  {
    h->min[h->min_n] = e;
    heapify_min(h, h->min_n);
    h->min_n++;
  }
  /*
   * Se max vazio ou w eh menor que raiz de max,
   * adiciona e em max.
   */
  else if (!h->max_n || w <= h->max[0]->key)
  {
    h->max[h->max_n] = e;
    heapify_max(h, h->max_n);
    h->max_n++;
  }
  /*
   * Se w menor que raiz de max e maior que raiz de min, 
   * adiciona e no heap com menos elementos.
   */
  else
  {
    if (h->min_n > h->max_n)
    {
      h->max[h->max_n] = e;
      heapify_max(h, h->max_n);
      h->max_n++;
    }
    else
    {
      h->min[h->min_n] = e;
      heapify_min(h, h->min_n);
      h->min_n++;
    }
  }

  return h;
}

/* Funcao auxiliar para visualisar heap. */
void
print_heap_debug(p_max_min_heap h, int m, int n)
{
  int i;

  for (i = 0; i < m; i++)
    printf("%s\n", h->max[i]->name);

  printf("-\n");

  for (i = 0; i < n; i++)
    printf("%s\n", h->min[i]->name);
}

/*
 * Faz com que a diferenca entre o numero de elementos dos heaps max e min
 * sejam no maximo 1 (para que os elementos nas raizes sejam mediana).
 */
p_max_min_heap
balance_heaps(p_max_min_heap h)
{
  if(abs(h->min_n - h->max_n) > 1)
  {
    if (h->min_n > h->max_n)
    {
      h->max[h->max_n] = h->min[0];
      swap(h->min, 0, h->min_n-1);
      h->max_n++;
      h->min_n--;
      heapify_max(h, h->max_n-1);
      sift_up_min(h, 0);

      h->min[h->min_n] = NULL;
    }
    else
    {
      h->min[h->min_n] = h->max[0];
      swap(h->max, 0, h->max_n-1);
      h->min_n++;
      h->max_n--;
      heapify_min(h, h->min_n-1);
      sift_up_max(h, 0);

      h->max[h->max_n] = NULL;
    }
  }
#if DEBUG
  print_heap_debug(h, h->max_n, h->min_n);
#endif

  return h;
}

/* Imprime o elemento ou os elementos que sao a mediana do conjunto. */
void
print_median(p_max_min_heap h)
{
  /* Existe numero impar de elementos e imprime apenas mediana. */
  if (abs(h->min_n - h->max_n) == 1)
  {
    if (h->min_n > h->max_n)
      printf("%s: %d\n", h->min[0]->name, h->min[0]->key);
    else
      printf("%s: %d\n", h->max[0]->name, h->max[0]->key);
  }
  /*
   * Existe numero par de elementos, serao imprimidos os dois 
   * elementos do meio.
   */
  else if (h->min_n && h->max_n)
  {
    printf("%s: %d\n", h->max[0]->name, h->max[0]->key);
    printf("%s: %d\n", h->min[0]->name, h->min[0]->key);
  }
}

/* Destroi a estrutura e seus elementos liberando a memoria. */
void
destroy_heaps(p_max_min_heap h)
{
  int i;

  for (i = 0; i < h->max_n || i < h->min_n; i++)
  {
    if (i < h->max_n)
      free(h->max[i]);
    if (i < h->min_n)
      free(h->min[i]);
  }
  if (h->max != NULL)
    free(h->max);
  if (h->min != NULL)
    free(h->min);
  free(h);
}

