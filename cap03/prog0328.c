#include <stdio.h>
int main(void)
{
  int ano;
  printf("Introd. um anoº: ");scanf("%d", &ano);
  if (ano%4 == 0)
    printf("Ano é Bissexto\n");
  else
    printf("Ano não é Bissexto\n");
  return 0;
}

