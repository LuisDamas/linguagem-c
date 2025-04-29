#include <stdio.h>

int main(void)
{
  int x;
  printf("Introduza um Nº ");
  scanf("%d", &x);
  if (x>=0)
    printf("Número Positivo\n");
  else
    printf("Número Negativo\n");
  return 0;
}
