#include <stdio.h>

int main(void)
{
  int n;

  while (1)
  {
     printf("Introduza um número: ");
     scanf("%d", &n);
     if (n>=1 && n<=10)
       break;
  }

  printf("Foi introduzido o número %d\n", n);
  return 0;
}
