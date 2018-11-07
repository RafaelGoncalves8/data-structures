/*
 * Lab 13
 * Rafael Goncalves
 *
 * Objetivo: Armazenar e buscar coautores utilizando uma tabela hash.
 */

#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Estrutura de lista ligada para armazenar coautores de um artigo. */
typedef struct node
{
  char val[MAX_CHAR_NAME];
  struct node * next;
}
Node;

typedef Node * p_node;

/* Cria uma lista ligada vazia. */
p_node
create_list()
{
  return NULL;
}

/* Aloca memoria para um no da lista ligada. */
p_node
alloc_node()
{
  p_node n;
  n = (p_node) malloc(sizeof(Node));
  if (n == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }
  return n;
}

/* Adiciona no na lista ligada. */
p_node
add_node(p_node n, char * val)
{
  p_node new;

  if (n == NULL)
  {
    new = alloc_node();
    strcpy(new->val, val);
    new->next = NULL;
    return new;
  }
  n->next = add_node(n->next, val);
  return n;
}

/* Destroi estrutura de lista ligada liberando memoria. */
void
destroy_list(p_node n)
{
  if (n != NULL)
  {
    if (n->next != NULL)
      destroy_list(n->next);
    free(n);
  }
}

/*
 * Le a entrada para o ponteiro name e devolve 1 se a linha terminou com .
 * e 0 caso contrário.
 */
int
read_name(char * name)
{
  char sep;
  int ans;

  scanf(" %c. %[^.,]%c", name, name+1, &sep);

  ans = (sep == '.');
  return ans;
}

/* Concatena s1 e s2 em ans em ordem alfabetica. */
void
merge_names(char * s1, char * s2, char * ans)
{
  int i = -1, j = 0;

  /* Se s2 for alfabeticamente menor que s1. */
  if (strncmp(s1, s2, MAX_CHAR_NAME) > 0)
  {
    while (s2[++i] != '\0')
      ans[i] = s2[i];
    while (s1[j] != '\0')
      ans[i++] = s1[j++];
  }
  /* Se s1 for alfabeticamente menor que s2. */
  else
  {
    while (s1[++i] != '\0')
      ans[i] = s1[i];
    while (s2[j] != '\0')
      ans[i++] = s2[j++];
  }

  ans[i] = '\0';
}

/* Le coautores e devolve lista list dos mesmos. */
p_node
read_coauthors()
{
  p_node list;
  int is_last;
  char name[MAX_CHAR_NAME];

  list = create_list();
  do
  {
    is_last = read_name(name);
    list = add_node(list, name);
  }
  while (!is_last); /* Continue enquanto nao for o ultimo nome. */

  return list;
}

/* Adiciona todas as possiveis combinacoes de autores na hash h. */
void
add_coauthors_to_hash(p_hash h, p_node list)
{
  char entry[MAX_CHAR_ENTRY];
  p_node aux;

  /* Enquanto existir pelo menos 2 autores na lista. */
  while (list != NULL && list->next != NULL)
  {
    aux = list->next;
    while (aux != NULL)
    {
      merge_names(list->val, aux->val, entry);
      add_entry(h, entry);
#if DEBUG
      printf("%s\n", entry);
#endif
      aux = aux->next;
    }
    list = list->next;
  }
}

int
main()
{
  int i;    /* Indexador para os lacos for. */
  int m, n; /* m linhas com entradas de autores, n linhas de busca. */
  p_node list; /* Lista de coautores para cada linha de entrada. */
  p_hash h; /* Tabela de hash com os coautores. */
  char entry[MAX_CHAR_ENTRY]; /* Entrada para a tabela h. */
  /* Primeiro e segundo nomes da busca. */
  char first[MAX_CHAR_NAME], second[MAX_CHAR_NAME];

  h = create_hash_table();

  scanf("%d %d", &n, &m);

  for (i = 0; i < n; i++)
  {
    list = read_coauthors();
    add_coauthors_to_hash(h, list);
    destroy_list(list);
  }

  for (i = 0; i < m; i++)
  {
    read_name(first);
    read_name(second);
    merge_names(first, second, entry);
#if DEBUG
    printf("%s\n", entry);
#endif
    if (exist_entry(h, entry))
      printf("S\n");
    else
      printf("N\n");
  }

  destroy_hash_table(h);

  return 0;

}
