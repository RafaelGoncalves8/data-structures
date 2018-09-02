/*
 * Lab 06
 * Rafael Goncalves
 *
 * Objetivo: Ler uma lista de professores com respectivos nome, materia e
 * salario e armazenar em registros. Ler alunos com respectivos nome, sobrenome,
 * quantidade de materias e as respectivas materias e notas desse aluno e
 * armazenar em registros. Implementar as funcoes em universidade.h que visam
 * criar os registros e calcular o novo salario de cada professor baseado nas
 * notas dos alunos em sua materia.
 */

#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int
main()
{
  int i, j; /* Indices para os lacos for. */

  p_professor * professores; /* Vetor de ponteiros para registros
                                de professores. */
  int p;         /* Numero de elementos no vetor professores. */

  p_aluno * alunos; /* Vetor de ponteiros para registros de alunos.*/
  int a;     /* Numero de elementos no vetor alunos. */

  /* Variaveis temporarias para criacao dos registros. */
  char prof_nome[MAX_NOME], prof_sobrenome[MAX_NOME];
  char al_nome[MAX_NOME], al_sobrenome[MAX_NOME];
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
    scanf("%s %s %lf %s", prof_nome, prof_sobrenome, &val, disciplina);
    professores[i] = criarProfessor(prof_nome, prof_sobrenome, val, disciplina);
  }

  scanf("%d", &a);

  alunos = (p_aluno *) malloc(a * sizeof(p_professor));

  for (i = 0; i < a; i++) /* Alunos. */
  {
    scanf("%s %s %d", al_nome, al_sobrenome, &n);

    alunos[i] = criarAluno(al_nome, al_sobrenome);

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
    reajusteSalario(professores[i], (nota_min + nota_max)/2.0);
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
