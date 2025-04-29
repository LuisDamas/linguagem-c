#include <stdio.h>

int main(void)
{
  float sal[13];           // índice 0 + 12 meses
  float total;
  int i;

  for (i=1; i<=12 ; i++)
  {
    printf("Introduza o salário do mês %d: ", i);
    scanf("%f", &sal[i]);
  }

  // Mostrar os valores Mensais e calcular o total
  puts(" Mês            Valor");

  for (i=1, total=0.0 ; i<=12 ; i++)
  {
    printf(" %3d          %7.2f\n", i, sal[i]);
    total += sal[i];
  }

  printf("\nTotal Anual: %7.2f\n", total);
  return 0;
}

