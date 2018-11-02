/*
 * Lab 13
 * Rafael Goncalves
 *
 * Objetivo:
 */

#include "hash.h"
#include <stdio.h>
#include <string.h>

int
read_name(char * name)
{
  char sep;
  int ans;

  scanf(" %c. %[^.,]%c", name, name+1, &sep);

  ans = (sep == '.');
  return ans;
}

void
merge_names(char * s1, char * s2, char * ans)
{
  int i = -1, j = 0;

  if (strncmp(s1, s2, MAX_CHAR_NAME) > 0)
  {
    while (s2[++i] != '\0')
      ans[i] = s2[i];
    while (s1[j] != '\0')
      ans[i++] = s1[j++];
  }
  else
  {
    while (s1[++i] != '\0')
      ans[i] = s1[i];
    while (s2[j] != '\0')
      ans[i++] = s2[j++];
  }

  ans[i] = '\0';
}


int
main()
{
  int i;
  int m, n;
  int is_first, is_last;
  /* p_hash h; */
  char first[MAX_CHAR_NAME], second[MAX_CHAR_NAME];
  char entry[MAX_CHAR_ENTRY];

  scanf("%d %d", &n, &m);

  /* h = create_hash_table(); */

  for (i = 0; i < m; i++)
  {
    is_first = 1;
    do
    {
      if (is_first) /* Sera 1 no primeiro nome de cada linha. */
      {
        is_first = 0;
        is_last = read_name(first);
        printf("\nfirst_name: %s\n", first);
      }
      else /* Nao eh o primeiro nome. */
      {
        is_last = read_name(second);
        merge_names(first, second, entry);
        printf("%s\n", entry);
        /* add_entry(h, entry); */
        /* printf("%s\n", h->v[entry]); */
      }
    }
    while (!is_last); /* Continue enquanto nao for o ultimo nome. */
  }

  /* for (i = 0; i < n, i++) */
  /* { */
  /* } */

  /* destroy_hash_table(); */

  return 0;

}
