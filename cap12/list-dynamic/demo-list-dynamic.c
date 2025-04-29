#include <stdio.h>
#include "list.h"

int main(void)
{
  LIST list;            //  Create a new list
  inic_list(&list);     //  Inic the list

  print_list(list, "Print empty list");

  for (int i=15; i>=10; i--)
    if (add_item(&list, i))
      printf("Added %d\n", i);

  print_list(list, ""); 

  add_item(&list, 17);
  print_list(list, "Adding 17");   

  add_item(&list, 13);
  print_list(list, "Adding 13");   

  add_item(&list, 999);
  print_list(list, "Adding 999");   

  if (remove_item(&list, 13))
    print_list(list, "Removing 13");
  else
    puts("Item 13 does not exist\n");

  if (remove_item(&list, 13))
    print_list(list, "Removing 13 again");
  else
    puts("Item 13 does not exist\n");

  if (remove_item(&list, 13))
    print_list(list, "Removing 13 again");
  else
    puts("Item 13 does not exist\n");

  // remove all items
  int value;
  while (!is_empty(list))
    if ((value=remove_item(&list, list->num)))
      printf("Removed %d\n", value);

  print_list(list, "\nEmpty list\n");

  return 0;
}

