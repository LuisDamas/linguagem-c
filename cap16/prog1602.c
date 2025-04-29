#include <stdio.h>

int main(void)
{
  int n=126;  // Valor em decimal

  printf("Valor Inteiro: %d  Valor em Hexa: %x\n", n, n);

  n=0x7E;    // Valor em Hexadecimal
  printf("Valor Inteiro: %d  Valor em Hexa: %x\n", n, n);
  printf("Valor Inteiro: %d  Valor em Hexa: %X\n", n, n);

  return 0;
}

