#include <stdio.h>

int main(void)
{
  float salario;
  printf("Qual o salário: ");
  scanf("%f", &salario);

  if (salario<=0)
    printf("Salário: Valor Inválido\n");

  if (salario > 1000)
    printf("Imposto = %.2f\n", salario*0.10);
  else
    printf("Imposto = %.2f\n", salario*0.05);

  return 0;
}

