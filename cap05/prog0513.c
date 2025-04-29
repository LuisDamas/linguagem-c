#include <stdio.h>

int my_toupper(char ch)
{
  if (ch >= 'a' && ch <= 'z') /* Se minúscula */
    return ch + 'A' - 'a';
  else
    return ch;   // Devolve-se o mesmo char
}

/* Escreve todos os carateres em maiúsculas */

int main(void)
{
  char c;
  while(1) /* Termina com CTRL-C */
  {
    c = getchar();
    putchar(my_toupper(c));
  }
  return 0;
}

