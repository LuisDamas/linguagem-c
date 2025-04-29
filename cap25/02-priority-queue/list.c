#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "list.h"

// Coloca a cabeça da lista a NULL
// E guarda a ref. para a função de comparação
void list_inic(LIST *list, int (*f)(PERSON*, PERSON*))
{
  list->head = NULL;
  list->compare = f;
}

// Verifica se a lista está vazia
int list_isEmpty(LIST *list)
{
  return list->head==NULL;
}

// Devolve o número de nós da lista
static size_t node_count(NODE *node)
{
  if (node==NULL) return 0;
  return 1 + node_count(node->next);
}

// Devolve o número de elementos na lista
size_t list_size(LIST *list)
{
  return node_count(list->head);
}

// Devolve o elemento no início da lista
PERSON* list_front(LIST *list)
{
  if (list_isEmpty(list))
    return NULL;

  return list->head->data;
}

// Adiciona uma nova PERSON à lista
void list_add(LIST *list, PERSON* ptr)
{
  // Criar um novo nó
  NODE *new_node = (NODE*) malloc(sizeof(NODE));
  if (new_node==NULL) return;

  new_node->data = ptr;

  // Guardar o endereço do apontador que contém
  // o nó a analisar ao longo da lista
  NODE **address = &list->head;

  // Enquanto existirem nós e forem menores que
  // o novo elemento a inserir, avançar na lista
  while (*address!=NULL &&
         list->compare((*address)->data, ptr)<0)
    address = &(*address)->next;

  // address contém o endereço onde inserir
  // o novo nó
  new_node->next = *address;
  *address = new_node;
}

void list_remove(LIST *list)
{
  if (list_isEmpty(list)) return;

  NODE *aux = list->head;
  list->head = list->head->next;
  aux->next = NULL; // por segurança
  free(aux);
}

void list_destroy(LIST *list, int free_itens)
{
  while (!list_isEmpty(list))
  {
    PERSON *person = list_front(list);
    list_remove(list);
    if (free_itens) person_destroy(person);
  }
}

// Extra
void list_print(LIST *list)
{
  for (NODE *node = list->head; node!=NULL; node = node->next)
    person_print(node->data);
}

