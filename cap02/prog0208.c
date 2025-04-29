#include <stdio.h>

int main(void)
{
  printf("     double --> %d bytes\n", (int) sizeof(double));
  printf("long double --> %d bytes\n", (int) sizeof(long double));
  return 0;
}

