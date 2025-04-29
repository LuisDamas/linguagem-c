#include <stdio.h>
#define ADD_NEWLINE 1

// Imprime um array de n inteiros no formato { 1, 2, 3, ..., n }
void print_array(int v[], int n, int show_NL)
{
  int i;

  printf("{");

  for (i=0; i<n ; i++)
    printf("%2d%s", v[i], (i<(n-1)) ? ", " : "");
  putchar('}');

  if (show_NL) 
    putchar('\n');
}

// Troca dois inteiros referenciados por cada um dos endereços
void swap_int(int *ptr1, int *ptr2)
{
  int tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
}

/*
 * Algoritmo Selection Sort aplicado a um array de n inteiros
 */
void selection_sort_int_stat(int v[], int n)
{
  printf("Array Original: "); print_array(v, n, ADD_NEWLINE); printf("\n");

  int index_min;
  for (int i=0; i<n-1 ; i++)
  {
    printf("Iteração %02d: ",i+1);
    index_min= i;

    for (int j=i+1; j<n; j++)
      if (v[j] < v[index_min])
	index_min = j;

    if (i!=index_min) // só se troca se for necessário 
    {
      printf(" Trocar (índices) <%d e %d> (valores <%2d e %2d>)\n", i, index_min,
			   v[i], v[index_min]);
      printf("\tAntes da troca : "); print_array(v, n, ADD_NEWLINE);
      swap_int(&v[i], &v[index_min]);
      printf("\tDepois da troca: "); print_array(v, n, ADD_NEWLINE); 
      putchar('\n');
    }
    else
      printf(" O índice %d já contém o menor elemento (%d) - SEM TROCAS!!!\n", 
             i, v[i]);
  }
  printf("\nResultado final: "); print_array(v, n, ADD_NEWLINE); printf("\n");
}

int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  selection_sort_int_stat(v, size);

  return 0;
}

