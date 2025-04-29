#include <stdio.h>

int main(void)
{
  int x=5, *px = &x;
  double y=5.0, *py = &y;

  printf("%d %lu\n", x, (unsigned long) px);
  printf("%d %lu\n\n", x+1, (unsigned long) (px+1));

  printf("%lf %lu\n", y, (unsigned long) py);
  printf("%lf %lu\n", y+1, (unsigned long) (py+1));

  return 0;
}

