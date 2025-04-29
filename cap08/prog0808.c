#include <stdio.h>

char *my_strchr(char *str, int ch)    /* Versão 1 */
{
  for (int i=0; str[i]!='\0'; i++)
    if (str[i]==ch)
      return &str[i];

  return NULL;
}

char *my_strchr_alt(char *str, int ch)    /* Versão 2 */
{
  while (*str!='\0')
    if (*str==ch)
      return str;
    else
      str++;

 return NULL;
}

int main(void)
{
  char s[100], c;

  printf("Introd. uma string: "); gets(s);
  printf("Introd. um char   : "); scanf(" %c", &c);

  puts(my_strchr(s, c));
  puts(my_strchr_alt(s, c));

  return 0;
}

