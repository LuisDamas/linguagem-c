#include <stdio.h>

int main(void)
{
  char ch;

  do
  {
    printf("Introduza um char: ");
    scanf(" %c", &ch);
  }
  while ( (!(ch>='a' && ch<='z'))  &&
          (!(ch>='A' && ch<='Z')));

  printf("Foi Introduzido o char '%c' com o ASCII %d\n", ch, ch);
  return 0;
}


