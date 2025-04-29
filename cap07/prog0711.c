#include <stdio.h>

int my_strcmp(char *s1 ,char *s2)
{
  int i=0;
  while (s1[i]==s2[i] && s1[i]!='\0')
    i++;
  return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int main(void)
{
  char nome[30+1];
  do
  {
    printf("Nome: "); gets(nome);
    puts(nome);
  }
  while (my_strcmp(nome, "SAIR")!=0);

  puts("Terminou o programa. Adeus.");
  return 0;
}

