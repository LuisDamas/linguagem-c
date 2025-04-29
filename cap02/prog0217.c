#include <stdio.h>

int main(void)
{ int num;
  printf("Introduza um inteiro: ");
  scanf("%d", &num);

  printf("Foi introduzido %d cujo caráter = '%c'\n",
          num, (char) num);
  printf("O caráter seguinte = '%c' tem o ASCII nº %d\n",
     (char) (num+1) , num+1);

  return 0;
}

