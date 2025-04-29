#include <stdio.h>

int main(void)
{
  char nome[100];
  while (1)              /* Ciclo Infinito            */
  {
    puts("Nome: ");
    gets(nome);
    if (nome[0]=='\0')   /* Se a string estiver vazia */
      break;             /* Terminar o ciclo          */
    printf("Nome introduzido: %s\n", nome);
  }

  return 0;
}

