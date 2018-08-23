/*
 * Lab 04 - Tipo Abstrato de Dado
 * Rafael Goncalves
 *
 * O objetivo do lab
 */

#include <stdio.h>
#include "acao.h"
#include "portfolio.h"

#define N 100
#define M  20

int
main()
{
  portfolio p;
  acao a;
  char nome[MAX_SIZE_NAME], sobrenome[MAX_SIZE_NAME];
  char nome_acao[MAX_SIZE_NAME];
  double investimento_acao, var;
  int i, j, m, n;

  scanf("%s %s ", nome, sobrenome);

  p = criar_portfolio(nome, sobrenome);

  scanf("%d ", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%s %lf %n", nome_acao, &investimento_acao, &m);
    a = criar_acao(nome_acao, investimento_acao);

    for (j = 0; j < m; j++)
    {
      scanf("%lf", &var);
      adicionar_variacao(a, var);
    }

    adicionar_acao(p, a);
  }

 criar_relatorio(p);

 return 0; 
}
