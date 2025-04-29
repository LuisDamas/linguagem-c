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
      if (strcmp(v[indexLeft], v[indexRight])<0) 
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
void merge_sort_string(char* v[], int indexStart, int indexEnd)
{
  if (indexStart >= indexEnd) return;

  int indexMiddle = (indexStart+indexEnd)/2;

  merge_sort_string(v, indexStart, indexMiddle);
  merge_sort_string(v, indexMiddle+1, indexEnd);

  merge(v, indexStart, indexMiddle+1, indexEnd);
}

int main()
{
  char* nomes[]={"carlao", "zeferino", "anabela", "mariana", "zoo", "ana", "bela",
                 "zulmira", "carlos", "carla", "manuela", "manuel", "ana bela"};

  int size = sizeof(nomes)/sizeof(nomes[0]);

  puts("Array ANTES da Ordenação");
  print_array(nomes, size);

  merge_sort_string(nomes, 0, size-1);

  puts("\nArray DEPOIS da Ordenação");
  print_array(nomes, size);

  return 0;
}


