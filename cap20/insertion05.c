#include <string.h>

void swap_strings(char* *ptr1, char* *ptr2);

// Algoritmo Insertion Sort aplicado a um array de n strings
void insertion_sort_strings(char* v[], int n)
{
  int j;
  char* new_value;
  for (int i=1; i<n ; i++)
  {
    new_value= v[i];
    for (j=i ; j>=1 && strcmp(v[j-1], new_value)>0 ; j--)
      v[j] = v[j-1];

    v[j] = new_value;
  }
}

void sort_strings(char* v[], int indexStart, int indexEnd)
{
  insertion_sort_strings(v, indexEnd+1);
}
