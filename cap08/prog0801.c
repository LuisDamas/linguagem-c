#include <stdio.h>

int main(void)
{
  char   v1[10];
  int    v2[] = {1,2,3};
  double v3[500] = {0};

  printf("v1=%p &v1[0]=%p\n", v1, &v1[0]);
  printf("v2=%p &v2[0]=%p\n", v2, &v2[0]);
  printf("v3=%p &v3[0]=%p\n", v3, &v3[0]);

  return 0;
}

