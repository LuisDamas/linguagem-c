#include <stdio.h>

int main(void)
{
  char ch1 = 'X', ch2 = 'Y';
  printf("Introduza um inteiro: ");
  scanf("%hd",&ch2);
  printf("O valor de ch1 = '%c' e ch2 = '%c'\n", ch1, ch2);
  return 0;
}

