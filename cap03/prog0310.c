#include <stdio.h>

int main(void)
{
  int a,b;
  printf("Introduza dois nºs: ");
  scanf("%d%d", &a, &b);
  if (a >= 0)
    if (b > 10)
      printf("B é muito grande\n");
  else
    printf("A tem um valor negativo\n");
  return 0;
}

