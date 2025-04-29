#include <stdio.h>

void Resolver_Hanoi(int n_discos, char origem,
                    char intermedio, char destino)
{
  if (n_discos==1)
    printf("Mover disco %d de %c para %c\n", n_discos,
           origem, destino);
  else
  {
    Resolver_Hanoi(n_discos-1, origem, destino, intermedio);
    printf("Mover disco %d de %c para %c\n", n_discos, 
           origem, destino);
    Resolver_Hanoi(n_discos-1, intermedio, origem, destino);
  }
}

int main(void)
{
  Resolver_Hanoi(3, 'O', 'I', 'D');

  return 0;
}

