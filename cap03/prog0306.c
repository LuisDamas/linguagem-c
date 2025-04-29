#include <stdio.h>

int main(void)
{
  int x, y, tmp;
  printf("Introd. dois Nºs: ");
  scanf("%d %d", &x, &y);

  if (x > y)  // trocar os valores
  {
     tmp = x;
     x = y;
     y = tmp;
  }

  printf("%d %d\n", x, y);
  return 0;
}

