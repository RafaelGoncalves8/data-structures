#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/* Checa se ha memoria e aloca memoria para a estrutura do tipo Elem. */
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
create_elem(n, w)
{
  p_elem e;

  e = alloc_elem();
  e->name = n;
  e->weight = w;

  return e;
}

/* Cria estrutura max_min_heap vazia. */
p_max_min_heap
create_heaps(n)
{
  p_max_min_heap h;
  int len = (n/2) + 1; /* Tamanho maximo de cada heap. */
  Elem max[len], min[len];

  h = alloc_heap();

  h->max_h = h->min_h = 0;
  h->max = max;
  h->min = min;
  h->len = len;

  return h;
}

/* Troca elementos entre si. */
p_elem
swap(p_elem e, a, b)
{
  p_elem tmp;

  tmp = e[a];
  e[a] = e[b];
  e[b] = tmp;

  return e;
}

/* Balanceia min para que mantenha a propriedade de min-heap. */
p_elem
sift_up(p_elem min, n)
{
  if (n > 0 && max[FAT(n)]->w > max[n]->w) 
  {
    max =  swap(max, max[FAT(n)], max[n]);
    return sift_up(max, FAT(n));
  }
  return max;
}

/* Balanceia max para que mantenha a propriedade de max-heap. */
p_elem
heapify(p_elem max, n)
{
  if (n > 0 && max[FAT(n)]->w < max[n]->w) 
  {
    max =  swap(max, max[FAT(n)], max[n]);
    return heapify(max, FAT(n));
  }
  return max;
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
  if (!h->min_n || w >= h->min[0]->weight)
  {
    h->min[h->min_n] = e;
    h->min++;
    h->min = sift_up(h->min, h->min_n);
  }
  /*
   * Se max vazio ou w eh menor que raiz de max,
   * adiciona e em max.
   */
  else if (!h->max_n || w <= h->max[0]->weight)
  {
    h->max[h->max_n] = e;
    h->max++;
    h->max = heapify(h->max, h->max_n);
  }
  /*
   * Se w menor que raiz de max e maior que raiz de min, 
   * adiciona e no heap com menos elementos.
   */
  else
  {
    if (h->min_n > h->max_n)
      h->max[h->max_n] = e;
      h->max++;
      h->max = heapify(h->max, h->max_n);
    else
      h->min[h->max_n] = e;
      h->min++;
      h->min = sift_up(h->min, h->min_n);
  }

  return h;
}

/*
 * Faz com que a diferenca entre o numero de elementos dos heaps max e min
 * sejam no maximo 1 (para que os elementos nas raizes sejam mediana).
 */
p_max_min_heap
balance_heaps(p_max_min_heap h)
{
  if(abs(h->min_h - h->max_h) > 1)
  {
    if (h->min_h > h->max_h)
    {
      h->max[h->max_h] = h->min[h->min_h];
      h->min_h--;
    }
    else
    {
      h->min[h->min_h] = h->max[h->max_h];
      h->max_h--;
    }
  }

  return h;
}

/* Imprime o elemento ou os elementos que sao a mediana do conjunto. */
void
print_median(p_max_min_heap h)
{
  /* Existe numero impar de elementos e imprime apenas mediana. */
  if (abs(h->min_h - h->max_h) == 1)
  {
    if (h->min_h > h->max_h)
      printf("%s: %d\n", h->min[0]->name, h->min[0]->w);
    else
      printf("%s: %d\n", h->max[0]->name, h->max[0]->w);
  }
  /*
   * Existe numero par de elementos, serao imprimidos os dois 
   * elementos do meio.
   */
  else
  {
    printf("%s: %d\n", h->min[0]->name, h->min[0]->w);
    printf("%s: %d\n", h->max[0]->name, h->max[0]->w);
  }
}

/* Destroi elemento liberando a memoria. */
void
destroy_elem(p_elem e)
{
  free(e);
}

/* Destroi a estrutura e seus elementos liberando a memoria. */
void
destroy_heaps(p_max_min_heap h)
{
  int i;

  for (i = 0; i < h->max_h || i < h->min_h; i++)
  {
    if (i < max_h)
      destroy_elem(max[i]);
    if (i < min_h)
      destroy_elem(min[i]);
  }
  free(max);
  free(min);
  free(h);
}

