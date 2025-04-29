#include <stdio.h>
#include <limits.h>

void printBinary(unsigned char ch)
{
  for (int i=CHAR_BIT-1; i>=0; i--)
    putchar(ch & (1 << i) ? '1' : '0');
}

int countOnes(unsigned int var)
{
  int res = 0;
  while (var!=0)
  {
    res += var & 1;   // 1 ou 0
    var >>= 1;        // Shift um bit à direita
  }
  return res;
}

int main()
{
  unsigned int my_char;

  my_char = '\0';
  printBinary(my_char); printf("\tnº 1s: %d\n", countOnes(my_char));

  my_char = 'A';
  printBinary(my_char); printf("\tnº 1s: %d\n", countOnes(my_char));

  my_char = 254;
  printBinary(my_char); printf("\tnº 1s: %d\n", countOnes(my_char));

  my_char = 126;
  printBinary(my_char); printf("\tnº 1s: %d\n", countOnes(my_char));

  my_char = 0xFF; // 255
  printBinary(my_char); printf("\tnº 1s: %d\n", countOnes(my_char));

  return 0;
}
