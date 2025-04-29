#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "utils.h"

#define LEN(x) (sizeof(x)/sizeof(x[0]))
int arr[] = {50, 30, 90, 95, 45, 10, 49, 92, 40};

int compare_asc(const void *a, const void *b)
{ return (*(int *)a)-(*(int *)b); }

int compare_desc(const void *a, const void *b)
{ return -compare_asc(a, b); }

void load_bst(NODE **tree)
{
  bst_init(tree);

  // Load BST
  printf("\nInserir:\n[ ");

  for (int i=0; i<LEN(arr); i++)
  {
    printf("%d ", arr[i]);
    bst_insert(tree, arr[i]);
  }
  printf("]\n");
}

void free_bst(NODE **tree)
{
  while (!bst_count(*tree)!=0)
    bst_remove(tree, (*tree)->value);
}

int main(void)
{
  NODE *tree;
  load_bst(&tree);

  pretty_print(tree);
  free_bst(&tree);
  puts("PRIMA <ENTER> . . . "); getchar();

  qsort(arr, LEN(arr), sizeof(arr[0]), compare_asc);
  load_bst(&tree);

  pretty_print(tree);
  free_bst(&tree);
  puts("PRIMA <ENTER> . . . "); getchar();

  qsort(arr, LEN(arr), sizeof(arr[0]), compare_desc);
  load_bst(&tree);

  pretty_print(tree);
  free_bst(&tree);

  return 0;
}
