#include <stdio.h>
#define MAX 5

char *my_memset(char arr[], char ch, int n)
{
  for (int i=0; i<n; i++)
    arr[i] = ch;
  return arr;
}

void print_array(char arr[], int n)
{
  putchar('[');
  for (int i=0; i<n; i++)
    putchar(arr[i]);
  printf("]\n");
}

int main(void)
{
  char vetor[MAX] = {'A','1','~','9','Z'};

  puts("Imprimir: Array inicializado na declaração");
  print_array(vetor, MAX);

  puts("Imprimir: Array inicializado só com '@'");
  my_memset(vetor, '@', MAX);
  print_array(vetor, MAX);

  puts("Imprimir: Array inicializado parcialmente com '#'");
  my_memset(vetor, '#', 3);
  print_array(vetor, MAX);

  return 0;
}

