#include <stdio.h>
#include <stdlib.h>

#define LEN(array) (sizeof(array)/sizeof(array[0]))

void print_double_array(double arr[], int n)
{
  putchar('[');
  for (int i=0; i<n; i++)
  {
    printf("%.2lf", arr[i]);
    if (i!=(n-1))
      printf(", ");
  }
  printf("]\n");
}

int compare_double(const void * p1, const void * p2)
{
  double d1 = *(const double *) p1;
  double d2 = *(const double *) p2;

  if (d1<d2) return -1;
  if (d1>d2) return 1;
  return 0;
}

int compare_double_rev(const void * p1, const void * p2)
{
  return -compare_double(p1, p2);
}

int main(void)
{
  double arr[] = {56.01, 23.02, -5.12, 13.00, 23.02, 0.0, 
                  97.99, -23.78, 0.00, 5.78};

  printf("Antes da ordenação\n");
  print_double_array(arr, LEN(arr));

  printf("\nOrdenando ASCENDENTEMENTE o array de doubles. . .\n");
  qsort(arr, LEN(arr), sizeof(arr[0]), compare_double);

  printf("Depois da ordenação\n");
  print_double_array(arr, LEN(arr));

  printf("\nOrdenando DESCENDENTEMENTE o array de doubles. . .\n");
  qsort(arr, LEN(arr), sizeof(arr[0]), compare_double_rev);

  printf("Depois da ordenação\n");
  print_double_array(arr, LEN(arr));

  return 0;
}
