#include <stdio.h>
#include <stdlib.h>

#define LEN(array) (sizeof(array)/sizeof(array[0]))

void print_int_array(int arr[], int n)
{
  putchar('[');
  for (int i=0; i<n; i++)
  {
    printf("%d", arr[i]);
    if (i!=(n-1))
      printf(", ");
  }
  printf("]\n");
}

int compare_int(const void * p1, const void * p2)
{
  int *ptr1 = (int *) p1;
  int *ptr2 = (int *) p2;
  return *ptr1-*ptr2;
}

int main(void)
{
  int iArr[] = {56, 23, -5, 13, 23, 0, 97, -23, 0, 5};

  printf("Antes da ordenação  : "); 
  print_int_array(iArr, LEN(iArr));

  printf("\nOrdenando o array de inteiros. . .\n\n");
  qsort(iArr, LEN(iArr), sizeof(iArr[0]), compare_int);

  printf("Depois da ordenação : "); 
  print_int_array(iArr, LEN(iArr));

  return 0;
}
