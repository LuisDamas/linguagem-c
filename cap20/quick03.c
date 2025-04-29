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

int partition(char* v[], int indexStart, int indexEnd)
{
  char* pivot = v[indexEnd]; // Último elemento
  int bound = indexStart;

  for (int index=indexStart; index<indexEnd; index++)
    if (strcmp(v[index], pivot)<0)
      swap_string(&v[bound++], &v[index]);

  swap_string(&v[bound], &v[indexEnd]);
  return bound;
}

// Algoritmo Quick Sort aplicado a um array de strings
void quick_sort_string(char* v[], int indexStart, int indexEnd)
{
  if (indexStart >= indexEnd) return;

  int indexPivot = partition(v, indexStart, indexEnd);

  quick_sort_string(v, indexStart, indexPivot-1);
  quick_sort_string(v, indexPivot+1, indexEnd);
}

int main()
{
  char* nomes[]={"carlao", "zeferino", "anabela", "mariana", "zoo", "ana", "bela",
                 "zulmira", "carlos", "carla", "manuela", "manuel", "ana bela"};

  int size = sizeof(nomes)/sizeof(nomes[0]);

  puts("Array ANTES da Ordenação");
  print_array(nomes, size);

  quick_sort_string(nomes, 0, size-1);

  puts("\nArray DEPOIS da Ordenação");
  print_array(nomes, size);

  return 0;
}


