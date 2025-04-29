#include <stdio.h>
#include <string.h>

static void troca(char **a, char **b)
{
  char *tmp=*a;
  *a=*b;
  *b=tmp;
}
 
static void ordenar(char *v[])
{
  int alterou,i;
  do
  {
    for (alterou=i=0;v[i]!=NULL && v[i+1]!=NULL;i++)
     if (strcmp(v[i], v[i+1])>0 )
      {
        troca(&v[i], &v[i+1]);
        alterou=1;
      }
  }
  while (alterou);
}

void imprimir_strings(char *v[])
{
  ordenar(v);
  puts("Imprimir Strings");
  puts("----------------");
  for (int i=0; v[i]!=0; i++)
    puts(v[i]);
}

