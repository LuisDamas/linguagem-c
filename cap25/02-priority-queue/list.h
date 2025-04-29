#pragma once
#include <stdio.h>
#include "person.h"

typedef struct Node
{
  PERSON *data;
  struct Node *next;
} NODE;

typedef struct LIST
{
  NODE *head;
  int (*compare)(PERSON *, PERSON*);
} LIST;

void list_inic(LIST *list, int (*f)(PERSON*, PERSON*));

int  list_isEmpty(LIST *list);
size_t list_size(LIST *list);

PERSON* list_front(LIST *list);

void list_add(LIST *list, PERSON* ptr);
void list_remove(LIST *list);

void list_destroy(LIST *list, int free_itens);

// Extra
void list_print(LIST *list);

