#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *str;

  /* Criar s String */
  str = (char *) malloc(6);

  /* colocar "Maria" na string str */
  strcpy(str, "Maria");
  printf("String: %-20s Endereço:%p\n", str, str);

  str = (char *) realloc(str, 100);

  strcat(str, "Silva");
  printf("String: %-20s Endereço:%p\n", str, str);

  /* Libertar a memória */
  free(str);

  return 0;
}

