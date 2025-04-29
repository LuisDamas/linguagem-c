#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void troca(char *s1, char *s2)
{
  char aux = *s1;
  *s1 = *s2;
  *s2 = aux;
}

char *strrev(char *s)
{
  int i, len;

  for (i=0, len=strlen(s)-1 ; i < len ; i++,len--)
    troca(s+i, s+len);
  return s;
}

char *inverte(char *s)
{ char *tmp = (char*) malloc(strlen(s)+1);
  if (tmp==NULL) 
    return tmp;

  strcpy(tmp, s);
  return strrev(tmp);
}

int main(void)
{
  char * ptr;

  ptr = inverte("roma");
  printf("|%s|\n", ptr);
  free(ptr);

  ptr = inverte("Omississimo");
  printf("|%s|\n", ptr);
  free(ptr);

  ptr = inverte("");
  printf("|%s|\n", ptr);
  free(ptr);

  return 0;
}
