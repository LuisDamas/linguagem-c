#include <stdio.h>
#include <limits.h>

int main(void)
{
  printf("Tipo char: Min: %d Max: %d\n", 
         CHAR_MIN, CHAR_MAX);

  printf("Tipo char com sinal por defeito? %s\n", 
         CHAR_MIN<0 ? "Sim" : "Não");
  return 0;
}
