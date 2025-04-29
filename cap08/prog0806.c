#include <stdio.h>
int my_strlen(char *s); /* Protótipo da função */

int main(void)
{
  char nome[100];
  printf("Introduza um nome: "); gets(nome);
  printf("[%s] --> %d\n", nome, my_strlen(nome));

  return 0;
}

int my_strlen(char *s)
{
  char *ptr_ini = s;    // Guardar o endereço inicial
  while (*s!='\0')      // Enquanto não chegarmos ao fim
    s++;                // Incrementar o apontador

  return (int) (s-ptr_ini);  // Devolver a diferença entre os
}                            // endereços

