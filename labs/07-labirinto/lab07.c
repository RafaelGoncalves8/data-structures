/*
 * Lab 07
 * Rafael Goncalves
 *
 * Objetivo: 
 */

#include <stdlib.h>
#include <stdio.h>

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

/*
 * Resolve o labirinto usando backtracking.
 *
 * Entradas: m = matriz do problema
 *           ans = matriz solucao do problema
 *           x = linha atual
 *           y = linha atual
 *           ls = linha da saida
 *           cs = coluna da saida
 *           lt = quantidade maxima de linhas
 *           ct = quantidade maxima de colunas
 *
 * Saida:    1 se encontrou uma solucao
 *           0 se nao encontrou solucao
 */
int
solve_maze(char * * m, char * * ans, int x, int y, int ls, int cs, int lt, int ct)
{
  if (x == ls && y == cs) /* Chegou na saida. */
  {
    printf("ganhei\n");
    ans[x][y] = '*';
    return 1;
  }
  else if ( x < 0
           || y < 0
           || x >= lt
           || y >= ct
           || m[x][y] == 'X') /* Nao eh posicao valida. */
  {
    printf("posicao nao permitida\n");
    return 0;
  }
  else  /* Eh uma posicao valida. */
  {
    printf("posicao permitida\n");
    ans[x][y] = '*';
    return solve_maze(m, ans, x-1, y, ls, cs, lt, ct)
        || solve_maze(m, ans, x, y-1, ls, cs, lt, ct)
        || solve_maze(m, ans, x+1, y, ls, cs, lt, ct)
        || solve_maze(m, ans, x, y+1, ls, cs, lt, ct);
  }
}

int
main()
{
  int i, j; /* Indexadores para os lacos for. */

  int lt, ct; /* Numero total de linhas (lt) e de colunas (ct). */
  int le, ce; /* Indices da linha (le) e da coluna (ce) da entrada. */
  int ls, cs; /* Indices da linha (ls) e da coluna (cs) da saida. */

  char * * maze; /* Matriz que representa o labirinto. */
  char * * ans; /* Matriz que representa a solucao do labirinto. */

  /* Leitura das dimensoes. */
  scanf("%d %d %d %d %d %d", &lt, &ct, &le, &ce, &ls, &cs);

  /* Alocacao dinamica da memoria para as matrizes maze e ans. */
  maze = (char * *) malloc(lt * sizeof(char *));
  if (maze == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    return NUM_ERR_OUT_OF_MEM;
  }

  ans = (char * *) malloc(lt * sizeof(char *));
  if (ans == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    return NUM_ERR_OUT_OF_MEM;
  }

  for (i = 0; i < lt; i++)
  {
    maze[i] = (char *) malloc(ct * sizeof(char));
      if (maze[i] == NULL)
      {
        printf(STR_ERR_OUT_OF_MEM);
        return NUM_ERR_OUT_OF_MEM;
      }

    ans[i] = (char *) malloc(ct * sizeof(char));
      if (ans[i] == NULL)
      {
        printf(STR_ERR_OUT_OF_MEM);
        return NUM_ERR_OUT_OF_MEM;
      }
  }

  /* Inicializacao da matriz de solucao com espacos. */
  for (i = 0; i < lt; i++)
    for (j = 0; j < ct; j++)
      ans[i][j] = ' ';

  /* Leitura do labirinto. */
  for (i = 0; i < lt; i++)
    for (j = 0; j < ct; j++)
      scanf(" %c", &maze[i][j]);

  /* Solucao do labirinto. */
  solve_maze(maze, ans, le, ce, ls, cs, lt, ct);

  /* Impressao da matriz de solucao. */
  for (i = 0; i < lt; i++)
  {
    for (j = 0; j < ct - 1; j++)
      printf("%c ", ans[i][j]);
    printf("%c\n", ans[i][j]);
  }

  /* Liberar as memorias. */
  for (i = 0; i < lt; i++)
  {
    free(maze[i]);
    free(ans[i]);
  }

  free(maze);
  free(ans);

  return 0;
}
