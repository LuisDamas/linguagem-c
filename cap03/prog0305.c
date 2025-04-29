#include <stdio.h>

int main(void)
{
  float salario;
  printf("Qual o Salário ");
  scanf("%f", &salario);

  if (salario < 1234.56)
    salario = salario + 99.87;
  printf("Salário Final: %.2f\n", salario);

  return 0;
}

