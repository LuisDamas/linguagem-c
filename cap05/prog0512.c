#include <stdio.h>

int my_isdigit(char ch)
{
  return (ch >='0' && ch <= '9');
}

/* Escreve todos os carateres não dígitos */

int main(void)
{
  char c;
  while(1)   // Termina com CTRL-C 
  {
   c = getchar();
   if (!my_isdigit(c)) /* se não for dígito */
     putchar(c);
  }
  return 0;
}

