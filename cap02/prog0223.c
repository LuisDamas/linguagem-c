#include <stdio.h>

int main(void)
{
  int dia, mes, ano;

  printf("Ano: "); scanf("%d", &ano);
  printf("Mes: "); scanf("%d", &mes);
  printf("Dia: "); scanf("%d", &dia);

  printf("Data Completa: %d/%d/%d\n", dia, mes, ano);

  return 0;
}

