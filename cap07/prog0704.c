#include <stdio.h>

int main(void)
{
  char nome[50];
  printf("Introduza o nome completo: "); 
  fgets(nome, 50, stdin);
  printf("Nome completo: [%s]\n",nome);

  return 0;
}

