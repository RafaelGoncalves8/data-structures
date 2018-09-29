#include "jogador.h"
#include <stdlib.h>
#include <stdio.h>

int
get_score(p_player player)
{
  int n;
  int ans;
  ans = player->sum_others;
  n = player->n_aces;
  while (player->n_aces)
  {
    if (ans + 10 <= 21)
      ans += 10;
    else
      ans += 1;
    n--;
  }

  return ans;
}

void
add_card(p_player player, int card)
{
  if (card == 1)
    player->n_aces++;
  else
    player->sum_others += card;

  if (get_score(player) >= 21)
    player->is_playing = 0;
}

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

p_player
new_player()
{
  p_player player;

  player = alloc_player();
  player->n_aces = 0;
  player->sum_others = 0;
  player->is_playing = 1;

  return player;
}

void
destroy_player(p_player player)
{
  free(player);
}
