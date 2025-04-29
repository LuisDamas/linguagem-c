#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

void hash_init(HASH_TABLE *h, unsigned int (*f)(ITEM *))
{
  memset(h->arr, 0, sizeof(ITEM *) * HASH_SIZE);
  h->hash_function = f;
}

// Devolve a soma dos ASCII do nome
unsigned int hash_function(ITEM *item)
{
  unsigned int res=0;
  for(int i=0; item->name[i]!='\0'; i++)
    res+=item->name[i];

  return res % HASH_SIZE;
}

void hash_add(HASH_TABLE *h, ITEM *item)
{
  unsigned int index = h->hash_function(item);

  // Ver se a posição já está ocupada
  if (h->arr[index]!=NULL)
  {
    printf(" Index %d: Colisão: Novo Registo: [%s, %s]", index,
           item->name, item->phone);
    printf(" Registo Atual: [%s, %s]\n",
           h->arr[index]->name, h->arr[index]->phone);
  }
  else
    h->arr[index]=item;
}

ITEM* hash_search(HASH_TABLE *h, ITEM *item)
{
  return hash_search_str(h, item->name);
}

ITEM* hash_search_str(HASH_TABLE *h, char* name)
{
  ITEM item;
  strcpy(item.name, name);

  unsigned int index = h->hash_function(&item);

  // Verificar se o name é mesmo aquele que se procura
  if (h->arr[index]!=NULL && strcmp(h->arr[index]->name, name)!=0)
    return NULL;

  return h->arr[index];
}

void hash_remove(HASH_TABLE *h, ITEM *item)
{
  if (hash_search(h, item)==NULL)
    printf("Registo inexistente!!!\n");
  else
  {
      unsigned int index = h->hash_function(item);
      h->arr[index]=NULL;
  }
}

void hash_remove_str(HASH_TABLE *h, char* name)
{
  ITEM item;
  strcpy(item.name, name);

  hash_remove(h, &item);
}

int hash_count(HASH_TABLE *h)
{
  int count=0;
  for (int i=0; i<HASH_SIZE; i++)
    if (h->arr[i]!=NULL)
      count++;
  return count;
}

void hash_print(HASH_TABLE *h)
{
  printf("Imprimir a HASH TABLE (%d) registos\n",
         hash_count(h));

  for (int i=0; i<HASH_SIZE; i++)
    item_print(i, h->arr[i], 1);
}

