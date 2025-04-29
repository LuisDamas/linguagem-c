#include <stdio.h>
#include <string.h>

char *my_strrchr(char *str , int ch)  /* Versão 1 - Do início para o fim */
{
  char *ptr = NULL;
  for (int i=0; str[i]!='\0'; i++)
    if (str[i]==ch)
      ptr=&str[i];    // ptr = str+i;

  return ptr;
}

char *my_strrchr_alt(char *str , char ch)   /* Versão 2 - Do fim para o início */
{
  char *ptr = str + strlen(str)-1; /* Colocar no último char útil da string */
  while (ptr >= str)
    if (*ptr==ch)
      return ptr;
    else
      ptr--;

 return NULL;
}

int main(void)
{
  char nome[100];
  char *apelido = NULL;
  printf("Introduza um nome: "); gets(nome);

  apelido = strrchr(nome, ' ');
  if (apelido==NULL) /* Não tem apelido. Não existe o espaço */
    apelido=nome;
  else
    apelido++;     /* Pois estava a apontar o espaço em branco */

  printf("Apelido: [%s]\n", apelido);
  return 0;
}

