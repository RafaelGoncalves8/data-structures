#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "universidade.h"

/*
    Cria um registro professor dinamicamente.

    Entrada: nome: nome do professor
             sobrenome: sobrenome do professor
             salario: salário do professor
             disciplina: disciplina lecionada pelo professor

    Saída: retorna um ponteiro para registro professor alocado
*/
p_professor
criarProfessor(char nome[], char sobrenome[], double salario,
               char disciplina[])
{
  p_professor p;

  p = (p_professor) malloc(sizeof(Professor));

  strcpy(p->nome, nome);
  strcpy(p->sobrenome, sobrenome);
  p->salario = salario;
  strcpy(p->disciplina, disciplina);

  return p;
}

/*
    Libera a memória alocada para registro professor.

    Entrada: professor: ponteiro para registro professor
*/
void
destruirProfessor(p_professor professor)
{
  free(professor);
}

/*
    Cria um registro aluno dinamicamente, inicialmente sem disciplinas
    matriculadas.

    Entrada: nome: nome do aluno
             sobrenome: sobrenome do aluno

    Saida: retorna um ponteiro para registro aluno alocado
*/
p_aluno
criarAluno(char nome[], char sobrenome[])
{
  p_aluno a;

  a = (p_aluno) malloc(sizeof(Aluno));

  strcpy(a->nome, nome);
  strcpy(a->sobrenome, sobrenome);
  a->qtd_disciplinas = 0;

  return a;
}

/*
    Adiciona uma disciplina à lista de disciplinas de um aluno.

    Entrada: aluno: ponteiro para registro aluno
             disciplina: código da disciplina
             nota: nota correspondente
*/
void
adicionarDisciplina(p_aluno aluno, char disciplina[], double nota)
{
  strcpy(aluno->disciplinas[aluno->qtd_disciplinas], disciplina);
  aluno->notas[aluno->qtd_disciplinas] = nota;
  aluno->qtd_disciplinas++;
}

/*
   Libera a memória alocada para registro aluno.

   Entrada: aluno: ponteiro para registro aluno
*/
void
destruirAluno(p_aluno aluno)
{
  free(aluno);
}

/*
    Obtém a nota máxima e a nota mínima entre todos os alunos matriculados em
    uma disciplina específica.

    Entrada: alunos: vetor com os dados dos alunos
             disciplina: código da disciplina
             qtd_alunos: quantidade de alunos no vetor

    Saída: devolve por parâmetro as notas máxima e mínima dos alunos
           nota_min: menor nota entre uma turma de alunos
           nota_max: maior nota entre uma turma de alunos

*/
void
obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[],
                   double *nota_min, double *nota_max)
{
  int i, j; /* Indexadores para os lacos for. */

  /* Valor inicial o pior caso possível. */
  *nota_min = 10.0;
  *nota_max = 0.0;

  for (i = 0; i < qtd_alunos; i++) /* Para cada aluno. */
  {
    for (j = 0; j < alunos[i]->qtd_disciplinas; j++) /* Para cada disciplina. */
    {
      /* Se for a mesma disciplina passada por parametro. */
      if (!strcmp(alunos[i]->disciplinas[j], disciplina))
      {
        if (alunos[i]->notas[j] <= *nota_min)
          *nota_min = (alunos[i]->notas[j]);
        if (alunos[i]->notas[j] >= *nota_max)
          *nota_max = (alunos[i]->notas[j]);
      }
    }
  }
}

/*
    Calcula o reajuste salarial do professor e atualiza registro.

    Entrada: professor: ponteiro para registro professor
             media_notas: média entre as notas máxima e mínima dos alunos de
             uma determinada disciplina
*/
void
reajusteSalario(p_professor professor, double media_notas)
{
  double val = 0; /* Porcentagem de aumento do salario. */

  if (media_notas == 10)
    val = 0.15;
  else if (media_notas >= 9)
    val = 0.10;
  else if (media_notas >= 8.5)
    val = 0.05;

  if (val)
    professor->salario +=  (professor->salario) * val;
}

/*
    Imprime o nome e sobrenome do professor e seu salário.

    Entrada: professor: ponteiro para registro professor
*/
void
imprimirProfessor(p_professor professor)
{
  printf("%s %s %.2f\n", professor->nome, professor->sobrenome,
          professor->salario);
}

