#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void inic_list(LIST *list)
{
  *list = NULL;
}

int size(LIST list)
{
  if (list==NULL)
    return 0;
  return 1+size(list->next);
}

int is_empty(LIST list)
{
  return (list==NULL);
}

int is_full(LIST list)
{
  return 0; // always false
}

// Adicionar um novo nº à lista
unsigned int add_item(LIST *list, unsigned int num)
{
  if (num%2==1 || *list==NULL) // Ímpar ou lista vazia 
  {
    ITEM *ptr = create_item(num);
    if (ptr==NULL)
      return 0;  // problemas com alloc
    ptr->next = *list;
    *list = ptr;
    return num;
  }
  else
    return add_item(&(*list)->next, num);
}

// Remover uma occ de num e devolve-o ou zero
unsigned int remove_item(LIST *list, unsigned int num)
{
  if (is_empty(*list)) // Se lista vazia
    return 0;
 
  if ((*list)->num != num) // Não é o valor a remover
    return  remove_item(&(*list)->next, num);

  // Encontrado o valor a remover
  ITEM* aux = *list;
  *list = (*list)->next;
  aux->next = NULL; // Just in case...
  free(aux);
  return num;
}

void print_list(LIST list, char *title)
{
  printf("%s\t", title);
  // Cabeçalho da lista
  printf("list: {count: %d | isEmpty: %s}\n",
         size(list), is_empty(list)? "Yes" : "No");

  while (!is_empty(list))
  {
    print_item(list);
    list = list->next;
  }
  printf("\n");
}

