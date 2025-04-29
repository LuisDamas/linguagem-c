#include <stdio.h>

unsigned long ite_fatorial(int n)
{
  unsigned long res=1L; // 1 pois vamos realizar multiplicações 

  for (int i=2; i<=n; i++)
    res *= i;

  return res;
}

unsigned long rec_fatorial(int n)
{
  if (n<=1)
    return 1L;  // 1 como long

  return n * rec_fatorial(n-1);
}

int main(void)
{
  for (int value=0; value<=20; value++)
    printf("%2d! = %-20ld %-20ld\n", value, 
           ite_fatorial(value), rec_fatorial(value));

  return 0;
}
