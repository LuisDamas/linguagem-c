#include <stdio.h>
#include <string.h>

#define DIM 20
#define SEP_NOME ", "

int main(void)
{
  char nome[DIM+1], apelido[DIM+1], completo[2*DIM+1];

  while (1)
  {
    printf("Nome: "); gets(nome);
    if (strlen(nome)==0) break;    /* Terminar o Programa */

    printf("Apelido: "); gets(apelido);

    /* Colocar o apelido, nome na string completa */
    strcpy(completo, apelido);      // Copiar o apelido
    strcat(completo, SEP_NOME);     // Juntar o Separador
    strcat(completo, nome);         // Juntar o Primeiro nome 

    puts(completo);
  }

  return 0;
}
