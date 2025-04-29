#include <stdio.h>

void Calc(float *v, int num, float * xmin, float *xmax)
{
  *xmin = *xmax = *v;   /* Ficam com o valor de v[0] */
  for (int i=0 ; i<num ; i++)
  {
    if (v[i] < *xmin) *xmin=v[i];
    if (v[i] > *xmax) *xmax=v[i];
  }
}

int main(void)
{
  float arr[] = {10.0, 20 , 30, 40, 50, 11, 12, 5, -33.33};
  float maior, menor;

  puts("Todas as posições do array");
  Calc(arr, 9, &menor, &maior);
  printf("\tMenor valor: %.2f Maior valor: %.2f\n", menor, maior);

  puts("Posições índice 5 (11.0)  a 7 (5.0)");
  Calc(arr+5, 3, &menor, &maior);
  printf("\tMenor valor: %.2f Maior valor: %.2f\n", menor, maior);

  return 0;
}

