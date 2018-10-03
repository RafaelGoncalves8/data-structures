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
  p_queue_node current;  /* Ponteiro para o jogador atual. */
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

  for (i = 0; i < n+1; i++)
  {
    tmp = new_player();
    enqueue(players, tmp);
  }

  /* Adiciona-se 2 cartas para cada jogador. */
  current = players->tail->next->next;
  for (i = 0; i < 2; i++)
  {
    while (current->val != DUMMY)
    {
      card = pop(deck);
      current->val = add_card(current->val, card);
      current = current->next;
    }
  }

  current = players->tail->next->next;
  /* Acoes dos jogadores. */
  scanf("%s", s);
  while (strcmp(s, "#"))
  {
    card = pop(deck);

    /* Pula para o próximo jogador ainda no jogo. */
    if (current->val == DUMMY)
    {
      current = current->next;
    }
    if (current->val != DUMMY)
    {
      do
      {
        current = current->next;
      }
      while (current->val == DUMMY || !(current->val->is_playing));
    }

    if (!strcmp(s, "H"))
    {
      current->val = add_card(current->val, card);
    }
    else if (!strcmp(s, "S"))
    {
      current->val->is_playing = 0;
    }
    else /* s eh uma carta. */
    {
      card = string_to_card(s);

      push(deck, card);
    }

    scanf("%s", s);
  }

  /* Imprimir scores. */
  while (players->tail->next->next->val != DUMMY)
  {
    tmp = dequeue(players);
    printf("%d\n", get_score(tmp));
    destroy_player(tmp);
  }

  /* Destruir estruturas (liberar memoria alocada dinamicamente). */
  destroy_stack(deck);
  destroy_queue(players);

  return 0;
}
