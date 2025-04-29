#include <stdio.h>

int main(void)
{
  int n;

  do
  {
    printf("Introduza um número: ");
    scanf("%d", &n);
  }
  while (n<1 || n>10);

  printf("Foi introduzido o número %d\n", n);
  return 0;
}
