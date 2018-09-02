/*
 * Lab 05
 * Rafael Gonçalves
 *
 * Objetivo: Ler uma quantidade indeterminada de registros contendo
 * nome e numero de telefone dos participantes de um sorteio. Ordenar
 * o vetor em ordem crescente de numero de telefone. Imprimir o
 * vencedor do sorteio que é o k-esimo elemento no vetor ordenado.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 30
#define INITIAL_SPACES 4
#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/* Registro com 2 campos: nome e numero de telefone. */
typedef struct Entry_Struct
{
  char name[MAX_STR];
  int num;
}
Entry;

/*
 * Copia as n entradas do vetor de registros a para o vetor de registros b.
 *
 * Entradas: vetor de registros fonte a, vetor de registros destino b,
 *           numero de elementos a serem copiados n.
 */
void
copy_entries(Entry * a, Entry * b, int n)
{
  int i;
  for (i = 0; i < n ; i++)
  {
    strcpy(b[i].name, a[i].name);
    b[i].num = a[i].num;
  }
}

/* 
 * Cria um novo registro com o dobro de tamanho alocado na memória e copia os
 * elementos do registro antigo.
 *
 * Entradas: registro antigo, tamanho atual,
 *           numero de elementos no registro antigo n.
 *
 * Saida: novo registro com o dobro de tamanho (2n).
 */
Entry *
double_entries(Entry * entries, int n)
{
  Entry * new_entries;

  /*
   * Aloca a memoria para o vetor e checa se teve espaco,
   * senao imprime erro.
   */
  new_entries = (Entry *) malloc(2 * n * sizeof(Entry));
  if (new_entries == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  /* Copia as entradas para o novo vetor. */
  copy_entries(entries, new_entries, n);

  free(entries);

  return new_entries;
}

/*
 * Ordena os elementos de um vetor de elementos do tipo Entry por
 * ordem crescente do numero de telefone (num).
 *
 * Entradas: o ponteiro para Entry de nome entries e o numero de elementos n
 */
void 
bubble_sort(Entry * entries, int n)
{
  /*
   * Variaveis para alocacao temporaria de valores para a troca de posicao dos
   * elementos no algoritimo de ordenacao.
   */
  int tmp_num;
  char tmp_name[MAX_STR];

  int i;       /* Indexador para o laco for. */
  int swapped; /* Flag que indica se houve troca ou nao.*/

  do
  {
    swapped = 0;
    for (i= 0; i < n - 1; i++)
    {
      if (entries[i+1].num < entries[i].num)
      {
        /* Troca entre os elemento i e i+1. */
        tmp_num = entries[i].num;
        strcpy(tmp_name, entries[i].name);
        entries[i].num = entries[i+1].num;
        strcpy(entries[i].name, entries[i+1].name);
        entries[i+1].num = tmp_num;
        strcpy(entries[i+1].name, tmp_name);

        swapped = 1;
      }
    }
  }
  while (swapped);
}


int
main()
{
  int n;              /* Numero de registros. */
  int k;              /* Numero sorteado. */
  int num;            /* Numero em cada linha da entrada. */
  char name[MAX_STR]; /* Nome em cada linha da entrada. */
  Entry * entries;    /* Vetor de registros do tipo Entry. */
  int spaces_left;    /* Entradas disponíveis no vetor de registros */

  /* Inicializacao do vetor de registros com 2 espacos. */
  entries = (Entry *) malloc(INITIAL_SPACES * sizeof(Entry));
  if (entries == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    return NUM_ERR_OUT_OF_MEM;
  }

  spaces_left = INITIAL_SPACES;
  n = 0;

  /* Leitura das entradas e criacao dos registros. */
  scanf("%s %d", name, &num);

  while (strcmp(name, "fim\0"))
  {
    entries[n].num = num;
    strcpy(entries[n].name, name);
    n++;
    spaces_left--;

    scanf("%s %d", name, &num);

    /* Se necessario, dobre o tamanho do vetor de registros. */
    if (!spaces_left)
    {
      entries = double_entries(entries, n);
      spaces_left = n;
    }
  }

  k = num;

  /* Ordenar vetor de structs. */
  bubble_sort(entries, n);

  /* Imprime o vencedor. */
  printf("%s %d\n", entries[k-1].name, entries[k-1].num);

  free(entries);

  return 0;
}
