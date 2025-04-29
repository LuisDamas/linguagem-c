#include <stdio.h>
#include <stdlib.h>

#define CHECK_DIVISION(dividendo, divisor) \
  if (divisor==0) \
   { printf("\t>>>Tentativa de divisão por zero\n"); \
     printf("\t>>>Fichieiro: %s Linha: %d\n", __FILE__, __LINE__); \
     exit(1); \
   } 

int main(void)
{
  int n1=10, n2=2, res;
  CHECK_DIVISION(n1,n2);
  res = n1/n2;
  printf("%d/%d=%d\n",n1, n2, res);

  n2-=2;  // n2=0
  CHECK_DIVISION(n1,n2);
  res = n1/n2;
  printf("%d/%d=%d\n",n1, n2, res);

  n2-=2;  // n2=-2
  CHECK_DIVISION(n1,n2);
  res = n1/n2;
  printf("%d/%d=%d\n",n1, n2, res);

  return 0;
}
   
