#include <stdio.h>

typedef struct
{
  char   c;
  int    n;
  float  x;
} ESTRUTURA;

typedef union
{
  char   c;
  int    n;
  float  x;
} UNIAO;

int main(void)
{
  printf("Dimensão da Estrutura: %d\n", (int) sizeof(ESTRUTURA));
  printf("Dimensão da União    : %d\n", (int) sizeof(UNIAO));

  return 0;
}

