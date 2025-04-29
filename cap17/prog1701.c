#include <stdio.h>
enum dias {SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO, DOMINGO};

int main(void)
 {  
  enum dias hoje = SEGUNDA;
  
  if ((hoje+1) == TERCA)
    puts("Amanhã será terça-feira");

  return 0;
 }

