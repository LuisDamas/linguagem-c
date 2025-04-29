#include <stdio.h>

int main(void)
{
  int dia, mes, ano;
  printf("Data (Formato aaaa-mm-dd): ");

  scanf("%d-%d-%d", &ano, &mes, &dia);

  printf("Data Completa: %d/%d/%d\n", dia, mes, ano);
  return 0;
}
