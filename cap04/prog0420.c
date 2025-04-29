#include <stdio.h>

int main(void)
{
  int n;
  char ch;

  printf("Introd. um Nº  : "); scanf("%d",&n);
  printf("Introd. um Char: "); scanf(" %c",&ch);

  for (int i=1 ; i<=n ; i++ )   // para cada linha
  {
    for (int j=1 ; j<=n ; j++)  // para cada coluna
      putchar(ch);
    putchar('\n');
  }
  return 0;
}

