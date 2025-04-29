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


// Algoritmo Selection Sort aplicado a um array de n strings
void selection_sort_string(char* v[], int n)
{
  int index_min;
  for (int i=0; i<n-1 ; i++)
  {
    index_min= i;

    for (int j=i+1; j<n; j++)
      if (strcmp(v[j], v[index_min])<0)
	index_min = j;

    if (i!=index_min) // só se troca se for necessário 
      swap_string(&v[i], &v[index_min]);
  }
}
int main()
{
  char* nomes[]={"carlao", "zeferino", "anabela", "mariana", "zoo", "ana", "bela",
                  "zulmira", "carlos", "carla", "manuela", "manuel", "ana bela"};

  int size = sizeof(nomes)/sizeof(nomes[0]);

  puts("Array ANTES da Ordenação");
  print_array(nomes, size);

  selection_sort_string(nomes, size);

  puts("\nArray DEPOIS da Ordenação");
  print_array(nomes, size);

  return 0;
}


