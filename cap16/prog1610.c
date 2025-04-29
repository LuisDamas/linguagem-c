#include <stdio.h>
#include <limits.h>

char *intToBin(char str[], unsigned int value)
{
  int n_total_bits = CHAR_BIT*sizeof(value); 
  unsigned int mask = 1 << (n_total_bits -1);
  int i;

  for (i=0; i<n_total_bits; i++, mask=mask>>1)
    str[i] = (value & mask)? '1' : '0';
  str[i]='\0';

  return str;
}

void printBinaryString(char s[])
{
  for (int i=0; s[i]!='\0'; i++)
  {
     if (i>0 && i%CHAR_BIT==0)  // Se for separação entre bytes
       putchar(' ');
     putchar(s[i]);
  }
}

int main()
{
  unsigned int my_var;
  char s[CHAR_BIT*sizeof(int)+1];

  my_var = 0;          printBinaryString(intToBin(s, my_var)); printf("\t%08X\n", my_var);
  my_var = 0xFFFFFFFF; printBinaryString(intToBin(s, my_var)); printf("\t%08X\n", my_var);
  my_var = 0xF1F00FF1; printBinaryString(intToBin(s, my_var)); printf("\t%08X\n", my_var);
  my_var = 0xFF00FF00; printBinaryString(intToBin(s, my_var)); printf("\t%08X\n", my_var);

  return 0;
}
