#include <stdio.h>
#include <time.h>

long sum_int(int n)
{
  long res=0;
  for (int i=1; i<=n; i++)
    res+=i;
  return res;
}

int main(void)
{
  int n_values;
  printf("Nº de inteiros a somar: "); 
  scanf("%d", &n_values);

  clock_t start = clock();

  printf("A soma dos primeiros %d valores = %ld\n",
         n_values, sum_int(n_values));

  clock_t end = clock();

  double time_used = ((double) (end-start))/CLOCKS_PER_SEC;
  printf("Temo de execução: %f secs.\n", time_used);
  return 0;
}
