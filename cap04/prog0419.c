#include <stdio.h>

int main(void)
{
  int n;

  printf("Introduza um número: "); scanf("%d",&n);
  for (int i=1 ; i<=n ; i++)
    printf("%d  %d\n", i, n-i+1);
  return 0;
}

