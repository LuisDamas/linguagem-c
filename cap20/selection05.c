#include <string.h>

void swap_strings(char* *ptr1, char* *ptr2);

// Algoritmo Selection Sort aplicado a um array de n strings
void selection_sort_strings(char* v[], int n)
{
  int index_min;
  for (int i=0; i<n-1 ; i++)
  {
    index_min= i;

    for (int j=i+1; j<n; j++)
      if (strcmp(v[j], v[index_min])<0)
	index_min = j;

    if (i!=index_min) // só se troca se for necessário
      swap_strings(&v[i], &v[index_min]);
  }
}

void sort_strings(char* v[], int indexStart, int indexEnd)
{
  selection_sort_strings(v, indexEnd+1);
}
