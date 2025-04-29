#include <stdio.h>

void inic(int s[])
{
  for(int i=0; i<10; i++)
    s[i]=0;
}

int main(void)
{
  int v[10];

  inic(v);

  for(int i=0; i<10 ;i++)
    v[i]=i;

  for(int i=10-1; i>=0; i--)
    printf("%d\n",v[i]);

  return 0;
}

