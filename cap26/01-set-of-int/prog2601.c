#include <stdio.h>
#include "item.h"
#include "set.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))

ITEM arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
ITEM arr2[] = {0, 2, 4, 5, 6, 9, 11, 99};


int main(void)
{
  Set set1, set2, empty_set, *aux;

  puts("Init set1, set2 & empty_set");
  set_init(&set1); set_init(&set2); set_init(&empty_set);

  set_print(&set1, "set1"); set_print(&set2, "set2");
  set_print(&empty_set, "empty_set");

  puts("\nAdd values to set1 & set2");
  set_addAll(&set1, arr1, LEN(arr1));
  set_addAll(&set2, arr2, LEN(arr2));

  set_print(&set1, "set1"); set_print(&set2, "set2");

  printf("\nset1 contains set2 : %s\n",
         set_contains(&set1, &set2) ? "TRUE" : "FALSE");
  printf("set2 contains set1 : %s\n",
         set_contains(&set2, &set1) ? "TRUE" : "FALSE");

  printf("\nset1 contains empty_set : %s\n", 
         set_contains(&set1, &empty_set) ? "TRUE" : "FALSE");
  printf("empty_set contains set1 : %s\n",
         set_contains(&empty_set, &set1) ? "TRUE" : "FALSE");

  printf("\nset1 contains set1 : %s\n",
         set_contains(&set1, &set1) ? "TRUE" : "FALSE");
  printf("set2 contains set2 : %s\n",
         set_contains(&set2, &set2) ? "TRUE" : "FALSE");
  printf("empty_set contains empty_set : %s\n",
         set_contains(&empty_set, &empty_set) ? "TRUE" : "FALSE");

  // Operações sobre conjuntos

  // Union
  puts("\nUnion between set1 & set2");
  aux = set_union(&set1, &set2);
  set_print(aux, "union");
  set_clear(aux);

  puts("Union between set1 & empty_set");
  aux = set_union(&set1, &empty_set);
  set_print(aux, "union");
  set_clear(aux);

  puts("Union between empty_set & empty_set");
  aux = set_union(&empty_set, &empty_set);
  set_print(aux, "union");
  set_clear(aux);

  // Intersection
  puts("\nIntersection between set1 & set2");
  aux = set_intersect(&set1, &set2);
  set_print(aux, "Intersection");
  set_clear(aux);

  puts("Intersection between set1 & empty_set");
  aux = set_intersect(&set1, &empty_set);
  set_print(aux, "Intersection");
  set_clear(aux);

  puts("Intersection between empty_set & empty_set");
  aux = set_intersect(&empty_set, &empty_set);
  set_print(aux, "Intersection");
  set_clear(aux);

  // Minus
  puts("\nDifference (Minus) between set1 & set2");
  aux = set_minus(&set1, &set2);
  set_print(aux, "Difference");
  set_clear(aux);

  puts("Difference (Minus) between set1 & empty_set");
  aux = set_minus(&set1, &empty_set);
  set_print(aux, "Difference");
  set_clear(aux);

  puts("Difference (Minus) between empty_set & empty_set");
  aux = set_minus(&empty_set, &empty_set);
  set_print(aux, "Difference");
  set_clear(aux);

  set_destroy(&set1);
  set_destroy(&set2);
  return 0;
}
