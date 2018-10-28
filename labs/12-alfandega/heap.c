#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

/* Checa se ha memoria e aloca memoria para a estrutura do tipo Elem. */
Elem *
alloc_elem(n)
{
  Elem * elem;

  elem = (Elem *) malloc(n * sizeof(Elem));
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
Elem
create_elem(char * n, int w)
{
  Elem e;

  e.name = n;
  e.key = w;

  return e;
}

/* Cria estrutura max_min_heap vazia. */
p_max_min_heap
create_heaps(int n)
{
  p_max_min_heap h;
  Elem *max, *min;
  int len;

  len  = (n/2) + 1; /* Tamanho maximo de cada heap. */

  max = alloc_elem(len);
  min = alloc_elem(len);

  h = alloc_heap();

  h->max_n = h->min_n = 0;
  h->max = max;
  h->min = min;
  h->len = len;

  return h;
}

/* Troca elementos entre si. */
Elem *
swap(Elem * e, int a, int b)
{
  Elem tmp;

  tmp = e[a];
  e[a] = e[b];
  e[b] = tmp;

  return e;
}

/* Balanceia min para que mantenha a propriedade de min-heap. */
Elem *
sift_up(Elem * min, int n)
{
  if (n > 0 && min[FAT(n)].key > min[n].key) 
  {
    min =  swap(min, FAT(n), n);
    return sift_up(min, FAT(n));
  }
  return min;
}

/* Balanceia max para que mantenha a propriedade de max-heap. */
Elem *
heapify(Elem * max, int n)
{
  if (n > 0 && max[FAT(n)].key < max[n].key) 
  {
    max =  swap(max, FAT(n), n);
    return heapify(max, FAT(n));
  }
  return max;
}

/* Adiciona o elemento (name, w) para um dos heaps na estrutura h. */
p_max_min_heap
add_to_heaps(char * name, int w, p_max_min_heap h)
{
  Elem e;

  e = create_elem(name, w);

  /*
   * Se min vazio ou w eh maior que raiz de min,
   * adiciona e em min.
   */
  if (!h->min_n || w >= h->min[0].key)
  {
    h->min[h->min_n] = e;
    h->min++;
    h->min = sift_up(h->min, h->min_n);
  }
  /*
   * Se max vazio ou w eh menor que raiz de max,
   * adiciona e em max.
   */
  else if (!h->max_n || w <= h->max[0].key)
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
    {
      h->max[h->max_n] = e;
      h->max++;
      h->max = heapify(h->max, h->max_n);
    }
    else
    {
      h->min[h->max_n] = e;
      h->min++;
      h->min = sift_up(h->min, h->min_n);
    }
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
  if(abs(h->min_n - h->max_n) > 1)
  {
    if (h->min_n > h->max_n)
    {
      h->max[h->max_n] = h->min[h->min_n];
      h->min_n--;
    }
    else
    {
      h->min[h->min_n] = h->max[h->max_n];
      h->max_n--;
    }
  }

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
      printf("%s: %d\n", (h->min)[0].name, (h->min)[0].key);
    else
      printf("%s: %d\n", (h->max[0]).name, (h->max)[0].key);
  }
  /*
   * Existe numero par de elementos, serao imprimidos os dois 
   * elementos do meio.
   */
  else
  {
    printf("%s: %d\n", (h->min)[0].name, (h->min)[0].key);
    printf("%s: %d\n", (h->max)[0].name, (h->max)[0].key);
  }
}

/* Destroi a estrutura e seus elementos liberando a memoria. */
void
destroy_heaps(p_max_min_heap h)
{
  free(h->max);
  free(h->min);
  free(h);
}

