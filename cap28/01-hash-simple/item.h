#pragma once
#define MAX_STR 20

typedef struct
{
  char name[MAX_STR+1];
  char phone[MAX_STR+1];
} ITEM;

void item_print(int index, ITEM *item, int add_NL);

