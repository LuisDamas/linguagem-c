#include <stdio.h>

int main(void)
{
  char nome[50];
  printf("Introduza o nome completo: "); 
  scanf("%[^\n]", nome);
  printf("Nome completo: [%s]\n", nome);

  return 0;
}

