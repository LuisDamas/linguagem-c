#include <stdio.h>

int main(void)
{
  register int x=7;
  printf("%d %x", x, &x);

  return 0;
}
