#include <stdio.h>
#include <string.h>
#include "item.h"

void item_print(int index, ITEM *item, int add_NL)
{
  printf("%2d -->", index);

  if (item!=NULL)
    printf("[ \"%s\",%*s \"%s\" ]", 
           item->name, 10-(int) strlen(item->name), "", item->phone);
  else
    printf("(Não existe)");

  if (add_NL) 
    putchar('\n');
}


