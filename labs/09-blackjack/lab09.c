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
  p_stack deck; /* Baralho de cartas. */
  p_player tmp; /* Variavel para criacao da fila de jogadores. */
  p_queue_node current; /* Ponteiro para o jogador atual. */
  p_queue players;      /* Jogadores. */
  int m, n;             /* Numero de cartas m e de jogadores n. */
  char s[MAX_CHAR];     /* Carta do baralho lida. */
  int card;             /* int representando uma carta do baralho. */
  int i;                /* Variavel indexadora para os lacos. */

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

  /* Criar fila de jogadores. */
  for (i = 0; i < n+1; i++)
  {
    tmp = new_player();
    enqueue(players, tmp);
  }

  /* Adiciona-se 2 cartas para cada jogador. */
  for (i = 0; i < 2; i++)
  {
    current = players->tail->next->next;
    while (current->val != DUMMY)
    {
      card = pop(deck);
      current->val = add_card(current->val, card);
      current = current->next;
    }
  }

  /* Acoes dos jogadores. */
  current = players->tail->next->next;
  scanf("%s", s);
  while (strcmp(s, "#") && current->val != DUMMY)
  {
    if (!strcmp(s, "H"))
    {
      card = pop(deck);
      current->val = add_card(current->val, card);
      current = current->next;
    }
    else if (!strcmp(s, "S"))
    {
      current->val->is_playing = 0;
      current = current->next;
    }
    else /* s eh uma carta. */
    {
      card = string_to_card(s);
      push(deck, card);
    }

    scanf("%s", s);

   /* Pular jogadores inativos e o no dummy. */
    while (current->val != DUMMY && !(current->val->is_playing))
      current = current->next;
    if (current->val == DUMMY)
      current = current->next;
    while (current->val != DUMMY && !(current->val->is_playing))
      current = current->next;
  }

  /* Imprimir scores. */
  while (first(players) != DUMMY)
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
