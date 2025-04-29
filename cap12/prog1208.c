#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *metade(char *s)
{
  char * tmp = (char*) malloc(strlen(s)/2+1);
  if (tmp==NULL)
    return tmp;

  strncpy(tmp, s, strlen(s)/2);
  tmp[strlen(s)/2]='\0';
  return tmp;
}

int main(void)
{
  char * ptr;

  ptr = metade("alvoco");
  printf("|%s|\n", ptr);
  free(ptr);

  ptr = metade("grave");
  printf("|%s|\n", ptr);
  free(ptr);

  ptr = metade("");
  printf("|%s|\n", ptr);
  free(ptr);

  return 0;
}
