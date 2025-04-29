#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

// Create a new Person
PERSON *create_node(int id, char*name)
{
  PERSON *ptr = malloc(sizeof(PERSON));
  if (ptr != NULL)
  {
    ptr->id = id;
    ptr->name = strdup(name);
    ptr->next = NULL;
  }

  return ptr;
}

void print_node(PERSON *ptr)
{
  printf("[%d|%s]", ptr->id, ptr->name);
}

// Liberta a memória que pode ser sido criada
// dinamicamente no nó.
void destroy_node(PERSON *ptr)
{
  free(ptr->name);
}
