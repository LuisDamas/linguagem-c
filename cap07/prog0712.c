#include <stdio.h>
#include <string.h>

char* strpad(char *s)
{
  int i = strlen(s);
  s[2*i] = s[i]; /* Colocar o terminador na nova posição */

  for (i-- ; i>=0 ; i--)
  {
    s[2*i] = s[i];
    s[2*i+1] = ' ';
  }
  return s;
}

int main(void)
{
  char arr[30];
  do
  {
    printf("Qual a string? (Termina com .)");
    gets(arr);
    if (strcmp(arr, ".")==0)
      break;
    strpad(arr);
    printf("[%s]\n", arr);
  }
  while (1);

  return 0;
}
