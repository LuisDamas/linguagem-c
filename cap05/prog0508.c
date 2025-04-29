#include <stdio.h>

/* Devolve a soma de dois inteiros */
int soma(int a, int b)
{
  return a+b;
}

/* Devolve o dobro de qualquer inteiro */
int dobro(int x)
{
  return soma(x, x);
}

int main(void)
{
  int n1, n2, total;
  printf("Introduza dois números: ");
  scanf("%d %d", &n1, &n2);

  total = soma(n1,n2);   // Guardar a soma

  printf("%d+%d=%d\n", n1, n2, total);
  printf("2x%d=%d e 2x%d=%d\n", n1, dobro(n1),
                                n2, dobro(n2));
  return 0;
}

