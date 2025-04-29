#include <stdio.h>

int main(void)
{
  int num;
  printf("Introduza um Nº ");
  scanf("%d", &num);
  if (num)
    printf("%d não é zero!!!\n", num);
  else
    printf("%d é igual a zero!!!\n", num);
  return 0;
}

