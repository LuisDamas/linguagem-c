#include <stdio.h>

int main(void)
{
  char s[100];
  char *ptr = s; // Aponta para o primeiro caráter de s

  printf("Introduza uma string: "); gets(s);
  if (*ptr == '\0') return 0;   // String Vazia

  // Imprimir a string Normalmente
  while (*ptr!='\0')
    putchar(*ptr++);
  printf("\n");

  // Imprimir a string ao contrário 
  ptr--; // Por estarmos situados no '\0'

  while (ptr>=s)  /* Enquanto ptr for >= que &s[0] */
    putchar(*ptr--);
  printf("\n");
  return 0;
}

