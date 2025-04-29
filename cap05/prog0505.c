#include <stdio.h>

int linha3x(void)
{
  for (int i=1 ; i<=3 ; i++)
    putchar('*');
  putchar('\n');
  return 0;
}

int linha5x(void)
{
  for (int i=1 ; i<=5 ; i++)
    putchar('*');
  putchar('\n');
  return 0;
}

int linha7x(void)
{
  for (int i=1 ; i<=7 ; i++)
    putchar('*');
  putchar('\n');
  return 0;
}

int main(void)
{
  linha3x();
  linha5x();
  linha7x();
  linha5x();
  linha3x();

  return 0;
}

