#include <stdio.h>

int linha(int num)
{
  for (int i=1 ; i<=num ; i++)
    putchar('*');
  putchar('\n');
  return 0;
}

int main(void)
{
  linha(3);
  linha(5);
  linha(7);
  linha(5);
  linha(3);
  return 0;
}

