/*
 * Lab 09
 * Rafael Gonçalves
 *
 * Objetivo: Simular uma partida de BlackJack utilizando uma
 * pilha para representar um baralho e uma fila para representar
 * os jogadores.
 */

#include "fila.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  p_queue players;  /* Jogadores que ainda estao no jogo. */
  p_queue current;  /* Ponteiro que aponta para o jogador atual. */
  int m, n;         /* Numero de cartas m e de jogadores n. */
  char s[MAX_CHAR]; /* Carta do baralho lida. */
  int card;         /* int representando uma carta do baralho. */

  deck = new_stack();
  players = new_queue();

  scanf("%d%d", m, n);

  /* Construcao do baralho. */
  for (i = 0; i < m; i++)
  {
    scanf("%s ", s);

    card = string_to_card(s);

    push(deck, card);
  }

  /* Acoes dos jogadores. */
  current = players;
  scanf("%s", s);
  while (strcmp(s, "#"))
  {
    card = pop(deck);

    if (!strcmp(s, "H"))
    {
      if (card == 1)
        current->val->n_aces++;
      else
        current->val->sum_others += card;
    }
    else if (!strcmp(s, "S"))
    {
      players->val->is_playing = 0;
    }
    else /* c eh uma carta. */
    {
      card = string_to_card(s);

      push(deck, card);
    }

    do
      current = current->next;
    while (!current->val->is_playing)

    scanf("%c", c);
  }

  /* Imprimir scores. */
  if (players != NULL) /* Fila nao esta vazia. */
  {
    current = players;
    do
    {
      printf("%d\n", get_score(current->val));
      current = current->next;
    }
    while (current != players)
  }

  /* Destruir estruturas (liberar memoria alocada dinamicamente). */
  deck = destroy_stack(deck);
  players = destroy_queue(players);

  return 0;
}
