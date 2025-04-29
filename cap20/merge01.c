#include <stdio.h>
#include <string.h>

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

// Junção das duas sublistas
// Lista esquerda entre os índices: startLeft  .. (startRight-1)
// Lista direita  entre os índices: startRight .. endRight
void merge(int v[], int startLeft, int startRight, int endRight)
{
  int endLeft = startRight-1;
  int n_elems = endRight - startLeft + 1;

  int aux[n_elems]; // array temporário
 
  // Variáveis para percorrer as sublistas.  
  int indexLeft  = startLeft,  indexRight = startRight;

  for (int i=0 ; i < n_elems ; i++)
    if (indexLeft <= endLeft && indexRight <= endRight)
      if (v[indexLeft] <= v[indexRight]) 
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

// Algoritmo Merge Sort aplicado a um array de n inteiros
void merge_sort_int(int v[], int indexStart, int indexEnd)
{
  if (indexStart >= indexEnd) return;

  int indexMiddle = (indexStart+indexEnd)/2;

  merge_sort_int(v, indexStart, indexMiddle);
  merge_sort_int(v, indexMiddle+1, indexEnd);

  merge(v, indexStart, indexMiddle+1, indexEnd);
}

int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  puts("Array ANTES da Ordenação");
  print_array(v, size);

  merge_sort_int(v, 0, size-1);

  puts("Array DEPOIS da Ordenação");
  print_array(v, size);

  return 0;
}
