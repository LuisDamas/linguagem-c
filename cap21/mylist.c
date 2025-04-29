#include <stdio.h>
#include <string.h>
#include "mylist.h"

// Zero elementos na lista
void inic_list(MYLIST *ptr)
{
  ptr->count = 0;
}

// Carrega a lista de palavras a partir do ficheiro fp previamente aberto
// Devolve um inteiro com o número de linhas lidas
int load_list(MYLIST *ptr, FILE *fp)
{
  char *s; // string atual
  while (1) 
  {
    if (ptr->count >= MAX_N_STRINGS) 
      break; // lista completa

    if ((s = fgets(ptr->word[ptr->count], MAX_STRING_SIZE, fp))==NULL)
      break; // Problemas na leitura do ficheiro

    // Retirar \n e \r finais da string
    int len = strlen(s)-1;
    while (len>0 && (s[len]=='\r' || s[len]=='\n'))
      s[len--] = '\0';
    ptr->count++; 
  }

  return ptr->count;
}

