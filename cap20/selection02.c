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
  if (n==0 || n==1) return; // Está ordenado

  int index_min=0;
  for (int j=1; j<n; j++)
    if (v[j] < v[index_min])
      index_min = j;

  if (index_min!=0) // só se troca se for necessário 
      swap_int(&v[0], &v[index_min]);

  selection_sort_int(v+1, n-1);
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

