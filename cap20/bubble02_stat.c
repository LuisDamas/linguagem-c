#include <stdio.h>

#define ADD_NEWLINE 1

// Imprime um array de n inteiros no formato { 1, 2, 3, ..., n }
void print_array(int v[], int n, int show_NL)
{
  int i;

  printf("{");

  for (i=0; i<n ; i++)
    printf("%d%s",v[i], (i<(n-1)) ? ", " : "");
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

// Algoritmo Bubble Sort aplicado a um array de n inteiros
void bubble_sort_int(int v[], int n)
{
  int n_trocas, n_trocas_total=0;
  int n_comparacoes, n_comparacoes_total=0;

  printf("Array Original: "); print_array(v, n, ADD_NEWLINE); 
  putchar('\n');

  for (int i=0; i<n-1 ; i++)
  {
    printf("Passo nº %02d     ", i+1);

    n_trocas=n_comparacoes=0;
    for (int j=0 ; j<n-i-1 ; j++, n_comparacoes++)
      if (v[j] > v[j+1])
      {
        swap_int(&v[j], &v[j+1]);
        n_trocas++;
      }
    n_trocas_total+=n_trocas;
    n_comparacoes_total+=n_comparacoes;
    print_array(v, n, !ADD_NEWLINE);
    printf("\tNº de trocas: %d | Nº comparações: %d\n",
           n_trocas, n_comparacoes);
    if (n_trocas==0) break;
  }
  printf("\nNº de trocas total: %d | Nº total de comparações: %d\n", 
         n_trocas_total, n_comparacoes_total);
}

int main()
{
  int v[]={ 14, 10, 28, 89, 24, 3, 14, 7, 35, 28};
  int size = sizeof(v)/sizeof(v[0]);

  bubble_sort_int(v, size);

  return 0;
}
