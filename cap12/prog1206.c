#include <stdio.h>
#include <stdlib.h>

char *ascii_create(int n, char inic)
{ int i;
  char *aux;
  if ((aux=(char *) malloc(n+1))==NULL)
    return aux; /* NULL */

  for (i=0; i<n; i++)
    aux[i]=inic+i;

  aux[i]='\0';
  return aux;
}

int main(void)
{
  char *ptr = ascii_create(3, 'A');
  printf("|%s|\n", ptr);
  free(ptr);

  ptr = ascii_create(5, 'p');
  printf("|%s|\n", ptr);
  free(ptr);

  ptr = ascii_create(0, 'A');
  printf("|%s|\n", ptr);
  free(ptr);

  return 0;
}
