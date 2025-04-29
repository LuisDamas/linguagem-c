#include <stdio.h>
/* Versão 3 */
int main(void)
{
  int n;
  printf("Introd. um nº: "); scanf("%d", &n);

  if (n!=0)
    printf("Número não é igual a zero\n");
  else
    printf("Número é igual a zero\n");

  return 0;
}

