#include <stdio.h>

float max2(float a, float b)
{
  return (a>=b)? a : b;
}

float max3(float x, float y, float w)
{
  return max2(x, max2(y, w));
}

int main(void)
{
  float a1, a2, a3;

  a1 = 1.0; a2 = 2.0; a3 = 3.0;
  printf("Max(%.2f, %.2f, %.2f) --> %.2f\n", a1, a2, a3,
         max3(a1, a2, a3));

  a1 = 3.0; a2 = 2.0; a3 = 1.0;
  printf("Max(%.2f, %.2f, %.2f) --> %.2f\n", a1, a2, a3,
         max3(a1, a2, a3)); 

  a1 = 1.0; a2 = 1.0; a3 = 1.0;
  printf("Max(%.2f, %.2f, %.2f) --> %.2f\n", a1, a2, a3,
         max3(a1, a2, a3));

  a1 = -1.0; a2 = -2.0; a3 = -3.0;
  printf("Max(%.2f, %.2f, %.2f) --> %.2f\n", a1, a2, a3,
         max3(a1, a2, a3));

  a1 = 1.0; a2 = 7.0; a3 = 3.0;
  printf("Max(%.2f, %.2f, %.2f) --> %.2f\n", a1, a2, a3,
         max3(a1, a2, a3));

  return 0;
}



