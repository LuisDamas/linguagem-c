#include <stdio.h>
#define VAR(variavel) n##variavel

int main(void)
{
  int n1=100, n2=200, n3=300, n4=400, n5=500;
  printf("%d\n", VAR(1));
  printf("%d\n", VAR(2));
  printf("%d\n", VAR(3));
  printf("%d\n", VAR(4));
  printf("%d\n", VAR(5));

  return 0;
}

