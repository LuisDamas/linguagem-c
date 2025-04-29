#include <stdio.h>

int Ler_Inteiro(char *prompt)
{
  int n;
  do
  {
    printf("%s", prompt);
    scanf("%d", &n);
  }
  while (n<0);

  return n;
}

int main(void)
{
  int idade, total;
  idade = Ler_Inteiro("Introd. a Idade: ");
  total = Ler_Inteiro("Qual o Total a Depositar: ");

  printf("Idade: %d Total: %d\n", idade, total);

  return 0;
}

