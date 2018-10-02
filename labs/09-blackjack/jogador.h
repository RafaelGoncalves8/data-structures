#ifndef jogador_h
#define jogador_h

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

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

p_player
add_card(p_player player, int card);

p_player
new_player();

void
destroy_player(p_player player);

#endif
