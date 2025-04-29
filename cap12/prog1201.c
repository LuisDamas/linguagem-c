#include <stdio.h>
#include <string.h>

int main(void)
{ char s[200];
  char outra[200]; /* 200 posições - não vá o diabo tecê-las */

  printf("Qual a string: "); gets(s);

  /* Colocar na string <outra> uma cópia da string <s> */
  strcpy(outra, s);
  printf("String original: |%s| Cópia: |%s|\n", s, outra);

  return 0;
}

