#include <stdio.h>

#define Mult(x,y) (x)*(y)

int main(void)
{
  printf("%d\n", 1000/Mult(2+3,7+3));
  return 0;
}

