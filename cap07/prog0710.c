#include <stdio.h>
#include <string.h>

char *strrev(char *s)
{
  int i,len;
  char aux;

  for (i=0,len=strlen(s)-1 ; i < len ; i++,len--)
  {
    aux = s[i];
    s[i] = s[len];
    s[len] = aux;
  }
  return s;
}


int main(void)
{
  char my_string[30];

  while (1)
  {
    printf("Qual a string a inverter? ");
    gets(my_string);
    if (my_string[0]=='\0')
      break;

    strrev(my_string);
    printf("[%s]\n", my_string);
  }
  return 0;
}
