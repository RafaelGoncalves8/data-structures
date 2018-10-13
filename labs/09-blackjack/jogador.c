#include "jogador.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Aloca dinamicamente espaco na memoria para o tipo Player e
 * devolve um ponteiro para a regiao de memoria alocada.
 */
p_player
alloc_player()
{
  p_player player;

  player = (p_player) malloc(sizeof(Player));
  if (player == NULL)
  {
    printf(STR_ERR_OUT_OF_MEM);
    exit(NUM_ERR_OUT_OF_MEM);
  }

  return player;
}

/* Cria novo jogador sem cartas e jogando (is_playing = 1). */
p_player
new_player()
{
  p_player player;

  player = alloc_player();
  player->n_aces = 0;
  player->sum_others = 0;

  return player;
}

/* Calcula e retorna a pontuacao do jogador player. */
int
get_score(p_player player)
{
  int n;
  int ans;
  ans = player->sum_others;
  n = player->n_aces;
  while (n)
  {
    n--;
    if ((ans + 11 + n) <= 21)
      ans += 11;
    else
      ans += 1;
  }

  return ans;
}

/* Adiciona carta card na mao do jogador player e devolve o mesmo. */
p_player
add_card(p_player player, int card)
{
  if (card == 1)
    player->n_aces += 1;
  else
    player->sum_others += card;

  return player;
}

/* Libera memoria alocada dinamicamente para o jogador player. */
void
destroy_player(p_player player)
{
  free(player);
}
