#include <stdio.h>

int main(void)
{
  // Escrever o cabeçalho
  for (int i=1 ; i<=20 ; i++)
    putchar('*');
  putchar('\n');

  puts("Números entre 1 e 5");

  for (int i=1 ; i<=20 ; i++)
    putchar('*');
  putchar('\n');

  // Escrever os valores 1..5
  for (int i=1; i<=5 ; i++)
    printf("%d\n",i);

  // Escrever o rodapé
  for (int i=1 ; i<=20 ; i++)
    putchar('*');
  putchar('\n');

  return 0;
}
