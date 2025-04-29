#include <stdio.h>

int main(void)
{
  int n;

  printf("Qual o nº de ramos: "); scanf("%d", &n);
  for (int i=1 ; i<=n ; i++)
  {
    for (int j=1 ; j<=i ; j++)
      putchar('*');
    putchar('\n');
  }
  return 0;
}

