#include <stdio.h>

void
hanoi(char * orig, char * temp, char * dest, int n)
{
  if (n == 1)
  {
    printf("Move de %s para %s.\n", orig, dest);
  }
  else
  {
    hanoi(orig, dest, temp, n-1);
    printf("Move de %s para %s.\n", orig, dest);
    hanoi(temp, orig, dest, n-1);
  }
}

int
main()
{
  int i;
  int n = 5;

  for (i = 1; i < n; i++)
  {
    hanoi("origem", "temporario", "destino", i);
    printf("\n");
  }

  return 0;
}
