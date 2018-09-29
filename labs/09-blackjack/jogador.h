#ifndef jogador_h
#define jogador_h

typedef struct PlayerStruct
{
  int sum_others; /* Soma das cartas que nao sao as. */
  int n_aces;     /* Numero de cartas as. */
  int is_playing; /* Flag que indica se jogador ainda recebera cartas. */
}
Player;

typedef Player * p_player;

int
get_score(p_player player);

void
add_card(p_player player, int card);

p_player
alloc_player();

p_player
new_player();

#endif
