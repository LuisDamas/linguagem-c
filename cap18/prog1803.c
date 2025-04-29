#include <stdio.h>

void rec_up(int n)
{
  if (n<=0) return;

  rec_up(n-1);
  printf("%d\n", n); 
}

void ite_up(int n)
{
  for (int i=1; i<=n; i++)
    printf("%d\n", i);
}

int main(void)
{
  puts("Up(3) - versão iterativa");
  ite_up(3);

  puts("Up(3) - versão recursiva");
  rec_up(3);

  return 0;
}
