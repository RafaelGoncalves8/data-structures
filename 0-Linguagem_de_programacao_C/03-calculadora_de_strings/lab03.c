/*Lab 03 - Calculadora de Strings
 *Rafael Goncalves
 *
 *
 *O objetivo do laboratorio eh implementar uma calculadora que
 *realize operacoes sobre uma string dada chamada buffer
 */

#include <stdio.h>

#define MAX 100

void cat(char buffer[], char str[])
{
  int i, j;

  for (i = 0; buffer[i] != '\0'; i++) {}

  for(j = 0; str[j] != '\0'; j++, i++)
    buffer[i] = str[j];
  buffer[i] = '\0';

  printf("%s\n", buffer);
}

void cmp(char buffer[], char str[])
{
  /* Flag indicating if buffer has a char different than str */
  int has_dif_char = 0;
  int i = 0;

  /* Itere o buffer e a string enquanto ambos nao terminam e ainda nao teve
   * caractere diferente
   */
  do
  {
    if (buffer[i] != str[i])
      has_dif_char = 1;
    i++;
  }
  while (buffer[i] != '\0' && str[i] != '\0' && has_dif_char == 0);

  if (has_dif_char == 1)
    printf("DIFERENTE\n");
  else
    printf("IGUAL\n");
}

void sub(char buffer[], int x, int tam)
{
  int i, j;

  for (j = 0, i = x; j < tam; i++, j++)
    buffer[j] = buffer[i];

  buffer[i-x] = '\0';

  printf("%s\n", buffer);
}

int main()
{
  char op[4];       /* Operacao */
  char buffer[MAX]; /* Buffer */
  char str[MAX];    /* String (argumento de cat ou cmp) */
  int x, tam;       /* Posicoes inicial e tamanho (argumentos de sub) */

  /* Inicializacao do buffer como string vazia */
  buffer[0] = '\0';

  /* Leitura da primeira operacao*/
  scanf("%s", op);

  /* Dado que o problema é fechado nas 4 operacoes citadas no enunciado
   * (CAT, CMP, SUB e END) e analisando-se apenas o segundo caractere
   * de cada operacao (respectivamente A, M, U e N) eh suficiente
   * discernir qual eh a operacao pedida, implementei o lab comparando
   * apenas o segundo caractere da operacao
   */
  while (op[1] != 'N')     /* Executa laco se operacao nao for END */
  {
    if (op[1] == 'A')      /* CAT */
    {
      scanf("%s", str);
      cat(buffer, str);
    }
    else if (op[1] == 'M') /* CMP */
    {
      scanf("%s", str);
      cmp(buffer, str);
    }
    else                    /* SUB */
    {
      scanf("%d %d", &x, &tam);
      sub(buffer, x, tam);
    }

    /* Leitura da proxima operacao */
    scanf("%s", op);
  }

  return 0;
}
