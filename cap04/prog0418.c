#include <stdio.h>

int main(void)
{
  int i, j, n;

  printf("Introduza um número: "); scanf("%d", &n);
  for (i=1,j=n ; i<=n ; i++, j--)
    printf("%d  %d\n", i, j);
  return 0;
}

