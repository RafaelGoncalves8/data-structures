/*
 * Lab 03 - Calculadora de Strings
 * Rafael Goncalves
 *
 * O objetivo do laboratorio eh implementar uma calculadora que
 * realize operacoes de concatenacao, comparacao e "fatia" sobre
 * strings (respectivamente CAT, CMP e SUB) utilizando um buffer
 * e as entradas OP (operador) e dependendo do operador
 * str (string para comparacao ou concatenacao) ou x e tam
 * (respectivamente inicio da "fatia" e tamanho da "fatia").
 * O comando deve parar para o operador END.
 */

#include <stdio.h>

#define MAX 100

/* Concatena str ao final de buffer e imprime o novo conteudo de buffer. */
void cat(char buffer[], char str[])
{
  int i, j;

  /* Conta ate o fim do buffer e armazena a posicao em i. */
  for (i = 0; buffer[i] != '\0'; i++) {}

  /* Copia str ao final do buffer (a partir da posicao i). */
  for(j = 0; str[j] != '\0'; j++, i++)
    buffer[i] = str[j];
  buffer[i] = '\0';

  printf("%s\n", buffer);
}

/*
 * Compara buffer e str e imprime IGUAL\n caso sejam iguais
 * ou DIFERENTE\n caso contrario.
 */
void cmp(char buffer[], char str[])
{
  /* Flag indicando se existe um char diferente entre buffer e str. */
  int has_dif_char = 0;
  int i = 0;

  /*
   * Itera buffer e str enquanto ambos nao terminam e o valor da
   * flag é negativo (ou seja, nao ha caractere diferente).
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

/*
 * Armazena em buffer a substring armazenada em buffer que tem inicio
 * em x e tem tamanho tam. Imprime o novo conteudo de buffer.
 */
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
  int x, tam;       /* Posicao inicial e tamanho (argumentos de sub) */

  /* Inicializacao do buffer como string vazia */
  buffer[0] = '\0';

  /* Leitura da primeira operacao*/
  scanf("%s", op);

  /*
   * Dado que o problema é fechado nas 4 operacoes citadas no enunciado
   * (CAT, CMP, SUB e END) e analisando-se apenas o segundo caractere
   * de cada operacao (respectivamente A, M, U e N) eh suficiente
   * discernir qual eh a operacao pedida, implementei o lab comparando
   * apenas o segundo caractere da operacao, sem a necessidade de se comparar
   * toda a string em op.
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
