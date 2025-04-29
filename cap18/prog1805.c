#include <stdio.h>
#include <string.h>

char *rec_strcat(char *dest, char *orig)
{
  if (*dest=='\0')
    return strcpy(dest,orig);

  rec_strcat(dest+1, orig);
  return dest;
}

int main(void)
{
  char s[30]="Ola", nome[30];
  printf("Qual o seu nome: ");
  gets(nome);
  rec_strcat(s, " ");
  rec_strcat(s, nome);
  puts(rec_strcat(s, "!!!"));

  return 0;
}

