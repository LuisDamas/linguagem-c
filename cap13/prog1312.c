#include <stdio.h>

int main(void)
{
  printf("Estou na Linha %d\n", __LINE__);
  printf("Estou na Linha %d\n\n", __LINE__);

#line 8000
  printf("Estou na Linha %d\n", __LINE__);
  printf("Estou na Linha %d\n", __LINE__);

  return 0;
}

