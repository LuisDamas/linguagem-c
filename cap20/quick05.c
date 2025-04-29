#include <string.h>

void swap_strings(char* *ptr1, char* *ptr2);

// Verifica se o array a analisar já está ordenado
static int isSorted(char* v[], int indexStart, int indexEnd)
{
  for (int i=indexStart; i<indexEnd; i++)
    if (strcmp(v[i], v[i+1])>0)
     return 0;
  return 1;
}

// LomutoPartition
static int partition(char* v[], int indexStart, int indexEnd)
{
  char* pivot = v[indexEnd]; // Último elemento
  int bound = indexStart;

  for (int index=indexStart; index<indexEnd; index++)
    if (strcmp(v[index], pivot)<0)
      swap_strings(&v[bound++], &v[index]);

  swap_strings(&v[bound], &v[indexEnd]);
  return bound;
}


int HoarePartition(char* arr[], int start, int end)
{
  char* pivotVal = arr[start];
  int i = start - 1;
  int j = end + 1;

  while(1)
  {
    do
      i++;
    while (strcmp(arr[i], pivotVal)<0);

    do
      j--;
    while (strcmp(arr[j], pivotVal)>0);

    if (i >= j)
      return j;

    swap_strings(&arr[i], &arr[j]);
  }
}


// Algoritmo Quick Sort aplicado a um array de strings
static void quick_sort_strings(char* v[], int indexStart, int indexEnd)
{
  if (indexStart >= indexEnd) return;
//  if (isSorted(v, indexStart, indexEnd)) return; // Já está ordenado

  int indexPivot = partition(v, indexStart, indexEnd);

  quick_sort_strings(v, indexStart, indexPivot-1);
  quick_sort_strings(v, indexPivot+1, indexEnd);
}


void sort_strings(char* v[], int indexStart, int indexEnd)
{
  quick_sort_strings(v, indexStart, indexEnd);
}
