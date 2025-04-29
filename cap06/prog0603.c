#include <stdio.h>

void inic(int s[], int n)
{
  for(int i=0;i<n;i++)
    s[i]=0;
}

int main(void)
{
  int v[10];
  int x[20];

  inic(v, 10);
  inic(x, 20);
  return 0;
}

