#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define MAX_STR 30

struct Item
{
  char brand[MAX_STR];
  char *model;
  struct {int day, month, year;} date;
};

ITEM item_create(char*brand, char*model, int year, int month, int day)
{
  ITEM item = (ITEM) malloc(sizeof(*item));
  if (item==NULL) return NULL;

  // Ver se conseguimos duplicar a string model
  if ((item->model = strdup(model))==NULL)
  {
    free(item);
    return NULL;
  }

  strcpy(item->brand, brand);
  item->date.day = day;
  item->date.month = month;
  item->date.year = year;

  return item;
}

void item_show(ITEM ptr)
{
  printf("[%s-%s : %d-%02d-%02d]", ptr->brand, ptr->model,
         ptr->date.year, ptr->date.month, ptr->date.day);
}

void item_destroy(ITEM q)
{
  if (q==NULL) return;
  free(q->model);
  free(q);
}
