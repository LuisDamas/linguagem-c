#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{ char s[200];
  char *ptr;  // Pointer para char (futura string)

  printf("Qual a string: "); gets(s);

  // Criar a memória necessária para ter uma cópia de <s>
  ptr = (char *) malloc(strlen(s)+1); // '\0' também conta
  if (ptr==NULL)
  {
    puts("Não foi possível criar a string");
    exit(1);
  }

  // ptr já tem a memória alocada. vamos copiar a string <s> 
  strcpy(ptr, s);
  printf("String original: |%s| Cópia: |%s|\n", s, ptr);

  // Libertar a memória existente em ptr
  free(ptr);
  return 0;
}

