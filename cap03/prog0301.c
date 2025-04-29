#include <stdio.h>

int main(void)
{
  int x, y;
  printf("Introduza dois inteiros: ");
  scanf("%d %d", &x, &y);
  printf("O Resultado de %d == %d : %d\n", x, y, x==y);
  printf("O Resultado de %d >  %d : %d\n", x, y, x>y);
  printf("O Resultado de %d >= %d : %d\n", x, y, x>=y);
  printf("O Resultado de %d <  %d : %d\n", x, y, x<y);
  printf("O Resultado de %d <= %d : %d\n", x, y, x<=y);
  printf("O Resultado de %d != %d : %d\n", x, y, x!=y);
  return 0;
}

