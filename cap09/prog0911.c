#include <stdio.h>

long int fib(int n)
{
  int i;
  long n1, n2, tmp;

  if (n<0)
    return -1L;   /* Parâmetro Inválido */
  if (n<=1)
    return (long) n;

  for (i=2, n1=n2=1L ; i<n ; i++)
  {
    tmp = n1;
    n1 = n2;
    n2 = n1 + tmp;
  }

  return n1+n2;
}

int main(void)
{
  int n;
  while(1)
  {
    printf("Introd. um inteiro: ");
    scanf("%d", &n);
    if (n<0) break;
    printf("Fibonacci(%d) --> %ld\n", n, fib(n));
  }

  return 0;
}

