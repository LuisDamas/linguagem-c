#include <stdio.h>
#include <stdlib.h>

#define LEN(array) (sizeof(array)/sizeof(array[0]))

int compare_int(const void * p1, const void * p2)
{
  int *ptr1 = (int *) p1;
  int *ptr2 = (int *) p2;
  return *ptr1-*ptr2;
}

int main()
{
  int values[] = {56, 23, -5, 13, 23, 0, 97, -23, 0, 5};
  int keys[] = {-23, 0, 97, 123};

  qsort(values, LEN(values), sizeof(values[0]), compare_int);

  // Array depois de ordenado
  // {-23, -5, 0, 0, 5, 13, 23, 23, 56, 97}

  for (int i=0; i<LEN(keys); i++)
  {
    int key = keys[i];
    int *ptr = bsearch(&key, values, LEN(values), sizeof(values[0]), compare_int);
    if (ptr==NULL)
      printf("  Key=%3d --> Not Found!!!\n", key);
    else
      printf("  Key=%3d --> Found at index=%d\n", key, (int) (ptr-values));
  }

  return 0;
}

