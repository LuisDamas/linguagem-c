#include <stdio.h>

long sum_int(int n)
{
  return (long) n * (long) (n+1) / 2;
}

int main(void)
{
  int n_values;
  printf("Nº de inteiros a somar: "); 
  scanf("%d", &n_values);

  printf("A soma dos primeiros %d valores = %ld\n",
         n_values, sum_int(n_values));

  return 0;
}
