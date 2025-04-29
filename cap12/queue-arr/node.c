#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// Devolve um novo nó preenchido com
// fn - first_name e ls - last_name
NODE create_node(const char *fn, const char *ls)
{
  NODE new_node;
  new_node.first_name = strdup(fn);
  new_node.last_name = strdup(ls);
  return new_node;
}

// Coloca a NULL os dois pointers sem mexer na alocação de memória
void reset_node(NODE *node)
{
  node->first_name = NULL;
  node->last_name = NULL;
}

// Liberta os recursos alocados, associados ao nó
void destroy_node(NODE node)
{
  free(node.first_name);
  free(node.last_name);
}

void print_node(NODE node)
{
  if (node.first_name == NULL || node.last_name == NULL)
    printf("[---] ");
  else
    printf("[%s|%s] ", node.first_name, node.last_name);
}
