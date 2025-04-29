#include <stdio.h>

#define NUM 10          // sem ponto e vírgula

void inic(int s[])
{
  for(int i=0; i<NUM; i++)
    s[i]=0;
}

int main(void)
{
  int v[NUM];

  inic(v);

  for(int i=0; i<NUM ;i++)
    v[i]=i;

  for(int i=NUM-1; i>=0; i--)
    printf("%d\n",v[i]);

  return 0;
}

