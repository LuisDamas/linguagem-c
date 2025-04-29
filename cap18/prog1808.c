#include <stdio.h>

long int fib_rec(int n)
{
  if (n<0) return -1L; /* Parâmetro Inválido */
  if (n<=1)
    return (long) n;

  return fib_rec(n-1)+fib_rec(n-2);
}

long int fib_ite(int n)
{
  if (n<0) return -1L; /* Parâmetro Inválido */
  if (n<=1) return (long) n;

  long res[2] = {0, 1}; // Últimos 2 resultados

  for (int i=2 ; i<n ; i++)
    res[i%2] = res[0]+res[1];

  return res[0]+res[1];
}

int main(void)
{
  int n;
  while (1)
  {
    printf("Introd. um inteiro: ");
    scanf("%d",&n);
    if (n<0) break;

    printf("fib_ite(%d) = %ld\n",n, fib_ite(n));
    printf("fib_rec(%d) = %ld\n",n, fib_rec(n));
  }

 return 0;
}

