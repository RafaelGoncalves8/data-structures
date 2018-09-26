/*
 * Lab 09
 * Rafael Gonçalves
 *
 * Objetivo:
 */

int
main()
{
  p_node deck;          /* Baralho de cartas. */
  p_node players;       /* Jogadores. */
  int m, n;             /* Numero de cartas m e de jogadores n. */
  char card[MAX_CHAR];  /* Carta do baralho. */
  char c;               /* Caractere lido (acao ou fim do programa). */

  deck = new_stack();
  players = new_queue();

  scanf("%d%d", m, n);

  /* Construcao do baralho. */
  for (i = 0; i < m; i++)
  {
    scanf("%s ", card);
    push(deck, card);
  }

  /* Acoes dos jogadores. */
  scanf("%c", c);
  while (c != '#')
  {
    card = pop(deck);
    /* TODO */
    scanf("%c", c);
  }

  /* Destruir estruturas (liberar memoria alocada dinamicamente). */
  deck = destroy_stack(deck);
  players = destroy_queue(players);

  return 0;
}
