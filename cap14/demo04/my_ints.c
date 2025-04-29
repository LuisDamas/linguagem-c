#include <stdio.h>

static void troca(int *a, int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

static void ordenar(int *v)
{
  int alterou, i;
  do
   {
    for (alterou=i=0; v[i]!=0; i++)
     if (v[i]>v[i+1] && v[i+1]!=0)
      {
        troca(&v[i], &v[i+1]);
        alterou=1;
      }
   }
  while (alterou);
}

void imprimir_inteiros(int *v)
{ 
  ordenar(v);
  puts("Imprimir Inteiros");
  puts("-----------------");

  for (int i=0; v[i]!=0; i++)
   printf("%d\n", v[i]);
}

