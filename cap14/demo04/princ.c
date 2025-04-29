#include <stdio.h>     /* Por causa do NULL */
#include "princ.h"

int main(void)
{
  int inteiros[] = {2, 5, 7, 3, 0};
  char *strings[] = {"odio", "felicidade", "amor", "choro", NULL};

  imprimir_inteiros(inteiros);
  imprimir_strings(strings);

  return 0;
}

