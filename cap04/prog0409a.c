#include <stdio.h>

int main(void)
{
  int n;

  printf("O valor de n é: %d\n", n);

  while (n<1 || n>10)
  {
    printf("Introduza um número: ");
    scanf("%d", &n);
  }

  printf("Foi introduzido o número %d\n", n);
  return 0;
}
