#include <stdio.h>

void Down(int n)
{
  while (n>=1)
    printf("%d\n", n--);
}

int main(void)
{
  Down(5);
  return 0;
}
