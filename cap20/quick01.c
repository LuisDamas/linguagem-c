#include <stdio.h>
#include <string.h>

// Imprime um array de inteiros
void print_array(int v[], int n)
{
  printf("{");
  for (int i=0; i<n ; i++)
    printf("%d%s", v[i], (i<(n-1)) ? ", " : "");
  printf("}\n");
}

// Troca dois inteiros referenciados por cada um dos endereços
void swap_int(int *ptr1, int *ptr2)
{
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

int partition(int v[], int indexStart, int indexEnd)
{
  int pivot = v[indexEnd]; // Último elemento
  int bound = indexStart;

  for (int index=indexStart; index<indexEnd; index++)
    if (v[index] < pivot)
      swap_int(&v[bound++], &v[index]);

  swap_int(&v[bound], &v[indexEnd]);
  return bound;
}

// Algoritmo Quick Sort aplicado a um array de n inteiros
void quick_sort_int(int v[], int indexStart, int indexEnd)
{
  if (indexStart >= indexEnd) return;

  int indexPivot = partition(v, indexStart, indexEnd);

  quick_sort_int(v, indexStart, indexPivot-1);
  quick_sort_int(v, indexPivot+1, indexEnd);
}

int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  puts("Array ANTES da Ordenação");
  print_array(v, size);

  quick_sort_int(v, 0, size-1);

  puts("Array DEPOIS da Ordenação");
  print_array(v, size);

  return 0;
}
