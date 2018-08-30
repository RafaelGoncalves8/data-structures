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
 *
 * TODO: check if new_entries = NULL and send error code.
 */
Entry *
double_entries(Entry * entries, int n)
{
  Entry * new_entries;

  new_entries = malloc(2*n * sizeof(Entry));

  copy_entries(entries, new_entries, n);

  free(entries);

  return new_entries;
}

void print_winner(Entry * entries, int k) {}

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
    printf("Não há espaço na memória.");
    return 1;
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

  /* Imprime o vencedor. */
  print_winner(entries, k);

  free(entries);

  return 0;
}
