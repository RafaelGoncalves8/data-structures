#include <stdlib.h>
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
  strcpy(p->disciplina);

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

  a->nome = nome;
  a->sobrenome = sobrenome;
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
  int i;

  for (i = 0; i < qtd_alunos; i++)
  {
    for (j = 0; j < alunos[i]->qtd_disciplinas; j++)
    {
      if (!strcmp(alunos[i]->disciplinas[j], disciplina))
      {


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
  /* TODO */
}

/*
    Imprime o nome e sobrenome do professor e seu salário.

    Entrada: professor: ponteiro para registro professor
*/
void
imprimirProfessor(p_professor professor)
{
  /* TODO */
}

