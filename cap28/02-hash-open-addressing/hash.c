#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

void hash_init(HASH_TABLE *h, unsigned int (*hash)(ITEM *),
          unsigned int (*probe)(unsigned int, unsigned int))
{
  memset(h->arr, 0, sizeof(ITEM *) * HASH_SIZE);
  h->hash_function = hash;
  h->probe_function = probe;
}

// Devolve a soma dos ASCII do nome
unsigned int hash_function(ITEM *item)
{
  unsigned int res=0;
  for(int i=0; item->name[i]!='\0'; i++)
    res+=item->name[i];

  return res % HASH_SIZE;
}

unsigned int linear_probing(unsigned int index,
                            unsigned int attempt)
{
  return (index + attempt) % HASH_SIZE;
}

unsigned int quadratic_probing(unsigned int index, 
                               unsigned int attempt)
{
  return (index + SQUARE(attempt)) % HASH_SIZE;
}

unsigned int prime_probing(unsigned int index, 
                           unsigned int attempt)
{
  // zero + primeiros 29 nºs primos
  static unsigned int arr_prime[] = {
          0, 2, 3, 5, 7, 11, 13, 17, 19, 23,
          29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
          71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

  return (index + arr_prime[attempt]) % HASH_SIZE;
}


void hash_add(HASH_TABLE *h, ITEM *item)
{
  unsigned int index = h->hash_function(item);
  unsigned int attempt = 0;
  unsigned int final_index = h->probe_function(index, attempt);

  while (h->arr[final_index] != NULL && attempt < MAX_ATTEMPTS)
  {
    if (strcmp(h->arr[final_index]->name, item->name) == 0)
    {
      printf("Registo: {\"%s\", \"%s\"} já existe no índice %d.\n",
              h->arr[final_index]->name, 
              h->arr[final_index]->phone, index);
      return;
    }

    final_index = h->probe_function(index, ++attempt);
  }

  if (attempt == MAX_ATTEMPTS) // Array está cheio ou nº max. tentativas
    return;

  h->arr[final_index]=item;
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
  unsigned int attempt = 0;
  unsigned int final_index = h->probe_function(index, attempt);

  while (h->arr[final_index] != NULL && attempt < MAX_ATTEMPTS)
  {
    if (strcmp(h->arr[final_index]->name, item.name) == 0)
      return h->arr[final_index];
    final_index = h->probe_function(index, ++attempt);
  }

  return NULL;
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

