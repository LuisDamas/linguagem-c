#include <stdio.h>

int main(void)
{
  int num=1000;
  printf("Introduza um caráter: ");
  scanf("%c", &num);
  printf("O valor de num = %d cujo caráter = '%c'\n",
       num, (char) num);
  return 0;
}

