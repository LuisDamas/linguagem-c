#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Troca(char *c1, char *c2)
{
  char tmp=*c1;
  *c1=*c2;
  *c2=tmp;
}

char *Encosta(char *s)
{ int existem_alteracoes, len=strlen(s)-1;
  do
  {
    existem_alteracoes=0;
    for (int i=0;i<len;i++)
      if ((!isupper(s[i]) && isupper(s[i+1])) || 
	  (islower(s[i]) && !islower(s[i+1])))
      {
         Troca(&s[i], &s[i+1]);
         existem_alteracoes=1;
      }
  }
  while(existem_alteracoes);
  return s;
}

int main(void)
{
  char str[100];

  strcpy(str, "");
  printf("Original: %-20s\t", str);
  printf("[%s]\n", Encosta(str));

  strcpy(str, "123AbCd45");
  printf("Original: %-20s\t", str);
  printf("[%s]\n", Encosta(str));

  strcpy(str, "X.Y");
  printf("Original: %-20s\t", str);
  printf("[%s]\n", Encosta(str));

  strcpy(str, "x1A2");
  printf("Original: %-20s\t", str);
  printf("[%s]\n", Encosta(str));
  return 0;
}
