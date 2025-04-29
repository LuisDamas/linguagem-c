#include <stdio.h>
#include <string.h>

// Imprime um array de inteiros
void print_array(int v[], int n)
{
  printf("{");
  for (int i=0; i<n ; i++)
    printf("%d%s",v[i], (i<(n-1)) ? ", " : "");
  printf("}\n");
}

// Troca dois inteiros referenciados por cada um dos endereços
void swap_int(int *ptr1, int *ptr2)
{
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

// Algoritmo Selection Sort aplicado a um array de n inteiros
void selection_sort_int(int v[], int n)
{
  int index_min;
  for (int i=0; i<n-1 ; i++)
  {
    index_min= i;

    for (int j=i+1; j<n; j++)
      if (v[j] < v[index_min])
	index_min = j;

    if (i!=index_min) // só se troca se for necessário 
      swap_int(&v[i], &v[index_min]);
  }
}

int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  puts("Array ANTES da Ordenação");
  print_array(v, size);

  selection_sort_int(v, size);

  puts("Array DEPOIS da Ordenação");
  print_array(v, size);

  return 0;
}

