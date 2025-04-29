#include <stdio.h>

int main(void)
{
  int n;

  n = 10;  // Valor em Decimal
  printf("Valor Inteiro: %2d  Valor em Octal: %2o\n", n, n);

  n = 010; // Valor em Octal
  printf("Valor Inteiro: %2d  Valor em Octal: %2o\n", n, n);

  return 0;
}

