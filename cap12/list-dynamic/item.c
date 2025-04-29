#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

// Create a new Item
ITEM *create_item(unsigned int num)
{
  ITEM *ptr = malloc(sizeof(ITEM));
  if (ptr != NULL)
  {
    ptr->num = num;
    ptr->next = NULL;
  }
  return ptr;
}

void print_item(ITEM *ptr)
{
  printf("[%d]\n", ptr->num);
}

// Liberta a memória que pode ser sido criada
// dinamicamente no nó.
void destroy_item(ITEM *ptr)
{
   // nada a fazer
}
