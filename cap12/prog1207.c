#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *repete(char *string, int n)
{
  char *aux;

  if (n==0)
    return strdup("");

  if ((aux=(char *) calloc(n, strlen(string)+1))==NULL)
    return aux; /* NULL */

  for (int i=1; i<=n; i++)
  {
    strcat(aux, string);
    if (i!=n)
     strcat(aux, " ");
  }

  return aux;
}

int main(void)
{
  char * ptr;
  for (int i=4; i>=0; i--)
  {
    ptr = repete("Ola", i);
    printf("|%s|\n", ptr);
    free(ptr);
  }
  return 0;
}
