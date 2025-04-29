#include <stdio.h>

int main(void)
{
  int n, num;

  num=1;
  while (num <= 5)
  {
    n=1;
    while (n<=10)
    {
      printf("%2d * %2d = %2d\n", num, n, num*n);
      n = n+1;
    }

    putchar('\n'); // Linha em branco a separar as tabuadas
    num = num + 1; // Passar à próxima tabuada
  }
  return 0;
}

