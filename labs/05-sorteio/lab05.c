/*
 * Lab 05
 * Rafael Gonçalves
 *
 * Objetivo:
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 30
#define INITIAL_SPACES 4
#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria."

/* Registro com 2 campos: nome e numero de telefone. */
typedef struct Entry_Struct
{
  char name[MAX_STR];
  int num;
}
Entry;

/*
 * Copia as n entradas do registro a para o registro b.
 *
 * Entradas: registro fonte a, registro destino b, tamanho n.
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
 * Cria um novo registro com o dobro de tamanho alocado na memória.
 *
 * Entradas: registro antigo, tamanho atual n.
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
  new_entries = malloc(2*n * sizeof(Entry));
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
 *
 */
void bubble_sort(Entry * entries, int n)
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
    for (i= 0; i < n - 2; i++)
    {
      if (entries[i].num < entries[i+1].num)
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



void print_winner(Entry * entries, int k)
{
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
  entries = (Entry *) malloc(2 * sizeof(Entry));
  if (entries == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    return NUM_ERR_OUT_OF_MEM;
  }

  spaces_left = INITIAL_SPACES;
  n = spaces_left;

  /* Leitura das entradas e criacao dos registros. */
  scanf("%s %n", name, &num);

  while (strcmp(name, "fim\0"))
  {
    scanf("%s %n", name, &num);
    n++;

    if (!spaces_left)
      entries = double_entries(entries, n);
  }

  scanf("%d", &k);

  /* Ordenar vetor de structs. */
  bubble_sort(entries, n);

  /* Imprime o vencedor. */
  print_winner(entries, k);

  free(entries);

  return 0;
}
