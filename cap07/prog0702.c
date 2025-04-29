#include <stdio.h>

int main(void)
{
  char nome[50], apelido[50];
  printf("Introduza o Nome    : "); scanf("%s", nome);
  printf("Introduza o Apelido : "); scanf("%s", apelido);
  printf("Nome completo       : %s %s\n", nome, apelido);
  return 0;
}

