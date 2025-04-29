#include <stdio.h>

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

// Algoritmo Insertion Sort aplicado a um array de n inteiros
void insertion_sort_int(int v[], int n)
{
  int j, new_value;
  for (int i=1; i<n ; i++)
  {
    new_value= v[i];
    for (j=i ; j>=1 && v[j-1]>new_value ; j--)
      v[j] = v[j-1];

    v[j] = new_value;
  }
}

int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  puts("Array ANTES da Ordenação");
  print_array(v, size);

  insertion_sort_int(v, size);

  puts("Array DEPOIS da Ordenação");
  print_array(v, size);

  return 0;
}
