#include <stdio.h>

typedef enum {SEGUNDA=2, TERCA, QUARTA, QUINTA,
              SEXTA, SABADO, DOMINGO=1} DIA_DA_SEMANA;

int main(void)
{  
  DIA_DA_SEMANA dia = SEGUNDA;

  puts("Dias úteis");
  while (dia<SABADO)
    printf(" >> %dª feira\n", dia++);

  return 0;
}

