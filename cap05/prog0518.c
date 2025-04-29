#include <stdio.h>
#include <string.h>

int main()
{
  char nome[50], apelido[50];

  printf("Nome: "); scanf("%s", nome);
  if (strlen(nome)<3)
  {
    printf("Erro: Nome [%s] demasiado pequeno\n", nome);
    return 1;
  }

  printf("Apelido: "); scanf("%s", apelido);
  if (strlen(apelido)==1)
  {
    printf("Erro: Introduzido um apelido com apenas um char\n");
    return 2;
  }

  printf("Nome: %s %s\n", nome, apelido);
  return 0;
}
