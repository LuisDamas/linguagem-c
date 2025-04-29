#include <stdio.h>
#include <stddef.h>

typedef struct
{
  int membro1;
  double membro2[100];
  char membro3[20];
} REG;


int main(void)
{
  printf("membro1 começa no Offset %ld\n", offsetof(REG, membro1));
  printf("membro2 começa no Offset %ld\n", offsetof(REG, membro2));
  printf("membro3 começa no Offset %ld\n", offsetof(REG, membro3));

  return 0;
}

