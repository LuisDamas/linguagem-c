#include <stdio.h>

const int num = 10;

void inic(int s[])
{
  for(int i=0; i<num; i++)
    s[i]=0;
}

int main(void)
{
  int v[num];

  inic(v);

  for(int i=0; i<num ;i++)
    v[i]=i;

  for(int i=num-1; i>=0; i--)
    printf("%d\n",v[i]);

  return 0;
}

