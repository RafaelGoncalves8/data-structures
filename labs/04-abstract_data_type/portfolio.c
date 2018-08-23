#include <stdio.h>
#include <string.h>
#include "portfolio.h"

/* Cria um novo portfolio. */
portfolio
criar_portfolio(char *nome, char *sobrenome)
{
  portfolio p;
  strncpy(p.nome, nome, MAX_SIZE_NAME);
  strncpy(p.sobrenome, sobrenome, MAX_SIZE_NAME);
  p.n_acoes = 0;

  return p;
}

/* Adiciona acao a um vetor do portfolio e incrementa contador. */
portfolio
adicionar_acao(portfolio p, acao a)
{
  p.acoes[p.n_acoes] = a;
  p.n_acoes++;

  return p;
}


/* Imprime nome, sobrenome e cada acao. */
void
criar_relatorio(portfolio p)
{
  int i;

  printf("Relatorio de %s %s\n", p.nome, p.sobrenome);

  for (i = 0; i <  p.n_acoes; i++)
    reportar_acao(p.acoes[i]);
}
