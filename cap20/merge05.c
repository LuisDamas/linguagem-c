#include <string.h>

void swap_strings(char* *ptr1, char* *ptr2);

// Junção das duas sublistas
// Lista esquerda entre os índices: startLeft  .. (startRight-1)
// Lista direita  entre os índices: startRight .. endRight
void merge(char* v[], int startLeft, int startRight, int endRight)
{
  int endLeft = startRight-1;
  int n_elems = endRight - startLeft + 1;

  char* aux[n_elems]; // array temporário
 
  // Variáveis para percorrer as sublistas.  
  int indexLeft  = startLeft,  indexRight = startRight;

  for (int i=0 ; i < n_elems ; i++)
    if (indexLeft <= endLeft && indexRight <= endRight)
      if (strcmp(v[indexLeft],v[indexRight])<0) 
        aux[i] = v[indexLeft++];
      else
        aux[i] = v[indexRight++];
    else
      if (indexLeft <= endLeft)  // sublista direita já terminou
        aux[i] = v[indexLeft++];
      else
        aux[i] = v[indexRight++]; // sublista esquerda já terminou

  memcpy(v+startLeft, aux, sizeof(aux));
}

// Algoritmo Merge Sort aplicado a um array de strings
void merge_sort_strings(char* v[], int indexStart, int indexEnd)
{
  if (indexStart >= indexEnd) return;

  int indexMiddle = (indexStart+indexEnd)/2;

  merge_sort_strings(v, indexStart, indexMiddle);
  merge_sort_strings(v, indexMiddle+1, indexEnd);

  merge(v, indexStart, indexMiddle+1, indexEnd);
}

void sort_strings(char* v[], int indexStart, int indexEnd)
{
  merge_sort_strings(v, indexStart, indexEnd);
}
