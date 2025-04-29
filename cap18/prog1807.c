#include <stdio.h>

int mdc(int a, int b)
{
  if (b==0)
    return a;

  return mdc(b, a%b);
}

int main(void)
{
  int m, n;
  printf("Introduza dois inteiros: ");
  scanf("%d%d", &m, &n);

  printf("O Máximo Divisor Comum entre %d e %d é %d\n",
         m, n, mdc(m,n));

  return 0;
}

