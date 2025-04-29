#include <string.h>

void swap_strings(char* *ptr1, char* *ptr2);

// Algoritmo Bubble Sort aplicado a um array de n strings
void bubble_sort_strings(char* v[], int n)
{
  for (int i=0; i<n-1 ; i++)
    for (int j=0 ; j<n-i-1 ; j++)
      if (strcmp(v[j], v[j+1])>0)
        swap_strings(&v[j], &v[j+1]);
}

void sort_strings(char* v[], int indexStart, int indexEnd)
{
  bubble_sort_strings(v, indexEnd+1);
}