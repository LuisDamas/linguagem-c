#include <stdio.h>

int main(void)
{
  char estCivil;
  printf("Qual o estado Civil: ");
  scanf(" %c", &estCivil); /* ou estCivil = getchar(); */

  switch(estCivil)
   {
    case 'C': printf("Casado\n"); break;
    case 'S': printf("Solteiro\n"); break;
    case 'D': printf("Divorciado\n");
              break;
    case 'V': printf("Viúvo\n");
              break;
    default : printf("Estado Civil Incorrecto\n");
   }

  return 0;
}

