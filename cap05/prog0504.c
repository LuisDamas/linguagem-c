#include <stdio.h>

int linha(void)
{
  for (int i=1 ; i<=20 ; i++)
    putchar('*');
  putchar('\n');

  return 0;
}

int main(void)
{
  linha();   // Escreve uma linha de asteriscos
  puts("Números entre 1 e 5");
  linha();   // Escreve outra linha de asteriscos 

  for (int i=1; i<=5 ; i++)
    printf("%d\n", i);

  linha();   // Escreve a última linha de asteriscos
  return 0;
}

