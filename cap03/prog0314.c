#include <stdio.h>

int main(void)
{
  char estCivil;
  puts("Qual o Estado Civil:");
  estCivil = getchar();

  if (estCivil == 'S' || estCivil == 's')
    printf("Solteiro");
  else
    if (estCivil == 'C' || estCivil == 'c')
      printf("Casado");
    else
      if (estCivil == 'D' || estCivil == 'd')
        printf("Divorciado");
      else
        if (estCivil == 'V' || estCivil == 'v')
          printf("Viúvo");
        else
          printf("Estado Civil Inválido");

  printf("\n");
  return 0;
}

