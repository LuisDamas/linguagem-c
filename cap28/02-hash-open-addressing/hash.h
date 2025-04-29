#pragma once
#include "item.h"

#define HASH_SIZE 10
#define MAX_ATTEMPTS (HASH_SIZE*3)

#define SQUARE(x) ((x)*(x))

typedef struct
{
   ITEM *arr[HASH_SIZE];
   unsigned int (*hash_function)(ITEM *item);
   unsigned int (*probe_function)(unsigned int index, 
                                  unsigned int attempt);
} HASH_TABLE;

void hash_init(HASH_TABLE *h, unsigned int (*hash)(ITEM *),
           unsigned int (*probe)(unsigned int, unsigned int));

unsigned int hash_function(ITEM *item);

unsigned int linear_probing(unsigned int index,
                            unsigned int attempt);
unsigned int quadratic_probing(unsigned int index,
                               unsigned int attempt);
unsigned int prime_probing(unsigned int index,
                           unsigned int attempt);

void hash_add(HASH_TABLE *h, ITEM *item);

ITEM* hash_search(HASH_TABLE *h, ITEM *item);
ITEM* hash_search_str(HASH_TABLE *h, char* name);

int hash_count(HASH_TABLE *h);

void hash_print(HASH_TABLE *h);

