#include <stdio.h>

#define PI 3.1415
#define Mult(x,y) x*y

int main(void)
{
  int x = 4, y = 5;
  float num = 1.23;

  printf("%d*%d=%d\n", x, y, Mult(x, y));
  printf("%d*%f=%f\n", x, PI, Mult(x, PI));
  printf("%f*%f=%f\n", num, PI, Mult(num, PI));

  return 0;
}

