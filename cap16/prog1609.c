#include <stdio.h>
#include <limits.h>

void printBinary(unsigned int value)
{
  for (int i=CHAR_BIT*sizeof(int)-1; i>=0; i--)
  {
    if ((i+1) % CHAR_BIT==0)
      putchar(' ');
    putchar(value & (1 << i) ? '1' : '0');
  }
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

int countZeros(unsigned int var)
{
  return countOnes(~var);
}

int main()
{
  unsigned int my_var;

  my_var = '\0'; printf("%08X\t", my_var);
  printBinary(my_var); printf("\t1s: %d \t 0s: %d\n", 
              countOnes(my_var), countZeros(my_var));

  my_var = 'A'; printf("%08X\t", my_var);
  printBinary(my_var); printf("\t1s: %d \t 0s: %d\n",
              countOnes(my_var), countZeros(my_var));

  my_var = 254; printf("%08X\t", my_var);
  printBinary(my_var); printf("\t1s: %d \t 0s: %d\n",
              countOnes(my_var), countZeros(my_var));

  my_var = 0xFF0FF0FF; printf("%08X\t", my_var);
  printBinary(my_var); printf("\t1s: %d \t 0s: %d\n",
              countOnes(my_var), countZeros(my_var));

  my_var = 0xFFFFFFFF; printf("%08X\t", my_var);
  printBinary(my_var); printf("\t1s: %d \t 0s: %d\n",
              countOnes(my_var), countZeros(my_var));

  return 0;
}
