#include <stdio.h>

int main(void)
{
  char estCivil;
  printf("Qual o estado Civil: ");
  scanf(" %c", &estCivil); /* ou estCivil = getchar(); */

  switch(estCivil)
   {
    case 'C': printf("Casado\n");
    case 'S': printf("Solteiro\n");
    case 'D': printf("Divorciado\n");
    case 'V': printf("Viúvo\n");
    default : printf("Estado Civil Incorrecto\n");
   }

  return 0;
}

