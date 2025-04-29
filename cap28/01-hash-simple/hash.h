#pragma once
#include "item.h"
#define HASH_SIZE 10

typedef struct
{
   ITEM *arr[HASH_SIZE];
   unsigned int (*hash_function)(ITEM *);
} HASH_TABLE;

void hash_init(HASH_TABLE *h, unsigned int (*f)(ITEM *));
unsigned int hash_function(ITEM *item);

void hash_add(HASH_TABLE *h, ITEM *item);

ITEM* hash_search(HASH_TABLE *h, ITEM *item);
ITEM* hash_search_str(HASH_TABLE *h, char* name);

void hash_remove(HASH_TABLE *h, ITEM *item);
void hash_remove_str(HASH_TABLE *h, char* name);

int hash_count(HASH_TABLE *h);

void hash_print(HASH_TABLE *h);

