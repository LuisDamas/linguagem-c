#include <stdio.h>

#define Mult(x,y) x*y

int main(void)
{
  printf("Valores: %d*%d=%d\n", 4, 5, Mult(4,5));
  printf("Macro  : %d*%d=%d\n", 3+1, 2+3, Mult(3+1,2+3));

  return 0;
}

