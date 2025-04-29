#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define OP_SAIR "SAIR"

int strCountChar(char *s, char ch)
{
  int i, conta;
  for (i=conta=0 ; s[i]!='\0' ; i++)
    if (s[i]==ch)  /* Se for o caráter que procuramos */
      conta++;     /* Incrementar o contador    */
  return conta;
}

char *strrev(char *s)
{
  int i,len;
  char aux;

  for (i=0, len=strlen(s)-1 ; i < len ; i++, len--)
  {
    aux=s[i];
    s[i] = s[len];
    s[len]= aux;
  }
  return s;
}

char *wordupr(char *s)
{
  s[0] = toupper(s[0]); /* O primeiro fica sempre em maiúsculas */

  for (int i=1 ; s[i-1]!='\0' ; i++)
    if (s[i-1]==' ') /* Se o caráter anterior for um espaço */
      s[i] = toupper(s[i]);
    else
      s[i] = tolower(s[i]);

  return s;
}

int stricmp(char *s1, char *s2)
{
  int i=0;
  while (toupper(s1[i])==toupper(s2[i]) && s1[i]!='\0')
    i++;
  return (toupper(s1[i]) - toupper(s2[i]));
}

/*
 * Coloca no Parâmetro Apelido a última palavra da string Nome.
 * Em seguida retira essa palavra da string Nome colocando um '\0'
 */

void separa(char *nome, char * apelido)
{
  int i,j;
  if (strCountChar(nome,' ')==0)   /* Existe apenas uma ou zero
                                   palavras no nome */
    {
       apelido[0]='\0';
       return;
    }

  /* Existe a garantia de que existe um apelido */

  for (i=strlen(nome)-1, j=0 ; nome[i]!=' ' ; )
    apelido[j++] = nome[i--];

  apelido[j]='\0';   /* Terminar a string Apelido        */
  nome[i]='\0';      /* Retirar o Apelido da String Nome */

 // Como a string Apelido foi colocada do fim para o princípio é
 // necessário invertê-la

   strrev(apelido);
}

int main(void)
{
  char nome[100],apelido[50];

  for (;;)  /* Equivalente a while (1) */
  {
    printf("Nome: ");
    gets(nome);
    if (stricmp(nome, OP_SAIR)==0) 
      break; /* Sair do Programa */
    separa(nome, apelido);
    printf("%s, %s\n", wordupr(apelido), wordupr(nome));
  }
  return 0;
}

