#ifndef jogador_h
#define jogador_h

#define NUM_ERR_OUT_OF_MEM -1
#define STR_ERR_OUT_OF_MEM "Nao ha espaco na memoria.\n"

typedef struct PlayerStruct
{
  int sum_others; /* Soma das cartas que nao sao as. */
  int n_aces;     /* Numero de cartas as. */
}
Player;

typedef Player * p_player;

/* Cria novo jogador sem cartas e jogando (is_playing = 1). */
p_player
new_player();

/* Calcula e retorna a pontuacao do jogador player. */
int
get_score(p_player player);

/* Adiciona carta card na mao do jogador player e devolve o mesmo. */
p_player
add_card(p_player player, int card);

/* Libera memoria alocada dinamicamente para o jogador player. */
void
destroy_player(p_player player);

#endif
