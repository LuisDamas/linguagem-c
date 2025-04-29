#include <stdio.h>

void Ler_Inteiro(char *prompt, int *ptr)
{
  do
  {
    printf("%s", prompt);
    scanf("%d", ptr); // sem & pois já é um endereço
  }
  while (*ptr<0);
}

int main(void)
{
  int idade, total;
  Ler_Inteiro("Introd. a Idade: ", &idade);
  Ler_Inteiro("Qual o Total a Depositar: ", &total);

  printf("Idade: %d Total: %d\n", idade, total);

  return 0;
}

