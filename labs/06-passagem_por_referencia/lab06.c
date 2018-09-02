/*
 * Lab 06
 * Rafael Goncalves
 *
 * Objetivo:
 */

#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int
main()
{
  int i, j; /* Indices para os lacos for. */

  p_professor * professores; /* Vetor de registros de professores. */
  int p;         /* Numero de elementos no vetor professores. */

  p_aluno * alunos; /* Vetor de registros de alunos.*/
  int a;     /* Numero de elementos no vetor alunos. */

  /* Variaveis temporarias para criacao dos registros. */
  char p_nome[MAX_NOME], p_sobrenome[MAX_NOME];
  char a_nome[MAX_NOME], a_sobrenome[MAX_NOME];
  char disciplina[MAX_CODIGO];
  int n;     /* Numero de disciplinas que o aluno esta matriculado. */
  double val; /* Valor do salario do professor. */
  double nota;

  /* Variaveis temporarias para o calculo de novo salario de cada professor.*/
  double nota_min, nota_max;

  /* Leitura das variaveis e criacao dos registros. */
  scanf("%d", &p);

  professores = (p_professor *) malloc(p * sizeof(p_professor));

  for (i = 0; i < p; i++) /* Professores. */
  {
    scanf("%s %s %lf %s", p_nome, p_sobrenome, &val, disciplina);
    professores[i] = criarProfessor(p_nome, p_sobrenome, val, disciplina);
  }

  scanf("%d", &a);

  alunos = (p_aluno *) malloc(a * sizeof(p_professor));

  for (i = 0; i < a; i++) /* Alunos. */
  {
    scanf("%s %s %d", a_nome, a_sobrenome, &n);

    alunos[i] = criarAluno(a_nome, a_sobrenome);

    for (j = 0; j < n; j++) /* Disciplinas de cada aluno. */
    {
      scanf("%s %lf", disciplina, &nota);

      adicionarDisciplina(alunos[i], disciplina, nota);
    }
  }

  /* Reajuste de salarios e impressao de cada professor. */
  for (i = 0; i < p; i++)
  {
    obterNotasExtremas(alunos, a, professores[i]->disciplina,
                       &nota_min, &nota_max);
    reajusteSalario(professores[i], nota_min+nota_max/2.0);
    imprimirProfessor(professores[i]);
    destruirProfessor(professores[i]); /* Liberar memoria do registro. */
  }

  /* Liberar memoria dos vetores de alunos e professores. */
  for (i = 0; i < a; i++)
    destruirAluno(alunos[i]);

  free(professores);
  free(alunos);

  return 0;
}
