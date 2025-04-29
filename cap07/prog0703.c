#include <stdio.h>

int main(void)
{
  char nome[50];
  printf("Introduza o nome completo: "); 
  gets(nome);
  printf("Nome completo: [%s]\n",nome);

  return 0;
}

