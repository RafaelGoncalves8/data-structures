#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Aloca memoria para Hash dinamicamente, se falhar termina o porgrama. */
p_hash
alloc_hash()
{
  p_hash h;

  h = (p_hash) malloc(sizeof(Hash));
  if (h == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return h;
}

/* Cria tabela de hash. */
p_hash
create_hash_table()
{
  p_hash h;
  int i;

  h = alloc_hash();

  for (i = 0; i < MAX_ENTRIES; i++)
    h->v[i][0] = '\0'; /* Vazio. */

  return h;
}

/*
 * Funcao hash que devolve valor par se is_second for 0 e impar
 * caso contrario.
 */
int
hash_aux(char * key, int is_second)
{
  int i;
  int n = 0;

  for (i = 0; i < strlen(key); i++)
    n = (256 * n + key[i]) % M;

  n = 2*n;

  if (is_second)
    n++;

  return n;
}

/* Funcao de hash. */
int
hash(p_hash h, char * key)
{
  int n;
  int i = 0;

  /* Enquanto nao estiver livre e chave ja nao existir na tabela. */
  do
  {
    n = (hash_aux(key, 0) + (i++)*hash_aux(key, 1)) % MAX_ENTRIES;
#if DEBUG
    printf("%d\n", n);
#endif
  }
  while (h->v[n][0] && strncmp(h->v[n], key, MAX_CHAR_ENTRY));

  return n;
}

/* Checa se existe entrada key na tabela h. */
int
exist_entry(p_hash h, char * key)
{
  return !(strcmp(h->v[hash(h, key)], key));
}

/* Adiciona entrada key para a tabela h caso ainda nao exista. */
void
add_entry(p_hash h, char * key)
{
  strcpy(h->v[hash(h, key)], key) ;
}

/* Destroi estrutura h liberando memoria alocada dinamicamente. */
void
destroy_hash_table(p_hash h)
{
  free(h);
}
