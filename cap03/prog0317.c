#include <stdio.h>

int main(void)
{
  char estCivil;
  printf("Qual o estado Civil: ");
  scanf(" %c", &estCivil); /* ou estCivil = getchar(); */

  switch(estCivil)
   {
    case 'c':
    case 'C': printf("Casado\n"); break;
    case 's':
    case 'S': printf("Solteiro\n"); break;
    case 'd':
    case 'D': printf("Divorciado\n"); break;
    case 'v': 
    case 'V': printf("Viúvo\n"); break;
    default : printf("Estado Civil Incorrecto\n");
   }

  return 0;
}

