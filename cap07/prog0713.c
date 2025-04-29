#include <stdio.h>
#include <string.h>

char *strdelc(char *s , char ch)
{
  int i, j;
  for (i=j=0 ; s[i]!='\0' ; i++)
    if (s[i]!=ch)
       s[j++] = s[i];
  s[j]='\0';
  return s;
}

int main(void)
{
  char str[30], ch;

  strcpy(str, "apaga carateres"); ch='a';
  printf("Apagar '%c' em \"%s\" --> ", ch, str);
  strdelc(str, ch);
  printf("[%s]\n", str);

  strcpy(str, "apaga carateres"); ch='e';
  printf("Apagar '%c' em \"%s\" --> ", ch, str);
  strdelc(str, ch);
  printf("[%s]\n", str);

  strcpy(str, "apaga carateres"); ch='y';
  printf("Apagar '%c' em \"%s\" --> ", ch, str);
  strdelc(str, ch);
  printf("[%s]\n", str);

  strcpy(str, "aaa"); ch='a';
  printf("Apagar '%c' em \"%s\" --> ", ch, str);
  strdelc(str, ch);
  printf("[%s]\n", str);

  return 0;
}
