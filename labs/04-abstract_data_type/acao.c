#include <stdio.h>
#include "acao.h"

/* Cria uma nova acao. */
acao
criar_acao(char *nome, double investimento)
{
  acao a;
  a.nome = nome;
  a.investimento = investimento;
  a.n_variacoes = 0;

  return a;
}

/* Adiciona nova variacao a um vetor da acao e incrementa contador. */
acao
adicionar_variacao(acao a, double variacao)
{
  a.variacao[a.n_variacoes] = variacao;
  a.n_variacoes++;

  return a;
}

/* Imprime nome, quantia remanescente e GANHO/PERDA para uma acao. */
void
reportar_acao(acao a)
{
  double sum = 0;
  int i;

  printf("%s ", a.nome);

  for (i = 0; i < a.n_variacoes; i++)
    sum += a.variacoes[i];

  if (sum > 0)
  {
    printf("%.2f GANHO\n", sum);
  }
  else
  {
    printf("%.2f PERDA\n", -sum);
  }
}
