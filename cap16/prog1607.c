#include <stdio.h>
#include <limits.h>

void printBinary(unsigned char ch)
{
  for (int i=CHAR_BIT-1; i>=0; i--)
    putchar(ch & (1 << i) ? '1' : '0');
}

int main()
{
  printBinary('A'); putchar('\n');
  printBinary(254); putchar('\n');
  printBinary(126); putchar('\n');

  return 0;
}
