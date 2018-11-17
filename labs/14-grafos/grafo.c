#include "grafo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int
M(int x)
{
  return ( (int) sum(x)/3);
}

p_graph
create_graph(int * v);

void
destroy_graph(p_graph p);

p_graph
add_edge(p_graph g, int u, int v);

void
print_bored(g);
