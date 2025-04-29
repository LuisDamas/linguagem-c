#include <stdio.h>

int main(void)
{
  int n, num, soma, produto;
  printf("Introd. um Nº: "); scanf ("%d", &num);

  for (soma=0, n=produto=1 ; n <= num ; n=n+1)
  {
    soma = soma + n;
    produto = produto * n;
  }

  printf("Soma = %d | Produto = %d\n", soma, produto);
  return 0;
}

