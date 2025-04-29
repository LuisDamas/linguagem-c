#include <stdio.h>
#include <string.h>

// Imprime um array de strings
void print_array(char* v[], int n)
{
  for (int i=0; i<n ; i++)
    printf("%2d: %s\n", i+1, v[i]);
}

// Troca duas strings referenciadas por cada um dos endereços
void swap_string(char* *ptr1, char* *ptr2)
{
  char* tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

// Algoritmo Bubble Sort aplicado a um array de n strings
void bubble_sort_string(char* v[], int n)
{
  for (int i=0; i<n-1 ; i++)
    for (int j=0 ; j<n-i-1 ; j++)
      if (strcmp(v[j], v[j+1])>0)
        swap_string(&v[j], &v[j+1]);
}

int main()
{
  char* nomes[]={"carlao", "zeferino", "anabela", "mariana", "zoo", "ana", "bela",
                  "zulmira", "carlos", "carla", "manuela", "manuel", "ana bela"};

  int size = sizeof(nomes)/sizeof(nomes[0]);

  puts("Array ANTES da Ordenação");
  print_array(nomes, size);

  bubble_sort_string(nomes, size);

  puts("\nArray DEPOIS da Ordenação");
  print_array(nomes, size);

  return 0;
}


