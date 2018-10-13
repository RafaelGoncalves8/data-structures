/*
 * Lab 09
 * Rafael Gonçalves
 *
 * Objetivo: Simular uma partida de BlackJack utilizando uma
 * pilha para representar um baralho e filas para representar
 * os jogadores.
 */

#include "fila.h"
#include "pilha.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 3

/* Converte a string s em um int card para ser empilhado. */
int
string_to_card(char * s)
{
  int card;
  if (!strcmp(s, "A"))
    card = 1;
  else if (!strcmp(s, "V") || !strcmp(s, "D") || !strcmp(s, "R"))
    card = 10;
  else
    card = atoi(s);

  return card;
}

int
main()
{
  p_stack deck;     /* Baralho de cartas. */
  p_player tmp;     /* Variavel para criacao da fila de jogadores. */
  p_queue playing;  /* Fila de jogadores ativos. */
  p_queue players;  /* Fila de todos os jogadores. */
  int m, n;         /* Numero de cartas m e de jogadores n. */
  char s[MAX_CHAR]; /* Carta do baralho lida. */
  int card;         /* int representando uma carta do baralho. */
  int i;            /* Variavel indexadora para os lacos. */

  deck = new_stack();
  players = new_queue();
  playing = new_queue();

  scanf("%d%d", &m, &n);

  /* Construcao do baralho. */
  for (i = 0; i < m; i++)
  {
    scanf("%s ", s);
    card = string_to_card(s);
    push(deck, card);
  }

  /* Criar fila de jogadores e fila de jogadores ativos. */
  for (i = 0; i < n+1; i++)
  {
    tmp = new_player();

    enqueue(players, tmp);
    enqueue(playing, tmp);
  }

  /* Cada jogador recebe 2 cartas. */
  for (i = 0; i < (n+1)*2; i++)
  {
    card = pop(deck);

    tmp = dequeue(playing);
    add_card(tmp, card);

    if (get_score(tmp) < 21)
      enqueue(playing, tmp);
  }

  /* Acoes dos jogadores. */
  scanf("%s", s);
  while (strcmp(s, "#"))
  {
    if (!strcmp(s, "H"))
    {
      card = pop(deck);
      tmp = dequeue(playing);
      add_card(tmp, card);

      if (get_score(tmp) < 21)
        enqueue(playing, tmp);
    }
    else if (!strcmp(s, "S"))
    {
      dequeue(playing);
    }
    else /* s eh uma carta. */
    {
      card = string_to_card(s);
      push(deck, card);
    }

    scanf("%s", s);
  }

  /* Imprimir scores. */
  while (first(players) != DUMMY) /* Enquanto fila nao esta vazia. */
  {
    tmp = dequeue(players);
    printf("%d\n", get_score(tmp));
    destroy_player(tmp);
  }

  /* Destruir estruturas (liberar memoria alocada dinamicamente). */
  destroy_stack(deck);
  destroy_queue(players);
  destroy_queue(playing);

  return 0;
}
