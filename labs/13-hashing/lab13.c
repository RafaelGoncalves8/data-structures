/*
 * Lab 13
 * Rafael Goncalves
 *
 * Objetivo:
 */

#include "hash.h"

int
read_name(char * name)
{
  char sep;
  int ans;

  scanf(" %c. %[^.,]%c", name, name+1, &sep);

  ans = (sep == '.');
  return ans;
}

char *
merge_names(char * s1, char * s2)
{
}


int
main()
{
  int m, n;
  int last;

  scanf("%d %d", &n, &m);

  h = create_hash_table();

  for (i = 0; i < m; i++)
  {
    last = 1;
    do
    {
      if (last) /* So sera 1 no primeiro nome de cada linha. */
      {
        last = read_name(first);
      }
      else
      {
        last = read_name(second);
        entry = merge_names(first, second);
        add_entry(h, entry);
      }
    }
    while (!last);
  }

  for (i = 0; i < n, i++)
  {
  }

  destroy_hash_table();

  return 0;

}
