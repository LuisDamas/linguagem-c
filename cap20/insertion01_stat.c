#include <stdio.h>
#define ADD_NEWLINE 1

// Imprime um array de n inteiros no formato { 1, 2, 3, ..., n }
void print_array(int v[], int n, int show_NL)
{
  int i;

  printf("{");

  for (i=0; i<n ; i++)
    printf("%2d%s",v[i], (i<(n-1)) ? ", " : "");
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
 * Algoritmo Insertion Sort aplicado a um array de n inteiros
 */
void insertion_sort_int_stat(int v[], int n)
{
  printf("Array Original: "); print_array(v, n, ADD_NEWLINE); printf("\n");

  int j, new_value;
  for (int i=1; i<n ; i++)
  {
    printf("Iteração %02d: ", i);
    printf("\tAntes : "); print_array(v, n, !ADD_NEWLINE);

    new_value= v[i];
    for (j=i ; j>=1 && v[j-1]>new_value ; j--)
      v[j] = v[j-1];

    printf(" Mover %d (arr[%d]) para o índice %d\n", new_value, i, j);
    v[j] = new_value;
    printf("\t\tDepois: "); print_array(v, n, ADD_NEWLINE); putchar('\n');
  }

  printf("\nResultado final: "); print_array(v, n, ADD_NEWLINE); printf("\n");
}

int main(void)
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  insertion_sort_int_stat(v, size);

  return 0;
}

