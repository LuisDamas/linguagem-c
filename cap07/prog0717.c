#include <stdio.h>

int main(void)
{
  char nome1[50], nome2[50];
  printf("Introduza o nome completo: "); 
  scanf("%[^\n]", nome1);

  printf("Introduza o nome completo: ");
  scanf("%[^\n]", nome2);

  printf("Nome completo: [%s]\n", nome1);
  printf("Nome completo: [%s]\n", nome2);

  return 0;
}

