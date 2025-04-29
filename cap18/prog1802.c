#include <stdio.h>

void Down(int n)
{
  if (n<=0) return;

  printf("%d\n", n); 
  Down(n-1);
}

int main(void)
{
  Down(5);
  return 0;
}
