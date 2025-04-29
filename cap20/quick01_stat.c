#include <stdio.h>
#include <string.h>

#define ADD_NEWLINE 1

// Imprime um array de inteiros
void print_array(int v[], int indexIni, int indexEnd, int addNL)
{
  printf("{");
  for (int i=indexIni; i<=indexEnd ; i++)
    printf("%d%s", v[i], (i==indexEnd) ? "" : ", ");
  printf("}");
  if (addNL) putchar('\n');
}

// Troca dois inteiros referenciados por cada um dos endereços
void swap_int(int *ptr1, int *ptr2)
{
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

int partition(int v[], int indexStart, int indexEnd)
{
  int pivot = v[indexEnd]; // Último elemento
  int bound = indexStart;  
  
  for (int index=indexStart; index<indexEnd; index++)
    if (v[index] < pivot)
      swap_int(&v[bound++], &v[index]);

  swap_int(&v[bound], &v[indexEnd]);
  return bound;
}

// Algoritmo Quick Sort aplicado a um array de n inteiros
// Parâmetro extra para facilitar a visualização
void quick_sort_int(int v[], int indexStart, int indexEnd, int n_call)
{
  for (int i=1; i<=n_call; i++)
    printf("   ");
  printf("+ Ordenar  : "); print_array(v, indexStart, indexEnd, ADD_NEWLINE);

  if (indexStart >= indexEnd) return;

  int indexPivot = partition(v, indexStart, indexEnd);

  quick_sort_int(v, indexStart, indexPivot-1, n_call+1);
  quick_sort_int(v, indexPivot+1, indexEnd, n_call+1);

  for (int i=1; i<=n_call; i++)
    printf("   ");
  printf("+ Resultado: "); print_array(v, indexStart, indexEnd, ADD_NEWLINE);
}


int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  puts("Array ANTES da Ordenação");
  print_array(v, 0, size-1, ADD_NEWLINE); putchar('\n');

  quick_sort_int(v, 0, size-1, 0);

  puts("\nArray DEPOIS da Ordenação");
  print_array(v, 0, size-1, ADD_NEWLINE);

  return 0;
}
