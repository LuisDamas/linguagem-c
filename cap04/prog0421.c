#include <stdio.h>

int main(void)
{
  int n;

  printf("Introd. um Nº: "); scanf("%d", &n);

  for (int i=n; ; i++) // Ciclo Infinito
   {
    if (i%10 == 0)     // Ver se é múltiplo de 10 
      break;           // Terminar o ciclo

    if (i%3 == 0)      // Se for múltiplo de 3
      continue;        // Passar à próxima iteração

    printf("%d\n", i);
   }
  return 0;
}

