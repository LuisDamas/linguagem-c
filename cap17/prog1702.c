#include <stdio.h>

typedef enum {SEGUNDA=2, TERCA=3, QUARTA=4, QUINTA=5,
              SEXTA=6, SABADO=7, DOMINGO=1} DIA_DA_SEMANA;

int main(void)
{  
  DIA_DA_SEMANA dia = SEGUNDA;

  puts("Dias úteis");
  while (dia < SABADO)
    printf(" >> %dª feira\n", dia++);

  return 0;
}

