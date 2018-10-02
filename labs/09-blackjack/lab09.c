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
  p_player tmp;     /* Variavel para criacao da fila de jogadores. */
  p_queue current;  /* Ponteiro para o jogador atual. */
  p_queue players;  /* Jogadores. */
  int m, n;         /* Numero de cartas m e de jogadores n. */
  char s[MAX_CHAR]; /* Carta do baralho lida. */
  int card;         /* int representando uma carta do baralho. */
  int i;            /* Variavel indexadora para os lacos. */

  deck = new_stack();
  players = new_queue();

  scanf("%d%d", &m, &n);

  /* Construcao do baralho. */
  for (i = 0; i < m; i++)
  {
    scanf("%s ", s);

    card = string_to_card(s);

    push(deck, card);
  }

  for (i = 0; i < n; i++)
  {
    tmp = new_player();
    players = enqueue(players, tmp);
  }

  current = players->next->next;
  /* Acoes dos jogadores. */
  scanf("%s", s);
  while (strcmp(s, "#"))
  {
    card = pop(deck);

    if (!strcmp(s, "H"))
    {
      current->val = add_card(current->val, card);
    }
    else if (!strcmp(s, "S"))
    {
      players->val->is_playing = 0;
    }
    else /* s eh uma carta. */
    {
      card = string_to_card(s);

      push(deck, card);
    }

    do
      current = current->next;
    while (!current->val->is_playing);

    scanf("%s", s);
  }

  /* Imprimir scores. */
  if (players != NULL) /* Fila nao esta vazia. */
  {
    current = players->next->next;
    do
    {
      printf("%d\n", get_score(current->val));
      current = current->next;
    }
    while (current->val != DUMMY);
  }

  /* Destruir estruturas (liberar memoria alocada dinamicamente). */
  destroy_stack(deck);
  destroy_queue(players);

  return 0;
}
