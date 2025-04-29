#include <stdio.h>

int main(void)
{
  float  quilos = 1.0E3; /* Uma tonelada são 1,000 quilos */
  double gramas = 1.0e6; /* Uma tonelada são 1,000,000 gramas */
  float n_toneladas;
  double res_quilos, res_gramas;

  printf("Quantas toneladas comprou: "); scanf("%f", &n_toneladas);

  res_quilos = n_toneladas * quilos;
  printf("Nº de Quilos = %lf = %l\n", res_quilos, res_quilos);

  res_gramas = n_toneladas * gramas;
  printf("Nº de Gramas = %lf = %E\n", res_gramas, res_gramas);

  return 0;
}

