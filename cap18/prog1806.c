#include <stdio.h>

// imprime n vezes ch
void print_chars(int ch, int n)
{
  while (n--)
    putchar(ch);
}

char *strchr(char *str, int ch)
{
  if (*str=='\0')
    return NULL;

  if (*str==ch)
      return str;

  return strchr(str+1, ch);
}

int main(void)
{
  char s[100];
  char ch;
  char *ptr;
  do
  {
    printf("Introduza uma string: ");
    gets(s);
    if (*s=='\0') break;

    printf("Char a procurar: ");
    scanf(" %c%*c", &ch); // Ler o char e eliminar o <ENTER> com %*c sem variável

    if ((ptr = strchr(s, ch))==NULL)
      puts("NOT FOUND");
    else
      {
        puts(s);
        print_chars(' ', (int) (ptr-s));
        puts("^ FOUND");
      }

    putchar('\n');
  }
  while (1);

  return 0;
}

