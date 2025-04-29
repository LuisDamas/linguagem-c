#include <stdio.h>

int main(void)
{
  short int idade;  // ou short idade
  int montante;
  long int n_conta; // ou long n_conta

  printf("Qual a Idade: "); scanf("%hd", &idade);
  printf("Qual o montante a depositar: "); scanf("%d", &montante);
  printf("Qual o nº de conta: "); scanf("%ld", &n_conta);

  printf("A pessoa de %hd anos depositou %d euros na conta %ld\n",
         idade, montante, n_conta);

  return 0;
}

