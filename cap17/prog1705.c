#include <stdio.h>

union Uniao
{
  char   c;
  int    n;
  float  x;
};


int main(void)
{
  union Uniao uniao;

  uniao.x = 12345.678;
  printf("Float inicial igual a : %9.3f\n", uniao.x);
  printf("char: '%c' int: %d  float: %9.3f\n\n", uniao.c, uniao.n, uniao.x);

  uniao.n = 1625001234;
  printf("Alterar apenas o int para %d\n", uniao.n);
  printf("char: '%c' int: %d  float: %9.3f\n\n", uniao.c, uniao.n, uniao.x);

  uniao.c = '@';
  printf("Alterar apenas o char para '%c'\n", uniao.c);
  printf("char: '%c' int: %d  float: %9.3f\n\n", uniao.c, uniao.n, uniao.x);

  return 0;
}

