#include <stdio.h>

int main(void)
{
  float x;
  printf("Introduza um nº real: ");
  scanf("%f", &x);

  printf("Parte Inteira     : %d\n", (int) x);
  printf("Parte Fracionária: %f\n",  x - ((int) x));

  return 0;
}

