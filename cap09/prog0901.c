#include <stdio.h>

int main(void)
{
  int num;

  printf("Introduza inteiros repetidamente\n");
  printf("ou algo que não seja um nº para terminar\n");

  while (scanf("%d", &num) == 1)
    printf("Foi introduzido o inteiro: %d\n", num);

  puts("Introduziu algo não válido como inteiro");
  return 0;
}
